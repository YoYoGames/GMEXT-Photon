//
// GM_Photon_voice_new.cpp
// ExitGames PhotonVoice-cpp SDK wrapper implementation
//
// Architecture:
//   LoadBalancingTransport wraps the LB::Client and implements IVoiceTransport,
//   routing voice frames through opRaiseEvent and receiving them via customEventAction.
//   VoiceClient owns the voice logic and uses the transport.
//
//   Note: SDK v5 createLocalVoiceFramed<T> has a missing mLogger arg in its
//   ALLOCATE call, so it cannot be instantiated directly. We instead use
//   createLocalVoiceAudioFromSource<short> with a minimal GMLAudioPusher adapter.
//   GMLAudioPusher implements IAudioPusher<short> and acts as the data source;
//   photon_voice_push_frame_buffer delivers PCM frames through it.
//
//   Bridge functions (photon_voice_internal_*) are declared here and called from
//   GMPhotonListener in GM_Photon_native_new.cpp so that room/player events
//   reach the voice layer without the two TUs sharing state directly.
//

#include "GMPhoton_native.h"

#include <atomic>  // required before PhotonVoice headers on GCC/Clang (std::atomic<bool> in SDK internals)
#include <PhotonVoice-cpp/inc/VoiceClient.h>
#include <PhotonVoice-cpp/inc/VoiceInfo.h>
#include <PhotonVoice-cpp/inc/VoiceAudio.h>
#include <PhotonVoice-cpp/inc/RemoteVoiceInfo.h>
#include <PhotonVoice-cpp/inc/RemoteVoiceOptions.h>
#include <PhotonVoice-cpp/inc/OpusCodec.h>
#include <PhotonVoice-cpp/inc/Logger.h>
#include <PhotonVoice-cpp/inc/Enums/Codec.h>
#include <PhotonVoice-cpp/inc/Transport/LoadBalancingTransport.h>

#include <LoadBalancing-cpp/inc/Client.h>
#include <Common-cpp/inc/JString.h>
#include <Common-cpp/inc/Common.h>
#include <Common-cpp/inc/Containers/JVector.h>
#include <Common-cpp/inc/Object.h>
#include <Common-cpp/inc/BaseListener.h>

#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include <deque>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <cwchar>
#include <codecvt>
#include <locale>

using namespace gm_structs;
using namespace gm_enums;

namespace C     = ExitGames::Common;
namespace LB    = ExitGames::LoadBalancing;
namespace Voice = ExitGames::Voice;

// Forward declaration — defined in GM_Photon_native_new.cpp
extern LB::Client* photon_internal_get_lb_client();

// =============================================================================
// Queued incoming voice frame (decoded PCM shorts stored as raw bytes)
// =============================================================================

struct PhotonQueuedVoiceFrame
{
    int  player_id = -1;
    int  voice_id  = -1;
    std::vector<nByte> payload; // raw bytes of decoded int16 PCM (2 bytes/sample)
};

// =============================================================================
// GMLAudioPusher — minimal IAudioPusher<short> that lets us push PCM from GML
//
// createLocalVoiceFramed<T> is broken in SDK v5 (missing mLogger in ALLOCATE).
// createLocalVoiceAudioFromSource<T> works correctly and uses this pusher as
// both the IAudioDesc (provides sampling rate/channels) and the data source.
// The SDK calls setCallback once; we call that callback from push().
// =============================================================================

class GMLAudioPusher : public Voice::IAudioPusher<short>
{
public:
    GMLAudioPusher(int samplingRate, int channels)
        : mSamplingRate(samplingRate), mChannels(channels)
        , mpOpaque(nullptr), mpCallback(nullptr) {}

    virtual int getSamplingRate(void) const override { return mSamplingRate; }
    virtual int getChannels(void)     const override { return mChannels; }
    virtual C::JString getError(void) const override { return C::JString(); }

    virtual void setCallback(void* opaque, void(*pCallback)(void*, const Voice::Buffer<short>&)) override
    {
        mpOpaque   = opaque;
        mpCallback = pCallback;
    }

    virtual C::JString& toString(C::JString& retStr, bool /*withTypes*/) const override
    {
        return retStr += C::JString(L"GMLAudioPusher");
    }

    // Called from photon_voice_push_frame_buffer to deliver PCM to the voice stream
    void push(const Voice::Buffer<short>& buf)
    {
        if(mpCallback)
            mpCallback(mpOpaque, buf);
    }

private:
    int   mSamplingRate;
    int   mChannels;
    void* mpOpaque;
    void(*mpCallback)(void*, const Voice::Buffer<short>&);
};

