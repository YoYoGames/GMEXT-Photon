//
// GM_Photon_chat_new.cpp
// ExitGames Chat-cpp SDK wrapper implementation
//

#include "GMPhoton_native.h"

#include <Chat-cpp/inc/Client.h>
#include <Chat-cpp/inc/Listener.h>
#include <Chat-cpp/inc/Channel.h>
#include <Chat-cpp/inc/AuthenticationValues.h>
#include <Chat-cpp/inc/Enums/ClientState.h>
#include <Chat-cpp/inc/Enums/DisconnectCause.h>
#include <Chat-cpp/inc/Enums/UserStatus.h>

#include <Common-cpp/inc/JString.h>
#include <Common-cpp/inc/ANSIString.h>
#include <Common-cpp/inc/Object.h>
#include <Common-cpp/inc/Common.h>
#include <Common-cpp/inc/Containers/JVector.h>

#include <atomic>
#include <cstdint>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <vector>
#include <deque>
#include <codecvt>
#include <locale>

using namespace gm_structs;
using namespace gm_enums;

namespace C    = ExitGames::Common;
namespace Chat = ExitGames::Chat;

// =============================================================================
// Global state
// =============================================================================

static std::unique_ptr<Chat::Client> g_chat_client;
static bool g_chat_initialized = false;

// GMChatListener callbacks can run on the SDK's background thread when
// use_background_thread is set, while these are read/mutated from the game thread.
static std::atomic<bool> g_chat_connected{false};
static std::atomic<bool> g_chat_background_thread{false};
static std::mutex g_chat_broadcast_mutex;

// Region requested via photon_chat_select_region(). Unlike Realtime, Chat::Client
// has no SELECT-mode pause/callback flow — setRegion() just needs to be called on
// the client instance before connect(), so we apply it in photon_chat_connect().
static std::string g_chat_pending_region;


// =============================================================================
// Callback registry
// =============================================================================

static gm::wire::GMFunction g_chat_callback_debug             = nullptr;
static gm::wire::GMFunction g_chat_callback_state_change      = nullptr;
static gm::wire::GMFunction g_chat_callback_connection_error  = nullptr;
static gm::wire::GMFunction g_chat_callback_client_error      = nullptr;
static gm::wire::GMFunction g_chat_callback_warning           = nullptr;
static gm::wire::GMFunction g_chat_callback_server_error      = nullptr;
static gm::wire::GMFunction g_chat_callback_connected           = nullptr;
static gm::wire::GMFunction g_chat_callback_disconnected        = nullptr;
static gm::wire::GMFunction g_chat_callback_subscribe         = nullptr;
static gm::wire::GMFunction g_chat_callback_unsubscribe       = nullptr;
static gm::wire::GMFunction g_chat_callback_status_update     = nullptr;
static gm::wire::GMFunction g_chat_callback_get_messages      = nullptr;
static gm::wire::GMFunction g_chat_callback_private_message   = nullptr;
static gm::wire::GMFunction g_chat_callback_receive_broadcast = nullptr;

struct PhotonChatQueuedBroadcast
{
    std::string channel_name;
    std::vector<nByte> payload;
};

static std::deque<PhotonChatQueuedBroadcast> g_chat_broadcast_queue;

// =============================================================================
// Helpers
// =============================================================================

// Manual UTF-8 <-> wchar_t conversion helpers.
//
// std::codecvt_utf8<wchar_t> (as opposed to codecvt_utf8_utf16<wchar_t>) is specified to
// treat wchar_t as a single UCS-2/UCS-4 code unit and never generates or interprets UTF-16
// surrogate pairs. On Windows wchar_t is 16-bit UTF-16, so it cannot represent any codepoint
// above U+FFFF (most emoji, many rare CJK characters): decoding such UTF-8 throws (falling
// back to a lossy ANSI/Latin-1 JString construction), and encoding a genuine UTF-16 surrogate
// pair mis-emits each half as its own invalid UTF-8 sequence instead of combining them. These
// helpers handle surrogate pairs explicitly and work correctly regardless of wchar_t's width.

static void chat_append_utf8_codepoint(std::string& out, std::uint32_t cp)
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

