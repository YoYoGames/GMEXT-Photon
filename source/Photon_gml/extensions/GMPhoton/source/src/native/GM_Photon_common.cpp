//
// GM_Photon_common_new.cpp
// ExitGames Common-cpp SDK wrapper implementation
//

#include "GMPhoton_native.h"

#include <Common-cpp/inc/Common.h>
#include <Common-cpp/inc/JString.h>
#include <Common-cpp/inc/ANSIString.h>
#include <Common-cpp/inc/Object.h>
#include <Common-cpp/inc/ValueObject.h>
#include <Common-cpp/inc/Containers/JVector.h>
#include <Common-cpp/inc/Containers/Hashtable.h>
#include <Common-cpp/inc/Containers/Dictionary.h>
#include <Common-cpp/inc/Enums/DebugLevel.h>
#include <Common-cpp/inc/Enums/TypeCode.h>
#include <Common-cpp/inc/Enums/SerializationProtocol.h>

#include <LoadBalancing-cpp/inc/Client.h>
#include <Chat-cpp/inc/Client.h>
#include <Photon-cpp/inc/Version.h>

#include <string>
#include <string_view>

using namespace gm_structs;
using namespace gm_enums;

namespace C    = ExitGames::Common;
namespace LB   = ExitGames::LoadBalancing;
namespace Chat = ExitGames::Chat;

// Forward declarations for the internal accessors defined in the other TUs.
extern LB::Client*   photon_internal_get_lb_client();
extern Chat::Client* photon_chat_internal_get_client();

// =============================================================================
// Debug level  (applies to all active clients simultaneously)
// =============================================================================

bool photon_common_set_debug_level(gm_enums::PhotonCommonDebugLevel level)
{
    const int lvl = static_cast<int>(level);
    bool applied = false;
    if(auto* c = photon_internal_get_lb_client())   { c->setDebugOutputLevel(lvl); applied = true; }
    if(auto* c = photon_chat_internal_get_client()) { c->setDebugOutputLevel(lvl); applied = true; }
    return applied;
}

gm_enums::PhotonCommonDebugLevel photon_common_get_debug_level()
{
    if(auto* c = photon_internal_get_lb_client())   return static_cast<gm_enums::PhotonCommonDebugLevel>(c->getDebugOutputLevel());
    if(auto* c = photon_chat_internal_get_client()) return static_cast<gm_enums::PhotonCommonDebugLevel>(c->getDebugOutputLevel());
    return gm_enums::PhotonCommonDebugLevel::Off;
}

// =============================================================================
// Serialization protocol
// =============================================================================

gm_enums::PhotonCommonSerializationProtocol photon_common_get_serialization_protocol()
{
    // Only LB::Client exposes getSerializationProtocol(); Chat::Client does not.
    if(auto* c = photon_internal_get_lb_client()) return static_cast<gm_enums::PhotonCommonSerializationProtocol>(c->getSerializationProtocol());
    return static_cast<gm_enums::PhotonCommonSerializationProtocol>(C::SerializationProtocol::DEFAULT);
}

// =============================================================================
// Object type inspection
// =============================================================================

std::string photon_common_type_code_to_string(gm_enums::PhotonCommonTypeCode type_code)
{
    // Type codes are defined in Common-cpp/inc/Enums/TypeCode.h
    // Constants are nByte (unsigned char) values — cast for the switch.
    switch(static_cast<nByte>(type_code))
    {
        case C::TypeCode::EG_NULL:    return "null";
        case C::TypeCode::BOOLEAN:    return "boolean";
        case C::TypeCode::BYTE:       return "byte";
        case C::TypeCode::SHORT:      return "short";
        case C::TypeCode::INTEGER:    return "integer";
        case C::TypeCode::LONG:       return "long";
        case C::TypeCode::FLOAT:      return "float";
        case C::TypeCode::DOUBLE:     return "double";
        case C::TypeCode::STRING:     return "string";
        case C::TypeCode::BYTEARRAY:  return "byte_array";
        case C::TypeCode::ARRAY:      return "array";
        case C::TypeCode::OBJECT:     return "object";
        case C::TypeCode::HASHTABLE:  return "hashtable";
        case C::TypeCode::DICTIONARY: return "dictionary";
        case C::TypeCode::CUSTOM:     return "custom";
        default:                      return "unknown";
    }
}

// =============================================================================
// Version info
// =============================================================================