// =============================================================================
// Local voice entry — voice pointer (owned by VoiceClient) + pusher (owned by us)
// The pusher must outlive the LocalVoice because the voice holds a pointer to it.
// transmit_enabled is mirrored locally so we can read it without depending on
// LocalVoice::isTransmitEnabled() (name varies across SDK versions).
// =============================================================================

// =============================================================================
// JString → std::string helper (ASCII-safe; SDK log messages are ASCII)
// =============================================================================

static void append_utf8_codepoint(std::string& out, std::uint32_t cp)
{
    if(cp <= 0x7F)
    {
        out += static_cast<char>(cp);
    }
    else if(cp <= 0x7FF)
    {
        out += static_cast<char>(0xC0 | (cp >> 6));
        out += static_cast<char>(0x80 | (cp & 0x3F));
    }
    else if(cp <= 0xFFFF)
    {
        out += static_cast<char>(0xE0 | (cp >> 12));
        out += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
        out += static_cast<char>(0x80 | (cp & 0x3F));
    }
    else
    {
        out += static_cast<char>(0xF0 | (cp >> 18));
        out += static_cast<char>(0x80 | ((cp >> 12) & 0x3F));
        out += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
        out += static_cast<char>(0x80 | (cp & 0x3F));
    }
}

// Manual wchar_t -> UTF-8 conversion. Handles UTF-16 surrogate pairs explicitly
// (wchar_t is UTF-16 on Windows, where codecvt_utf8<wchar_t> incorrectly assumes
// UCS-4 and mis-encodes any codepoint above U+FFFF) and is also correct on
// platforms where wchar_t is already UTF-32.
static std::string voice_jstring_to_str(const C::JString& js)
{
    const wchar_t* ws = js.cstr();
    if(!ws || *ws == L'\0')
        return {};

    std::string out;
    for(const wchar_t* p = ws; *p != L'\0'; ++p)
    {
        std::uint32_t cu = static_cast<std::uint32_t>(static_cast<std::uint16_t>(*p));

        if(cu >= 0xD800 && cu <= 0xDBFF)
        {
            const wchar_t* next = p + 1;
            std::uint32_t lo = static_cast<std::uint32_t>(static_cast<std::uint16_t>(*next));
            if(*next != L'\0' && lo >= 0xDC00 && lo <= 0xDFFF)
            {
                const std::uint32_t cp = 0x10000 + ((cu - 0xD800) << 10) + (lo - 0xDC00);
                append_utf8_codepoint(out, cp);
                ++p;
                continue;
            }
            // Unpaired high surrogate — emit the replacement character.
            append_utf8_codepoint(out, 0xFFFD);
            continue;
        }
        if(cu >= 0xDC00 && cu <= 0xDFFF)
        {
            // Unpaired low surrogate — emit the replacement character.
            append_utf8_codepoint(out, 0xFFFD);
            continue;
        }

        append_utf8_codepoint(out, cu);
    }
    return out;
}

// =============================================================================
// BaseListener subclass — captures SDK voice log messages into a thread-safe
// queue that is drained and forwarded to GML in photon_voice_service().
// =============================================================================

struct VoiceDebugMessage { int level; std::string text; };
static std::deque<VoiceDebugMessage> g_voice_debug_queue;
static std::mutex                    g_voice_debug_mutex;

class GMLVoiceDebugListener : public C::BaseListener
{
public:
    void debugReturn(int debugLevel, const C::JString& string) override
    {
        std::lock_guard<std::mutex> lk(g_voice_debug_mutex);
        g_voice_debug_queue.push_back({ debugLevel, voice_jstring_to_str(string) });
    }
};
static GMLVoiceDebugListener g_voice_debug_listener;

// =============================================================================
// Global state
// =============================================================================

static Voice::Logger                                     g_voice_logger;
static std::unique_ptr<Voice::LoadBalancingTransport>    g_voice_transport;
static std::unique_ptr<Voice::VoiceClient>               g_voice_client;
static bool                                              g_voice_initialized = false;

// Stable wrapper voice handle -> entry. Do not expose LocalVoice::getId() directly:
// SDK voice ids are nByte and can roll over after 256 creations.
// transmit_enabled mirrors LocalVoice::isTransmitEnabled so we can read it without SDK getter
struct LocalVoiceEntry
{
    Voice::LocalVoice*              voice;
    std::unique_ptr<GMLAudioPusher> pusher;
    bool                            transmit_enabled = true;
};
static std::unordered_map<int, LocalVoiceEntry>          g_local_voices;
static std::int32_t                                      g_next_local_voice_handle = 1;

// remote voice snapshot rebuilt each service tick for GML queries
struct RemoteVoiceEntry { int player_id; int voice_id; int codec; int sample_rate; int channels; bool is_speaking; };
static std::vector<RemoteVoiceEntry>                     g_remote_voices_snapshot;

