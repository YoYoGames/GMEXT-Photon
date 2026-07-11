#include "GMPhoton_native.h"

#include <LoadBalancing-cpp/inc/Client.h>
#include <LoadBalancing-cpp/inc/Listener.h>
#include <LoadBalancing-cpp/inc/ConnectOptions.h>
#include <LoadBalancing-cpp/inc/ClientConstructOptions.h>
#include <LoadBalancing-cpp/inc/Enums/RegionSelectionMode.h>
#include <LoadBalancing-cpp/inc/AuthenticationValues.h>
#include <LoadBalancing-cpp/inc/RoomOptions.h>
#include <LoadBalancing-cpp/inc/RaiseEventOptions.h>
#include <LoadBalancing-cpp/inc/LobbyStatsResponse.h>
#include <LoadBalancing-cpp/inc/Player.h>
#include <LoadBalancing-cpp/inc/Room.h>
#include <LoadBalancing-cpp/inc/MutablePlayer.h>
#include <LoadBalancing-cpp/inc/MutableRoom.h>

#include <Photon-cpp/inc/OperationResponse.h>

#include <Common-cpp/inc/JString.h>
#include <Common-cpp/inc/ANSIString.h>
#include <Common-cpp/inc/Object.h>
#include <Common-cpp/inc/Common.h>
#include <Common-cpp/inc/ValueObject.h>
#include <Common-cpp/inc/Containers/JVector.h>
#include <Common-cpp/inc/Containers/Hashtable.h>
#include <Common-cpp/inc/Containers/Dictionary.h>
#include <Common-cpp/inc/Helpers/SmartPointers/SharedPointer.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <codecvt>
#include <locale>

using namespace gm_structs;
using namespace gm_enums;

namespace EG = ExitGames;
namespace C  = ExitGames::Common;
namespace LB = ExitGames::LoadBalancing;
namespace P  = ExitGames::Photon;

// Voice bridge — defined in GM_Photon_voice_new.cpp
extern void photon_voice_internal_on_join_room();
extern void photon_voice_internal_on_leave_room();
extern void photon_voice_internal_on_player_join(int playerNr);
extern void photon_voice_internal_on_player_leave(int playerNr);
extern bool photon_voice_internal_on_custom_event(int playerNr, nByte eventCode, const C::Object& eventContent);
extern void photon_voice_internal_on_direct_message(const C::Object& msg, int remoteID, bool relay);

// =============================================================================
// Global state
// =============================================================================

static std::unique_ptr<LB::Client> g_photon_client;
static bool g_photon_initialized = false;
static bool g_photon_connected   = false;


static std::string g_current_region;
static std::string g_current_room_name;
static int g_local_player_number = 0;

// A region requested via photon_realtime_select_region() before/while connecting.
// The SDK only honors selectRegion() when the Client was constructed with
// RegionSelectionMode::SELECT, and only once it pauses the connect flow to call
// onAvailableRegions(). Recording the desired region here lets rebuild_client()
// opt into SELECT mode and lets onAvailableRegions() apply it automatically,
// so callers can keep calling select_region() before connect() as before.
static std::string g_pending_selected_region;
static bool        g_has_pending_selected_region      = false;
static bool        g_region_selected_since_available  = false;

// =============================================================================
// Buffered incoming event queue
// =============================================================================

struct PhotonQueuedBufferEvent
{
    int player_number  = -1;
    int event_code = -1;
    std::vector<nByte> payload;
};

static std::deque<PhotonQueuedBufferEvent> g_buffer_event_queue;
static constexpr std::size_t kMaxBufferEventQueueSize = 256;

// =============================================================================
// Callback registry
// =============================================================================

static gm::wire::GMFunction g_callback_debug                          = nullptr;
static gm::wire::GMFunction g_callback_connected                      = nullptr;
static gm::wire::GMFunction g_callback_disconnected                   = nullptr;
static gm::wire::GMFunction g_callback_connection_error               = nullptr;
static gm::wire::GMFunction g_callback_client_error                   = nullptr;
static gm::wire::GMFunction g_callback_server_error                   = nullptr;
static gm::wire::GMFunction g_callback_warning                        = nullptr;
static gm::wire::GMFunction g_callback_create_room_return             = nullptr;
static gm::wire::GMFunction g_callback_join_or_create_room_return     = nullptr;
static gm::wire::GMFunction g_callback_join_random_or_create_room_return = nullptr;
static gm::wire::GMFunction g_callback_join_room_return               = nullptr;
static gm::wire::GMFunction g_callback_join_random_room_return        = nullptr;
static gm::wire::GMFunction g_callback_leave_room_return              = nullptr;
static gm::wire::GMFunction g_callback_join_lobby_return              = nullptr;
static gm::wire::GMFunction g_callback_leave_lobby_return             = nullptr;
static gm::wire::GMFunction g_callback_join_room_event                = nullptr;
static gm::wire::GMFunction g_callback_leave_room_event               = nullptr;
static gm::wire::GMFunction g_callback_custom_event                   = nullptr;
static gm::wire::GMFunction g_callback_room_properties_change         = nullptr;
static gm::wire::GMFunction g_callback_player_properties_change       = nullptr;
static gm::wire::GMFunction g_callback_room_list_update               = nullptr;
static gm::wire::GMFunction g_callback_find_friends_response          = nullptr;
static gm::wire::GMFunction g_callback_lobby_stats_response           = nullptr;
static gm::wire::GMFunction g_callback_web_rpc_return                 = nullptr;
static gm::wire::GMFunction g_callback_app_stats_update               = nullptr;
static gm::wire::GMFunction g_callback_lobby_stats_update             = nullptr;
static gm::wire::GMFunction g_callback_cache_slice_changed            = nullptr;
static gm::wire::GMFunction g_callback_master_client_changed          = nullptr;
static gm::wire::GMFunction g_callback_properties_change_failed       = nullptr;
static gm::wire::GMFunction g_callback_custom_authentication_step     = nullptr;
static gm::wire::GMFunction g_callback_available_regions              = nullptr;
static gm::wire::GMFunction g_callback_secret_receival                = nullptr;
static gm::wire::GMFunction g_callback_direct_connection_established  = nullptr;
static gm::wire::GMFunction g_callback_direct_connection_failed       = nullptr;
static gm::wire::GMFunction g_callback_direct_message                 = nullptr;
static gm::wire::GMFunction g_callback_custom_operation_response      = nullptr;
static gm::wire::GMFunction g_callback_get_room_list_response         = nullptr;

// =============================================================================
// Helpers
// =============================================================================

// Manual UTF-8 <-> wchar_t conversion helpers.
//
// std::codecvt_utf8<wchar_t> (as opposed to codecvt_utf8_utf16<wchar_t>) is specified to
// treat wchar_t as a single UCS-2/UCS-4 code unit and never generates or interprets UTF-16
// surrogate pairs. On Windows wchar_t is 16-bit UTF-16, so it cannot represent any codepoint
// above U+FFFF (most emoji, many rare CJK characters): decoding such UTF-8 throws (falling
// back to a lossy ANSI/Latin-1 JString construction — the exact bug this conversion exists to
// avoid), and encoding a genuine UTF-16 surrogate pair mis-emits each half as its own invalid
// UTF-8 sequence instead of combining them. These helpers handle surrogate pairs explicitly
// and work correctly regardless of wchar_t's width.

static void photon_realtime_append_utf8_codepoint(std::string& out, std::uint32_t cp)
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

static std::wstring photon_realtime_utf8_to_wstring(const std::string& s)
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

static inline C::JString photon_realtime_to_jstring(const std::string& s)
{
    if(s.empty())
        return C::JString();

    const std::wstring ws = photon_realtime_utf8_to_wstring(s);
    return C::JString(ws.c_str());
}

static inline std::string photon_realtime_from_jstring(const C::JString& s)
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
                photon_realtime_append_utf8_codepoint(out, cp);
                ++p;
                continue;
            }
            photon_realtime_append_utf8_codepoint(out, 0xFFFD);
            continue;
        }
        if(cu >= 0xDC00 && cu <= 0xDFFF)
        {
            photon_realtime_append_utf8_codepoint(out, 0xFFFD);
            continue;
        }

        photon_realtime_append_utf8_codepoint(out, cu);
    }
    return out;
}

static inline nByte photon_realtime_to_nbyte(double v)
{
    if(!std::isfinite(v))
        return static_cast<nByte>(0);

    double clamped = std::clamp(v, 0.0, 255.0);
    return static_cast<nByte>(clamped);
}

static inline int photon_realtime_success_error_code()
{
    return 0;
}

static inline bool photon_realtime_has_client()
{
    return g_photon_initialized && static_cast<bool>(g_photon_client);
}

static inline bool photon_realtime_state_looks_connected(int state)
{
    switch(state)
    {
        case 3:  // ConnectedToNameserver
        case 5:  // Connecting
        case 6:  // Connected
        case 7:  // WaitingForCustomAuthNextStep
        case 8:  // Authenticated
        case 9:  // JoinedLobby
        case 11: // ConnectingToGameserver
        case 12: // ConnectedToGameserver
        case 13: // AuthenticatedOnGameServer
        case 14: // Joining
        case 15: // Joined
        case 19: // ConnectingToMasterserver
        case 20: // ConnectedComingFromGameserver
        case 21: // AuthenticatedComingFromGameserver
            return true;
        default:
            return false;
    }
}

static inline gm_enums::PhotonRealtimeState photon_realtime_state_from_sdk(int state)
{
    namespace PS = ExitGames::LoadBalancing::PeerStates;

    switch(state)
    {
        case PS::Uninitialized:                              return gm_enums::PhotonRealtimeState::Uninitialized;
        case PS::PeerCreated:                                return gm_enums::PhotonRealtimeState::PeerCreated;
        case PS::ConnectingToNameserver:                     return gm_enums::PhotonRealtimeState::ConnectingToNameserver;
        case PS::ConnectedToNameserver:                      return gm_enums::PhotonRealtimeState::ConnectedToNameserver;
        case PS::DisconnectingFromNameserver:                return gm_enums::PhotonRealtimeState::DisconnectingFromNameserver;
        case PS::Connecting:                                 return gm_enums::PhotonRealtimeState::Connecting;
        case PS::Connected:                                  return gm_enums::PhotonRealtimeState::Connected;
        case PS::WaitingForCustomAuthenticationNextStepCall: return gm_enums::PhotonRealtimeState::WaitingForCustomAuthNextStep;
        case PS::Authenticated:                              return gm_enums::PhotonRealtimeState::Authenticated;
        case PS::JoinedLobby:                                return gm_enums::PhotonRealtimeState::JoinedLobby;
        case PS::DisconnectingFromMasterserver:              return gm_enums::PhotonRealtimeState::DisconnectingFromMasterserver;
        case PS::ConnectingToGameserver:                     return gm_enums::PhotonRealtimeState::ConnectingToGameserver;
        case PS::ConnectedToGameserver:                      return gm_enums::PhotonRealtimeState::ConnectedToGameserver;
        case PS::AuthenticatedOnGameServer:                  return gm_enums::PhotonRealtimeState::AuthenticatedOnGameServer;
        case PS::Joining:                                    return gm_enums::PhotonRealtimeState::Joining;
        case PS::Joined:                                     return gm_enums::PhotonRealtimeState::Joined;
        case PS::Leaving:                                    return gm_enums::PhotonRealtimeState::Leaving;
        case PS::Left:                                       return gm_enums::PhotonRealtimeState::Left;
        case PS::DisconnectingFromGameserver:                return gm_enums::PhotonRealtimeState::DisconnectingFromGameserver;
        case PS::ConnectingToMasterserver:                   return gm_enums::PhotonRealtimeState::ConnectingToMasterserver;
        case PS::ConnectedComingFromGameserver:              return gm_enums::PhotonRealtimeState::ConnectedComingFromGameserver;
        case PS::AuthenticatedComingFromGameserver:          return gm_enums::PhotonRealtimeState::AuthenticatedComingFromGameserver;
        case PS::Disconnecting:                              return gm_enums::PhotonRealtimeState::Disconnecting;
        case PS::Disconnected:                               return gm_enums::PhotonRealtimeState::Disconnected;
        default: return gm_enums::PhotonRealtimeState::Unknown;
    }
}