static std::wstring chat_utf8_to_wstring(const std::string& s)
{
    std::wstring out;
    std::size_t i = 0;
    const std::size_t n = s.size();
    while(i < n)
    {
        const unsigned char c0 = static_cast<unsigned char>(s[i]);
        std::uint32_t cp = 0;
        std::size_t len = 0;
        if(c0 < 0x80)                 { cp = c0;          len = 1; }
        else if((c0 & 0xE0) == 0xC0)  { cp = c0 & 0x1F;    len = 2; }
        else if((c0 & 0xF0) == 0xE0)  { cp = c0 & 0x0F;    len = 3; }
        else if((c0 & 0xF8) == 0xF0)  { cp = c0 & 0x07;    len = 4; }
        else
        {
            out.push_back(static_cast<wchar_t>(0xFFFD));
            ++i;
            continue;
        }

        if(i + len > n)
        {
            out.push_back(static_cast<wchar_t>(0xFFFD));
            break;
        }

        bool valid = true;
        for(std::size_t k = 1; k < len; ++k)
        {
            const unsigned char ck = static_cast<unsigned char>(s[i + k]);
            if((ck & 0xC0) != 0x80) { valid = false; break; }
            cp = (cp << 6) | (ck & 0x3F);
        }
        if(!valid)
        {
            out.push_back(static_cast<wchar_t>(0xFFFD));
            ++i;
            continue;
        }
        i += len;

        if constexpr(sizeof(wchar_t) >= 4)
        {
            out.push_back(static_cast<wchar_t>(cp));
        }
        else if(cp <= 0xFFFF)
        {
            out.push_back(static_cast<wchar_t>(cp));
        }
        else
        {
            const std::uint32_t v = cp - 0x10000;
            out.push_back(static_cast<wchar_t>(0xD800 + (v >> 10)));
            out.push_back(static_cast<wchar_t>(0xDC00 + (v & 0x3FF)));
        }
    }
    return out;
}

static inline C::JString chat_to_jstring(const std::string& s)
{
    if(s.empty())
        return C::JString();

    const std::wstring ws = chat_utf8_to_wstring(s);
    return C::JString(ws.c_str());
}

static inline std::string chat_from_jstring(const C::JString& s)
{
    const wchar_t* ws = s.cstr();
    if(!ws || *ws == L'\0')
        return std::string{};

    std::string out;
    for(const wchar_t* p = ws; *p != L'\0'; ++p)
    {
        std::uint32_t cu = static_cast<std::uint32_t>(static_cast<std::uint16_t>(*p));

        if(cu >= 0xD800 && cu <= 0xDBFF)
        {
            const wchar_t* next = p + 1;
            const std::uint32_t lo = static_cast<std::uint32_t>(static_cast<std::uint16_t>(*next));
            if(*next != L'\0' && lo >= 0xDC00 && lo <= 0xDFFF)
            {
                const std::uint32_t cp = 0x10000 + ((cu - 0xD800) << 10) + (lo - 0xDC00);
                chat_append_utf8_codepoint(out, cp);
                ++p;
                continue;
            }
            chat_append_utf8_codepoint(out, 0xFFFD);
            continue;
        }
        if(cu >= 0xDC00 && cu <= 0xDFFF)
        {
            chat_append_utf8_codepoint(out, 0xFFFD);
            continue;
        }

        chat_append_utf8_codepoint(out, cu);
    }
    return out;
}

static inline std::string chat_object_to_string(const C::Object& obj)
{
    if(obj.getType() == C::TypeCode::STRING)
    {
        C::ValueObject<C::JString> vo(obj);
        const C::JString* p = vo.getDataAddress();
        return p ? chat_from_jstring(*p) : std::string{};
    }
    return chat_from_jstring(obj.toString(false));
}

static inline bool chat_has_client()
{
    return g_chat_initialized && static_cast<bool>(g_chat_client);
}

// =============================================================================
// Listener
// =============================================================================

class GMChatListener final : public Chat::Listener
{
public:
    // ---- Debug / Errors -------------------------------------------------
    void debugReturn(int debugLevel, const C::JString& string) override
    {
        if(g_chat_callback_debug)
            g_chat_callback_debug.call(debugLevel, chat_from_jstring(string));
    }