// thread-safe incoming frame queue — output callback may arrive on SDK thread
static std::deque<PhotonQueuedVoiceFrame>                g_voice_frame_queue;
static std::mutex                                        g_voice_frame_mutex;

// removed voice events — queued from SDK callback, drained in service() on game thread
struct RemoteVoiceRemovedEvent { int player_id; int voice_id; };
static std::deque<RemoteVoiceRemovedEvent>               g_voice_removed_queue;

// Voice protocol events (202 / 203) that arrived before the transport was ready.
// Replayed in photon_voice_init() so late-init doesn't miss existing players' voice infos.
struct PendingVoiceEvent { int playerNr; nByte eventCode; C::Object eventContent; };
static std::vector<PendingVoiceEvent>                    g_pending_voice_events;

// per-remote-player mute, volume, and last-frame-time (protected by g_voice_cfg_mutex)
static std::mutex                                        g_voice_cfg_mutex;
static std::unordered_map<int, bool>                     g_remote_player_muted;
static std::unordered_map<int, float>                    g_remote_player_volume;
static std::unordered_map<int, std::chrono::steady_clock::time_point> g_remote_voice_last_frame_time;

// =============================================================================
// Callback registry
// =============================================================================

static gm::wire::GMFunction g_voice_cb_remote_voice_added   = nullptr;
static gm::wire::GMFunction g_voice_cb_remote_voice_removed = nullptr;
static gm::wire::GMFunction g_voice_cb_speaking_changed     = nullptr;
static gm::wire::GMFunction g_voice_cb_debug                = nullptr;

// Speaking detection — threshold in ms and previous per-voice state
// Key: player_id * 256 + voice_id  (voice_id is nByte, 0-255)
static std::int32_t                  g_speaking_threshold_ms = 200;
static std::unordered_map<int, bool> g_voice_prev_speaking;

// =============================================================================
// Remote voice context (heap-allocated per remote voice stream)
// =============================================================================

struct RemoteVoiceCtx
{
    int player_id;
    int voice_id;
};

static std::mutex g_remote_voice_ctx_mutex;
static std::unordered_set<RemoteVoiceCtx*> g_remote_voice_contexts;

// Static output callback — non-capturing so it converts to a function pointer.
// Checks mute/volume under g_voice_cfg_mutex, applies PCM scaling if needed,
// updates last-frame-time for speaking detection, then enqueues the frame.
static void remote_voice_output(void* op, const Voice::Buffer<short>& buf)
{
    if(!op || buf.getSize() == 0)
        return;

    auto* ctx = static_cast<RemoteVoiceCtx*>(op);

    float vol = 1.0f;
    {
        std::lock_guard<std::mutex> cfg_lk(g_voice_cfg_mutex);

        // mute check
        auto mit = g_remote_player_muted.find(ctx->player_id);
        if(mit != g_remote_player_muted.end() && mit->second)
            return;

        // volume
        auto vit = g_remote_player_volume.find(ctx->player_id);
        if(vit != g_remote_player_volume.end())
            vol = vit->second;

        // speaking activity timestamp — keyed by player+voice so two simultaneous
        // remote voices for one player don't share a timestamp (matches the key
        // scheme used by g_voice_prev_speaking).
        g_remote_voice_last_frame_time[ctx->player_id * 256 + ctx->voice_id] = std::chrono::steady_clock::now();
    }

    PhotonQueuedVoiceFrame frame;
    frame.player_id = ctx->player_id;
    frame.voice_id  = ctx->voice_id;

    const int num_samples = buf.getSize();
    const int byte_count  = num_samples * static_cast<int>(sizeof(short));
    frame.payload.resize(byte_count);

    if(vol == 1.0f)
    {
        std::memcpy(frame.payload.data(), buf.getArray(), byte_count);
    }
    else
    {
        // Scale PCM samples by volume, clamping to int16 range
        const short* src = buf.getArray();
        short* dst = reinterpret_cast<short*>(frame.payload.data());
        for(int i = 0; i < num_samples; ++i)
        {
            float s = static_cast<float>(src[i]) * vol;
            s = std::max(-32768.f, std::min(32767.f, s));
            dst[i] = static_cast<short>(s);
        }
    }

    std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
    g_voice_frame_queue.push_back(std::move(frame));
}

// Queues a removed-voice event so the GML callback fires on the game thread in service().
static void remote_voice_remove(void* op)
{
    auto* ctx = static_cast<RemoteVoiceCtx*>(op);
    if(!ctx)
        return;

    int player_id = -1;
    int voice_id = -1;
    {
        std::lock_guard<std::mutex> ctx_lk(g_remote_voice_ctx_mutex);
        const auto it = g_remote_voice_contexts.find(ctx);
        if(it == g_remote_voice_contexts.end())
            return;
        player_id = ctx->player_id;
        voice_id = ctx->voice_id;
        g_remote_voice_contexts.erase(it);
    }

    {
        std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
        g_voice_removed_queue.push_back({ player_id, voice_id });
    }
    delete ctx;
}