static inline gm_enums::PhotonRealtimeDisconnectCause photon_realtime_disconnect_cause_from_sdk(int cause)
{
    namespace DC = ExitGames::LoadBalancing::DisconnectCause;

    switch(cause)
    {
        case DC::NONE:                                   return gm_enums::PhotonRealtimeDisconnectCause::None;
        case DC::DISCONNECT_BY_SERVER_USER_LIMIT:        return gm_enums::PhotonRealtimeDisconnectCause::ServerUserLimit;
        case DC::EXCEPTION_ON_CONNECT:                   return gm_enums::PhotonRealtimeDisconnectCause::ExceptionOnConnect;
        case DC::DISCONNECT_BY_SERVER:                   return gm_enums::PhotonRealtimeDisconnectCause::DisconnectByServer;
        case DC::DISCONNECT_BY_SERVER_LOGIC:             return gm_enums::PhotonRealtimeDisconnectCause::DisconnectByServerLogic;
        case DC::TIMEOUT_DISCONNECT:                     return gm_enums::PhotonRealtimeDisconnectCause::TimeoutDisconnect;
        case DC::EXCEPTION:                              return gm_enums::PhotonRealtimeDisconnectCause::Exception;
        case DC::INVALID_AUTHENTICATION:                 return gm_enums::PhotonRealtimeDisconnectCause::InvalidAuthentication;
        case DC::MAX_CCU_REACHED:                        return gm_enums::PhotonRealtimeDisconnectCause::MaxCcuReached;
        case DC::INVALID_REGION:                         return gm_enums::PhotonRealtimeDisconnectCause::InvalidRegion;
        case DC::OPERATION_NOT_ALLOWED_IN_CURRENT_STATE: return gm_enums::PhotonRealtimeDisconnectCause::OperationNotAllowed;
        case DC::CUSTOM_AUTHENTICATION_FAILED:           return gm_enums::PhotonRealtimeDisconnectCause::CustomAuthenticationFailed;
        case DC::CLIENT_VERSION_TOO_OLD:                 return gm_enums::PhotonRealtimeDisconnectCause::ClientVersionTooOld;
        case DC::CLIENT_VERSION_INVALID:                 return gm_enums::PhotonRealtimeDisconnectCause::ClientVersionInvalid;
        case DC::DASHBOARD_VERSION_INVALID:              return gm_enums::PhotonRealtimeDisconnectCause::DashboardVersionInvalid;
        case DC::AUTHENTICATION_TICKET_EXPIRED:          return gm_enums::PhotonRealtimeDisconnectCause::AuthenticationTicketExpired;
        case DC::DISCONNECT_BY_OPERATION_LIMIT:          return gm_enums::PhotonRealtimeDisconnectCause::OperationLimit;
        default: return gm_enums::PhotonRealtimeDisconnectCause::Unknown;
    }
}

static inline bool photon_realtime_can_raise_event()
{
    return photon_realtime_has_client() && g_photon_client->getIsInGameRoom();
}

static inline std::string photon_realtime_object_to_string(const C::Object& obj)
{
    if(obj.getType() == C::TypeCode::STRING)
    {
        C::ValueObject<C::JString> vo(obj);
        const C::JString* p = vo.getDataAddress();
        return p ? photon_realtime_from_jstring(*p) : std::string{};
    }
    return photon_realtime_from_jstring(obj.toString(false));
}

static inline std::string photon_realtime_hashtable_to_string(const C::Hashtable& ht)
{
    return photon_realtime_from_jstring(ht.toString(false));
}

// -----------------------------------------------------------------------------
// Object -> wire (StructStream / ArrayStream) marshalling.
//
// StructStream and ArrayStream are both CollectionStreams over the same DataStream
// serializer; the only difference is that a struct writes a key before each value.
// So a single type dispatch (photon_realtime_emit_object) feeds both, parameterised
// by an "emit" sink. Photon erases an Object's element type at runtime, so a
// type-code switch is unavoidable — but there is exactly one for scalars and one
// for array elements, not one per stream kind.
//
// Scalars keep their native type; nested Hashtables become nested structs;
// single-dimension arrays become nested arrays (recursing for arrays of objects or
// hashtables). Anything not representable (generic Dictionary, multi-dimension
// arrays, custom types) falls back to its SDK toString() form.
// -----------------------------------------------------------------------------
static void photon_realtime_fill_hashtable_to_struct_stream(const C::Hashtable& ht, gm::wire::StructStream& ss);
static void photon_realtime_fill_array_stream(const C::Object& value, gm::wire::ArrayStream& as);
static void photon_realtime_add_object_to_array_stream(gm::wire::ArrayStream& as, const C::Object& value);

// Reads a single-dimension Photon array<T> and pushes each element through proj().
template<typename T, typename Proj>
static void photon_realtime_push_scalar_array(const C::Object& value, gm::wire::ArrayStream& as, Proj proj)
{
    C::ValueObject<T*> vo(value);
    T* const* pp = vo.getDataAddress();
    const int* sz = vo.getSizes();
    if(pp && *pp && sz)
        for(int i = 0; i < sz[0]; ++i)
            as.push(proj((*pp)[i]));
}

// Single scalar dispatch for one Photon Object, writing into any sink. `emit` takes
// one GML-ready value (a scalar, a std::string, or a nested Struct/ArrayStream).
template<typename Emit>
static void photon_realtime_emit_object(const C::Object& value, Emit&& emit)
{
    // Arrays share their element's type code and are told apart only by the
    // dimension count, so that must be checked before the scalar switch.
    if(value.getDimensions() >= 1)
    {
        gm::wire::ArrayStream child;
        photon_realtime_fill_array_stream(value, child);
        emit(child);
        return;
    }

    switch(value.getType())
    {
        case C::TypeCode::STRING:  { C::ValueObject<C::JString> vo(value); const C::JString* p = vo.getDataAddress(); emit(p ? photon_realtime_from_jstring(*p) : std::string{}); break; }
        case C::TypeCode::BOOLEAN: { C::ValueObject<bool> vo(value);       const bool* p  = vo.getDataAddress();      emit(p ? *p : false); break; }
        case C::TypeCode::BYTE:    { C::ValueObject<nByte> vo(value);      const nByte* p = vo.getDataAddress();      emit(static_cast<std::int32_t>(p ? *p : 0)); break; }
        case C::TypeCode::SHORT:   { C::ValueObject<short> vo(value);      const short* p = vo.getDataAddress();      emit(static_cast<std::int32_t>(p ? *p : 0)); break; }
        case C::TypeCode::INTEGER: { C::ValueObject<int> vo(value);        const int* p   = vo.getDataAddress();      emit(static_cast<std::int32_t>(p ? *p : 0)); break; }
        // GML has no 64-bit integer type; forward LONG as a real (double).
        case C::TypeCode::LONG:    { C::ValueObject<long long> vo(value);  const long long* p = vo.getDataAddress();  emit(p ? static_cast<double>(*p) : 0.0); break; }
        case C::TypeCode::FLOAT:   { C::ValueObject<float> vo(value);      const float* p = vo.getDataAddress();      emit(p ? *p : 0.0f); break; }
        case C::TypeCode::DOUBLE:  { C::ValueObject<double> vo(value);     const double* p = vo.getDataAddress();     emit(p ? *p : 0.0); break; }
        case C::TypeCode::HASHTABLE:
        {
            C::ValueObject<C::Hashtable> vo(value); const C::Hashtable* p = vo.getDataAddress();
            gm::wire::StructStream child;
            if(p) photon_realtime_fill_hashtable_to_struct_stream(*p, child);
            emit(child);
            break;
        }
        default: // generic Dictionary, custom types, null, etc.
            emit(photon_realtime_from_jstring(value.toString(false)));
            break;
    }
}

static void photon_realtime_add_object_to_struct_stream(gm::wire::StructStream& ss, const std::string& key, const C::Object& value)
{
    photon_realtime_emit_object(value, [&](const auto& v){ ss.add(key.c_str(), v); });
}

static void photon_realtime_add_object_to_array_stream(gm::wire::ArrayStream& as, const C::Object& value)
{
    photon_realtime_emit_object(value, [&](const auto& v){ as.push(v); });
}

// Populate a StructStream from a Photon Hashtable, one key-value pair per entry.
static void photon_realtime_fill_hashtable_to_struct_stream(const C::Hashtable& ht, gm::wire::StructStream& ss)
{
    const C::JVector<C::Object>& keys = ht.getKeys();
    for(unsigned int i = 0; i < keys.getSize(); ++i)
    {
        const C::Object& keyObj = keys[i];
        const C::Object* valObj = ht.getValue(keyObj);
        if(!valObj) continue;
        photon_realtime_add_object_to_struct_stream(ss, photon_realtime_object_to_string(keyObj), *valObj);
    }
}

// Fills a Photon Hashtable from a GML object (GMObjectView).
// Handles string, bool, int32, float, and double values from GML.
static void photon_realtime_fill_gm_object_to_hashtable(const gm::wire::GMObjectView& obj, C::Hashtable& ht)
{
    for (const auto& entry : obj)
    {
        std::string key(entry.first);
        const auto& val = entry.second;
        const auto kind = val.kind();
        if (kind == gm::wire::GMKind::String || kind == gm::wire::GMKind::Text)
        {
            ht.put(photon_realtime_to_jstring(key), photon_realtime_to_jstring(std::string(val.as<std::string_view>())));
        }
        else if (kind == gm::wire::GMKind::Bool)
        {
            ht.put(photon_realtime_to_jstring(key), val.as<bool>());
        }
        else if (kind == gm::wire::GMKind::Int32)
        {
            ht.put(photon_realtime_to_jstring(key), static_cast<int>(val.as<std::int32_t>()));
        }
        else if (kind == gm::wire::GMKind::Float)
        {
            ht.put(photon_realtime_to_jstring(key), val.as<float>());
        }
        else if (kind == gm::wire::GMKind::Double)
        {
            ht.put(photon_realtime_to_jstring(key), val.as<double>());
        }
        // Other types (arrays, structs, etc.) are silently skipped.
    }
}