    void connectionErrorReturn(int errorCode) override
    {
        g_chat_connected = false;
        if(g_chat_callback_connection_error)
            g_chat_callback_connection_error.call(errorCode);
    }

    void clientErrorReturn(int errorCode) override
    {
        if(g_chat_callback_client_error)
            g_chat_callback_client_error.call(errorCode);
    }

    void warningReturn(int warningCode) override
    {
        if(g_chat_callback_warning)
            g_chat_callback_warning.call(warningCode);
    }

    void serverErrorReturn(int errorCode) override
    {
        if(g_chat_callback_server_error)
            g_chat_callback_server_error.call(errorCode);
    }

    // ---- Connection -----------------------------------------------------
    void onStateChange(int state) override
    {
        // Correct g_chat_connected against any SDK-side transition to Disconnected that
        // doesn't go through connectReturn/disconnectReturn/connectionErrorReturn, so the
        // cached flag can't go stale.
        if(state == ExitGames::Chat::ClientState::Disconnected)
            g_chat_connected = false;

        if(g_chat_callback_state_change)
            g_chat_callback_state_change.call(state);
    }

    void connectReturn(int errorCode, const C::JString& errorString) override
    {
        g_chat_connected = (errorCode == 0);

        if(g_chat_callback_connected)
            g_chat_callback_connected.call(errorCode, chat_from_jstring(errorString));
    }

    void disconnectReturn(void) override
    {
        g_chat_connected = false;

        if(g_chat_callback_disconnected)
            g_chat_callback_disconnected.call();
    }

    // ---- Channel operations ---------------------------------------------
    void subscribeReturn(const C::JVector<C::JString>& channels, const C::JVector<bool>& results) override
    {
        if(!g_chat_callback_subscribe) return;
        gm::wire::ArrayStream stream;
        for(unsigned int i = 0; i < channels.getSize(); ++i)
        {
            PhotonChatSubscribeResult r;
            r.channel_name = chat_from_jstring(channels[i]);
            r.success      = (i < results.getSize()) ? results[i] : false;
            stream << r;
        }
        g_chat_callback_subscribe.call(stream);
    }

    void unsubscribeReturn(const C::JVector<C::JString>& channels) override
    {
        if(!g_chat_callback_unsubscribe) return;
        gm::wire::ArrayStream stream;
        for(unsigned int i = 0; i < channels.getSize(); ++i)
            stream << chat_from_jstring(channels[i]);
        g_chat_callback_unsubscribe.call(stream);
    }

    // ---- Messages -------------------------------------------------------
    void onGetMessages(const C::JString& channelName, const C::JVector<C::JString>& senders, const C::JVector<C::Object>& messages) override
    {
        if(!g_chat_callback_get_messages) return;
        gm::wire::ArrayStream stream;
        for(unsigned int i = 0; i < messages.getSize(); ++i)
        {
            PhotonChatMessage msg;
            msg.sender  = (i < senders.getSize()) ? chat_from_jstring(senders[i]) : std::string{};
            msg.content = chat_object_to_string(messages[i]);
            stream << msg;
        }
        g_chat_callback_get_messages.call(chat_from_jstring(channelName), stream);
    }

    void onPrivateMessage(const C::JString& sender, const C::Object& message, const C::JString& channelName) override
    {
        if(g_chat_callback_private_message)
            g_chat_callback_private_message.call(
                chat_from_jstring(sender),
                chat_from_jstring(channelName),
                chat_object_to_string(message)
            );
    }

    void onReceiveBroadcastMessage(const C::JString& channelName, nByte* inBuff, int inBuffBodyLength) override
    {
        const std::string channel = chat_from_jstring(channelName);

        PhotonChatQueuedBroadcast ev{};
        ev.channel_name = channel;
        if(inBuff && inBuffBodyLength > 0)
            ev.payload.assign(inBuff, inBuff + inBuffBodyLength);
        {
            std::lock_guard<std::mutex> lk(g_chat_broadcast_mutex);
            g_chat_broadcast_queue.push_back(std::move(ev));
        }

        if(g_chat_callback_receive_broadcast)
            g_chat_callback_receive_broadcast.call(
                channel,
                inBuffBodyLength
            );
    }

