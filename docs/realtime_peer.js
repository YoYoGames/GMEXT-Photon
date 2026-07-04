// FUNCTIONS

/**
 * @function photon_realtime_peer_get_state
 * @desc Returns the low-level peer state of the Realtime connection.
 * @returns {Constant.PhotonPeerState} The peer state.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_round_trip_time
 * @desc Returns the peer's measured round-trip time to the server, in milliseconds.
 * @returns {Real} The round-trip time in milliseconds.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_round_trip_time_variance
 * @desc Returns the variance of the peer's round-trip time, in milliseconds.
 * @returns {Real} The round-trip time variance.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_bytes_in
 * @desc Returns the total number of bytes received by the peer.
 * @returns {Real} The number of bytes received.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_bytes_out
 * @desc Returns the total number of bytes sent by the peer.
 * @returns {Real} The number of bytes sent.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_queued_incoming_commands
 * @desc Returns the number of incoming commands currently queued on the peer.
 * @returns {Real} The number of queued incoming commands.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_queued_outgoing_commands
 * @desc Returns the number of outgoing commands currently queued on the peer.
 * @returns {Real} The number of queued outgoing commands.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_debug_output_level
 * @desc Returns the peer's debug output level.
 * @returns {Constant.PhotonCommonDebugLevel} The debug output level.
 * @function_end
 */

/**
 * @function photon_realtime_peer_set_debug_output_level
 * @desc Sets the peer's debug output level.
 * @param {Constant.PhotonCommonDebugLevel} level The debug output level to apply.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_disconnect_timeout
 * @desc Returns the peer's disconnect timeout, in milliseconds.
 * @returns {Real} The disconnect timeout.
 * @function_end
 */

/**
 * @function photon_realtime_peer_set_disconnect_timeout
 * @desc Sets the peer's disconnect timeout, in milliseconds.
 * @param {Real} timeout_ms The timeout in milliseconds.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_time_ping_interval
 * @desc Returns the peer's ping interval, in milliseconds.
 * @returns {Real} The ping interval.
 * @function_end
 */

/**
 * @function photon_realtime_peer_set_time_ping_interval
 * @desc Sets the peer's ping interval, in milliseconds.
 * @param {Real} interval_ms The ping interval in milliseconds.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_crc_enabled
 * @desc Returns whether CRC checking is enabled on the peer.
 * @returns {Bool} Whether CRC checking is enabled.
 * @function_end
 */

/**
 * @function photon_realtime_peer_set_crc_enabled
 * @desc Enables or disables CRC checking on the peer. CRC adds a small overhead but detects corrupted packets.
 * @param {Bool} enabled Whether to enable CRC checking.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_packet_loss_by_crc
 * @desc Returns the number of packets discarded due to a failed CRC check.
 * @returns {Real} The number of packets lost to CRC failures.
 * @function_end
 */

/**
 * @function photon_realtime_peer_get_timestamp_of_last_socket_receive
 * @desc Returns the timestamp (in milliseconds) of the last data received on the peer's socket.
 * @returns {Real} The timestamp of the last socket receive.
 * @function_end
 */

/**
 * @function photon_realtime_peer_reset_traffic_stats
 * @desc Resets the peer's traffic statistics (bytes in/out and related counters).
 * @returns {Bool} Whether the statistics were reset.
 * @function_end
 */

// MODULES

/**
 * @module realtime_peer
 * @title Realtime Peer
 * @desc Low-level diagnostics and tuning for the Realtime connection's underlying peer: round-trip time, byte counters, queued commands, CRC checking and timeouts. These mirror the equivalent Chat peer functions in ${module.chat_peer}.
 *
 * [[NOTE: Some peer statistics return a safe default when a background send/receive thread is active (Nintendo Switch only). On the shipping desktop and mobile platforms the client runs on the game thread and the values are live.]]
 *
 * @section_func Functions
 * @desc The Realtime Peer module provides the following functions:
 * @ref photon_realtime_peer_get_state
 * @ref photon_realtime_peer_get_round_trip_time
 * @ref photon_realtime_peer_get_round_trip_time_variance
 * @ref photon_realtime_peer_get_bytes_in
 * @ref photon_realtime_peer_get_bytes_out
 * @ref photon_realtime_peer_get_queued_incoming_commands
 * @ref photon_realtime_peer_get_queued_outgoing_commands
 * @ref photon_realtime_peer_get_debug_output_level
 * @ref photon_realtime_peer_set_debug_output_level
 * @ref photon_realtime_peer_get_disconnect_timeout
 * @ref photon_realtime_peer_set_disconnect_timeout
 * @ref photon_realtime_peer_get_time_ping_interval
 * @ref photon_realtime_peer_set_time_ping_interval
 * @ref photon_realtime_peer_get_crc_enabled
 * @ref photon_realtime_peer_set_crc_enabled
 * @ref photon_realtime_peer_get_packet_loss_by_crc
 * @ref photon_realtime_peer_get_timestamp_of_last_socket_receive
 * @ref photon_realtime_peer_reset_traffic_stats
 * @section_end
 *
 * @module_end
 */