// Expands a single-dimension Photon array into an ArrayStream, element by element.
// Multi-dimension arrays and unreadable data fall back to a string form.
static void photon_realtime_fill_array_stream(const C::Object& value, gm::wire::ArrayStream& as)
{
    if(value.getDimensions() != 1)
    {
        as.push(photon_realtime_from_jstring(value.toString(false)));
        return;
    }

    switch(value.getType())
    {
        case C::TypeCode::BYTE:    photon_realtime_push_scalar_array<nByte>    (value, as, [](nByte v)     { return static_cast<std::int32_t>(v); }); break;
        case C::TypeCode::SHORT:   photon_realtime_push_scalar_array<short>    (value, as, [](short v)     { return static_cast<std::int32_t>(v); }); break;
        case C::TypeCode::INTEGER: photon_realtime_push_scalar_array<int>      (value, as, [](int v)       { return static_cast<std::int32_t>(v); }); break;
        case C::TypeCode::LONG:    photon_realtime_push_scalar_array<long long>(value, as, [](long long v) { return static_cast<double>(v); }); break;
        case C::TypeCode::FLOAT:   photon_realtime_push_scalar_array<float>    (value, as, [](float v)     { return v; }); break;
        case C::TypeCode::DOUBLE:  photon_realtime_push_scalar_array<double>   (value, as, [](double v)    { return v; }); break;
        case C::TypeCode::BOOLEAN: photon_realtime_push_scalar_array<bool>     (value, as, [](bool v)      { return v; }); break;
        case C::TypeCode::STRING:  photon_realtime_push_scalar_array<C::JString>(value, as, [](const C::JString& v){ return photon_realtime_from_jstring(v); }); break;
        case C::TypeCode::HASHTABLE:
        {
            C::ValueObject<C::Hashtable*> vo(value); C::Hashtable* const* pp = vo.getDataAddress(); const int* sz = vo.getSizes();
            if(pp && *pp && sz) for(int i = 0; i < sz[0]; ++i)
            {
                gm::wire::StructStream child;
                photon_realtime_fill_hashtable_to_struct_stream((*pp)[i], child);
                as.push(child);
            }
            break;
        }
        case C::TypeCode::OBJECT:
        {
            C::ValueObject<C::Object*> vo(value); C::Object* const* pp = vo.getDataAddress(); const int* sz = vo.getSizes();
            if(pp && *pp && sz) for(int i = 0; i < sz[0]; ++i) photon_realtime_add_object_to_array_stream(as, (*pp)[i]);
            break;
        }
        default:
            as.push(photon_realtime_from_jstring(value.toString(false)));
            break;
    }
}

static void photon_realtime_fill_object_dictionary_to_struct_stream(
    const C::Dictionary<C::Object, C::Object>& dict,
    gm::wire::StructStream& ss)
{
    const C::JVector<C::Object>& keys = dict.getKeys();
    for(unsigned int i = 0; i < keys.getSize(); ++i)
    {
        const C::Object& key_obj = keys[i];
        const C::Object* value = dict.getValue(key_obj);
        if(!value) continue;
        photon_realtime_add_object_to_struct_stream(
            ss, photon_realtime_object_to_string(key_obj), *value);
    }
}

static void photon_realtime_fill_string_dictionary_to_struct_stream(
    const C::Dictionary<C::JString, C::Object>& dict,
    gm::wire::StructStream& ss)
{
    const C::JVector<C::JString>& keys = dict.getKeys();
    for(unsigned int i = 0; i < keys.getSize(); ++i)
    {
        const C::Object* value = dict.getValue(keys[i]);
        if(!value) continue;
        photon_realtime_add_object_to_struct_stream(
            ss, photon_realtime_from_jstring(keys[i]), *value);
    }
}

static void photon_realtime_fill_byte_dictionary_to_struct_stream(
    const C::Dictionary<nByte, C::Object>& dict,
    gm::wire::StructStream& ss)
{
    const C::JVector<nByte>& keys = dict.getKeys();
    for(unsigned int i = 0; i < keys.getSize(); ++i)
    {
        const C::Object* value = dict.getValue(keys[i]);
        if(!value) continue;
        photon_realtime_add_object_to_struct_stream(
            ss, std::to_string(static_cast<unsigned int>(keys[i])), *value);
    }
}

static void photon_realtime_reset_room_state()
{
    g_current_room_name.clear();
    g_local_player_number = 0;
}

static void photon_realtime_reset_connection_state()
{
    g_photon_connected = false;
    g_current_region.clear();
    photon_realtime_reset_room_state();
}

static bool photon_realtime_rebuild_client(const std::string& app_id, const std::string& app_version)
{
    g_photon_client.reset();

    extern LB::Listener& photon_get_listener_instance();

    LB::ClientConstructOptions ctorOpts;
    if(g_has_pending_selected_region)
        ctorOpts.setRegionSelectionMode(LB::RegionSelectionMode::SELECT);

    g_photon_client = std::make_unique<LB::Client>(
        photon_get_listener_instance(),
        photon_realtime_to_jstring(app_id),
        photon_realtime_to_jstring(app_version),
        ctorOpts
    );

    g_region_selected_since_available = false;
    g_photon_client->setAutoJoinLobby(false);
    return true;
}

static inline bool photon_realtime_try_extract_byte_array(const C::Object& eventContent, std::vector<nByte>& out_bytes)
{
    C::ValueObject<nByte*> value(eventContent);

    nByte* const* ppData = value.getDataAddress();
    const int* pSizes = value.getSizes();

    if(!ppData || !(*ppData) || !pSizes)
        return false;

    if(eventContent.getDimensions() != 1)
        return false;

    const int count = pSizes[0];
    if(count <= 0)
        return false;

    out_bytes.assign(*ppData, *ppData + count);
    return true;
}

// =============================================================================
// RaiseEvent options builders
// =============================================================================

static LB::RaiseEventOptions photon_realtime_make_raise_event_options(const gm_structs::PhotonRealtimeRaiseEventOptions& opts)
{
    LB::RaiseEventOptions options;
    if(opts.receiver_group)   options.setReceiverGroup(static_cast<nByte>(*opts.receiver_group));
    if(opts.interest_group)   options.setInterestGroup(static_cast<nByte>(*opts.interest_group));
    if(opts.event_cache)      options.setEventCaching(static_cast<nByte>(*opts.event_cache));
    if(opts.channel_id)       options.setChannelID(static_cast<nByte>(*opts.channel_id));
    if(opts.cache_slice_index && *opts.cache_slice_index >= 0)
        options.setCacheSliceIndex(*opts.cache_slice_index);
    if(opts.encrypt)          options.setEncrypt(*opts.encrypt);
    if(!opts.target_players.empty())
        options.setTargetPlayers(reinterpret_cast<const int*>(opts.target_players.data()),
                                 static_cast<short>(opts.target_players.size()));
    return options;
}

// =============================================================================
// Properties accessors
// =============================================================================

static inline LB::MutableRoom* photon_realtime_room_ref()
{
    if(!photon_realtime_has_client() || !g_photon_client->getIsInGameRoom())
        return nullptr;
    return &g_photon_client->getCurrentlyJoinedRoom();
}

static inline LB::MutablePlayer* photon_realtime_local_player_ref()
{
    if(!photon_realtime_has_client() || !g_photon_client->getIsInGameRoom())
        return nullptr;
    return &g_photon_client->getLocalPlayer();
}

static inline const LB::Player* photon_realtime_remote_player_ptr(int player_number)
{
    if(!photon_realtime_has_client() || !g_photon_client->getIsInGameRoom())
        return nullptr;
    return g_photon_client->getCurrentlyJoinedRoom().getPlayerForNumber(player_number);
}

static inline bool photon_realtime_hashtable_has_key(const C::Hashtable& ht, const std::string& key)
{
    return ht.contains(photon_realtime_to_jstring(key));
}

static inline const C::Object* photon_realtime_hashtable_get_object(const C::Hashtable& ht, const std::string& key)
{
    return ht.getValue(photon_realtime_to_jstring(key));
}

static inline std::string photon_realtime_object_as_string_or_default(const C::Object* obj, const std::string& fallback = "")
{
    if(!obj) return fallback;
    C::ValueObject<C::JString> v(*obj);
    const C::JString* p = v.getDataAddress();
    if(!p) return fallback;
    return photon_realtime_from_jstring(*p);
}

static inline std::int32_t photon_realtime_object_as_i32_or_default(const C::Object* obj, std::int32_t fallback = 0)
{
    if(!obj) return fallback;
    C::ValueObject<int> v(*obj);
    const int* p = v.getDataAddress();
    if(!p) return fallback;
    return static_cast<std::int32_t>(*p);
}

static inline double photon_realtime_object_as_f64_or_default(const C::Object* obj, double fallback = 0.0)
{
    if(!obj) return fallback;
    C::ValueObject<double> v(*obj);
    const double* p = v.getDataAddress();
    if(!p) return fallback;
    return *p;
}

static inline bool photon_realtime_object_as_bool_or_default(const C::Object* obj, bool fallback = false)
{
    if(!obj) return fallback;
    C::ValueObject<bool> v(*obj);
    const bool* p = v.getDataAddress();
    if(!p) return fallback;
    return *p;
}

// =============================================================================
// Listener
// =============================================================================

class GMPhotonListener final : public LB::Listener
{
public:
    // ---- Debug / Errors -------------------------------------------------
    void debugReturn(int debugLevel, const C::JString& string) override
    {
        if(g_callback_debug)
            g_callback_debug.call(debugLevel, photon_realtime_from_jstring(string));
    }

    void connectionErrorReturn(int errorCode) override
    {
        g_photon_connected = false;
        if(g_callback_connection_error)
            g_callback_connection_error.call(errorCode);
    }

    void clientErrorReturn(int errorCode) override
    {
        if(g_callback_client_error)
            g_callback_client_error.call(errorCode);
    }

    void warningReturn(int warningCode) override
    {
        if(g_callback_warning)
            g_callback_warning.call(warningCode);
    }

    void serverErrorReturn(int errorCode) override
    {
        if(g_callback_server_error)
            g_callback_server_error.call(errorCode);
    }

    // ---- Room events ----------------------------------------------------
    void joinRoomEventAction(int playerNr, const C::JVector<int>& playernrs, const LB::Player& player) override
    {
        (void)playernrs;
        photon_voice_internal_on_player_join(playerNr);

        if(g_callback_join_room_event)
        {
            g_callback_join_room_event.call(
                playerNr,
                player.getNumber(),
                photon_realtime_from_jstring(player.getName()),
                photon_realtime_from_jstring(player.getUserID()),
                player.getIsInactive(),
                player.getIsMasterClient()
            );
        }
    }

    void leaveRoomEventAction(int playerNr, bool isInactive) override
    {
        photon_voice_internal_on_player_leave(playerNr);

        if(g_callback_leave_room_event)
            g_callback_leave_room_event.call(playerNr, isInactive);
    }

    void customEventAction(int playerNr, nByte eventCode, const C::Object& eventContent) override
    {
        // Voice transport handles event codes 202 (VOICE_DATA) and 203 (VOICE_FRAME_DATA).
        // If consumed, skip regular event processing so voice packets don't appear twice.
        if(photon_voice_internal_on_custom_event(playerNr, eventCode, eventContent))
            return;

        std::vector<nByte> bytes;
        if(photon_realtime_try_extract_byte_array(eventContent, bytes))
        {
            PhotonQueuedBufferEvent ev{};
            ev.player_number = playerNr;
            ev.event_code    = static_cast<int>(eventCode);
            ev.payload       = std::move(bytes);
            if(g_buffer_event_queue.size() >= kMaxBufferEventQueueSize)
                g_buffer_event_queue.pop_front();
            g_buffer_event_queue.push_back(std::move(ev));
            // Notify GML that a binary event was queued. The fourth argument tells the
            // callback to fetch the bytes with photon_realtime_receive_one_buffer_event().
            if(g_callback_custom_event)
                g_callback_custom_event.call(
                    playerNr,
                    static_cast<int>(eventCode),
                    std::string{},
                    true
                );
            return;
        }

        if(g_callback_custom_event)
        {
            g_callback_custom_event.call(
                playerNr,
                static_cast<int>(eventCode),
                photon_realtime_object_to_string(eventContent),
                false
            );
        }
    }

    // ---- Connection -----------------------------------------------------
    void connectReturn(int errorCode, const C::JString& errorString, const C::JString& region, const C::JString& cluster) override
    {
        (void)cluster;
        g_photon_connected = (errorCode == photon_realtime_success_error_code());
        std::string region_upper = photon_realtime_from_jstring(region);
        for(auto& c : region_upper) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        if(g_photon_connected)
            g_current_region = region_upper;

        if(g_callback_connected)
        {
            g_callback_connected.call(
                errorCode,
                photon_realtime_from_jstring(errorString),
                region_upper
            );
        }
    }