// =============================================================================
// Remote voice info callback — wires up decoder output and GML notification
// =============================================================================

static void on_remote_voice_info(void* /*opaque*/,
                                 int /*channelId*/, int playerId, nByte voiceId,
                                 const Voice::VoiceInfo& info,
                                 Voice::RemoteVoiceOptions& options)
{
    auto* ctx = new RemoteVoiceCtx{ playerId, static_cast<int>(voiceId) };
    {
        std::lock_guard<std::mutex> ctx_lk(g_remote_voice_ctx_mutex);
        g_remote_voice_contexts.insert(ctx);
    }

    // Decoded short PCM frames will be enqueued for GML to poll
    options.setOutput(ctx, remote_voice_output);
    options.setRemoteVoiceRemoveAction(ctx, remote_voice_remove);

    if(g_voice_cb_remote_voice_added)
    {
        g_voice_cb_remote_voice_added.call(
            playerId,
            static_cast<int>(voiceId),
            static_cast<int>(info.getCodec()),
            info.getSamplingRate(),
            info.getChannels()
        );
    }
}

// =============================================================================
// Lifecycle
// =============================================================================

bool photon_voice_init()
{
    if(g_voice_initialized)
        return true;

    LB::Client* lbc = photon_internal_get_lb_client();
    if(!lbc)
        return false;

    g_voice_logger.setListener(g_voice_debug_listener);

    g_voice_transport = std::make_unique<Voice::LoadBalancingTransport>(g_voice_logger, *lbc);
    g_voice_client    = std::make_unique<Voice::VoiceClient>(g_voice_logger, g_voice_transport.get());

    g_voice_client->setOnRemoteVoiceInfoAction(nullptr, on_remote_voice_info);

    // Replay voice protocol events that arrived before the transport existed.
    // Existing players send their voice infos when a newcomer joins — if that
    // happens before photon_voice_init(), they're buffered here and processed now.
    for(const auto& ev : g_pending_voice_events)
        g_voice_transport->onCustomEvent(ev.playerNr, ev.eventCode, ev.eventContent);
    g_pending_voice_events.clear();

    g_voice_initialized = true;
    return true;
}

bool photon_voice_shutdown()
{
    if(!g_voice_initialized)
        return false;

    if(g_voice_client)
        g_voice_client->onLeaveAllChannels();

    // VoiceClient owns LocalVoices, which may still point at our pushers.
    // Destroy the VoiceClient first while pushers are still alive, then release pushers.
    g_voice_client.reset();

    // SDK teardown normally invokes each remote-voice remove action. Delete any
    // contexts left behind if this SDK build does not do so for every active voice.
    {
        std::lock_guard<std::mutex> ctx_lk(g_remote_voice_ctx_mutex);
        for(RemoteVoiceCtx* ctx : g_remote_voice_contexts)
            delete ctx;
        g_remote_voice_contexts.clear();
    }

    g_local_voices.clear();
    g_next_local_voice_handle = 1;
    g_voice_transport.reset();

    {
        std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
        g_voice_frame_queue.clear();
        g_voice_removed_queue.clear();
    }

    g_pending_voice_events.clear();

    {
        std::lock_guard<std::mutex> cfg_lk(g_voice_cfg_mutex);
        g_remote_player_muted.clear();
        g_remote_player_volume.clear();
        g_remote_voice_last_frame_time.clear();
    }

    {
        std::lock_guard<std::mutex> lk(g_voice_debug_mutex);
        g_voice_debug_queue.clear();
    }

    g_voice_prev_speaking.clear();
    g_remote_voices_snapshot.clear();
    g_voice_initialized = false;
    return true;
}

