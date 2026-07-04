// FUNCTIONS

/**
 * @function photon_chat_peer_get_state
 * @desc Returns the current state of the Chat connection.
 * @returns {Real} The connection state.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_round_trip_time
 * @desc Returns the Chat peer's measured round-trip time to the server, in milliseconds.
 * @returns {Real} The round-trip time in milliseconds.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_round_trip_time_variance
 * @desc Returns the variance of the Chat peer's round-trip time, in milliseconds.
 * @returns {Real} The round-trip time variance.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_bytes_in
 * @desc Returns the total number of bytes received by the Chat peer.
 * @returns {Real} The number of bytes received.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_bytes_out
 * @desc Returns the total number of bytes sent by the Chat peer.
 * @returns {Real} The number of bytes sent.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_queued_incoming_commands
 * @desc Returns the number of incoming commands currently queued on the Chat peer.
 * @returns {Real} The number of queued incoming commands.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_queued_outgoing_commands
 * @desc Returns the number of outgoing commands currently queued on the Chat peer.
 * @returns {Real} The number of queued outgoing commands.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_debug_output_level
 * @desc Returns the Chat peer's debug output level.
 * @returns {Constant.PhotonCommonDebugLevel} The debug output level.
 * @function_end
 */

/**
 * @function photon_chat_peer_set_debug_output_level
 * @desc Sets the Chat peer's debug output level.
 * @param {Constant.PhotonCommonDebugLevel} level The debug output level to apply.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_disconnect_timeout
 * @desc Returns the Chat peer's disconnect timeout, in milliseconds.
 * @returns {Real} The disconnect timeout.
 * @function_end
 */

/**
 * @function photon_chat_peer_set_disconnect_timeout
 * @desc Sets the Chat peer's disconnect timeout, in milliseconds.
 * @param {Real} timeout_ms The timeout in milliseconds.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_time_ping_interval
 * @desc Returns the Chat peer's ping interval, in milliseconds.
 * @returns {Real} The ping interval.
 * @function_end
 */

/**
 * @function photon_chat_peer_set_time_ping_interval
 * @desc Sets the Chat peer's ping interval, in milliseconds.
 * @param {Real} interval_ms The ping interval in milliseconds.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_crc_enabled
 * @desc Returns whether CRC checking is enabled on the Chat peer.
 * @returns {Bool} Whether CRC checking is enabled.
 * @function_end
 */

/**
 * @function photon_chat_peer_set_crc_enabled
 * @desc Enables or disables CRC checking on the Chat peer. CRC adds a small overhead but detects corrupted packets.
 * @param {Bool} enabled Whether to enable CRC checking.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_packet_loss_by_crc
 * @desc Returns the number of packets discarded due to a failed CRC check on the Chat peer.
 * @returns {Real} The number of packets lost to CRC failures.
 * @function_end
 */

/**
 * @function photon_chat_peer_get_timestamp_of_last_socket_receive
 * @desc Returns the timestamp (in milliseconds) of the last data received on the Chat peer's socket.
 * @returns {Real} The timestamp of the last socket receive.
 * @function_end
 */

/**
 * @function photon_chat_peer_reset_traffic_stats
 * @desc Resets the Chat peer's traffic statistics (bytes in/out and related counters).
 * @returns {Bool} Whether the statistics were reset.
 * @function_end
 */

// MODULES

/**
 * @module chat_peer
 * @title Chat Peer
 * @desc Low-level diagnostics and tuning for the Chat connection's underlying peer: round-trip time, byte counters, queued commands, CRC checking and timeouts. These mirror the equivalent Realtime peer functions in ${module.realtime_peer}.
 *
 * [[NOTE: These getters return a safe default when Chat is running with a background send/receive thread (Nintendo Switch only). On the shipping desktop and mobile platforms the client runs on the game thread and the values are live.]]
 *
 * @section_func Functions
 * @desc The Chat Peer module provides the following functions:
 * @ref photon_chat_peer_get_state
 * @ref photon_chat_peer_get_round_trip_time
 * @ref photon_chat_peer_get_round_trip_time_variance
 * @ref photon_chat_peer_get_bytes_in
 * @ref photon_chat_peer_get_bytes_out
 * @ref photon_chat_peer_get_queued_incoming_commands
 * @ref photon_chat_peer_get_queued_outgoing_commands
 * @ref photon_chat_peer_get_debug_output_level
 * @ref photon_chat_peer_set_debug_output_level
 * @ref photon_chat_peer_get_disconnect_timeout
 * @ref photon_chat_peer_set_disconnect_timeout
 * @ref photon_chat_peer_get_time_ping_interval
 * @ref photon_chat_peer_set_time_ping_interval
 * @ref photon_chat_peer_get_crc_enabled
 * @ref photon_chat_peer_set_crc_enabled
 * @ref photon_chat_peer_get_packet_loss_by_crc
 * @ref photon_chat_peer_get_timestamp_of_last_socket_receive
 * @ref photon_chat_peer_reset_traffic_stats
 * @section_end
 *
 * @module_end
 */