    void disconnectReturn(void) override
    {
        photon_voice_internal_on_leave_room();
        photon_realtime_reset_connection_state();

        if(g_callback_disconnected)
            g_callback_disconnected.call();
    }

    // ---- Room operations ------------------------------------------------
    void createRoomReturn(int localPlayerNr, const C::Hashtable& gameProperties, const C::Hashtable& playerProperties, int errorCode, const C::JString& errorString) override
    {
        (void)gameProperties;
        (void)playerProperties;

        if(errorCode == photon_realtime_success_error_code() && photon_realtime_has_client() && g_photon_client->getIsInGameRoom())
        {
            photon_voice_internal_on_join_room();
            g_current_room_name  = photon_realtime_from_jstring(g_photon_client->getCurrentlyJoinedRoom().getName());
            g_local_player_number = g_photon_client->getLocalPlayer().getNumber();
        }

        if(g_callback_create_room_return)
        {
            g_callback_create_room_return.call(
                errorCode,
                photon_realtime_from_jstring(errorString),
                g_current_room_name,
                localPlayerNr
            );
        }
    }

    void joinOrCreateRoomReturn(int localPlayerNr, const C::Hashtable& gameProperties, const C::Hashtable& playerProperties, int errorCode, const C::JString& errorString) override
    {
        (void)gameProperties;
        (void)playerProperties;

        if(errorCode == photon_realtime_success_error_code() && photon_realtime_has_client() && g_photon_client->getIsInGameRoom())
        {
            photon_voice_internal_on_join_room();
            g_current_room_name  = photon_realtime_from_jstring(g_photon_client->getCurrentlyJoinedRoom().getName());
            g_local_player_number = g_photon_client->getLocalPlayer().getNumber();
        }

        if(g_callback_join_or_create_room_return)
        {
            g_callback_join_or_create_room_return.call(
                errorCode,
                photon_realtime_from_jstring(errorString),
                g_current_room_name,
                localPlayerNr
            );
        }
    }

    void joinRandomOrCreateRoomReturn(int localPlayerNr, const C::Hashtable& gameProperties, const C::Hashtable& playerProperties, int errorCode, const C::JString& errorString) override
    {
        (void)gameProperties;
        (void)playerProperties;

        if(errorCode == photon_realtime_success_error_code() && photon_realtime_has_client() && g_photon_client->getIsInGameRoom())
        {
            photon_voice_internal_on_join_room();
            g_current_room_name  = photon_realtime_from_jstring(g_photon_client->getCurrentlyJoinedRoom().getName());
            g_local_player_number = g_photon_client->getLocalPlayer().getNumber();
        }

        if(g_callback_join_random_or_create_room_return)
        {
            g_callback_join_random_or_create_room_return.call(
                errorCode,
                photon_realtime_from_jstring(errorString),
                g_current_room_name,
                localPlayerNr
            );
        }
    }

    void joinRoomReturn(int localPlayerNr, const C::Hashtable& gameProperties, const C::Hashtable& playerProperties, int errorCode, const C::JString& errorString) override
    {
        (void)gameProperties;
        (void)playerProperties;

        if(errorCode == photon_realtime_success_error_code() && photon_realtime_has_client() && g_photon_client->getIsInGameRoom())
        {
            photon_voice_internal_on_join_room();
            g_current_room_name  = photon_realtime_from_jstring(g_photon_client->getCurrentlyJoinedRoom().getName());
            g_local_player_number = g_photon_client->getLocalPlayer().getNumber();
        }

        if(g_callback_join_room_return)
        {
            g_callback_join_room_return.call(
                errorCode,
                photon_realtime_from_jstring(errorString),
                g_current_room_name,
                localPlayerNr
            );
        }
    }

    void joinRandomRoomReturn(int localPlayerNr, const C::Hashtable& gameProperties, const C::Hashtable& playerProperties, int errorCode, const C::JString& errorString) override
    {
        (void)gameProperties;
        (void)playerProperties;

        if(errorCode == photon_realtime_success_error_code() && photon_realtime_has_client() && g_photon_client->getIsInGameRoom())
        {
            photon_voice_internal_on_join_room();
            g_current_room_name  = photon_realtime_from_jstring(g_photon_client->getCurrentlyJoinedRoom().getName());
            g_local_player_number = g_photon_client->getLocalPlayer().getNumber();
        }

        if(g_callback_join_random_room_return)
        {
            g_callback_join_random_room_return.call(
                errorCode,
                photon_realtime_from_jstring(errorString),
                g_current_room_name,
                localPlayerNr
            );
        }
    }

    void leaveRoomReturn(int errorCode, const C::JString& errorString) override
    {
        if(errorCode == photon_realtime_success_error_code())
        {
            photon_voice_internal_on_leave_room();
            photon_realtime_reset_room_state();
        }

        if(g_callback_leave_room_return)
            g_callback_leave_room_return.call(errorCode, photon_realtime_from_jstring(errorString));
    }

    // ---- Lobby operations -----------------------------------------------
    void joinLobbyReturn(void) override
    {
        if(g_callback_join_lobby_return)
            g_callback_join_lobby_return.call();
    }

    void leaveLobbyReturn(void) override
    {
        if(g_callback_leave_lobby_return)
            g_callback_leave_lobby_return.call();
    }

    // ---- Advanced callbacks ---------------------------------------------
    void onFindFriendsResponse(void) override
    {
        if(!g_callback_find_friends_response || !photon_realtime_has_client()) return;

        const C::JVector<LB::FriendInfo>& list = g_photon_client->getFriendList();
        gm::wire::ArrayStream stream;
        for(unsigned int i = 0; i < list.getSize(); ++i)
        {
            const LB::FriendInfo& fi = list[i];
            gm_structs::PhotonRealtimeFriendInfo info;
            info.user_id    = photon_realtime_from_jstring(fi.getUserID());
            info.is_online  = fi.getIsOnline();
            info.room       = photon_realtime_from_jstring(fi.getRoom());
            info.is_in_room = fi.getIsInRoom();
            stream << info;
        }
        g_callback_find_friends_response.call(stream);
    }

    void onLobbyStatsResponse(const C::JVector<LB::LobbyStatsResponse>& lobbyStats) override
    {
        if(!g_callback_lobby_stats_response) return;
        gm::wire::ArrayStream stream;
        for(unsigned int i = 0; i < lobbyStats.getSize(); ++i)
        {
            const LB::LobbyStatsResponse& ls = lobbyStats[i];
            gm_structs::PhotonRealtimeLobbyStats s;
            s.name       = photon_realtime_from_jstring(ls.getName());
            s.type       = static_cast<gm_enums::PhotonRealtimeLobbyType>(ls.getType());
            s.peer_count = ls.getPeerCount();
            s.room_count = ls.getRoomCount();
            stream << s;
        }
        g_callback_lobby_stats_response.call(stream);
    }

    void webRpcReturn(int errorCode, const C::JString& errorString, const C::JString& uriPath, int resultCode, const C::Dictionary<C::Object, C::Object>& data) override
    {
        if(!g_callback_web_rpc_return) return;
        gm::wire::StructStream response_data;
        photon_realtime_fill_object_dictionary_to_struct_stream(data, response_data);
        g_callback_web_rpc_return.call(
            errorCode,
            photon_realtime_from_jstring(errorString),
            photon_realtime_from_jstring(uriPath),
            resultCode,
            response_data
        );
    }

    void onRoomListUpdate(void) override
    {
        if(g_callback_room_list_update)
            g_callback_room_list_update.call();
    }

    void onRoomPropertiesChange(const C::Hashtable& changes) override
    {
        if(!g_callback_room_properties_change) return;
        gm::wire::StructStream ss;
        photon_realtime_fill_hashtable_to_struct_stream(changes, ss);
        g_callback_room_properties_change.call(ss);
    }

    void onPlayerPropertiesChange(int playerNr, const C::Hashtable& changes) override
    {
        if(!g_callback_player_properties_change) return;
        gm::wire::StructStream ss;
        photon_realtime_fill_hashtable_to_struct_stream(changes, ss);
        g_callback_player_properties_change.call(playerNr, ss);
    }

    void onAppStatsUpdate(void) override
    {
        if(g_callback_app_stats_update)
            g_callback_app_stats_update.call();
    }

    void onLobbyStatsUpdate(const C::JVector<LB::LobbyStatsResponse>& lobbyStats) override
    {
        if(!g_callback_lobby_stats_update) return;
        gm::wire::ArrayStream stream;
        for(unsigned int i = 0; i < lobbyStats.getSize(); ++i)
        {
            const LB::LobbyStatsResponse& ls = lobbyStats[i];
            gm_structs::PhotonRealtimeLobbyStats s;
            s.name       = photon_realtime_from_jstring(ls.getName());
            s.type       = static_cast<gm_enums::PhotonRealtimeLobbyType>(ls.getType());
            s.peer_count = ls.getPeerCount();
            s.room_count = ls.getRoomCount();
            stream << s;
        }
        g_callback_lobby_stats_update.call(stream);
    }

    void onCacheSliceChanged(int cacheSliceIndex) override
    {
        if(g_callback_cache_slice_changed)
            g_callback_cache_slice_changed.call(cacheSliceIndex);
    }

    void onMasterClientChanged(int id, int oldID) override
    {
        if(g_callback_master_client_changed)
            g_callback_master_client_changed.call(id, oldID);
    }

    void onPropertiesChangeFailed(void) override
    {
        if(g_callback_properties_change_failed)
            g_callback_properties_change_failed.call();
    }

    void onCustomAuthenticationIntermediateStep(const C::Dictionary<C::JString, C::Object>& customResponseData) override
    {
        if(!g_callback_custom_authentication_step) return;
        gm::wire::StructStream response_data;
        photon_realtime_fill_string_dictionary_to_struct_stream(customResponseData, response_data);
        g_callback_custom_authentication_step.call(response_data);
    }

    void onAvailableRegions(const C::JVector<C::JString>& availableRegions, const C::JVector<C::JString>& availableRegionServers) override
    {
        g_region_selected_since_available = false;

        if(g_callback_available_regions)
        {
            gm::wire::ArrayStream regions_stream;
            for(unsigned int i = 0; i < availableRegions.getSize(); ++i)
                regions_stream << photon_realtime_from_jstring(availableRegions[i]);
            gm::wire::ArrayStream servers_stream;
            for(unsigned int i = 0; i < availableRegionServers.getSize(); ++i)
                servers_stream << photon_realtime_from_jstring(availableRegionServers[i]);
            g_callback_available_regions.call(regions_stream, servers_stream);
        }

        // If the GML callback above didn't already pick a region via
        // photon_realtime_select_region(), apply whatever region was requested
        // earlier (e.g. before connect() was called) to resume the connect flow.
        if(!g_region_selected_since_available && g_has_pending_selected_region && g_photon_client)
        {
            g_region_selected_since_available = true;
            g_photon_client->selectRegion(photon_realtime_to_jstring(g_pending_selected_region));
        }
    }

    void onSecretReceival(const C::JString& secret) override
    {
        if(g_callback_secret_receival)
            g_callback_secret_receival.call(photon_realtime_from_jstring(secret));
    }

    // ---- Direct connection ----------------------------------------------
    void onDirectConnectionEstablished(int remotePeerId) override
    {
        if(g_callback_direct_connection_established)
            g_callback_direct_connection_established.call(remotePeerId);
    }

    void onDirectConnectionFailedToEstablish(int remotePeerId) override
    {
        if(g_callback_direct_connection_failed)
            g_callback_direct_connection_failed.call(remotePeerId);
    }