bool photon_voice_service()
{
    if(!g_voice_initialized || !g_voice_transport || !g_voice_client)
        return false;

    g_voice_transport->service();

    // Rebuild remote voice snapshot and detect speaking-state transitions
    auto infos = g_voice_client->getRemoteVoiceInfos();
    g_remote_voices_snapshot.clear();

    // Collect speaking-state transitions while the lock is held, but defer firing
    // the GML callback until after it's released — g_voice_cfg_mutex is non-reentrant
    // and the callback may re-enter functions (e.g. set_remote_player_muted) that take it.
    struct SpeakingChange { int player_id; int voice_id; bool speaking; };
    std::vector<SpeakingChange> speaking_changes;
    {
        auto now = std::chrono::steady_clock::now();
        std::lock_guard<std::mutex> cfg_lk(g_voice_cfg_mutex);
        for(int i = 0; i < static_cast<int>(infos.getSize()); ++i)
        {
            const auto& rv   = infos[i];
            const auto& info = rv.getInfo();

            bool speaking = false;
            const int frame_time_key = rv.getPlayerId() * 256 + static_cast<int>(rv.getVoiceId());
            auto tit = g_remote_voice_last_frame_time.find(frame_time_key);
            if(tit != g_remote_voice_last_frame_time.end())
                speaking = (now - tit->second) < std::chrono::milliseconds(g_speaking_threshold_ms);

            g_remote_voices_snapshot.push_back({
                rv.getPlayerId(),
                static_cast<int>(rv.getVoiceId()),
                static_cast<int>(info.getCodec()),
                info.getSamplingRate(),
                info.getChannels(),
                speaking
            });

            // Record speaking-state transitions; callback fires after the lock is released.
            if(g_voice_cb_speaking_changed)
            {
                int key = rv.getPlayerId() * 256 + static_cast<int>(rv.getVoiceId());
                auto sit = g_voice_prev_speaking.find(key);
                bool prev = (sit != g_voice_prev_speaking.end()) ? sit->second : false;
                if(speaking != prev)
                {
                    g_voice_prev_speaking[key] = speaking;
                    speaking_changes.push_back({rv.getPlayerId(), static_cast<int>(rv.getVoiceId()), speaking});
                }
            }
        }
    }
    for(const auto& ch : speaking_changes)
        g_voice_cb_speaking_changed.call(ch.player_id, ch.voice_id, ch.speaking);

    // Drain removed-voice events
    std::deque<RemoteVoiceRemovedEvent> removed;
    {
        std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
        removed.swap(g_voice_removed_queue);
    }
    for(const auto& ev : removed)
    {
        const int key = ev.player_id * 256 + ev.voice_id;
        g_voice_prev_speaking.erase(key);
        {
            std::lock_guard<std::mutex> cfg_lk(g_voice_cfg_mutex);
            g_remote_voice_last_frame_time.erase(key);
        }
        if(g_voice_cb_remote_voice_removed)
            g_voice_cb_remote_voice_removed.call(ev.player_id, ev.voice_id);
    }

    // Drain SDK debug messages and forward to GML
    if(g_voice_cb_debug)
    {
        std::deque<VoiceDebugMessage> dbg;
        {
            std::lock_guard<std::mutex> lk(g_voice_debug_mutex);
            dbg.swap(g_voice_debug_queue);
        }
        for(const auto& msg : dbg)
            g_voice_cb_debug.call(msg.level, msg.text);
    }
    else
    {
        std::lock_guard<std::mutex> lk(g_voice_debug_mutex);
        g_voice_debug_queue.clear();
    }

    return true;
}

bool photon_voice_is_initialized() { return g_voice_initialized; }

// Called from GML after photon_voice_init() when already inside a room.
// Triggers the voice-info exchange handshake so existing players' remote voices
// are discovered (the automatic bridge call fires at join time, before init).
bool photon_voice_notify_joined_room()
{
    if(!g_voice_transport) return false;
    g_voice_transport->onJoinRoom();
    return true;
}

// =============================================================================
// Bridge functions — called from GMPhotonListener in GM_Photon_native_new.cpp
// =============================================================================

void photon_voice_internal_on_join_room()
{
    if(g_voice_transport) g_voice_transport->onJoinRoom();
}

void photon_voice_internal_on_leave_room()
{
    if(g_voice_transport) g_voice_transport->onLeaveRoom();
}

void photon_voice_internal_on_player_join(int playerNr)
{
    if(g_voice_transport) g_voice_transport->onPlayerJoinRoom(playerNr);
}

void photon_voice_internal_on_player_leave(int playerNr)
{
    if(g_voice_transport) g_voice_transport->onPlayerLeaveRoom(playerNr);
}

// Returns true if the event was a voice protocol event (codes 202 / 203) and should
// not be forwarded to the regular realtime event queue.
bool photon_voice_internal_on_custom_event(int playerNr, nByte eventCode, const C::Object& eventContent)
{
    // EventCode::VOICE_DATA = 202, EventCode::VOICE_FRAME_DATA = 203
    if(eventCode != 202 && eventCode != 203) return false;

    if(!g_voice_transport)
    {
        // Transport not ready yet — buffer so init() can replay.
        // Code 202 (voice info) is the one that matters; 203 (frame data) can be discarded
        // since audio frames for unknown voices are meaningless before the decoder is set up.
        if(eventCode == 202)
            g_pending_voice_events.push_back({ playerNr, eventCode, eventContent });
        return true; // still consume it — keep it out of the regular event queue
    }

    g_voice_transport->onCustomEvent(playerNr, eventCode, eventContent);
    return true;
}

void photon_voice_internal_on_direct_message(const C::Object& msg, int remoteID, bool relay)
{
    if(g_voice_transport) g_voice_transport->onDirectMessage(msg, remoteID, relay);
}