    // ---- Friends / Status -----------------------------------------------
    void onStatusUpdate(const C::JString& user, int status, bool gotMessage, const C::Object& message) override
    {
        if(g_chat_callback_status_update)
            g_chat_callback_status_update.call(
                chat_from_jstring(user),
                status,
                gotMessage,
                gotMessage ? chat_object_to_string(message) : std::string{}
            );
    }
};

static GMChatListener g_chat_listener_instance;

// =============================================================================
// Lifecycle
// =============================================================================

bool photon_chat_init()
{
    g_chat_initialized = true;
    g_chat_connected   = false;

    return true;
}

bool photon_chat_shutdown()
{
    if(g_chat_client)
    {
        try { g_chat_client->disconnect(); }
        catch(...) {}
    }

    g_chat_client.reset();
    {
        std::lock_guard<std::mutex> lk(g_chat_broadcast_mutex);
        g_chat_broadcast_queue.clear();
    }
    g_chat_connected = false;
    g_chat_background_thread = false;
    g_chat_initialized = false;

    return true;
}

bool photon_chat_service()
{
    if(!chat_has_client())
        return false;

    g_chat_client->service();
    return true;
}

// =============================================================================
// Connection
// =============================================================================

bool photon_chat_select_region(std::string_view region)
{
    g_chat_pending_region = std::string(region);

    // Chat-cpp has no SELECT-mode pause/callback flow like Realtime — setRegion()
    // just needs to have been called on the Client instance before connect().
    // If a client already exists (e.g. selecting a region between reconnects),
    // apply it immediately; otherwise it will be applied in photon_chat_connect().
    if(chat_has_client())
        g_chat_client->setRegion(chat_to_jstring(g_chat_pending_region));

    return true;
}

bool photon_chat_connect(std::string_view app_id, std::string_view app_version, const std::optional<gm_structs::PhotonChatConnectOptions>& options)
{

    if(!g_chat_initialized)
        return false;

    try
    {
        if(g_chat_client && g_chat_connected)
        {
            try { g_chat_client->disconnect(); }
            catch(...) {}
        }
        g_chat_client.reset();
        g_chat_client = std::make_unique<Chat::Client>(
            g_chat_listener_instance,
            chat_to_jstring(std::string(app_id)),
            chat_to_jstring(std::string(app_version))
        );

        if(!g_chat_pending_region.empty())
            g_chat_client->setRegion(chat_to_jstring(g_chat_pending_region));
    }
    catch(...)
    {
        g_chat_client.reset();
        return false;
    }

    Chat::AuthenticationValues auth;
    C::JString nameServer;
    bool hasNameServerOverride = false;
    bool useBackgroundThread = false;

    if(options)
    {
        if(options->authentication_values)
        {
            const auto& a = *options->authentication_values;
            if(a.user_id)    auth.setUserID(chat_to_jstring(*a.user_id));
            if(a.auth_type)  auth.setType(static_cast<nByte>(*a.auth_type));
            if(a.parameters) auth.setParameters(chat_to_jstring(*a.parameters));
        }
        if(options->server_address)
        {
            nameServer = chat_to_jstring(*options->server_address);
            hasNameServerOverride = true;
        }
        if(options->use_background_thread) useBackgroundThread = *options->use_background_thread;
    }

    g_chat_connected = false;
    try
    {
        if(hasNameServerOverride)
        {
            g_chat_background_thread = useBackgroundThread;
            return g_chat_client->connect(auth, nameServer, useBackgroundThread);
        }

        g_chat_background_thread = false;
        // Omit the address entirely so Chat-cpp uses the SDK's own default name server.
        // Do not duplicate the SDK's private M_NAMESERVER literal in the wrapper.
        return g_chat_client->connect(auth);
    }
    catch(...)
    {
        return false;
    }
}

bool photon_chat_disconnect()
{
    if(!chat_has_client())
        return false;

    try { g_chat_client->disconnect(); }
    catch(...) { return false; }
    return true;
}

// =============================================================================
// Channel operations
// =============================================================================

static C::JVector<C::JString> chat_to_jvector(const std::vector<std::string_view>& v)
{
    C::JVector<C::JString> jv;
    for(const auto& s : v)
        jv.addElement(chat_to_jstring(std::string(s)));
    return jv;
}

