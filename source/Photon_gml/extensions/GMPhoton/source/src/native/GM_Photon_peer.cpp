//
// GM_Photon_peer_new.cpp
// ExitGames Photon-cpp base SDK wrapper implementation
//
// PhotonPeer diagnostics are exposed through explicit _realtime_ (LB::Client)
// and _chat_ (Chat::Client) variants. Both delegate to their public peer API.
//

#include "GMPhoton_native.h"

#include <LoadBalancing-cpp/inc/Client.h>
#include <Chat-cpp/inc/Client.h>

using namespace gm_structs;
using namespace gm_enums;

namespace LB   = ExitGames::LoadBalancing;
namespace Chat = ExitGames::Chat;

// Forward declarations for the internal accessors defined in the other TUs.
extern LB::Client*   photon_internal_get_lb_client();
extern Chat::Client* photon_chat_internal_get_client();

// =============================================================================
// Diagnostics / protocol info — Realtime (LoadBalancing client)
// =============================================================================

std::int32_t photon_realtime_peer_get_state()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getState();
    return 0;
}

std::int32_t photon_realtime_peer_get_round_trip_time()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getRoundTripTime();
    return 0;
}

std::int32_t photon_realtime_peer_get_round_trip_time_variance()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getRoundTripTimeVariance();
    return 0;
}

std::int32_t photon_realtime_peer_get_bytes_in()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getBytesIn();
    return 0;
}

std::int32_t photon_realtime_peer_get_bytes_out()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getBytesOut();
    return 0;
}

std::int32_t photon_realtime_peer_get_queued_incoming_commands()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getQueuedIncomingCommands();
    return 0;
}

std::int32_t photon_realtime_peer_get_queued_outgoing_commands()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getQueuedOutgoingCommands();
    return 0;
}

std::int32_t photon_realtime_peer_get_debug_output_level()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getDebugOutputLevel();
    return 0;
}

bool photon_realtime_peer_set_debug_output_level(std::int32_t level)
{
    if(auto* c = photon_internal_get_lb_client()) { c->setDebugOutputLevel(level); return true; }
    return false;
}

std::int32_t photon_realtime_peer_get_disconnect_timeout()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getDisconnectTimeout();
    return 0;
}

bool photon_realtime_peer_set_disconnect_timeout(std::int32_t timeout_ms)
{
    if(auto* c = photon_internal_get_lb_client()) { c->setDisconnectTimeout(timeout_ms); return true; }
    return false;
}

std::int32_t photon_realtime_peer_get_time_ping_interval()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getTimePingInterval();
    return 0;
}

bool photon_realtime_peer_set_time_ping_interval(std::int32_t interval_ms)
{
    if(auto* c = photon_internal_get_lb_client()) { c->setTimePingInterval(interval_ms); return true; }
    return false;
}

bool photon_realtime_peer_get_crc_enabled()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getCRCEnabled();
    return false;
}

bool photon_realtime_peer_set_crc_enabled(bool enabled)
{
    if(auto* c = photon_internal_get_lb_client()) { c->setCRCEnabled(enabled); return true; }
    return false;
}

std::int32_t photon_realtime_peer_get_packet_loss_by_crc()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getPacketLossByCRC();
    return 0;
}

std::int32_t photon_realtime_peer_get_timestamp_of_last_socket_receive()
{
    if(auto* c = photon_internal_get_lb_client()) return c->getTimestampOfLastSocketReceive();
    return 0;
}

// =============================================================================
// Diagnostics / protocol info — Chat client
// =============================================================================

std::int32_t photon_chat_peer_get_state()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getState();
    return 0;
}

std::int32_t photon_chat_peer_get_round_trip_time()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getRoundTripTime();
    return 0;
}

std::int32_t photon_chat_peer_get_round_trip_time_variance()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getRoundTripTimeVariance();
    return 0;
}

std::int32_t photon_chat_peer_get_bytes_in()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getBytesIn();
    return 0;
}

std::int32_t photon_chat_peer_get_bytes_out()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getBytesOut();
    return 0;
}

std::int32_t photon_chat_peer_get_queued_incoming_commands()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getQueuedIncomingCommands();
    return 0;
}

std::int32_t photon_chat_peer_get_queued_outgoing_commands()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getQueuedOutgoingCommands();
    return 0;
}

std::int32_t photon_chat_peer_get_debug_output_level()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getDebugOutputLevel();
    return 0;
}

bool photon_chat_peer_set_debug_output_level(std::int32_t level)
{
    if(auto* c = photon_chat_internal_get_client()) { c->setDebugOutputLevel(level); return true; }
    return false;
}

std::int32_t photon_chat_peer_get_disconnect_timeout()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getDisconnectTimeout();
    return 0;
}

bool photon_chat_peer_set_disconnect_timeout(std::int32_t timeout_ms)
{
    if(auto* c = photon_chat_internal_get_client()) { c->setDisconnectTimeout(timeout_ms); return true; }
    return false;
}

std::int32_t photon_chat_peer_get_time_ping_interval()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getTimePingInterval();
    return 0;
}

bool photon_chat_peer_set_time_ping_interval(std::int32_t interval_ms)
{
    if(auto* c = photon_chat_internal_get_client()) { c->setTimePingInterval(interval_ms); return true; }
    return false;
}

bool photon_chat_peer_get_crc_enabled()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getCRCEnabled();
    return false;
}

bool photon_chat_peer_set_crc_enabled(bool enabled)
{
    if(auto* c = photon_chat_internal_get_client()) { c->setCRCEnabled(enabled); return true; }
    return false;
}

std::int32_t photon_chat_peer_get_packet_loss_by_crc()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getPacketLossByCRC();
    return 0;
}

std::int32_t photon_chat_peer_get_timestamp_of_last_socket_receive()
{
    if(auto* c = photon_chat_internal_get_client()) return c->getTimestampOfLastSocketReceive();
    return 0;
}

// =============================================================================
// Traffic stats reset
// =============================================================================

bool photon_realtime_peer_reset_traffic_stats()
{
    if(auto* c = photon_internal_get_lb_client()) { c->resetTrafficStats(); return true; }
    return false;
}

bool photon_chat_peer_reset_traffic_stats()
{
    if(auto* c = photon_chat_internal_get_client()) { c->resetTrafficStats(); return true; }
    return false;
}

// =============================================================================
// Network simulation  (not available in Photon Windows SDK v5 — stubs only)
// These functions are defined so the GML API surface is stable.
// If a future SDK version re-introduces NetworkSimulationSet, replace these
// stubs with the real implementation using getNetworkSimulationSettings().
// =============================================================================

bool photon_peer_network_sim_get_enabled()                                              { return false; }
bool photon_peer_network_sim_set_enabled(bool /*enabled*/)                              { return false; }
bool photon_peer_network_sim_set_lag(std::int32_t /*in*/, std::int32_t /*out*/)         { return false; }
bool photon_peer_network_sim_set_jitter(std::int32_t /*in*/, std::int32_t /*out*/)      { return false; }
bool photon_peer_network_sim_set_packet_loss(std::int32_t /*in*/, std::int32_t /*out*/) { return false; }