// =============================================================================
// Transport channel events  (manual GML-driven channel lifecycle)
// =============================================================================

bool photon_voice_on_join_channel(std::int32_t channel_id)
{
    if(!g_voice_client) return false;
    g_voice_client->onJoinChannel(channel_id);
    return true;
}

bool photon_voice_on_leave_channel(std::int32_t channel_id)
{
    if(!g_voice_client) return false;
    g_voice_client->onLeaveChannel(channel_id);
    return true;
}

bool photon_voice_on_join_all_channels()
{
    if(!g_voice_client) return false;
    g_voice_client->onJoinAllChannels();
    return true;
}

bool photon_voice_on_leave_all_channels()
{
    if(!g_voice_client) return false;
    g_voice_client->onLeaveAllChannels();
    return true;
}

bool photon_voice_on_player_join(std::int32_t channel_id, std::int32_t player_id)
{
    if(!g_voice_client) return false;
    g_voice_client->onPlayerJoin(channel_id, player_id);
    return true;
}

bool photon_voice_on_player_leave(std::int32_t channel_id, std::int32_t player_id)
{
    if(!g_voice_client) return false;
    g_voice_client->onPlayerLeave(channel_id, player_id);
    return true;
}

// =============================================================================
// Local voice management
// =============================================================================

// codec       : PhotonVoiceCodec enum value (e.g. AUDIO_OPUS = 11)
// sample_rate : e.g. 48000
// channels    : 1 = mono, 2 = stereo
// bitrate     : Opus encoder bitrate in bps (e.g. 24000)
// frames_per_packet : number of 10ms Opus frames per network packet (e.g. 2 = 20ms)
std::int32_t photon_voice_create_local_voice(std::int32_t channel_id, gm_enums::PhotonVoiceCodec codec,
    std::int32_t sample_rate, std::int32_t channels,
    std::int32_t bitrate, std::int32_t frames_per_packet)
{
    if(!g_voice_client) return -1;

    const int frame_duration_us = frames_per_packet * Voice::Opus::FrameDuration::FRAME_10_MS;

    Voice::VoiceInfo info;
    info.setCodec(static_cast<Voice::Codec::Enum>(codec))
        .setSamplingRate(sample_rate)
        .setChannels(channels)
        .setFrameDurationUs(frame_duration_us)
        .setBitrate(bitrate);

    // Create a pusher that acts as both IAudioDesc and the data source.
    // createLocalVoiceAudioFromSource<short> works; createLocalVoiceFramed<short>
    // does not (SDK v5 ALLOCATE bug — missing mLogger argument).
    auto pusher = std::make_unique<GMLAudioPusher>(sample_rate, channels);
    GMLAudioPusher* pusher_raw = pusher.get();

    Voice::LocalVoiceAudio<short>* voice =
        g_voice_client->createLocalVoiceAudioFromSource<short>(info, pusher_raw, channel_id);

    if(!voice) return -1;

    std::int32_t handle = g_next_local_voice_handle++;
    if(g_next_local_voice_handle <= 0)
        g_next_local_voice_handle = 1;

    while(g_local_voices.find(handle) != g_local_voices.end())
    {
        handle = g_next_local_voice_handle++;
        if(g_next_local_voice_handle <= 0)
            g_next_local_voice_handle = 1;
    }

    g_local_voices[handle] = LocalVoiceEntry{ voice, std::move(pusher), true };
    return handle;
}

bool photon_voice_remove_local_voice(std::int32_t voice_id)
{
    if(!g_voice_client) return false;

    auto it = g_local_voices.find(voice_id);
    if(it == g_local_voices.end()) return false;

    // removeLocalVoice destroys the LocalVoice; erase after so pusher outlives it
    g_voice_client->removeLocalVoice(*it->second.voice);
    g_local_voices.erase(it); // also destroys pusher via unique_ptr
    return true;
}

// Push raw int16 PCM (little-endian) from a GML buffer into the local voice stream.
// The SDK's LocalVoiceAudio<short> re-frames and Opus-encodes before sending.
bool photon_voice_push_frame_buffer(std::int32_t voice_id, gm::wire::GMBuffer data, std::uint32_t bytes)
{
    if(!g_voice_client || bytes == 0)
        return false;

    auto it = g_local_voices.find(voice_id);
    if(it == g_local_voices.end()) return false;

    // Validate against the full sample frame size (all channels), not just one int16
    // sample, so an odd sample count for stereo/multi-channel voices is rejected
    // instead of silently misaligning channels for the rest of the stream.
    const std::size_t frame_size = static_cast<std::size_t>(it->second.pusher->getChannels()) * sizeof(short);
    if(frame_size == 0 || bytes % frame_size != 0)
        return false;

    // Read raw bytes from GML buffer
    std::vector<nByte> raw(bytes);
    auto reader = data.getReader();
    reader.readBytes(reinterpret_cast<char*>(raw.data()), static_cast<int>(bytes));

    // Wrap as Voice::Buffer<short> and push through the pusher
    const int num_samples = static_cast<int>(bytes / 2);
    Voice::Buffer<short> buf(num_samples);
    std::memcpy(buf.getArray(), raw.data(), bytes);

    it->second.pusher->push(buf);
    return true;
}