std::string photon_common_get_sdk_version()
{
    // EG_PHOTON_CLIENT_VERSION expands to a wide string (L"5.0.14.0").
    // Build a narrow version string from the integer component macros instead.
    return std::to_string(EG_PHOTON_CLIENT_VERSION_MAJOR)        + "." +
           std::to_string(EG_PHOTON_CLIENT_VERSION_SERVER_MINOR) + "." +
           std::to_string(EG_PHOTON_CLIENT_VERSION_CLIENT_MINOR) + "." +
           std::to_string(EG_PHOTON_CLIENT_VERSION_PATCH_RELEASE);
}

// =============================================================================
// State name helpers
// =============================================================================

std::string photon_common_client_state_to_string(std::int32_t state)
{
    namespace PS = ExitGames::LoadBalancing::PeerStates;

    switch(state)
    {
        case PS::Uninitialized:                               return "Uninitialized";
        case PS::PeerCreated:                                 return "PeerCreated";
        case PS::ConnectingToNameserver:                      return "ConnectingToNameserver";
        case PS::ConnectedToNameserver:                       return "ConnectedToNameserver";
        case PS::DisconnectingFromNameserver:                 return "DisconnectingFromNameserver";
        case PS::Connecting:                                  return "Connecting";
        case PS::Connected:                                   return "Connected";
        case PS::WaitingForCustomAuthenticationNextStepCall:  return "WaitingForCustomAuthenticationNextStepCall";
        case PS::Authenticated:                               return "Authenticated";
        case PS::JoinedLobby:                                 return "JoinedLobby";
        case PS::DisconnectingFromMasterserver:               return "DisconnectingFromMasterserver";
        case PS::ConnectingToGameserver:                      return "ConnectingToGameserver";
        case PS::ConnectedToGameserver:                       return "ConnectedToGameserver";
        case PS::AuthenticatedOnGameServer:                   return "AuthenticatedOnGameServer";
        case PS::Joining:                                     return "Joining";
        case PS::Joined:                                      return "Joined";
        case PS::Leaving:                                     return "Leaving";
        case PS::Left:                                        return "Left";
        case PS::DisconnectingFromGameserver:                 return "DisconnectingFromGameserver";
        case PS::ConnectingToMasterserver:                    return "ConnectingToMasterserver";
        case PS::ConnectedComingFromGameserver:               return "ConnectedComingFromGameserver";
        case PS::AuthenticatedComingFromGameserver:           return "AuthenticatedComingFromGameserver";
        case PS::Disconnecting:                               return "Disconnecting";
        case PS::Disconnected:                                return "Disconnected";
        default: return "Unknown(" + std::to_string(state) + ")";
    }
}

std::string photon_common_disconnect_cause_to_string(std::int32_t cause)
{
    namespace DC = ExitGames::LoadBalancing::DisconnectCause;

    switch(cause)
    {
        case DC::NONE:                                   return "NONE";
        case DC::DISCONNECT_BY_SERVER_USER_LIMIT:        return "DISCONNECT_BY_SERVER_USER_LIMIT";
        case DC::EXCEPTION_ON_CONNECT:                   return "EXCEPTION_ON_CONNECT";
        case DC::DISCONNECT_BY_SERVER:                   return "DISCONNECT_BY_SERVER";
        case DC::DISCONNECT_BY_SERVER_LOGIC:             return "DISCONNECT_BY_SERVER_LOGIC";
        case DC::TIMEOUT_DISCONNECT:                     return "TIMEOUT_DISCONNECT";
        case DC::EXCEPTION:                              return "EXCEPTION";
        case DC::INVALID_AUTHENTICATION:                 return "INVALID_AUTHENTICATION";
        case DC::MAX_CCU_REACHED:                        return "MAX_CCU_REACHED";
        case DC::INVALID_REGION:                         return "INVALID_REGION";
        case DC::OPERATION_NOT_ALLOWED_IN_CURRENT_STATE: return "OPERATION_NOT_ALLOWED_IN_CURRENT_STATE";
        case DC::CUSTOM_AUTHENTICATION_FAILED:           return "CUSTOM_AUTHENTICATION_FAILED";
        case DC::CLIENT_VERSION_TOO_OLD:                 return "CLIENT_VERSION_TOO_OLD";
        case DC::CLIENT_VERSION_INVALID:                 return "CLIENT_VERSION_INVALID";
        case DC::DASHBOARD_VERSION_INVALID:              return "DASHBOARD_VERSION_INVALID";
        case DC::AUTHENTICATION_TICKET_EXPIRED:          return "AUTHENTICATION_TICKET_EXPIRED";
        case DC::DISCONNECT_BY_OPERATION_LIMIT:          return "DISCONNECT_BY_OPERATION_LIMIT";
        default: return "Unknown(" + std::to_string(cause) + ")";
    }
}