bool photon_chat_operation_subscribe(const std::vector<std::string_view>& channels, std::optional<std::int32_t> messages_from_history, const std::optional<gm::wire::GMFunction>& callback)
{
    if (callback) g_chat_callback_subscribe = *callback;
    if(!chat_has_client() || channels.empty()) return false;
    if(messages_from_history)
        return g_chat_client->opSubscribe(chat_to_jvector(channels), *messages_from_history);
    return g_chat_client->opSubscribe(chat_to_jvector(channels));
}

bool photon_chat_operation_unsubscribe(const std::vector<std::string_view>& channels, const std::optional<gm::wire::GMFunction>& callback)
{
    if (callback) g_chat_callback_unsubscribe = *callback;
    if(!chat_has_client() || channels.empty()) return false;
    return g_chat_client->opUnsubscribe(chat_to_jvector(channels));
}

// =============================================================================
// Publish / Private messages
// =============================================================================

bool photon_chat_operation_publish_message(std::string_view channel_name, std::string_view message)
{
    if(!chat_has_client()) return false;
    return g_chat_client->opPublishMessage(
        chat_to_jstring(std::string(channel_name)),
        chat_to_jstring(std::string(message))
    );
}

bool photon_chat_operation_send_private_message(std::string_view user_name, std::string_view message, std::optional<bool> encrypt)
{
    if(!chat_has_client()) return false;
    return g_chat_client->opSendPrivateMessage(
        chat_to_jstring(std::string(user_name)),
        chat_to_jstring(std::string(message)),
        encrypt.value_or(false)
    );
}

// =============================================================================
// User status
// =============================================================================

bool photon_chat_operation_set_online_status(gm_enums::PhotonChatUserStatus status, std::optional<std::string_view> message)
{
    if(!chat_has_client())
        return false;

    if(message)
        return g_chat_client->opSetOnlineStatus(static_cast<int>(status), chat_to_jstring(std::string(*message)));
    return g_chat_client->opSetOnlineStatus(static_cast<int>(status));
}

// =============================================================================
// Friends
// =============================================================================

bool photon_chat_operation_add_friends(const std::vector<std::string_view>& user_ids)
{
    if(!chat_has_client() || user_ids.empty()) return false;
    return g_chat_client->opAddFriends(chat_to_jvector(user_ids));
}

bool photon_chat_operation_remove_friends(const std::vector<std::string_view>& user_ids)
{
    if(!chat_has_client() || user_ids.empty()) return false;
    return g_chat_client->opRemoveFriends(chat_to_jvector(user_ids));
}

// =============================================================================
// Incoming broadcast buffer queue
// =============================================================================

std::int32_t photon_chat_get_broadcast_queue_count()
{
    std::lock_guard<std::mutex> lk(g_chat_broadcast_mutex);
    return static_cast<std::int32_t>(g_chat_broadcast_queue.size());
}

bool photon_chat_clear_broadcast_queue()
{
    std::lock_guard<std::mutex> lk(g_chat_broadcast_mutex);
    g_chat_broadcast_queue.clear();
    return true;
}

std::int32_t photon_chat_peek_next_broadcast_size()
{
    std::lock_guard<std::mutex> lk(g_chat_broadcast_mutex);
    if(g_chat_broadcast_queue.empty())
        return 0;
    return static_cast<std::int32_t>(g_chat_broadcast_queue.front().payload.size());
}

std::string photon_chat_peek_next_broadcast_channel()
{
    std::lock_guard<std::mutex> lk(g_chat_broadcast_mutex);
    if(g_chat_broadcast_queue.empty())
        return std::string{};
    return g_chat_broadcast_queue.front().channel_name;
}

gm_structs::PhotonRealtimeEventBufferReceived photon_chat_receive_one_broadcast_buffer(
    gm::wire::GMBuffer out_data,
    std::uint32_t max_bytes,
    std::uint32_t offset)
{
    gm_structs::PhotonRealtimeEventBufferReceived out{};
    out.ok = false;
    out.player_number = -1;
    out.event_code = -1;
    out.bytes_written = 0;

    std::lock_guard<std::mutex> lk(g_chat_broadcast_mutex);

    if(max_bytes == 0 || g_chat_broadcast_queue.empty())
        return out;

    const PhotonChatQueuedBroadcast& ev = g_chat_broadcast_queue.front();
    const std::uint32_t cb = static_cast<std::uint32_t>(ev.payload.size());

    if(cb > max_bytes)
        return out;

    auto writer = out_data.getWriter();
    writer.skip(offset);
    if(cb > 0)
        writer.writeBytes(reinterpret_cast<const char*>(ev.payload.data()), static_cast<int>(cb));

    g_chat_broadcast_queue.pop_front();

    out.bytes_written = cb;
    out.ok = true;
    return out;
}