// =============================================================================
// Incoming voice frame queue  (polled by GML each frame)
// =============================================================================

std::int32_t photon_voice_get_frame_queue_count()
{
    std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
    return static_cast<std::int32_t>(g_voice_frame_queue.size());
}

bool photon_voice_clear_frame_queue()
{
    std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
    g_voice_frame_queue.clear();
    return true;
}

std::int32_t photon_voice_peek_next_frame_size()
{
    std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
    if(g_voice_frame_queue.empty()) return 0;
    return static_cast<std::int32_t>(g_voice_frame_queue.front().payload.size());
}

std::int32_t photon_voice_peek_next_frame_player_id()
{
    std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
    if(g_voice_frame_queue.empty()) return -1;
    return g_voice_frame_queue.front().player_id;
}

std::int32_t photon_voice_peek_next_frame_voice_id()
{
    std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
    if(g_voice_frame_queue.empty()) return -1;
    return g_voice_frame_queue.front().voice_id;
}

// Dequeues the front frame into out_data starting at offset, up to max_bytes bytes.
// Returns struct: { ok, player_number (= player_id), event_code (= voice_id), bytes_written }
gm_structs::PhotonRealtimeEventBufferReceived photon_voice_receive_frame_buffer(
    gm::wire::GMBuffer out_data, std::uint32_t max_bytes, std::uint32_t offset)
{
    gm_structs::PhotonRealtimeEventBufferReceived out{};
    out.ok           = false;
    out.player_number = -1;
    out.event_code   = -1;
    out.bytes_written = 0;

    if(max_bytes == 0) return out;

    std::lock_guard<std::mutex> lk(g_voice_frame_mutex);
    if(g_voice_frame_queue.empty()) return out;

    PhotonQueuedVoiceFrame frame = std::move(g_voice_frame_queue.front());
    g_voice_frame_queue.pop_front();

    const std::uint32_t cb       = static_cast<std::uint32_t>(frame.payload.size());
    const std::uint32_t to_write = (cb < max_bytes) ? cb : max_bytes;

    auto writer = out_data.getWriter();
    writer.skip(offset);
    writer.writeBytes(reinterpret_cast<const char*>(frame.payload.data()), static_cast<int>(to_write));

    out.player_number  = frame.player_id;
    out.event_code     = frame.voice_id;
    out.bytes_written  = to_write;
    out.ok             = true;
    return out;
}

// =============================================================================
// Remote voice list  (snapshot rebuilt by photon_voice_service each tick)
// =============================================================================

std::int32_t photon_voice_get_remote_voice_count()
{
    return static_cast<std::int32_t>(g_remote_voices_snapshot.size());
}

std::int32_t photon_voice_get_remote_voice_player_id(std::int32_t index)
{
    if(index < 0 || index >= static_cast<int>(g_remote_voices_snapshot.size())) return -1;
    return g_remote_voices_snapshot[index].player_id;
}

std::int32_t photon_voice_get_remote_voice_id(std::int32_t index)
{
    if(index < 0 || index >= static_cast<int>(g_remote_voices_snapshot.size())) return -1;
    return g_remote_voices_snapshot[index].voice_id;
}

gm_enums::PhotonVoiceCodec photon_voice_get_remote_voice_codec(std::int32_t index)
{
    if(index < 0 || index >= static_cast<int>(g_remote_voices_snapshot.size())) return gm_enums::PhotonVoiceCodec{};
    return static_cast<gm_enums::PhotonVoiceCodec>(g_remote_voices_snapshot[index].codec);
}

std::int32_t photon_voice_get_remote_voice_sample_rate(std::int32_t index)
{
    if(index < 0 || index >= static_cast<int>(g_remote_voices_snapshot.size())) return 0;
    return g_remote_voices_snapshot[index].sample_rate;
}

std::int32_t photon_voice_get_remote_voice_channels(std::int32_t index)
{
    if(index < 0 || index >= static_cast<int>(g_remote_voices_snapshot.size())) return 0;
    return g_remote_voices_snapshot[index].channels;
}

bool photon_voice_get_remote_voice_is_speaking(std::int32_t index)
{
    if(index < 0 || index >= static_cast<int>(g_remote_voices_snapshot.size())) return false;
    return g_remote_voices_snapshot[index].is_speaking;
}