    void onDirectMessage(const C::Object& msg, int remotePeerId, bool relayFallback) override
    {
        photon_voice_internal_on_direct_message(msg, remotePeerId, relayFallback);

        if(g_callback_direct_message)
            g_callback_direct_message.call(remotePeerId, relayFallback, photon_realtime_object_to_string(msg));
    }

    // ---- Custom operations ----------------------------------------------
    void onCustomOperationResponse(const P::OperationResponse& operationResponse) override
    {
        if(!g_callback_custom_operation_response) return;
        gm::wire::StructStream parameters;
        photon_realtime_fill_byte_dictionary_to_struct_stream(operationResponse.getParameters(), parameters);
        g_callback_custom_operation_response.call(
            static_cast<std::int32_t>(operationResponse.getOperationCode()),
            static_cast<std::int32_t>(operationResponse.getReturnCode()),
            photon_realtime_from_jstring(operationResponse.getDebugMessage()),
            parameters
        );
    }

    void onGetRoomListResponse(const C::JVector<C::Helpers::SharedPointer<LB::Room>>& rooms, const C::JVector<C::JString>& roomsToRemove) override
    {
        // Serialize each room as a [[PhotonRealtimeRoomInfo]] struct and push into an ArrayStream.
        gm::wire::ArrayStream rooms_stream;
        for(unsigned int i = 0; i < rooms.getSize(); ++i)
        {
            const LB::Room* r = rooms[i].operator->();
            if(!r) continue;
            gm_structs::PhotonRealtimeRoomInfo info;
            info.name         = photon_realtime_from_jstring(r->getName());
            info.player_count = static_cast<std::int32_t>(r->getPlayerCount());
            info.max_players  = static_cast<std::int32_t>(r->getMaxPlayers());
            info.is_open      = r->getIsOpen();
            photon_realtime_fill_hashtable_to_struct_stream(r->getCustomProperties(), info.custom_properties);
            rooms_stream << info;
        }

        // Serialize each removed room name as a string stream.
        gm::wire::ArrayStream removed_stream;
        for(unsigned int i = 0; i < roomsToRemove.getSize(); ++i)
            removed_stream << photon_realtime_from_jstring(roomsToRemove[i]);
        if(g_callback_get_room_list_response)
        {
            g_callback_get_room_list_response.call(rooms_stream, removed_stream);
        }
    }
};

static GMPhotonListener g_photon_listener_instance;

LB::Listener& photon_get_listener_instance()
{
    return g_photon_listener_instance;
}

// =============================================================================
// Lifecycle
// =============================================================================

bool photon_realtime_init()
{
    g_photon_initialized = true;
    photon_realtime_reset_connection_state();
    g_buffer_event_queue.clear();

    return true;
}

bool photon_realtime_shutdown()
{
    if(g_photon_client)
        g_photon_client->disconnect();

    g_photon_client.reset();
    photon_realtime_reset_connection_state();
    g_photon_initialized = false;
    g_buffer_event_queue.clear();

    return true;
}

bool photon_realtime_service()
{
    if(!photon_realtime_has_client())
        return false;

    g_photon_client->service();
    g_photon_connected = photon_realtime_state_looks_connected(g_photon_client->getState());
    return true;
}

// =============================================================================
// Connection
// =============================================================================

bool photon_realtime_connect(std::string_view app_id, std::string_view app_version, const std::optional<gm_structs::PhotonRealtimeConnectOptions>& options)
{
    if(!g_photon_initialized)
        return false;

    photon_realtime_reset_connection_state();
    g_buffer_event_queue.clear();

    if(!photon_realtime_rebuild_client(std::string(app_id), std::string(app_version)))
        return false;

    LB::AuthenticationValues auth;
    LB::ConnectOptions opts;

    if(options)
    {
        if(options->authentication_values)
        {
            const auto& a = *options->authentication_values;
            if(a.user_id)    auth.setUserID(photon_realtime_to_jstring(*a.user_id));
            if(a.auth_type)  auth.setType(static_cast<nByte>(*a.auth_type));
            if(a.parameters) auth.setParameters(photon_realtime_to_jstring(*a.parameters));
        }
        if(options->username)                    opts.setUsername(photon_realtime_to_jstring(*options->username));
        if(options->server_address)              opts.setServerAddress(photon_realtime_to_jstring(*options->server_address));
        if(options->try_use_datagram_encryption) opts.setTryUseDatagramEncryption(*options->try_use_datagram_encryption);
        if(options->use_background_thread)       opts.setUseBackgroundSendReceiveThread(*options->use_background_thread);
    }

    opts.setAuthenticationValues(auth);

    return g_photon_client->connect(opts);
}

bool photon_realtime_disconnect()
{
    if(!photon_realtime_has_client())
        return false;

    g_photon_client->disconnect();
    return true;
}

bool photon_realtime_select_region(std::string_view region)
{
    g_pending_selected_region     = std::string(region);
    g_has_pending_selected_region = !g_pending_selected_region.empty();

    // No client yet (e.g. called before connect()) — the desired region is
    // remembered and will be applied once the client pauses at onAvailableRegions().
    if(!photon_realtime_has_client())
        return true;

    g_region_selected_since_available = true;
    return g_photon_client->selectRegion(photon_realtime_to_jstring(g_pending_selected_region));
}

bool photon_realtime_reconnect_and_rejoin()
{
    if(!photon_realtime_has_client())
        return false;

    return g_photon_client->reconnectAndRejoin();
}

bool photon_realtime_fetch_server_timestamp()
{
    if(!photon_realtime_has_client())
        return false;

    g_photon_client->fetchServerTimestamp();
    return true;
}

// =============================================================================
// Lobby / Rooms
// =============================================================================

bool photon_realtime_operation_join_lobby(std::string_view lobby_name, gm_enums::PhotonRealtimeLobbyType lobby_type, const std::optional<gm::wire::GMFunction>& callback)
{
    if (callback) g_callback_join_lobby_return = *callback;

    if(!photon_realtime_has_client())
        return false;

    return g_photon_client->opJoinLobby(
        photon_realtime_to_jstring(std::string(lobby_name)),
        static_cast<nByte>(lobby_type)
    );
}

bool photon_realtime_operation_leave_lobby(const std::optional<gm::wire::GMFunction>& callback)
{
    if (callback) g_callback_leave_lobby_return = *callback;

    if(!photon_realtime_has_client())
        return false;

    return g_photon_client->opLeaveLobby();
}

static LB::RoomOptions photon_realtime_make_room_options(const gm_structs::PhotonRealtimeRoomOptions& opts, const gm::wire::GMObjectView& custom_properties)
{
    LB::RoomOptions roomOpts;
    if (opts.max_players)          roomOpts.setMaxPlayers(photon_realtime_to_nbyte(*opts.max_players));
    if (opts.is_visible)           roomOpts.setIsVisible(*opts.is_visible);
    if (opts.is_open)              roomOpts.setIsOpen(*opts.is_open);
    if (opts.lobby_name)           roomOpts.setLobbyName(photon_realtime_to_jstring(*opts.lobby_name));
    if (opts.lobby_type)           roomOpts.setLobbyType(static_cast<nByte>(*opts.lobby_type));
    if (opts.player_ttl)           roomOpts.setPlayerTtl(static_cast<int>(*opts.player_ttl));
    if (opts.empty_room_ttl)       roomOpts.setEmptyRoomTtl(static_cast<int>(*opts.empty_room_ttl));
    if (opts.suppress_room_events) roomOpts.setSuppressRoomEvents(*opts.suppress_room_events);
    if (opts.publish_user_id)      roomOpts.setPublishUserID(*opts.publish_user_id);
    // Build lobby-visible key list from opts.lobby_keys
    C::JVector<C::JString> lobbyKeys;
    for (const auto& k : opts.lobby_keys)
        lobbyKeys.addElement(photon_realtime_to_jstring(k));
    roomOpts.setPropsListedInLobby(lobbyKeys);
    // Build custom room properties from the GML object argument
    C::Hashtable customProps;
    photon_realtime_fill_gm_object_to_hashtable(custom_properties, customProps);
    roomOpts.setCustomRoomProperties(customProps);
    return roomOpts;
}

bool photon_realtime_operation_create_room(std::string_view room_name, const gm_structs::PhotonRealtimeRoomOptions& options, const gm::wire::GMObjectView& custom_properties, const std::optional<gm::wire::GMFunction>& callback)
{
    if (callback) g_callback_create_room_return = *callback;

    if(!photon_realtime_has_client())
        return false;

    C::JVector<C::JString> expectedUsers;
    for (const auto& uid : options.expected_users)
        expectedUsers.addElement(photon_realtime_to_jstring(uid));

    return g_photon_client->opCreateRoom(
        photon_realtime_to_jstring(std::string(room_name)),
        photon_realtime_make_room_options(options, custom_properties),
        expectedUsers
    );
}

bool photon_realtime_operation_join_or_create_room(std::string_view room_name, const gm_structs::PhotonRealtimeRoomOptions& options, const gm::wire::GMObjectView& custom_properties, std::optional<std::int32_t> cache_slice_index, const std::optional<gm::wire::GMFunction>& callback)
{
    if (callback) g_callback_join_or_create_room_return = *callback;

    if(!photon_realtime_has_client())
        return false;

    const int cacheSlice = cache_slice_index ? static_cast<int>(*cache_slice_index) : 0;

    C::JVector<C::JString> expectedUsers;
    for (const auto& uid : options.expected_users)
        expectedUsers.addElement(photon_realtime_to_jstring(uid));

    return g_photon_client->opJoinOrCreateRoom(
        photon_realtime_to_jstring(std::string(room_name)),
        photon_realtime_make_room_options(options, custom_properties),
        cacheSlice,
        expectedUsers
    );
}

bool photon_realtime_operation_join_room(std::string_view room_name, const gm_structs::PhotonRealtimeJoinRoomOptions& options, const std::optional<gm::wire::GMFunction>& callback)
{
    if (callback) g_callback_join_room_return = *callback;

    if(!photon_realtime_has_client())
        return false;

    const bool rejoin    = options.rejoin            ? *options.rejoin                              : false;
    const int cacheSlice = options.cache_slice_index ? static_cast<int>(*options.cache_slice_index) : 0;

    return g_photon_client->opJoinRoom(
        photon_realtime_to_jstring(std::string(room_name)),
        rejoin,
        cacheSlice
    );
}

bool photon_realtime_operation_join_random_room(const gm_structs::PhotonRealtimeJoinRandomOptions& options, const gm::wire::GMObjectView& expected_properties, const std::optional<gm::wire::GMFunction>& callback)
{
    if (callback) g_callback_join_random_room_return = *callback;

    if(!photon_realtime_has_client())
        return false;

    const nByte maxPlayers  = options.max_players      ? photon_realtime_to_nbyte(*options.max_players)      : 0;
    const nByte matchmaking = options.matchmaking_mode ? static_cast<nByte>(*options.matchmaking_mode) : LB::MatchmakingMode::FILL_ROOM;
    const nByte lobbyType   = options.lobby_type       ? static_cast<nByte>(*options.lobby_type)       : LB::LobbyType::DEFAULT;
    const C::JString lobbyName = options.lobby_name ? photon_realtime_to_jstring(*options.lobby_name) : C::JString();
    const C::JString sqlFilter = options.sql_filter  ? photon_realtime_to_jstring(*options.sql_filter)  : C::JString();

    C::Hashtable expectedPropsHt;
    photon_realtime_fill_gm_object_to_hashtable(expected_properties, expectedPropsHt);

    C::JVector<C::JString> expectedUsers;
    for (const auto& uid : options.expected_users)
        expectedUsers.addElement(photon_realtime_to_jstring(uid));

    return g_photon_client->opJoinRandomRoom(
        expectedPropsHt,
        maxPlayers,
        matchmaking,
        lobbyName,
        lobbyType,
        sqlFilter,
        expectedUsers
    );
}