// =============================================================================
// State getters
// =============================================================================

// Symbolic-constant mappings (verified against Chat-cpp/inc/Enums/ClientState.h and
// DisconnectCause.h) instead of a raw static_cast, so a future SDK enum renumbering fails
// safe to Unknown rather than silently producing a wrong GML-side state/cause - same pattern
// already used for the LoadBalancing side in photon_realtime_state_from_sdk/
// photon_realtime_disconnect_cause_from_sdk.
static gm_enums::PhotonChatState chat_state_from_sdk(int state)
{
    namespace CS = ExitGames::Chat::ClientState;

    switch(state)
    {
        case CS::Uninitialized:               return gm_enums::PhotonChatState::Uninitialized;
        case CS::ConnectingToNameServer:      return gm_enums::PhotonChatState::ConnectingToNameServer;
        case CS::ConnectedToNameServer:       return gm_enums::PhotonChatState::ConnectedToNameServer;
        case CS::Authenticating:              return gm_enums::PhotonChatState::Authenticating;
        case CS::Authenticated:               return gm_enums::PhotonChatState::Authenticated;
        case CS::DisconnectingFromNameServer: return gm_enums::PhotonChatState::DisconnectingFromNameServer;
        case CS::ConnectingToFrontEnd:        return gm_enums::PhotonChatState::ConnectingToFrontEnd;
        case CS::ConnectedToFrontEnd:         return gm_enums::PhotonChatState::ConnectedToFrontEnd;
        case CS::Disconnecting:               return gm_enums::PhotonChatState::Disconnecting;
        case CS::Disconnected:                return gm_enums::PhotonChatState::Disconnected;
        default: return gm_enums::PhotonChatState::Unknown;
    }
}

static gm_enums::PhotonChatDisconnectCause chat_disconnect_cause_from_sdk(int cause)
{
    namespace DC = ExitGames::Chat::DisconnectCause;

    switch(cause)
    {
        case DC::NONE:                                   return gm_enums::PhotonChatDisconnectCause::None;
        case DC::DISCONNECT_BY_SERVER_USER_LIMIT:        return gm_enums::PhotonChatDisconnectCause::ServerUserLimit;
        case DC::EXCEPTION_ON_CONNECT:                   return gm_enums::PhotonChatDisconnectCause::ExceptionOnConnect;
        case DC::DISCONNECT_BY_SERVER:                   return gm_enums::PhotonChatDisconnectCause::DisconnectByServer;
        case DC::DISCONNECT_BY_SERVER_LOGIC:             return gm_enums::PhotonChatDisconnectCause::DisconnectByServerLogic;
        case DC::TIMEOUT_DISCONNECT:                     return gm_enums::PhotonChatDisconnectCause::TimeoutDisconnect;
        case DC::EXCEPTION:                              return gm_enums::PhotonChatDisconnectCause::Exception;
        case DC::INVALID_AUTHENTICATION:                 return gm_enums::PhotonChatDisconnectCause::InvalidAuthentication;
        case DC::MAX_CCU_REACHED:                        return gm_enums::PhotonChatDisconnectCause::MaxCcuReached;
        case DC::INVALID_REGION:                         return gm_enums::PhotonChatDisconnectCause::InvalidRegion;
        case DC::OPERATION_NOT_ALLOWED_IN_CURRENT_STATE: return gm_enums::PhotonChatDisconnectCause::OperationNotAllowed;
        case DC::CUSTOM_AUTHENTICATION_FAILED:           return gm_enums::PhotonChatDisconnectCause::CustomAuthenticationFailed;
        default: return gm_enums::PhotonChatDisconnectCause::Unknown;
    }
}