// =============================================================================
// Stats
// =============================================================================

std::int32_t photon_voice_get_frames_sent()           { return g_voice_client ? g_voice_client->getFramesSent()             : 0; }
std::int32_t photon_voice_get_frames_received()       { return g_voice_client ? g_voice_client->getFramesReceived()         : 0; }
std::int32_t photon_voice_get_frames_lost()           { return g_voice_client ? g_voice_client->getFramesLost()             : 0; }
std::int32_t photon_voice_get_round_trip_time()       { return g_voice_client ? g_voice_client->getRoundTripTime()          : 0; }
std::int32_t photon_voice_get_round_trip_time_variance() { return g_voice_client ? g_voice_client->getRoundTripTimeVariance() : 0; }

// =============================================================================
// Callback registration
// =============================================================================

bool photon_voice_set_callback_remote_voice_added(const gm::wire::GMFunction& callback)
{
    g_voice_cb_remote_voice_added = callback;
    return true;
}

bool photon_voice_set_callback_remote_voice_removed(const gm::wire::GMFunction& callback)
{
    g_voice_cb_remote_voice_removed = callback;
    return true;
}

bool photon_voice_remove_callback_remote_voice_added()   { g_voice_cb_remote_voice_added   = nullptr; return true; }
bool photon_voice_remove_callback_remote_voice_removed() { g_voice_cb_remote_voice_removed = nullptr; return true; }

bool photon_voice_set_callback_speaking_changed(const gm::wire::GMFunction& callback)
{
    g_voice_cb_speaking_changed = callback;
    return true;
}
bool photon_voice_remove_callback_speaking_changed() { g_voice_cb_speaking_changed = nullptr; return true; }

bool photon_voice_set_callback_debug(const gm::wire::GMFunction& callback)
{
    g_voice_cb_debug = callback;
    return true;
}
bool photon_voice_remove_callback_debug() { g_voice_cb_debug = nullptr; return true; }

// =============================================================================
// Speaking threshold
// =============================================================================

std::int32_t photon_voice_get_speaking_threshold_ms()
{
    std::lock_guard<std::mutex> cfg_lk(g_voice_cfg_mutex);
    return g_speaking_threshold_ms;
}

bool photon_voice_set_speaking_threshold_ms(std::int32_t ms)
{
    if(ms < 0) return false;
    std::lock_guard<std::mutex> cfg_lk(g_voice_cfg_mutex);
    g_speaking_threshold_ms = ms;
    return true;
}

// =============================================================================
// Debug
// =============================================================================

std::int32_t photon_voice_get_debug_lost_percent()
{
    return g_voice_client ? g_voice_client->getDebugLostPercent() : 0;
}

bool photon_voice_set_debug_lost_percent(std::int32_t percent)
{
    if(!g_voice_client) return false;
    g_voice_client->setDebugLostPercent(percent);
    return true;
}

// =============================================================================
// Local voice transmit control
// =============================================================================

bool photon_voice_local_voice_set_transmit(std::int32_t voice_id, bool enabled)
{
    auto it = g_local_voices.find(voice_id);
    if(it == g_local_voices.end()) return false;
    it->second.voice->setTransmitEnabled(enabled);
    it->second.transmit_enabled = enabled;
    return true;
}

bool photon_voice_local_voice_get_transmit(std::int32_t voice_id)
{
    auto it = g_local_voices.find(voice_id);
    if(it == g_local_voices.end()) return false;
    return it->second.transmit_enabled;
}

// =============================================================================
// Remote player mute / volume
// Applied in remote_voice_output before frames reach the GML queue.
// =============================================================================

bool photon_voice_set_remote_player_muted(std::int32_t player_id, bool muted)
{
    std::lock_guard<std::mutex> lk(g_voice_cfg_mutex);
    g_remote_player_muted[player_id] = muted;
    return true;
}

bool photon_voice_get_remote_player_muted(std::int32_t player_id)
{
    std::lock_guard<std::mutex> lk(g_voice_cfg_mutex);
    auto it = g_remote_player_muted.find(player_id);
    return (it != g_remote_player_muted.end()) ? it->second : false;
}

bool photon_voice_set_remote_player_volume(std::int32_t player_id, double volume)
{
    std::lock_guard<std::mutex> lk(g_voice_cfg_mutex);
    g_remote_player_volume[player_id] = static_cast<float>(volume);
    return true;
}

double photon_voice_get_remote_player_volume(std::int32_t player_id)
{
    std::lock_guard<std::mutex> lk(g_voice_cfg_mutex);
    auto it = g_remote_player_volume.find(player_id);
    return (it != g_remote_player_volume.end()) ? static_cast<double>(it->second) : 1.0;
}