bool photon_realtime_operation_leave_room(bool will_come_back, bool send_authentication_cookie, const std::optional<gm::wire::GMFunction>& callback)
{
    if (callback) g_callback_leave_room_return = *callback;

    if(!photon_realtime_has_client())
        return false;

    return g_photon_client->opLeaveRoom(will_come_back, send_authentication_cookie);
}

bool photon_realtime_operation_join_random_or_create_room(std::string_view room_name, const gm_structs::PhotonRealtimeRoomOptions& options, const gm::wire::GMObjectView& custom_properties, const gm_structs::PhotonRealtimeJoinRandomOptions& random_options, const gm::wire::GMObjectView& expected_properties, const std::optional<gm::wire::GMFunction>& callback)
{
    if(callback) g_callback_join_random_or_create_room_return = *callback;

    if(!photon_realtime_has_client())
        return false;

    const nByte maxPlayers  = random_options.max_players      ? photon_realtime_to_nbyte(*random_options.max_players)                   : 0;
    const nByte matchmaking = random_options.matchmaking_mode ? static_cast<nByte>(*random_options.matchmaking_mode)           : LB::MatchmakingMode::FILL_ROOM;
    const nByte lobbyType   = random_options.lobby_type       ? static_cast<nByte>(*random_options.lobby_type)                 : LB::LobbyType::DEFAULT;
    const C::JString lobbyName = random_options.lobby_name    ? photon_realtime_to_jstring(*random_options.lobby_name)                  : C::JString();
    const C::JString sqlFilter = random_options.sql_filter    ? photon_realtime_to_jstring(*random_options.sql_filter)                  : C::JString();

    C::Hashtable expectedPropsHt;
    photon_realtime_fill_gm_object_to_hashtable(expected_properties, expectedPropsHt);

    C::JVector<C::JString> expectedUsers;
    for(const auto& uid : random_options.expected_users)
        expectedUsers.addElement(photon_realtime_to_jstring(uid));

    return g_photon_client->opJoinRandomOrCreateRoom(
        photon_realtime_to_jstring(std::string(room_name)),
        photon_realtime_make_room_options(options, custom_properties),
        expectedPropsHt,
        maxPlayers,
        matchmaking,
        lobbyName,
        lobbyType,
        sqlFilter,
        expectedUsers
    );
}

bool photon_realtime_operation_get_room_list(std::string_view lobby_name, std::string_view sql_filter, const std::optional<gm::wire::GMFunction>& callback)
{
    if(callback) g_callback_get_room_list_response = *callback;

    if(!photon_realtime_has_client())
        return false;

    return g_photon_client->opGetRoomList(
        photon_realtime_to_jstring(std::string(lobby_name)),
        photon_realtime_to_jstring(std::string(sql_filter))
    );
}

bool photon_realtime_operation_lobby_stats(const std::optional<gm::wire::GMFunction>& callback)
{
    if(callback) g_callback_lobby_stats_response = *callback;

    if(!photon_realtime_has_client())
        return false;

    return g_photon_client->opLobbyStats();
}

bool photon_realtime_operation_find_friends(const std::vector<std::string_view>& friends, const std::optional<gm::wire::GMFunction>& callback)
{
    if(callback) g_callback_find_friends_response = *callback;

    if(!photon_realtime_has_client() || friends.empty())
        return false;

    const short count = static_cast<short>(friends.size());
    std::vector<C::JString> jstrings(static_cast<size_t>(count));
    for(short i = 0; i < count; ++i)
        jstrings[static_cast<size_t>(i)] = photon_realtime_to_jstring(std::string(friends[static_cast<size_t>(i)]));

    return g_photon_client->opFindFriends(jstrings.data(), count);
}

bool photon_realtime_operation_web_rpc(std::string_view uri_path, const std::optional<gm::wire::GMFunction>& callback)
{
    if(callback) g_callback_web_rpc_return = *callback;

    if(!photon_realtime_has_client())
        return false;

    return g_photon_client->opWebRpc(photon_realtime_to_jstring(std::string(uri_path)));
}

bool photon_realtime_operation_custom_auth_next_step(const gm_structs::PhotonRealtimeAuthenticationValues& authentication)
{
    if(!photon_realtime_has_client())
        return false;

    LB::AuthenticationValues auth;
    if(authentication.user_id)    auth.setUserID(photon_realtime_to_jstring(*authentication.user_id));
    if(authentication.auth_type)  auth.setType(static_cast<nByte>(*authentication.auth_type));
    if(authentication.parameters) auth.setParameters(photon_realtime_to_jstring(*authentication.parameters));
    return g_photon_client->opCustomAuthenticationSendNextStepData(auth);
}

bool photon_realtime_operation_change_groups(const std::optional<std::vector<std::int32_t>>& groups_to_remove, const std::optional<std::vector<std::int32_t>>& groups_to_add)
{
    if(!photon_realtime_has_client())
        return false;

    C::JVector<nByte> remove_groups;
    C::JVector<nByte> add_groups;

    const C::JVector<nByte>* remove_ptr = nullptr;
    const C::JVector<nByte>* add_ptr = nullptr;

    if(groups_to_remove)
    {
        for(const std::int32_t group : groups_to_remove.value())
        {
            if(group < 0 || group > 255)
                return false;

            remove_groups.addElement(static_cast<nByte>(group));
        }

        // Keep this non-null even when remove_groups is empty.
        // Photon interprets a non-null empty array as "remove ALL groups".
        remove_ptr = &remove_groups;
    }

    if(groups_to_add)
    {
        for(const std::int32_t group : groups_to_add.value())
        {
            if(group < 0 || group > 255)
                return false;

            add_groups.addElement(static_cast<nByte>(group));
        }

        // Keep this non-null even when add_groups is empty.
        // Photon interprets a non-null empty array as "subscribe to ALL groups".
        add_ptr = &add_groups;
    }

    return g_photon_client->opChangeGroups(remove_ptr, add_ptr);
}

// =============================================================================
// Raise Event — String
// =============================================================================

bool photon_realtime_operation_raise_event_string(bool reliable, std::string_view payload, std::int32_t event_code, const std::optional<gm_structs::PhotonRealtimeRaiseEventOptions>& options)
{
    if(!photon_realtime_can_raise_event())
        return false;

    LB::RaiseEventOptions opts = options ? photon_realtime_make_raise_event_options(*options) : LB::RaiseEventOptions();
    return g_photon_client->opRaiseEvent(reliable, photon_realtime_to_jstring(std::string(payload)), static_cast<nByte>(event_code), opts);
}

// =============================================================================
// Raise Event — Buffer
// =============================================================================

bool photon_realtime_operation_raise_event_buffer(bool reliable, gm::wire::GMBuffer data, std::uint32_t bytes, std::int32_t event_code, const std::optional<gm_structs::PhotonRealtimeRaiseEventOptions>& options)
{
    if(!photon_realtime_can_raise_event() || bytes == 0)
        return false;

    std::vector<nByte> payload(bytes);
    auto reader = data.getReader();
    reader.readBytes(reinterpret_cast<char*>(payload.data()), static_cast<int>(bytes));

    LB::RaiseEventOptions opts = options ? photon_realtime_make_raise_event_options(*options) : LB::RaiseEventOptions();
    return g_photon_client->opRaiseEvent(reliable, payload.data(), static_cast<int>(payload.size()), static_cast<nByte>(event_code), opts);
}

// =============================================================================
// Incoming buffer event queue
// =============================================================================

std::int32_t photon_realtime_get_buffer_event_queue_count()
{
    return static_cast<std::int32_t>(g_buffer_event_queue.size());
}

bool photon_realtime_clear_buffer_event_queue()
{
    g_buffer_event_queue.clear();
    return true;
}

std::int32_t photon_realtime_peek_next_buffer_event_size()
{
    if(g_buffer_event_queue.empty())
        return 0;

    return static_cast<std::int32_t>(g_buffer_event_queue.front().payload.size());
}

std::int32_t photon_realtime_peek_next_buffer_event_code()
{
    if(g_buffer_event_queue.empty())
        return -1;

    return static_cast<std::int32_t>(g_buffer_event_queue.front().event_code);
}

std::int32_t photon_realtime_peek_next_buffer_event_player_number()
{
    if(g_buffer_event_queue.empty())
        return -1;

    return static_cast<std::int32_t>(g_buffer_event_queue.front().player_number);
}

gm_structs::PhotonRealtimeEventBufferReceived photon_realtime_receive_one_event_buffer(gm::wire::GMBuffer out_data,
    std::uint32_t max_bytes, std::uint32_t offset)
{
    gm_structs::PhotonRealtimeEventBufferReceived out{};
    out.ok           = false;
    out.player_number = -1;
    out.event_code   = -1;
    out.bytes_written = 0;

    if(max_bytes == 0 || g_buffer_event_queue.empty())
        return out;

    PhotonQueuedBufferEvent ev = std::move(g_buffer_event_queue.front());
    g_buffer_event_queue.pop_front();

    const std::uint32_t cb       = static_cast<std::uint32_t>(ev.payload.size());
    const std::uint32_t to_write = (cb < max_bytes) ? cb : max_bytes;

    auto writer = out_data.getWriter();
    writer.skip(offset);
    writer.writeBytes(reinterpret_cast<const char*>(ev.payload.data()), static_cast<int>(to_write));

    out.player_number  = ev.player_number;
    out.event_code    = ev.event_code;
    out.bytes_written = to_write;
    out.ok            = true;

    return out;
}

// =============================================================================
// State getters
// =============================================================================

bool         photon_realtime_is_initialized()  { return g_photon_initialized; }
bool         photon_realtime_is_connected()    { return photon_realtime_has_client() ? photon_realtime_state_looks_connected(g_photon_client->getState()) : g_photon_connected; }
bool         photon_realtime_is_in_game_room() { return photon_realtime_has_client() ? g_photon_client->getIsInGameRoom() : false; }
bool         photon_realtime_is_in_room()      { return photon_realtime_has_client() ? g_photon_client->getIsInRoom()     : false; }
bool         photon_realtime_is_in_lobby()     { return photon_realtime_has_client() ? g_photon_client->getIsInLobby()    : false; }

std::string photon_realtime_get_current_room_name()
{
    if(photon_realtime_has_client() && g_photon_client->getIsInGameRoom())
        return photon_realtime_from_jstring(g_photon_client->getCurrentlyJoinedRoom().getName());

    return g_current_room_name;
}

std::int32_t photon_realtime_get_local_player_number()
{
    if(photon_realtime_has_client() && g_photon_client->getIsInGameRoom())
        return g_photon_client->getLocalPlayer().getNumber();

    return g_local_player_number;
}