bool         photon_chat_is_initialized()         { return g_chat_initialized; }
bool         photon_chat_is_connected()           { return g_chat_connected; }
gm_enums::PhotonChatState           photon_chat_get_state()           { return chat_has_client() ? chat_state_from_sdk(g_chat_client->getState())                       : gm_enums::PhotonChatState::Uninitialized; }
gm_enums::PhotonChatDisconnectCause photon_chat_get_disconnect_cause() { return chat_has_client() ? chat_disconnect_cause_from_sdk(g_chat_client->getDisconnectedCause()) : gm_enums::PhotonChatDisconnectCause::None; }
std::string  photon_chat_get_user_id()            { return chat_has_client() ? chat_from_jstring(g_chat_client->getUserID())  : std::string{}; }
std::string  photon_chat_get_region()             { return chat_has_client() ? chat_from_jstring(g_chat_client->getRegion())  : std::string{}; }
std::int32_t photon_chat_get_server_time()        { return chat_has_client() ? g_chat_client->getServerTime()       : 0; }
std::int32_t photon_chat_get_server_time_offset() { return chat_has_client() ? g_chat_client->getServerTimeOffset() : 0; }
std::int32_t photon_chat_get_bytes_in()           { return chat_has_client() ? g_chat_client->getBytesIn()          : 0; }
std::int32_t photon_chat_get_bytes_out()          { return chat_has_client() ? g_chat_client->getBytesOut()         : 0; }

// =============================================================================
// Channel data  (Public = 0, Private = 1)
// =============================================================================

static bool chat_channel_is_private(gm_enums::PhotonChatChannelType channel_type)
{
    return channel_type == gm_enums::PhotonChatChannelType::Private;
}

static const Chat::Channel* chat_get_channel(gm_enums::PhotonChatChannelType channel_type, std::string_view name)
{
    auto jname = chat_to_jstring(std::string(name));
    return chat_channel_is_private(channel_type)
        ? g_chat_client->getPrivateChannel(jname)
        : g_chat_client->getPublicChannel(jname);
}

std::int32_t photon_chat_get_channel_count(gm_enums::PhotonChatChannelType channel_type)
{
    // SDK-owned channel containers are not safe to inspect while the Chat SDK
    // background thread may resize them. Use callbacks, or connect without background mode.
    if(g_chat_background_thread) return 0;
    if(!chat_has_client()) return 0;
    const auto& ch = chat_channel_is_private(channel_type)
        ? g_chat_client->getPrivateChannels()
        : g_chat_client->getPublicChannels();
    return static_cast<std::int32_t>(ch.getSize());
}

std::string photon_chat_get_channel_name(gm_enums::PhotonChatChannelType channel_type, std::int32_t index)
{
    // SDK-owned channel containers are not safe to inspect while the Chat SDK
    // background thread may resize them. Use callbacks, or connect without background mode.
    if(g_chat_background_thread) return {};
    if(!chat_has_client()) return {};
    const auto& channels = chat_channel_is_private(channel_type)
        ? g_chat_client->getPrivateChannels()
        : g_chat_client->getPublicChannels();
    if(index < 0 || static_cast<unsigned>(index) >= channels.getSize()) return {};
    return chat_from_jstring(channels[static_cast<unsigned>(index)]->getName());
}

std::int32_t photon_chat_get_channel_message_count(gm_enums::PhotonChatChannelType channel_type, std::string_view channel_name)
{
    // SDK-owned channel containers are not safe to inspect while the Chat SDK
    // background thread may resize them. Use callbacks, or connect without background mode.
    if(g_chat_background_thread) return 0;
    if(!chat_has_client()) return 0;
    const Chat::Channel* ch = chat_get_channel(channel_type, channel_name);
    if(!ch) return 0;
    return static_cast<std::int32_t>(ch->getMessageCount());
}

std::string photon_chat_get_channel_message(gm_enums::PhotonChatChannelType channel_type, std::string_view channel_name, std::int32_t index)
{
    // SDK-owned channel containers are not safe to inspect while the Chat SDK
    // background thread may resize them. Use callbacks, or connect without background mode.
    if(g_chat_background_thread) return {};
    if(!chat_has_client()) return {};
    const Chat::Channel* ch = chat_get_channel(channel_type, channel_name);
    if(!ch) return {};
    const auto& msgs = ch->getMessages();
    if(index < 0 || static_cast<unsigned>(index) >= msgs.getSize()) return {};
    return chat_object_to_string(msgs[static_cast<unsigned>(index)]);
}

std::string photon_chat_get_channel_sender(gm_enums::PhotonChatChannelType channel_type, std::string_view channel_name, std::int32_t index)
{
    // SDK-owned channel containers are not safe to inspect while the Chat SDK
    // background thread may resize them. Use callbacks, or connect without background mode.
    if(g_chat_background_thread) return {};
    if(!chat_has_client()) return {};
    const Chat::Channel* ch = chat_get_channel(channel_type, channel_name);
    if(!ch) return {};
    const auto& senders = ch->getSenders();
    if(index < 0 || static_cast<unsigned>(index) >= senders.getSize()) return {};
    return chat_from_jstring(senders[static_cast<unsigned>(index)]);
}

// =============================================================================
// Callback registration
// =============================================================================

bool photon_chat_set_callback_debug(const gm::wire::GMFunction& callback)             { g_chat_callback_debug             = callback; return true; }
bool photon_chat_set_callback_connected(const gm::wire::GMFunction& callback)           { g_chat_callback_connected           = callback; return true; }
bool photon_chat_set_callback_state_change(const gm::wire::GMFunction& callback)      { g_chat_callback_state_change      = callback; return true; }
bool photon_chat_set_callback_connection_error(const gm::wire::GMFunction& callback)  { g_chat_callback_connection_error  = callback; return true; }
bool photon_chat_set_callback_client_error(const gm::wire::GMFunction& callback)      { g_chat_callback_client_error      = callback; return true; }
bool photon_chat_set_callback_warning(const gm::wire::GMFunction& callback)           { g_chat_callback_warning           = callback; return true; }
bool photon_chat_set_callback_server_error(const gm::wire::GMFunction& callback)      { g_chat_callback_server_error      = callback; return true; }
bool photon_chat_set_callback_disconnected(const gm::wire::GMFunction& callback)        { g_chat_callback_disconnected        = callback; return true; }
bool photon_chat_set_callback_status_update(const gm::wire::GMFunction& callback)     { g_chat_callback_status_update     = callback; return true; }
bool photon_chat_set_callback_get_messages(const gm::wire::GMFunction& callback)      { g_chat_callback_get_messages      = callback; return true; }
bool photon_chat_set_callback_private_message(const gm::wire::GMFunction& callback)   { g_chat_callback_private_message   = callback; return true; }
bool photon_chat_set_callback_receive_broadcast(const gm::wire::GMFunction& callback) { g_chat_callback_receive_broadcast = callback; return true; }

// =============================================================================
// Callback removal
// =============================================================================

bool photon_chat_remove_callback_debug()             { g_chat_callback_debug             = nullptr; return true; }
bool photon_chat_remove_callback_connected()           { g_chat_callback_connected           = nullptr; return true; }
bool photon_chat_remove_callback_state_change()      { g_chat_callback_state_change      = nullptr; return true; }
bool photon_chat_remove_callback_connection_error()  { g_chat_callback_connection_error  = nullptr; return true; }
bool photon_chat_remove_callback_client_error()      { g_chat_callback_client_error      = nullptr; return true; }
bool photon_chat_remove_callback_warning()           { g_chat_callback_warning           = nullptr; return true; }
bool photon_chat_remove_callback_server_error()      { g_chat_callback_server_error      = nullptr; return true; }
bool photon_chat_remove_callback_disconnected()        { g_chat_callback_disconnected        = nullptr; return true; }
bool photon_chat_remove_callback_status_update()     { g_chat_callback_status_update     = nullptr; return true; }
bool photon_chat_remove_callback_get_messages()      { g_chat_callback_get_messages      = nullptr; return true; }
bool photon_chat_remove_callback_private_message()   { g_chat_callback_private_message   = nullptr; return true; }
bool photon_chat_remove_callback_receive_broadcast() { g_chat_callback_receive_broadcast = nullptr; return true; }

// =============================================================================
// Internal accessor (used by peer/common modules)
// =============================================================================

Chat::Client* photon_chat_internal_get_client()
{
    return g_chat_client.get();
}