std::int32_t photon_realtime_get_server_time_offset()        { return photon_realtime_has_client() ? g_photon_client->getServerTimeOffset()     : 0; }
std::int32_t photon_realtime_get_server_time()               { return photon_realtime_has_client() ? g_photon_client->getServerTime()           : 0; }
std::int32_t photon_realtime_get_bytes_in()                  { return photon_realtime_has_client() ? g_photon_client->getBytesIn()              : 0; }
std::int32_t photon_realtime_get_bytes_out()                 { return photon_realtime_has_client() ? g_photon_client->getBytesOut()             : 0; }
gm_enums::PhotonRealtimeState photon_realtime_get_state()             { return photon_realtime_has_client() ? photon_realtime_state_from_sdk(g_photon_client->getState()) : gm_enums::PhotonRealtimeState::Uninitialized; }
std::int32_t photon_realtime_get_round_trip_time()           { return photon_realtime_has_client() ? g_photon_client->getRoundTripTime()        : 0; }
std::int32_t photon_realtime_get_round_trip_time_variance()  { return photon_realtime_has_client() ? g_photon_client->getRoundTripTimeVariance(): 0; }
gm_enums::PhotonRealtimeDisconnectCause photon_realtime_get_disconnected_cause() { return photon_realtime_has_client() ? photon_realtime_disconnect_cause_from_sdk(g_photon_client->getDisconnectedCause()) : gm_enums::PhotonRealtimeDisconnectCause::None; }
std::int32_t photon_realtime_get_count_players_ingame()      { return photon_realtime_has_client() ? g_photon_client->getCountPlayersIngame()   : 0; }
std::int32_t photon_realtime_get_count_games_running()       { return photon_realtime_has_client() ? g_photon_client->getCountGamesRunning()    : 0; }
std::int32_t photon_realtime_get_count_players_online()      { return photon_realtime_has_client() ? g_photon_client->getCountPlayersOnline()   : 0; }

std::string photon_realtime_get_user_id()
{
    return photon_realtime_has_client() ? photon_realtime_from_jstring(g_photon_client->getUserID()) : std::string();
}

std::string  photon_realtime_get_region()                { return g_current_region; }
std::string  photon_realtime_get_master_server_address() { return photon_realtime_has_client() ? photon_realtime_from_jstring(g_photon_client->getMasterserverAddress()) : std::string(); }
std::string  photon_realtime_get_region_with_best_ping() { return photon_realtime_has_client() ? photon_realtime_from_jstring(g_photon_client->getRegionWithBestPing())  : std::string(); }
std::int32_t photon_realtime_get_friend_list_age()       { return photon_realtime_has_client() ? g_photon_client->getFriendListAge()        : 0; }
std::int32_t photon_realtime_get_disconnect_timeout()    { return photon_realtime_has_client() ? g_photon_client->getDisconnectTimeout()    : 0; }
bool         photon_realtime_set_disconnect_timeout(std::int32_t milliseconds) { if(!photon_realtime_has_client()) return false; g_photon_client->setDisconnectTimeout(milliseconds); return true; }
std::int32_t photon_realtime_get_ping_interval()         { return photon_realtime_has_client() ? g_photon_client->getTimePingInterval()     : 0; }
bool         photon_realtime_set_ping_interval(std::int32_t milliseconds)      { if(!photon_realtime_has_client()) return false; g_photon_client->setTimePingInterval(milliseconds);  return true; }
bool         photon_realtime_get_auto_join_lobby()        { return photon_realtime_has_client() ? g_photon_client->getAutoJoinLobby()        : false; }
bool         photon_realtime_set_auto_join_lobby(bool enabled) { if(!photon_realtime_has_client()) return false; g_photon_client->setAutoJoinLobby(enabled); return true; }

// =============================================================================
// Callback registration
// =============================================================================

bool photon_realtime_set_callback_debug(const gm::wire::GMFunction& callback)                         { g_callback_debug                         = callback; return true; }
bool photon_realtime_set_callback_connected(const gm::wire::GMFunction& callback)                     { g_callback_connected                     = callback; return true; }
bool photon_realtime_set_callback_disconnected(const gm::wire::GMFunction& callback)                  { g_callback_disconnected                  = callback; return true; }
bool photon_realtime_set_callback_connection_error(const gm::wire::GMFunction& callback)              { g_callback_connection_error              = callback; return true; }
bool photon_realtime_set_callback_client_error(const gm::wire::GMFunction& callback)                  { g_callback_client_error                  = callback; return true; }
bool photon_realtime_set_callback_server_error(const gm::wire::GMFunction& callback)                  { g_callback_server_error                  = callback; return true; }
bool photon_realtime_set_callback_warning(const gm::wire::GMFunction& callback)                       { g_callback_warning                       = callback; return true; }
bool photon_realtime_set_callback_join_room_event(const gm::wire::GMFunction& callback)               { g_callback_join_room_event               = callback; return true; }
bool photon_realtime_set_callback_leave_room_event(const gm::wire::GMFunction& callback)              { g_callback_leave_room_event              = callback; return true; }
bool photon_realtime_set_callback_custom_event(const gm::wire::GMFunction& callback)                  { g_callback_custom_event                  = callback; return true; }
bool photon_realtime_set_callback_room_properties_change(const gm::wire::GMFunction& callback)        { g_callback_room_properties_change        = callback; return true; }
bool photon_realtime_set_callback_player_properties_change(const gm::wire::GMFunction& callback)      { g_callback_player_properties_change      = callback; return true; }
bool photon_realtime_set_callback_room_list_update(const gm::wire::GMFunction& callback)              { g_callback_room_list_update              = callback; return true; }
bool photon_realtime_set_callback_app_stats_update(const gm::wire::GMFunction& callback)              { g_callback_app_stats_update              = callback; return true; }
bool photon_realtime_set_callback_lobby_stats_update(const gm::wire::GMFunction& callback)            { g_callback_lobby_stats_update            = callback; return true; }
bool photon_realtime_set_callback_cache_slice_changed(const gm::wire::GMFunction& callback)           { g_callback_cache_slice_changed           = callback; return true; }
bool photon_realtime_set_callback_master_client_changed(const gm::wire::GMFunction& callback)         { g_callback_master_client_changed         = callback; return true; }
bool photon_realtime_set_callback_properties_change_failed(const gm::wire::GMFunction& callback)      { g_callback_properties_change_failed      = callback; return true; }
bool photon_realtime_set_callback_custom_authentication_step(const gm::wire::GMFunction& callback)    { g_callback_custom_authentication_step    = callback; return true; }
bool photon_realtime_set_callback_available_regions(const gm::wire::GMFunction& callback)             { g_callback_available_regions             = callback; return true; }
bool photon_realtime_set_callback_secret_receival(const gm::wire::GMFunction& callback)               { g_callback_secret_receival               = callback; return true; }
bool photon_realtime_set_callback_direct_connection_established(const gm::wire::GMFunction& callback) { g_callback_direct_connection_established = callback; return true; }
bool photon_realtime_set_callback_direct_connection_failed(const gm::wire::GMFunction& callback)      { g_callback_direct_connection_failed      = callback; return true; }
bool photon_realtime_set_callback_direct_message(const gm::wire::GMFunction& callback)                { g_callback_direct_message                = callback; return true; }
bool photon_realtime_set_callback_custom_operation_response(const gm::wire::GMFunction& callback)     { g_callback_custom_operation_response     = callback; return true; }

// =============================================================================
// Callback removal
// =============================================================================

bool photon_realtime_remove_callback_debug()                         { g_callback_debug                         = nullptr; return true; }
bool photon_realtime_remove_callback_connected()                     { g_callback_connected                     = nullptr; return true; }
bool photon_realtime_remove_callback_disconnected()                  { g_callback_disconnected                  = nullptr; return true; }
bool photon_realtime_remove_callback_connection_error()              { g_callback_connection_error              = nullptr; return true; }
bool photon_realtime_remove_callback_client_error()                  { g_callback_client_error                  = nullptr; return true; }
bool photon_realtime_remove_callback_server_error()                  { g_callback_server_error                  = nullptr; return true; }
bool photon_realtime_remove_callback_warning()                       { g_callback_warning                       = nullptr; return true; }
bool photon_realtime_remove_callback_join_room_event()               { g_callback_join_room_event               = nullptr; return true; }
bool photon_realtime_remove_callback_leave_room_event()              { g_callback_leave_room_event              = nullptr; return true; }
bool photon_realtime_remove_callback_custom_event()                  { g_callback_custom_event                  = nullptr; return true; }
bool photon_realtime_remove_callback_room_properties_change()        { g_callback_room_properties_change        = nullptr; return true; }
bool photon_realtime_remove_callback_player_properties_change()      { g_callback_player_properties_change      = nullptr; return true; }
bool photon_realtime_remove_callback_room_list_update()              { g_callback_room_list_update              = nullptr; return true; }
bool photon_realtime_remove_callback_app_stats_update()              { g_callback_app_stats_update              = nullptr; return true; }
bool photon_realtime_remove_callback_lobby_stats_update()            { g_callback_lobby_stats_update            = nullptr; return true; }
bool photon_realtime_remove_callback_cache_slice_changed()           { g_callback_cache_slice_changed           = nullptr; return true; }
bool photon_realtime_remove_callback_master_client_changed()         { g_callback_master_client_changed         = nullptr; return true; }
bool photon_realtime_remove_callback_properties_change_failed()      { g_callback_properties_change_failed      = nullptr; return true; }
bool photon_realtime_remove_callback_custom_authentication_step()    { g_callback_custom_authentication_step    = nullptr; return true; }
bool photon_realtime_remove_callback_available_regions()             { g_callback_available_regions             = nullptr; return true; }
bool photon_realtime_remove_callback_secret_receival()               { g_callback_secret_receival               = nullptr; return true; }
bool photon_realtime_remove_callback_direct_connection_established() { g_callback_direct_connection_established = nullptr; return true; }
bool photon_realtime_remove_callback_direct_connection_failed()      { g_callback_direct_connection_failed      = nullptr; return true; }
bool photon_realtime_remove_callback_direct_message()                { g_callback_direct_message                = nullptr; return true; }
bool photon_realtime_remove_callback_custom_operation_response()     { g_callback_custom_operation_response     = nullptr; return true; }

// =============================================================================
// Room properties
// =============================================================================

bool photon_realtime_room_properties_set_string(std::string_view key, std::string_view value)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    room->addCustomProperty(photon_realtime_to_jstring(std::string(key)), photon_realtime_to_jstring(std::string(value)));
    return true;
}

bool photon_realtime_room_properties_set_i32(std::string_view key, std::int32_t value)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    room->addCustomProperty(photon_realtime_to_jstring(std::string(key)), static_cast<int>(value));
    return true;
}

bool photon_realtime_room_properties_set_f64(std::string_view key, double value)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    room->addCustomProperty(photon_realtime_to_jstring(std::string(key)), value);
    return true;
}

bool photon_realtime_room_properties_set_bool(std::string_view key, bool value)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    room->addCustomProperty(photon_realtime_to_jstring(std::string(key)), value);
    return true;
}

bool photon_realtime_room_properties_remove(std::string_view key)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    room->removeCustomProperty(photon_realtime_to_jstring(std::string(key)));
    return true;
}

bool photon_realtime_room_properties_clear()
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    const C::Hashtable& props = room->getCustomProperties();
    const C::JVector<C::Object> keys(props.getKeys());
    for(unsigned int i = 0; i < keys.getSize(); ++i)
        room->removeCustomProperty(keys[i]);
    return true;
}

bool photon_realtime_room_properties_has(std::string_view key)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    return photon_realtime_hashtable_has_key(room->getCustomProperties(), std::string(key));
}

std::string photon_realtime_room_properties_get_string(std::string_view key)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return "";
    return photon_realtime_object_as_string_or_default(
        photon_realtime_hashtable_get_object(room->getCustomProperties(), std::string(key)), "");
}

std::int32_t photon_realtime_room_properties_get_i32(std::string_view key)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return 0;
    return photon_realtime_object_as_i32_or_default(
        photon_realtime_hashtable_get_object(room->getCustomProperties(), std::string(key)), 0);
}

double photon_realtime_room_properties_get_f64(std::string_view key)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return 0.0;
    return photon_realtime_object_as_f64_or_default(
        photon_realtime_hashtable_get_object(room->getCustomProperties(), std::string(key)), 0.0);
}

bool photon_realtime_room_properties_get_bool(std::string_view key)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    return photon_realtime_object_as_bool_or_default(
        photon_realtime_hashtable_get_object(room->getCustomProperties(), std::string(key)), false);
}

std::string photon_realtime_room_properties_to_string()
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return "";
    return photon_realtime_hashtable_to_string(room->getCustomProperties());
}

gm::wire::StructStream photon_realtime_room_properties_get_all()
{
    gm::wire::StructStream ss;
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(room) photon_realtime_fill_hashtable_to_struct_stream(room->getCustomProperties(), ss);
    return ss;
}

bool photon_realtime_room_properties_cas_string(std::string_view key, std::string_view expected_value, std::string_view new_value)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    C::Hashtable expected;
    expected.put(photon_realtime_to_jstring(std::string(key)), photon_realtime_to_jstring(std::string(expected_value)));
    return room->addCustomProperty(photon_realtime_to_jstring(std::string(key)), photon_realtime_to_jstring(std::string(new_value)), expected);
}

bool photon_realtime_room_properties_cas_i32(std::string_view key, std::int32_t expected_value, std::int32_t new_value)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    C::Hashtable expected;
    expected.put(photon_realtime_to_jstring(std::string(key)), static_cast<int>(expected_value));
    return room->addCustomProperty(photon_realtime_to_jstring(std::string(key)), static_cast<int>(new_value), expected);
}

bool photon_realtime_room_properties_cas_f64(std::string_view key, double expected_value, double new_value)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    C::Hashtable expected;
    expected.put(photon_realtime_to_jstring(std::string(key)), expected_value);
    return room->addCustomProperty(photon_realtime_to_jstring(std::string(key)), new_value, expected);
}

bool photon_realtime_room_properties_cas_bool(std::string_view key, bool expected_value, bool new_value)
{
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(!room) return false;
    C::Hashtable expected;
    expected.put(photon_realtime_to_jstring(std::string(key)), expected_value);
    return room->addCustomProperty(photon_realtime_to_jstring(std::string(key)), new_value, expected);
}

// =============================================================================
// Player properties — local
// =============================================================================

bool photon_realtime_player_properties_set_local_string(std::string_view key, std::string_view value)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return false;
    p->addCustomProperty(photon_realtime_to_jstring(std::string(key)), photon_realtime_to_jstring(std::string(value)));
    return true;
}

bool photon_realtime_player_properties_set_local_i32(std::string_view key, std::int32_t value)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return false;
    p->addCustomProperty(photon_realtime_to_jstring(std::string(key)), static_cast<int>(value));
    return true;
}

bool photon_realtime_player_properties_set_local_f64(std::string_view key, double value)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return false;
    p->addCustomProperty(photon_realtime_to_jstring(std::string(key)), value);
    return true;
}

bool photon_realtime_player_properties_set_local_bool(std::string_view key, bool value)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return false;
    p->addCustomProperty(photon_realtime_to_jstring(std::string(key)), value);
    return true;
}

bool photon_realtime_player_properties_remove_local(std::string_view key)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return false;
    p->removeCustomProperty(photon_realtime_to_jstring(std::string(key)));
    return true;
}

bool photon_realtime_player_properties_clear_local()
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return false;
    const C::Hashtable& props = p->getCustomProperties();
    const C::JVector<C::Object> keys(props.getKeys());
    for(unsigned int i = 0; i < keys.getSize(); ++i)
        p->removeCustomProperty(keys[i]);
    return true;
}

bool photon_realtime_player_properties_has_local(std::string_view key)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return false;
    return photon_realtime_hashtable_has_key(p->getCustomProperties(), std::string(key));
}

std::string photon_realtime_player_properties_get_local_string(std::string_view key)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return "";
    return photon_realtime_object_as_string_or_default(
        photon_realtime_hashtable_get_object(p->getCustomProperties(), std::string(key)), "");
}

std::int32_t photon_realtime_player_properties_get_local_i32(std::string_view key)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return 0;
    return photon_realtime_object_as_i32_or_default(
        photon_realtime_hashtable_get_object(p->getCustomProperties(), std::string(key)), 0);
}

double photon_realtime_player_properties_get_local_f64(std::string_view key)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return 0.0;
    return photon_realtime_object_as_f64_or_default(
        photon_realtime_hashtable_get_object(p->getCustomProperties(), std::string(key)), 0.0);
}

bool photon_realtime_player_properties_get_local_bool(std::string_view key)
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return false;
    return photon_realtime_object_as_bool_or_default(
        photon_realtime_hashtable_get_object(p->getCustomProperties(), std::string(key)), false);
}

std::string photon_realtime_player_properties_to_string_local()
{
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(!p) return "";
    return photon_realtime_hashtable_to_string(p->getCustomProperties());
}

gm::wire::StructStream photon_realtime_player_properties_get_local_all()
{
    gm::wire::StructStream ss;
    LB::MutablePlayer* p = photon_realtime_local_player_ref();
    if(p) photon_realtime_fill_hashtable_to_struct_stream(p->getCustomProperties(), ss);
    return ss;
}


// =============================================================================
// Player properties — remote
// =============================================================================

bool photon_realtime_player_properties_has_remote(std::int32_t player_number, std::string_view key)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    if(!p) return false;
    return photon_realtime_hashtable_has_key(p->getCustomProperties(), std::string(key));
}

std::string photon_realtime_player_properties_get_remote_string(std::int32_t player_number, std::string_view key)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    if(!p) return "";
    return photon_realtime_object_as_string_or_default(
        photon_realtime_hashtable_get_object(p->getCustomProperties(), std::string(key)), "");
}

std::int32_t photon_realtime_player_properties_get_remote_i32(std::int32_t player_number, std::string_view key)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    if(!p) return 0;
    return photon_realtime_object_as_i32_or_default(
        photon_realtime_hashtable_get_object(p->getCustomProperties(), std::string(key)), 0);
}

double photon_realtime_player_properties_get_remote_f64(std::int32_t player_number, std::string_view key)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    if(!p) return 0.0;
    return photon_realtime_object_as_f64_or_default(
        photon_realtime_hashtable_get_object(p->getCustomProperties(), std::string(key)), 0.0);
}

bool photon_realtime_player_properties_get_remote_bool(std::int32_t player_number, std::string_view key)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    if(!p) return false;
    return photon_realtime_object_as_bool_or_default(
        photon_realtime_hashtable_get_object(p->getCustomProperties(), std::string(key)), false);
}

std::string photon_realtime_player_properties_to_string_remote(std::int32_t player_number)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    if(!p) return "";
    return photon_realtime_hashtable_to_string(p->getCustomProperties());
}

gm::wire::StructStream photon_realtime_player_properties_get_remote_all(std::int32_t player_number)
{
    gm::wire::StructStream ss;
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    if(p) photon_realtime_fill_hashtable_to_struct_stream(p->getCustomProperties(), ss);
    return ss;
}

// =============================================================================
// Current room state getters
// =============================================================================

static const LB::MutableRoom* photon_realtime_room_const_ptr()
{
    if(!photon_realtime_has_client() || !g_photon_client->getIsInGameRoom()) return nullptr;
    return &g_photon_client->getCurrentlyJoinedRoom();
}

std::int32_t photon_realtime_get_room_player_count()
{
    const auto* r = photon_realtime_room_const_ptr();
    return r ? static_cast<std::int32_t>(r->getPlayerCount()) : 0;
}

std::int32_t photon_realtime_get_room_max_players()
{
    const auto* r = photon_realtime_room_const_ptr();
    return r ? static_cast<std::int32_t>(r->getMaxPlayers()) : 0;
}

bool photon_realtime_get_room_is_open()
{
    const auto* r = photon_realtime_room_const_ptr();
    return r ? r->getIsOpen() : false;
}

bool photon_realtime_get_room_is_visible()
{
    const auto* r = photon_realtime_room_const_ptr();
    return r ? r->getIsVisible() : false;
}

std::int32_t photon_realtime_get_master_client_number()
{
    const auto* r = photon_realtime_room_const_ptr();
    return r ? static_cast<std::int32_t>(r->getMasterClientID()) : 0;
}

bool photon_realtime_set_master_client(std::int32_t player_number)
{
    if(!photon_realtime_has_client() || !g_photon_client->getIsInGameRoom())
        return false;

    const LB::Player* player = g_photon_client->getCurrentlyJoinedRoom().getPlayerForNumber(player_number);
    return player ? g_photon_client->setMasterClient(*player) : false;
}

// =============================================================================
// Lobby room list getters
// =============================================================================

static const LB::Room* photon_realtime_room_list_ptr(std::int32_t index)
{
    if(!photon_realtime_has_client()) return nullptr;
    const C::JVector<LB::Room*>& rooms = g_photon_client->getRoomList();
    if(index < 0 || static_cast<unsigned int>(index) >= rooms.getSize()) return nullptr;
    return rooms[static_cast<unsigned int>(index)];
}

std::int32_t photon_realtime_get_room_list_count()
{
    if(!photon_realtime_has_client()) return 0;
    return static_cast<std::int32_t>(g_photon_client->getRoomList().getSize());
}

gm_structs::PhotonRealtimeRoomInfo photon_realtime_get_room_info_by_index(std::int32_t index)
{
    gm_structs::PhotonRealtimeRoomInfo info;
    const auto* r = photon_realtime_room_list_ptr(index);
    if(!r) return info;

    info.name         = photon_realtime_from_jstring(r->getName());
    info.player_count = static_cast<std::int32_t>(r->getPlayerCount());
    info.max_players  = static_cast<std::int32_t>(r->getMaxPlayers());
    info.is_open      = r->getIsOpen();
    photon_realtime_fill_hashtable_to_struct_stream(r->getCustomProperties(), info.custom_properties);
    return info;
}

// =============================================================================
// Player list getters
// =============================================================================

std::int32_t photon_realtime_get_player_count()
{
    const auto* r = photon_realtime_room_const_ptr();
    return r ? static_cast<std::int32_t>(r->getPlayerCount()) : 0;
}

std::int32_t photon_realtime_get_player_number_by_index(std::int32_t index)
{
    const auto* r = photon_realtime_room_const_ptr();
    if(!r) return 0;
    const auto& players = r->getPlayers();
    if(index < 0 || static_cast<unsigned int>(index) >= players.getSize()) return 0;
    const LB::Player* p = players[static_cast<unsigned int>(index)];
    return p ? static_cast<std::int32_t>(p->getNumber()) : 0;
}

std::string photon_realtime_player_get_name(std::int32_t player_number)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    if(!p) return "";
    return photon_realtime_from_jstring(p->getName());
}

std::string photon_realtime_player_get_user_id(std::int32_t player_number)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    if(!p) return "";
    return photon_realtime_from_jstring(p->getUserID());
}

bool photon_realtime_player_is_inactive(std::int32_t player_number)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    return p ? p->getIsInactive() : false;
}

bool photon_realtime_player_is_master_client(std::int32_t player_number)
{
    const LB::Player* p = photon_realtime_remote_player_ptr(player_number);
    return p ? p->getIsMasterClient() : false;
}

std::vector<std::int32_t> photon_realtime_get_player_numbers()
{
    std::vector<std::int32_t> numbers;
    LB::MutableRoom* room = photon_realtime_room_ref();
    if(room)
    {
        const C::JVector<LB::Player*>& players = room->getPlayers();
        for(unsigned int i = 0; i < players.getSize(); ++i)
            if(players[i])
                numbers.push_back(static_cast<std::int32_t>(players[i]->getNumber()));
    }
    return numbers;
}

// =============================================================================
// Common enum string helpers
// =============================================================================




// =============================================================================
// Internal accessor (used by peer/common modules)
// =============================================================================

LB::Client* photon_internal_get_lb_client()
{
    return g_photon_client.get();
}
