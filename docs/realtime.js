// FUNCTIONS

// --- Lifecycle ---

/**
 * @function photon_realtime_init
 * @desc Initialises the Realtime client. Call this once before any other Realtime function.
 * @returns {Bool} Whether initialisation succeeded.
 * @function_end
 */

/**
 * @function photon_realtime_shutdown
 * @desc Shuts the Realtime client down and releases its resources. Call ${function.photon_realtime_disconnect} first if still connected.
 * @returns {Bool} Whether the client was shut down.
 * @function_end
 */

/**
 * @function photon_realtime_service
 * @desc Dispatches queued incoming and outgoing traffic for the Realtime client. This **must** be called every step while connected, otherwise the client neither sends nor receives.
 * @returns {Bool} Whether the client was serviced.
 * @function_end
 */

/**
 * @function photon_realtime_connect
 * @desc Connects to the Photon Cloud using the given Application ID and application version. The App ID identifies your Photon Realtime application; the version string keeps incompatible client builds apart. The result is delivered to the ${function.photon_realtime_set_callback_connected} callback.
 *
 * @param {String} app_id Your Photon Realtime Application ID.
 * @param {String} app_version A version string of your choosing for your game build.
 * @param {Struct.PhotonRealtimeConnectOptions} [options] Optional connection options.
 *
 * @returns {Bool} Whether the connection attempt started.
 *
 * @example
 * ```gml
 * var _app_id = extension_get_option_value("GMPhoton", "appIdRealtime");
 * photon_realtime_connect(_app_id, "1.0", new PhotonRealtimeConnectOptions());
 * ```
 * @function_end
 */

/**
 * @function photon_realtime_disconnect
 * @desc Disconnects the Realtime client from the Photon Cloud. The ${function.photon_realtime_set_callback_disconnected} callback fires once the disconnect completes.
 * @returns {Bool} Whether the disconnect started.
 * @function_end
 */

/**
 * @function photon_realtime_select_region
 * @desc Selects the Photon Cloud region to connect to (for example `"eu"`, `"us"`, `"asia"`). Call before connecting, or in response to ${function.photon_realtime_set_callback_available_regions}.
 * @param {String} region The region token to use.
 * @returns {Bool} Whether the region was selected.
 * @function_end
 */

/**
 * @function photon_realtime_reconnect_and_rejoin
 * @desc Attempts to reconnect to the last game server and rejoin the room the client was previously in. Useful for recovering from a temporary disconnect.
 * @returns {Bool} Whether the reconnect attempt started.
 * @function_end
 */

/**
 * @function photon_realtime_fetch_server_timestamp
 * @desc Requests the current server timestamp. Once available it can be read with ${function.photon_realtime_get_server_time}.
 * @returns {Bool} Whether the request was sent.
 * @function_end
 */

// --- Lobby & room operations ---

/**
 * @function photon_realtime_operation_join_lobby
 * @desc Joins a matchmaking lobby. While in a lobby the client receives room-list and lobby-stats updates.
 * @param {String} lobby_name The name of the lobby to join.
 * @param {Constant.PhotonRealtimeLobbyType} lobby_type The lobby type.
 * @param {Function} [callback] Optional callback invoked with no arguments when the join completes.
 * @returns {Bool} Whether the operation was sent.
 * @function_end
 */

/**
 * @function photon_realtime_operation_leave_lobby
 * @desc Leaves the current matchmaking lobby.
 * @param {Function} [callback] Optional callback invoked with no arguments when the operation completes.
 * @returns {Bool} Whether the operation was sent.
 * @function_end
 */

/**
 * @function photon_realtime_operation_create_room
 * @desc Creates a new room and joins it. Fails if a room with the same name already exists.
 * @param {String} room_name The name of the room to create.
 * @param {Struct.PhotonRealtimeRoomOptions} options The room configuration.
 * @param {Struct} custom_properties Custom room properties as a GML struct.
 * @param {Function} [callback] Optional callback invoked with the operation result.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Constant.PhotonRealtimeAppErrorCode} error_code The operation result code (`Ok` on success).
 * @member {String} error_string A human-readable result message.
 * @member {String} room_name The name of the room that was created.
 * @member {Real} local_player_number The local player's actor number in the room.
 * @event_end
 * @example
 * ```gml
 * var _opts = new PhotonRealtimeRoomOptions();
 * _opts.max_players = 4;
 * photon_realtime_operation_create_room("arena", _opts, { map: "desert" }, function(_error_code, _error_string, _room_name, _player_number) {
 *     if (_error_code == PhotonRealtimeAppErrorCode.Ok) show_debug_message($"Created {_room_name}");
 * });
 * ```
 * @function_end
 */

/**
 * @function photon_realtime_operation_join_or_create_room
 * @desc Joins the named room, creating it with the given options if it does not yet exist.
 * @param {String} room_name The name of the room to join or create.
 * @param {Struct.PhotonRealtimeRoomOptions} options The room configuration used if the room is created.
 * @param {Struct} custom_properties Custom room properties as a GML struct (used on creation).
 * @param {Real} [cache_slice_index] Optional event-cache slice index to fetch on join.
 * @param {Function} [callback] Optional callback invoked with the operation result.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Constant.PhotonRealtimeAppErrorCode} error_code The operation result code (`Ok` on success).
 * @member {String} error_string A human-readable result message.
 * @member {String} room_name The name of the room that was joined or created.
 * @member {Real} local_player_number The local player's actor number in the room.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_operation_join_room
 * @desc Joins an existing room by name.
 * @param {String} room_name The name of the room to join.
 * @param {Struct.PhotonRealtimeJoinRoomOptions} options The join options.
 * @param {Function} [callback] Optional callback invoked with the operation result.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Constant.PhotonRealtimeAppErrorCode} error_code The operation result code (`Ok` on success).
 * @member {String} error_string A human-readable result message.
 * @member {String} room_name The name of the room that was joined.
 * @member {Real} local_player_number The local player's actor number in the room.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_operation_join_random_room
 * @desc Joins a random room matching the given criteria and expected properties.
 * @param {Struct.PhotonRealtimeJoinRandomOptions} options The matchmaking options.
 * @param {Struct} expected_properties Custom properties a room must match, as a GML struct.
 * @param {Function} [callback] Optional callback invoked with the operation result.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Constant.PhotonRealtimeAppErrorCode} error_code The operation result code (`Ok` on success; `NoMatchFound` if no room matched).
 * @member {String} error_string A human-readable result message.
 * @member {String} room_name The name of the room that was joined.
 * @member {Real} local_player_number The local player's actor number in the room.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_operation_leave_room
 * @desc Leaves the current room.
 * @param {Bool} will_come_back If `true`, the player stays as an inactive actor so they can rejoin later.
 * @param {Bool} send_authentication_cookie Whether to send the authentication cookie with the request.
 * @param {Function} [callback] Optional callback invoked with the operation result.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Constant.PhotonRealtimeAppErrorCode} error_code The operation result code (`Ok` on success).
 * @member {String} error_string A human-readable result message.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_operation_join_random_or_create_room
 * @desc Attempts to join a random room matching the criteria, creating a new room with the given options if none is found.
 * @param {String} room_name The name to use if a room is created.
 * @param {Struct.PhotonRealtimeRoomOptions} options The room configuration used if a room is created.
 * @param {Struct} custom_properties Custom room properties as a GML struct (used on creation).
 * @param {Struct.PhotonRealtimeJoinRandomOptions} random_options The random-matchmaking options.
 * @param {Struct} expected_properties Custom properties a room must match, as a GML struct.
 * @param {Function} [callback] Optional callback invoked with the operation result.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Constant.PhotonRealtimeAppErrorCode} error_code The operation result code (`Ok` on success).
 * @member {String} error_string A human-readable result message.
 * @member {String} room_name The name of the room that was joined or created.
 * @member {Real} local_player_number The local player's actor number in the room.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_operation_get_room_list
 * @desc Requests a room list from a specific SQL lobby.
 * @param {String} lobby_name The lobby to query.
 * @param {String} sql_filter An SQL-style filter string.
 * @param {Function} [callback] Optional callback invoked with the room list.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Array[Struct.PhotonRealtimeRoomInfo]} rooms The rooms that were added or updated.
 * @member {Array[String]} removed The names of rooms that were removed.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_operation_lobby_stats
 * @desc Requests lobby statistics for all tracked lobbies.
 * @param {Function} [callback] Optional callback invoked with the lobby stats.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Array[Struct.PhotonRealtimeLobbyStats]} stats The statistics for each tracked lobby.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_operation_find_friends
 * @desc Finds friends by user ID.
 * @param {Array[String]} friends An array of user IDs to look up.
 * @param {Function} [callback] Optional callback invoked with the friend info.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Array[Struct.PhotonRealtimeFriendInfo]} friends The status of each requested friend.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_operation_web_rpc
 * @desc Calls a WebRPC endpoint configured for your Photon application.
 * @param {String} uri_path The WebRPC path to call.
 * @param {Function} [callback] Optional callback invoked with the response.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} error_code The operation result code.
 * @member {String} error_string A human-readable result message.
 * @member {String} uri_path The WebRPC path that was called.
 * @member {Real} result_code The result code returned by the WebRPC service.
 * @member {Struct} response_data The response data returned by the service, as a GML struct.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_operation_change_groups
 * @desc Changes the interest groups this client receives events from. Pass the groups to remove and the groups to add; an empty or omitted array leaves that set unchanged.
 * @param {Array[Real]} [groups_to_remove] The interest groups to stop receiving.
 * @param {Array[Real]} [groups_to_add] The interest groups to start receiving.
 * @returns {Bool} Whether the operation was sent.
 * @function_end
 */

/**
 * @function photon_realtime_operation_custom_auth_next_step
 * @desc Sends additional data for a multi-step custom authentication flow. Call this from inside the ${function.photon_realtime_set_callback_custom_authentication_step} callback.
 * @param {Struct.PhotonRealtimeAuthenticationValues} authentication The next-step authentication values.
 * @returns {Bool} Whether the operation was sent.
 * @function_end
 */

// --- Sending & receiving events ---

/**
 * @function photon_realtime_operation_raise_event_string
 * @desc Raises a custom event carrying a string payload to other players in the room. Receivers get it via ${function.photon_realtime_set_callback_custom_event}.
 * @param {Bool} reliable Whether the event is sent reliably.
 * @param {String} payload The string payload to send.
 * @param {Real} event_code A custom event code identifying the event.
 * @param {Struct.PhotonRealtimeRaiseEventOptions} [options] Optional targeting and caching options.
 * @returns {Bool} Whether the event was raised.
 * @example
 * ```gml
 * photon_realtime_operation_raise_event_string(true, "hello", 1);
 * ```
 * @function_end
 */

/**
 * @function photon_realtime_operation_raise_event_buffer
 * @desc Raises a custom event carrying a binary buffer payload to other players in the room. Receivers are notified via ${function.photon_realtime_set_callback_custom_event} (with `is_buffer` set) and read the bytes with ${function.photon_realtime_receive_one_event_buffer}.
 * @param {Bool} reliable Whether the event is sent reliably.
 * @param {Buffer} data The buffer holding the payload.
 * @param {Real} bytes The number of bytes from the buffer to send.
 * @param {Real} event_code A custom event code identifying the event.
 * @param {Struct.PhotonRealtimeRaiseEventOptions} [options] Optional targeting and caching options.
 * @returns {Bool} Whether the event was raised.
 * @function_end
 */

/**
 * @function photon_realtime_get_buffer_event_queue_count
 * @desc Returns the number of buffered binary events waiting to be read from the queue.
 * @returns {Real} The number of queued buffer events.
 * @function_end
 */

/**
 * @function photon_realtime_clear_buffer_event_queue
 * @desc Clears all buffered binary events from the queue without reading them.
 * @returns {Bool} Whether the queue was cleared.
 * @function_end
 */

/**
 * @function photon_realtime_peek_next_buffer_event_size
 * @desc Returns the size in bytes of the next buffered binary event without removing it from the queue.
 * @returns {Real} The size of the next event in bytes.
 * @function_end
 */

/**
 * @function photon_realtime_peek_next_buffer_event_code
 * @desc Returns the event code of the next buffered binary event without removing it from the queue.
 * @returns {Real} The event code of the next event.
 * @function_end
 */

/**
 * @function photon_realtime_peek_next_buffer_event_player_number
 * @desc Returns the sender's player number for the next buffered binary event without removing it from the queue.
 * @returns {Real} The player number of the next event's sender.
 * @function_end
 */

/**
 * @function photon_realtime_receive_one_event_buffer
 * @desc Removes the next buffered binary event from the queue and writes its payload into the given buffer.
 * @param {Buffer} out_data The buffer to write the payload into.
 * @param {Real} max_bytes The maximum number of bytes to write.
 * @param {Real} offset The offset within the buffer to start writing at.
 * @returns {Struct.PhotonRealtimeEventBufferReceived} A struct describing the received event.
 * @example
 * ```gml
 * while (photon_realtime_get_buffer_event_queue_count() > 0) {
 *     var _size = photon_realtime_peek_next_buffer_event_size();
 *     var _buf = buffer_create(_size, buffer_grow, 1);
 *     var _info = photon_realtime_receive_one_event_buffer(_buf, _size, 0);
 *     if (_info.ok) {
 *         // read from _buf ... (event_code _info.event_code, from player _info.player_number)
 *     }
 *     buffer_delete(_buf);
 * }
 * ```
 * @function_end
 */

// --- State & info ---

/**
 * @function photon_realtime_is_initialized
 * @desc Returns whether the Realtime client has been initialised.
 * @returns {Bool} Whether the client is initialised.
 * @function_end
 */

/**
 * @function photon_realtime_is_connected
 * @desc Returns whether the client is currently connected to the Photon Cloud.
 * @returns {Bool} Whether the client is connected.
 * @function_end
 */

/**
 * @function photon_realtime_is_in_game_room
 * @desc Returns whether the client is connected to a game server and inside a room.
 * @returns {Bool} Whether the client is in a game room.
 * @function_end
 */

/**
 * @function photon_realtime_is_in_room
 * @desc Returns whether the client is currently in a room.
 * @returns {Bool} Whether the client is in a room.
 * @function_end
 */

/**
 * @function photon_realtime_is_in_lobby
 * @desc Returns whether the client is currently in a matchmaking lobby.
 * @returns {Bool} Whether the client is in a lobby.
 * @function_end
 */

/**
 * @function photon_realtime_get_current_room_name
 * @desc Returns the name of the room the client is currently in, or an empty string if not in a room.
 * @returns {String} The current room name.
 * @function_end
 */

/**
 * @function photon_realtime_get_local_player_number
 * @desc Returns the local player's actor number within the current room.
 * @returns {Real} The local player number.
 * @function_end
 */

/**
 * @function photon_realtime_get_server_time_offset
 * @desc Returns the offset between local time and server time, in milliseconds.
 * @returns {Real} The server time offset in milliseconds.
 * @function_end
 */

/**
 * @function photon_realtime_get_server_time
 * @desc Returns the current server time in milliseconds.
 * @returns {Real} The server time in milliseconds.
 * @function_end
 */

/**
 * @function photon_realtime_get_bytes_in
 * @desc Returns the total number of bytes received by the client.
 * @returns {Real} The number of bytes received.
 * @function_end
 */

/**
 * @function photon_realtime_get_bytes_out
 * @desc Returns the total number of bytes sent by the client.
 * @returns {Real} The number of bytes sent.
 * @function_end
 */

/**
 * @function photon_realtime_get_state
 * @desc Returns the current client state.
 * @returns {Constant.PhotonRealtimeState} The current state.
 * @function_end
 */

/**
 * @function photon_realtime_get_round_trip_time
 * @desc Returns the current round-trip time to the server, in milliseconds.
 * @returns {Real} The round-trip time in milliseconds.
 * @function_end
 */

/**
 * @function photon_realtime_get_round_trip_time_variance
 * @desc Returns the variance of the round-trip time to the server, in milliseconds.
 * @returns {Real} The round-trip time variance.
 * @function_end
 */

/**
 * @function photon_realtime_get_disconnected_cause
 * @desc Returns the cause of the most recent disconnect.
 * @returns {Constant.PhotonRealtimeDisconnectCause} The disconnect cause.
 * @function_end
 */

/**
 * @function photon_realtime_get_user_id
 * @desc Returns the local player's user ID.
 * @returns {String} The local user ID.
 * @function_end
 */

/**
 * @function photon_realtime_get_count_players_ingame
 * @desc Returns the number of players currently in games across the application. Available after connecting and while receiving app stats.
 * @returns {Real} The number of players in games.
 * @function_end
 */

/**
 * @function photon_realtime_get_count_games_running
 * @desc Returns the number of games (rooms) currently running across the application.
 * @returns {Real} The number of running games.
 * @function_end
 */

/**
 * @function photon_realtime_get_count_players_online
 * @desc Returns the total number of players currently online across the application.
 * @returns {Real} The number of players online.
 * @function_end
 */

/**
 * @function photon_realtime_get_master_server_address
 * @desc Returns the address of the master server the client is using.
 * @returns {String} The master server address.
 * @function_end
 */

/**
 * @function photon_realtime_get_region
 * @desc Returns the region token the client is currently connected to.
 * @returns {String} The current region.
 * @function_end
 */

/**
 * @function photon_realtime_get_region_with_best_ping
 * @desc Returns the region with the best measured ping, available after the available-regions ping check completes.
 * @returns {String} The best-ping region token.
 * @function_end
 */

/**
 * @function photon_realtime_get_friend_list_age
 * @desc Returns the age in milliseconds of the last friend-list result from ${function.photon_realtime_operation_find_friends}.
 * @returns {Real} The friend list age in milliseconds.
 * @function_end
 */

// --- Settings ---

/**
 * @function photon_realtime_get_disconnect_timeout
 * @desc Returns the disconnect timeout in milliseconds.
 * @returns {Real} The disconnect timeout.
 * @function_end
 */

/**
 * @function photon_realtime_set_disconnect_timeout
 * @desc Sets the disconnect timeout: how long without a response before the client considers itself disconnected.
 * @param {Real} milliseconds The timeout in milliseconds.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_realtime_get_ping_interval
 * @desc Returns the interval in milliseconds between pings sent to the server.
 * @returns {Real} The ping interval.
 * @function_end
 */

/**
 * @function photon_realtime_set_ping_interval
 * @desc Sets the interval in milliseconds between pings sent to the server.
 * @param {Real} milliseconds The ping interval in milliseconds.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_realtime_get_auto_join_lobby
 * @desc Returns whether the client automatically joins the default lobby after connecting.
 * @returns {Bool} Whether auto-join-lobby is enabled.
 * @function_end
 */

/**
 * @function photon_realtime_set_auto_join_lobby
 * @desc Sets whether the client automatically joins the default lobby after connecting.
 * @param {Bool} enabled Whether to auto-join the lobby.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

// --- Room & player info ---

/**
 * @function photon_realtime_get_room_player_count
 * @desc Returns the number of players currently in the room.
 * @returns {Real} The room player count.
 * @function_end
 */

/**
 * @function photon_realtime_get_room_max_players
 * @desc Returns the maximum number of players allowed in the current room.
 * @returns {Real} The room's maximum players.
 * @function_end
 */

/**
 * @function photon_realtime_get_room_is_open
 * @desc Returns whether the current room is open to new players.
 * @returns {Bool} Whether the room is open.
 * @function_end
 */

/**
 * @function photon_realtime_get_room_is_visible
 * @desc Returns whether the current room is visible in the lobby room list.
 * @returns {Bool} Whether the room is visible.
 * @function_end
 */

/**
 * @function photon_realtime_get_master_client_number
 * @desc Returns the player number of the current room's master client.
 * @returns {Real} The master client's player number.
 * @function_end
 */

/**
 * @function photon_realtime_set_master_client
 * @desc Assigns the master client role to the given player. Only the current master client may do this.
 * @param {Real} player_number The player number to make master client.
 * @returns {Bool} Whether the request was sent.
 * @function_end
 */

/**
 * @function photon_realtime_get_room_list_count
 * @desc Returns the number of rooms in the most recent lobby room list.
 * @returns {Real} The number of rooms.
 * @function_end
 */

/**
 * @function photon_realtime_get_room_info_by_index
 * @desc Returns information about a room in the lobby room list by index.
 * @param {Real} index The zero-based index into the room list.
 * @returns {Struct.PhotonRealtimeRoomInfo} The room information.
 * @function_end
 */

/**
 * @function photon_realtime_get_player_count
 * @desc Returns the number of players currently tracked in the room.
 * @returns {Real} The player count.
 * @function_end
 */

/**
 * @function photon_realtime_get_player_number_by_index
 * @desc Returns the player number at the given index in the room's player list.
 * @param {Real} index The zero-based index into the player list.
 * @returns {Real} The player number.
 * @function_end
 */

/**
 * @function photon_realtime_player_get_name
 * @desc Returns the display name of the given player.
 * @param {Real} player_number The player number.
 * @returns {String} The player's name.
 * @function_end
 */

/**
 * @function photon_realtime_player_get_user_id
 * @desc Returns the user ID of the given player.
 * @param {Real} player_number The player number.
 * @returns {String} The player's user ID.
 * @function_end
 */

/**
 * @function photon_realtime_player_is_inactive
 * @desc Returns whether the given player is currently inactive (has left but may rejoin).
 * @param {Real} player_number The player number.
 * @returns {Bool} Whether the player is inactive.
 * @function_end
 */

/**
 * @function photon_realtime_player_is_master_client
 * @desc Returns whether the given player is the room's master client.
 * @param {Real} player_number The player number.
 * @returns {Bool} Whether the player is the master client.
 * @function_end
 */

/**
 * @function photon_realtime_get_player_numbers
 * @desc Returns an array of the player numbers currently in the room.
 * @returns {Array[Real]} An array of player numbers.
 * @function_end
 */

// --- Callbacks ---
// Each set_* function registers a callback; the matching remove_* function clears it.

/**
 * @function photon_realtime_set_callback_connected
 * @desc Registers the callback fired when the client finishes connecting.
 * @param {Function} callback The function to call on connect.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Constant.PhotonRealtimeAppErrorCode} error_code The connect result code (`Ok` on success).
 * @member {String} error_string A human-readable result message.
 * @member {String} region The region that was connected to.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_disconnected
 * @desc Registers the callback fired when the client has disconnected. The callback takes no arguments.
 * @param {Function} callback The function to call on disconnect.
 * @returns {Bool} Whether the callback was set.
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_connection_error
 * @desc Registers the callback fired on a low-level connection error.
 * @param {Function} callback The function to call on a connection error.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} error_code The connection error code.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_client_error
 * @desc Registers the callback fired on a client-side error.
 * @param {Function} callback The function to call on a client error.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} error_code The client error code.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_server_error
 * @desc Registers the callback fired on a server-reported error.
 * @param {Function} callback The function to call on a server error.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} error_code The server error code.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_warning
 * @desc Registers the callback fired on a client warning.
 * @param {Function} callback The function to call on a warning.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} warning_code The warning code.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_debug
 * @desc Registers the callback fired with SDK debug output.
 * @param {Function} callback The function to call with debug output.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} debug_level The debug level of the message.
 * @member {String} message The debug message.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_join_room_event
 * @desc Registers the callback fired when a player joins the room. When the local client joins, it fires once per player already present.
 * @param {Function} callback The function to call on a join event.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} joining_player_number The player number that triggered the join.
 * @member {Real} player_number The player number described by this call.
 * @member {String} player_name The player's display name.
 * @member {String} user_id The player's user ID.
 * @member {Bool} is_inactive Whether the player is inactive.
 * @member {Bool} is_master_client Whether the player is the master client.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_leave_room_event
 * @desc Registers the callback fired when a player leaves the room.
 * @param {Function} callback The function to call on a leave event.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} player_number The player number that left.
 * @member {Bool} is_inactive Whether the player became inactive (may rejoin) rather than leaving for good.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_custom_event
 * @desc Registers the callback fired when a custom event raised by ${function.photon_realtime_operation_raise_event_string} or ${function.photon_realtime_operation_raise_event_buffer} is received.
 * @param {Function} callback The function to call on a custom event.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} player_number The sender's player number.
 * @member {Real} event_code The custom event code.
 * @member {String} payload The string payload; empty for buffer events (read the bytes with ${function.photon_realtime_receive_one_event_buffer}).
 * @member {Bool} is_buffer Whether the event carries a binary buffer payload.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_player_properties_change
 * @desc Registers the callback fired when a player's custom properties change. See ${module.realtime_player_properties}.
 * @param {Function} callback The function to call on a player-properties change.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} player_number The player whose properties changed.
 * @member {Struct} properties The changed properties, as a GML struct.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_room_properties_change
 * @desc Registers the callback fired when the room's custom properties change. See ${module.realtime_room_properties}.
 * @param {Function} callback The function to call on a room-properties change.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Struct} properties The changed properties, as a GML struct.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_room_list_update
 * @desc Registers the callback fired when the lobby room list updates. The callback takes no arguments; read the updated list with ${function.photon_realtime_get_room_list_count} and ${function.photon_realtime_get_room_info_by_index}.
 * @param {Function} callback The function to call on a room-list update.
 * @returns {Bool} Whether the callback was set.
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_app_stats_update
 * @desc Registers the callback fired when application statistics update. The callback takes no arguments; read the values with ${function.photon_realtime_get_count_players_online}, ${function.photon_realtime_get_count_players_ingame} and ${function.photon_realtime_get_count_games_running}.
 * @param {Function} callback The function to call on an app-stats update.
 * @returns {Bool} Whether the callback was set.
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_lobby_stats_update
 * @desc Registers the callback fired with lobby statistics updates.
 * @param {Function} callback The function to call on a lobby-stats update.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Array[Struct.PhotonRealtimeLobbyStats]} stats The statistics for each tracked lobby.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_cache_slice_changed
 * @desc Registers the callback fired when the active event-cache slice index changes.
 * @param {Function} callback The function to call on a cache-slice change.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} cache_slice_index The new active cache slice index.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_master_client_changed
 * @desc Registers the callback fired when the room's master client changes.
 * @param {Function} callback The function to call on a master-client change.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} player_number The player number of the new master client.
 * @member {Real} old_player_number The player number of the previous master client.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_properties_change_failed
 * @desc Registers the callback fired when a properties change (for example a compare-and-swap) is rejected by the server. The callback takes no arguments.
 * @param {Function} callback The function to call on a failed properties change.
 * @returns {Bool} Whether the callback was set.
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_custom_authentication_step
 * @desc Registers the callback fired during a multi-step custom authentication flow. Respond with ${function.photon_realtime_operation_custom_auth_next_step}.
 * @param {Function} callback The function to call for each authentication step.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Struct} response_data The intermediate authentication response data, as a GML struct.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_available_regions
 * @desc Registers the callback fired when the list of available regions arrives. Use it to pick a region with ${function.photon_realtime_select_region}.
 * @param {Function} callback The function to call with the available regions.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Array[String]} regions The available region tokens.
 * @member {Array[String]} servers The server address for each region.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_secret_receival
 * @desc Registers the callback fired when the client receives an authentication secret from the server.
 * @param {Function} callback The function to call on secret receival.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {String} secret The authentication secret.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_direct_connection_established
 * @desc Registers the callback fired when a direct (peer-to-peer) connection to another player is established.
 * @param {Function} callback The function to call when a direct connection is established.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} remote_peer_id The peer ID of the remote player.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_direct_connection_failed
 * @desc Registers the callback fired when a direct (peer-to-peer) connection attempt fails.
 * @param {Function} callback The function to call when a direct connection fails.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} remote_peer_id The peer ID of the remote player.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_direct_message
 * @desc Registers the callback fired when a message arrives over a direct (peer-to-peer) connection.
 * @param {Function} callback The function to call on a direct message.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} remote_peer_id The peer ID of the sender.
 * @member {Bool} relay_fallback Whether the message was relayed through the server rather than sent directly.
 * @member {String} message The message payload.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_set_callback_custom_operation_response
 * @desc Registers the callback fired with the response to a custom operation.
 * @param {Function} callback The function to call on a custom operation response.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} operation_code The operation code the response is for.
 * @member {Real} return_code The server's return code.
 * @member {String} debug_message A human-readable debug message.
 * @member {Struct} parameters The response parameters, as a GML struct.
 * @event_end
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_debug
 * @desc Removes the debug callback registered with ${function.photon_realtime_set_callback_debug}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_connected
 * @desc Removes the connected callback registered with ${function.photon_realtime_set_callback_connected}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_disconnected
 * @desc Removes the disconnected callback registered with ${function.photon_realtime_set_callback_disconnected}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_connection_error
 * @desc Removes the connection-error callback registered with ${function.photon_realtime_set_callback_connection_error}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_client_error
 * @desc Removes the client-error callback registered with ${function.photon_realtime_set_callback_client_error}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_server_error
 * @desc Removes the server-error callback registered with ${function.photon_realtime_set_callback_server_error}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_warning
 * @desc Removes the warning callback registered with ${function.photon_realtime_set_callback_warning}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_join_room_event
 * @desc Removes the join-room callback registered with ${function.photon_realtime_set_callback_join_room_event}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_leave_room_event
 * @desc Removes the leave-room callback registered with ${function.photon_realtime_set_callback_leave_room_event}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_custom_event
 * @desc Removes the custom-event callback registered with ${function.photon_realtime_set_callback_custom_event}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_player_properties_change
 * @desc Removes the player-properties-change callback registered with ${function.photon_realtime_set_callback_player_properties_change}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_room_properties_change
 * @desc Removes the room-properties-change callback registered with ${function.photon_realtime_set_callback_room_properties_change}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_room_list_update
 * @desc Removes the room-list-update callback registered with ${function.photon_realtime_set_callback_room_list_update}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_app_stats_update
 * @desc Removes the app-stats-update callback registered with ${function.photon_realtime_set_callback_app_stats_update}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_lobby_stats_update
 * @desc Removes the lobby-stats-update callback registered with ${function.photon_realtime_set_callback_lobby_stats_update}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_cache_slice_changed
 * @desc Removes the cache-slice-changed callback registered with ${function.photon_realtime_set_callback_cache_slice_changed}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_master_client_changed
 * @desc Removes the master-client-changed callback registered with ${function.photon_realtime_set_callback_master_client_changed}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_properties_change_failed
 * @desc Removes the properties-change-failed callback registered with ${function.photon_realtime_set_callback_properties_change_failed}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_custom_authentication_step
 * @desc Removes the custom-authentication-step callback registered with ${function.photon_realtime_set_callback_custom_authentication_step}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_available_regions
 * @desc Removes the available-regions callback registered with ${function.photon_realtime_set_callback_available_regions}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_secret_receival
 * @desc Removes the secret-receival callback registered with ${function.photon_realtime_set_callback_secret_receival}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_direct_connection_established
 * @desc Removes the direct-connection-established callback registered with ${function.photon_realtime_set_callback_direct_connection_established}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_direct_connection_failed
 * @desc Removes the direct-connection-failed callback registered with ${function.photon_realtime_set_callback_direct_connection_failed}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_direct_message
 * @desc Removes the direct-message callback registered with ${function.photon_realtime_set_callback_direct_message}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_realtime_remove_callback_custom_operation_response
 * @desc Removes the custom-operation-response callback registered with ${function.photon_realtime_set_callback_custom_operation_response}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

// STRUCTS

/**
 * @struct PhotonRealtimeConnectOptions
 * @desc Options passed to ${function.photon_realtime_connect}.
 * @member {Struct.PhotonRealtimeAuthenticationValues} [authentication_values] Authentication values for a custom auth provider.
 * @member {String} [username] Display name visible to other players. Separate from the `user_id` in `authentication_values`.
 * @member {String} [server_address] Override the Photon name server address. Leave unset to use the default cloud.
 * @member {Bool} [try_use_datagram_encryption] Whether to attempt datagram encryption for the connection.
 * @member {Bool} [use_background_thread] Whether to use a background send/receive thread. Honored only on Nintendo Switch; ignored on other platforms.
 * @struct_end
 */

/**
 * @struct PhotonRealtimeAuthenticationValues
 * @desc Authentication values for a custom authentication provider.
 * @member {String} [user_id] Unique identifier for this player. Used by Photon for matchmaking and friend lookup.
 * @member {Constant.PhotonRealtimeCustomAuthType} [auth_type] Authentication provider. Defaults to `PhotonRealtimeCustomAuthType.None`.
 * @member {String} [parameters] Token/parameters string passed to the authentication provider.
 * @struct_end
 */

/**
 * @struct PhotonRealtimeRoomOptions
 * @desc Options describing a room to create.
 * @member {Real} [max_players] Maximum number of players allowed in the room (0 for unlimited).
 * @member {Bool} [is_visible] Whether the room is listed in the lobby.
 * @member {Bool} [is_open] Whether the room accepts new players.
 * @member {String} [lobby_name] The lobby the room belongs to.
 * @member {Constant.PhotonRealtimeLobbyType} [lobby_type] The type of the room's lobby.
 * @member {Real} [player_ttl] How long (ms) an inactive player is kept before being removed.
 * @member {Real} [empty_room_ttl] How long (ms) an empty room is kept alive before being removed.
 * @member {Bool} [suppress_room_events] Whether to suppress join/leave events for the room.
 * @member {Bool} [publish_user_id] Whether player user IDs are visible to others in the room.
 * @member {Array[String]} lobby_keys The custom-property keys exposed to the lobby for matchmaking.
 * @member {Array[String]} expected_users User IDs reserved a slot in the room.
 * @struct_end
 */

/**
 * @struct PhotonRealtimeJoinRoomOptions
 * @desc Options passed to ${function.photon_realtime_operation_join_room}.
 * @member {Bool} [rejoin] Whether to rejoin as a previously-inactive actor.
 * @member {Real} [cache_slice_index] The event-cache slice index to fetch on join.
 * @struct_end
 */

/**
 * @struct PhotonRealtimeJoinRandomOptions
 * @desc Options describing random-room matchmaking.
 * @member {Real} [max_players] Only match rooms with this maximum player count.
 * @member {Constant.PhotonRealtimeMatchmakingMode} [matchmaking_mode] How rooms are filled during matchmaking.
 * @member {String} [lobby_name] The lobby to match within.
 * @member {Constant.PhotonRealtimeLobbyType} [lobby_type] The type of lobby to match within.
 * @member {String} [sql_filter] An SQL-style filter applied when using an SQL lobby.
 * @member {Array[String]} expected_users User IDs reserved a slot in the matched room.
 * @struct_end
 */

/**
 * @struct PhotonRealtimeRaiseEventOptions
 * @desc Targeting and caching options for raised events.
 * @member {Constant.PhotonRealtimeReceiverGroup} [receiver_group] Which group of players receives the event.
 * @member {Real} [interest_group] The interest group the event belongs to.
 * @member {Constant.PhotonRealtimeEventCache} [event_cache] How the event is cached on the server.
 * @member {Real} [channel_id] The sequencing channel to send on.
 * @member {Real} [cache_slice_index] The cache slice index to target.
 * @member {Bool} [encrypt] Whether to encrypt the event payload.
 * @member {Array[Real]} target_players Target specific player numbers. An empty array broadcasts to `receiver_group` (default: `Others`).
 * @struct_end
 */

/**
 * @struct PhotonRealtimeEventBufferReceived
 * @desc Describes a binary event read with ${function.photon_realtime_receive_one_event_buffer}.
 * @member {Bool} ok Whether an event was successfully read.
 * @member {Real} player_number The sender's player number.
 * @member {Real} event_code The event's custom event code.
 * @member {Real} bytes_written The number of bytes written into the output buffer.
 * @struct_end
 */

/**
 * @struct PhotonRealtimeRoomInfo
 * @desc A snapshot of a single room in the lobby room list.
 * @member {String} name The room's name.
 * @member {Real} player_count The current number of players in the room.
 * @member {Real} max_players The room's maximum player count.
 * @member {Bool} is_open Whether the room is open to new players.
 * @member {Struct} custom_properties The room's lobby-exposed custom properties, as a GML struct.
 * @struct_end
 */

/**
 * @struct PhotonRealtimeFriendInfo
 * @desc A friend-status entry delivered by ${function.photon_realtime_operation_find_friends}.
 * @member {String} user_id The friend's user ID.
 * @member {Bool} is_online Whether the friend is currently online.
 * @member {String} room The room the friend is in, if any.
 * @member {Bool} is_in_room Whether the friend is currently in a room.
 * @struct_end
 */

/**
 * @struct PhotonRealtimeLobbyStats
 * @desc A statistics entry for a single lobby, delivered by ${function.photon_realtime_operation_lobby_stats} and the lobby-stats-update callback.
 * @member {String} name The lobby's name.
 * @member {Constant.PhotonRealtimeLobbyType} type The lobby's type.
 * @member {Real} peer_count The number of players in the lobby.
 * @member {Real} room_count The number of rooms in the lobby.
 * @struct_end
 */

// CONSTANTS

/**
 * @const PhotonRealtimeState
 * @desc The states the Realtime client moves through, returned by ${function.photon_realtime_get_state}.
 * @member Unknown Unknown state.
 * @member Uninitialized The client has not been initialised.
 * @member PeerCreated The peer has been created but is not connecting.
 * @member ConnectingToNameserver Connecting to the name server.
 * @member ConnectedToNameserver Connected to the name server.
 * @member DisconnectingFromNameserver Disconnecting from the name server.
 * @member Connecting Connecting to the master server.
 * @member Connected Connected to the master server.
 * @member WaitingForCustomAuthNextStep Waiting on the next custom authentication step.
 * @member Authenticated Authenticated on the master server.
 * @member JoinedLobby Joined a matchmaking lobby.
 * @member DisconnectingFromMasterserver Disconnecting from the master server.
 * @member ConnectingToGameserver Connecting to a game server.
 * @member ConnectedToGameserver Connected to a game server.
 * @member AuthenticatedOnGameServer Authenticated on the game server.
 * @member Joining Joining a room.
 * @member Joined Joined a room.
 * @member Leaving Leaving a room.
 * @member Left Left a room.
 * @member DisconnectingFromGameserver Disconnecting from the game server.
 * @member ConnectingToMasterserver Connecting back to the master server.
 * @member ConnectedComingFromGameserver Connected to the master server after leaving a game server.
 * @member AuthenticatedComingFromGameserver Authenticated on the master server after leaving a game server.
 * @member Disconnecting Disconnecting.
 * @member Disconnected Fully disconnected.
 * @const_end
 */

/**
 * @const PhotonRealtimeDisconnectCause
 * @desc The reasons a client can be disconnected, returned by ${function.photon_realtime_get_disconnected_cause}.
 * @member Unknown Unknown cause.
 * @member None No disconnect.
 * @member ServerUserLimit The server's user limit was reached.
 * @member ExceptionOnConnect An exception occurred while connecting.
 * @member DisconnectByServer The server closed the connection.
 * @member DisconnectByServerLogic Server-side logic closed the connection.
 * @member TimeoutDisconnect The connection timed out.
 * @member Exception A client-side exception occurred.
 * @member InvalidAuthentication Authentication was invalid.
 * @member MaxCcuReached The application's maximum concurrent-user limit was reached.
 * @member InvalidRegion The requested region was invalid.
 * @member OperationNotAllowed An operation was not allowed in the current state.
 * @member CustomAuthenticationFailed Custom authentication failed.
 * @member ClientVersionTooOld The client version is too old.
 * @member ClientVersionInvalid The client version is invalid.
 * @member DashboardVersionInvalid The dashboard-configured version is invalid.
 * @member AuthenticationTicketExpired The authentication ticket expired.
 * @member OperationLimit An operation limit was exceeded.
 * @const_end
 */

/**
 * @const PhotonRealtimeAppErrorCode
 * @desc Application-level result codes reported by operations and the connected callback.
 * @member Ok The operation succeeded.
 * @member InvalidAuthentication Authentication was invalid.
 * @member GameIdAlreadyExists A room with that name already exists.
 * @member GameFull The room is full.
 * @member GameClosed The room is closed.
 * @member AlreadyMatched The client is already matched.
 * @member ServerFull The server is full.
 * @member UserBlocked The user is blocked.
 * @member NoMatchFound No matching room was found.
 * @member GameDoesNotExist The room does not exist.
 * @member MaxCcuReached The maximum concurrent-user limit was reached.
 * @member InvalidRegion The region was invalid.
 * @member CustomAuthenticationFailed Custom authentication failed.
 * @member AuthTicketExpired The authentication ticket expired.
 * @member PluginReportedError A server plugin reported an error.
 * @member PluginMismatch A server plugin mismatch occurred.
 * @member JoinFailedPeerAlreadyJoined Join failed: the peer already joined.
 * @member JoinFailedFoundInactiveJoiner Join failed: an inactive joiner was found.
 * @member JoinFailedRejoinNotFound Join failed: no actor to rejoin was found.
 * @member JoinFailedFoundExcludedUserId Join failed: the user ID is excluded.
 * @member JoinFailedFoundActiveJoiner Join failed: an active joiner was found.
 * @member HttpLimitReached The HTTP request limit was reached.
 * @member ExternalHttpCallFailed An external HTTP call failed.
 * @member OperationLimitReached An operation limit was reached.
 * @member SlotError A slot-reservation error occurred.
 * @member InvalidEncryptionParameters The encryption parameters were invalid.
 * @member ClientVersionTooOld The client version is too old.
 * @member ClientVersionInvalid The client version is invalid.
 * @member DashboardVersionInvalid The dashboard-configured version is invalid.
 * @const_end
 */

/**
 * @const PhotonRealtimeLobbyType
 * @desc The types of matchmaking lobby.
 * @member Default The default lobby.
 * @member SqlLobby An SQL-filterable lobby.
 * @member AsyncRandomLobby An asynchronous random-matchmaking lobby.
 * @const_end
 */

/**
 * @const PhotonRealtimeMatchmakingMode
 * @desc How rooms are filled during random matchmaking.
 * @member FillRoom Fill rooms to capacity before starting new ones.
 * @member SerialMatching Match rooms serially.
 * @member RandomMatching Match into a random room.
 * @const_end
 */

/**
 * @const PhotonRealtimeReceiverGroup
 * @desc Which players receive a raised event.
 * @member Others All players except the sender.
 * @member All All players including the sender.
 * @member MasterClient Only the room's master client.
 * @const_end
 */

/**
 * @const PhotonRealtimeEventCache
 * @desc How a raised event is cached on the server.
 * @member DoNotCache Do not cache the event.
 * @member MergeCache Merge the event into the cache.
 * @member ReplaceCache Replace the cached event.
 * @member RemoveCache Remove the event from the cache.
 * @member AddToRoomCache Add the event to the room cache.
 * @member AddToRoomCacheGlobal Add the event to the global room cache.
 * @member RemoveFromRoomCache Remove the event from the room cache.
 * @member RemoveFromRoomCacheForActorsLeft Remove cached events for actors that have left.
 * @member SliceIncIndex Increment the cache slice index.
 * @member SliceSetIndex Set the cache slice index.
 * @member SlicePurgeIndex Purge a specific cache slice.
 * @member SlicePurgeUpToIndex Purge cache slices up to an index.
 * @const_end
 */

/**
 * @const PhotonRealtimeCustomAuthType
 * @desc The custom authentication providers supported by Photon.
 * @member Custom A custom authentication service.
 * @member Steam Steam authentication.
 * @member Facebook Facebook authentication.
 * @member Oculus Oculus authentication.
 * @member PlayStation4 PlayStation 4 authentication.
 * @member Xbox Xbox authentication.
 * @member Viveport Viveport authentication.
 * @member NintendoSwitch Nintendo Switch authentication.
 * @member PlayStation5 PlayStation 5 authentication.
 * @member Epic Epic authentication.
 * @member FacebookGaming Facebook Gaming authentication.
 * @member None No custom authentication.
 * @const_end
 */

/**
 * @const PhotonRealtimeDirectMode
 * @desc The direct (peer-to-peer) connection modes.
 * @member None No direct connections.
 * @member AllToOthers Every client connects directly to every other.
 * @member MasterToOthers The master client connects directly to the others.
 * @member AllToAll All clients connect directly to all clients.
 * @member MasterToAll The master client connects directly to all clients.
 * @const_end
 */

/**
 * @const PhotonRealtimeRegionSelectionMode
 * @desc How the connection region is selected.
 * @member Default Use the default region behaviour.
 * @member Select Use an explicitly selected region.
 * @member Best Use the region with the best ping.
 * @const_end
 */

/**
 * @const PhotonRealtimeServerType
 * @desc The Photon server types.
 * @member NameServer The name server.
 * @member MasterServer The master server.
 * @const_end
 */

/**
 * @const PhotonRealtimeLBOperationCode
 * @desc The LoadBalancing operation codes. Primarily useful when interpreting custom operation responses.
 * @member Leave Leave a room.
 * @member RaiseEvent Raise an event.
 * @member SetProperties Set properties.
 * @member GetProperties Get properties.
 * @member ChangeGroups Change interest groups.
 * @member AuthOnce Authenticate once.
 * @member Authenticate Authenticate.
 * @member JoinLobby Join a lobby.
 * @member LeaveLobby Leave a lobby.
 * @member CreateRoom Create a room.
 * @member JoinRoom Join a room.
 * @member JoinRandomRoom Join a random room.
 * @member FindFriends Find friends.
 * @member LobbyStats Request lobby stats.
 * @member GetRegions Get available regions.
 * @member Rpc Call a WebRPC.
 * @member GetRoomList Get a room list.
 * @const_end
 */

/**
 * @const PhotonRealtimeLBEventCode
 * @desc The LoadBalancing event codes. Primarily useful when interpreting incoming events.
 * @member Join A player joined.
 * @member Leave A player left.
 * @member PropertiesChanged Properties changed.
 * @member ErrorInfo Error information from the server.
 * @member CacheSliceChanged The cache slice changed.
 * @member RoomList A room list was received.
 * @member RoomListUpdate A room list update was received.
 * @member AppStats Application statistics were received.
 * @member LobbyStats Lobby statistics were received.
 * @member Auth An authentication event.
 * @member PunchMsg A NAT-punchthrough message.
 * @member VoiceFrameData Voice frame data.
 * @member VoiceData Voice data.
 * @member MaxCustomEvCode The highest reserved event code; custom codes must stay below it.
 * @const_end
 */

// MODULES

/**
 * @module realtime
 * @title Realtime
 * @desc The Realtime module is the core of the extension: it connects to the Photon Cloud, joins matchmaking lobbies and rooms, and sends and receives events between players. Player and room custom properties have their own modules (${module.realtime_player_properties} and ${module.realtime_room_properties}), and connection diagnostics live in ${module.realtime_peer}.
 *
 * [[NOTE: After connecting you must call ${function.photon_realtime_service} every step for the client to send and receive.]]
 *
 * @section_func Lifecycle
 * @desc Initialise, connect, and service the client:
 * @ref photon_realtime_init
 * @ref photon_realtime_shutdown
 * @ref photon_realtime_service
 * @ref photon_realtime_connect
 * @ref photon_realtime_disconnect
 * @ref photon_realtime_select_region
 * @ref photon_realtime_reconnect_and_rejoin
 * @ref photon_realtime_fetch_server_timestamp
 * @section_end
 *
 * @section_func Lobby & room operations
 * @desc Join lobbies, and create, join and leave rooms:
 * @ref photon_realtime_operation_join_lobby
 * @ref photon_realtime_operation_leave_lobby
 * @ref photon_realtime_operation_create_room
 * @ref photon_realtime_operation_join_or_create_room
 * @ref photon_realtime_operation_join_room
 * @ref photon_realtime_operation_join_random_room
 * @ref photon_realtime_operation_join_random_or_create_room
 * @ref photon_realtime_operation_leave_room
 * @ref photon_realtime_operation_get_room_list
 * @ref photon_realtime_operation_lobby_stats
 * @ref photon_realtime_operation_find_friends
 * @ref photon_realtime_operation_web_rpc
 * @ref photon_realtime_operation_change_groups
 * @ref photon_realtime_operation_custom_auth_next_step
 * @section_end
 *
 * @section_func Sending & receiving events
 * @desc Raise custom events and read buffered binary events:
 * @ref photon_realtime_operation_raise_event_string
 * @ref photon_realtime_operation_raise_event_buffer
 * @ref photon_realtime_get_buffer_event_queue_count
 * @ref photon_realtime_clear_buffer_event_queue
 * @ref photon_realtime_peek_next_buffer_event_size
 * @ref photon_realtime_peek_next_buffer_event_code
 * @ref photon_realtime_peek_next_buffer_event_player_number
 * @ref photon_realtime_receive_one_event_buffer
 * @section_end
 *
 * @section_func State & info
 * @desc Query connection and room state:
 * @ref photon_realtime_is_initialized
 * @ref photon_realtime_is_connected
 * @ref photon_realtime_is_in_game_room
 * @ref photon_realtime_is_in_room
 * @ref photon_realtime_is_in_lobby
 * @ref photon_realtime_get_current_room_name
 * @ref photon_realtime_get_local_player_number
 * @ref photon_realtime_get_server_time_offset
 * @ref photon_realtime_get_server_time
 * @ref photon_realtime_get_bytes_in
 * @ref photon_realtime_get_bytes_out
 * @ref photon_realtime_get_state
 * @ref photon_realtime_get_round_trip_time
 * @ref photon_realtime_get_round_trip_time_variance
 * @ref photon_realtime_get_disconnected_cause
 * @ref photon_realtime_get_user_id
 * @ref photon_realtime_get_count_players_ingame
 * @ref photon_realtime_get_count_games_running
 * @ref photon_realtime_get_count_players_online
 * @ref photon_realtime_get_master_server_address
 * @ref photon_realtime_get_region
 * @ref photon_realtime_get_region_with_best_ping
 * @ref photon_realtime_get_friend_list_age
 * @section_end
 *
 * @section_func Settings
 * @desc Tune connection behaviour:
 * @ref photon_realtime_get_disconnect_timeout
 * @ref photon_realtime_set_disconnect_timeout
 * @ref photon_realtime_get_ping_interval
 * @ref photon_realtime_set_ping_interval
 * @ref photon_realtime_get_auto_join_lobby
 * @ref photon_realtime_set_auto_join_lobby
 * @section_end
 *
 * @section_func Room & player info
 * @desc Query the current room and its players:
 * @ref photon_realtime_get_room_player_count
 * @ref photon_realtime_get_room_max_players
 * @ref photon_realtime_get_room_is_open
 * @ref photon_realtime_get_room_is_visible
 * @ref photon_realtime_get_master_client_number
 * @ref photon_realtime_set_master_client
 * @ref photon_realtime_get_room_list_count
 * @ref photon_realtime_get_room_info_by_index
 * @ref photon_realtime_get_player_count
 * @ref photon_realtime_get_player_number_by_index
 * @ref photon_realtime_player_get_name
 * @ref photon_realtime_player_get_user_id
 * @ref photon_realtime_player_is_inactive
 * @ref photon_realtime_player_is_master_client
 * @ref photon_realtime_get_player_numbers
 * @section_end
 *
 * @section_func Callbacks
 * @desc Register and remove the event callbacks:
 * @ref photon_realtime_set_callback_debug
 * @ref photon_realtime_set_callback_connected
 * @ref photon_realtime_set_callback_disconnected
 * @ref photon_realtime_set_callback_connection_error
 * @ref photon_realtime_set_callback_client_error
 * @ref photon_realtime_set_callback_server_error
 * @ref photon_realtime_set_callback_warning
 * @ref photon_realtime_set_callback_join_room_event
 * @ref photon_realtime_set_callback_leave_room_event
 * @ref photon_realtime_set_callback_custom_event
 * @ref photon_realtime_set_callback_player_properties_change
 * @ref photon_realtime_set_callback_room_properties_change
 * @ref photon_realtime_set_callback_room_list_update
 * @ref photon_realtime_set_callback_app_stats_update
 * @ref photon_realtime_set_callback_lobby_stats_update
 * @ref photon_realtime_set_callback_cache_slice_changed
 * @ref photon_realtime_set_callback_master_client_changed
 * @ref photon_realtime_set_callback_properties_change_failed
 * @ref photon_realtime_set_callback_custom_authentication_step
 * @ref photon_realtime_set_callback_available_regions
 * @ref photon_realtime_set_callback_secret_receival
 * @ref photon_realtime_set_callback_direct_connection_established
 * @ref photon_realtime_set_callback_direct_connection_failed
 * @ref photon_realtime_set_callback_direct_message
 * @ref photon_realtime_set_callback_custom_operation_response
 * @ref photon_realtime_remove_callback_debug
 * @ref photon_realtime_remove_callback_connected
 * @ref photon_realtime_remove_callback_disconnected
 * @ref photon_realtime_remove_callback_connection_error
 * @ref photon_realtime_remove_callback_client_error
 * @ref photon_realtime_remove_callback_server_error
 * @ref photon_realtime_remove_callback_warning
 * @ref photon_realtime_remove_callback_join_room_event
 * @ref photon_realtime_remove_callback_leave_room_event
 * @ref photon_realtime_remove_callback_custom_event
 * @ref photon_realtime_remove_callback_player_properties_change
 * @ref photon_realtime_remove_callback_room_properties_change
 * @ref photon_realtime_remove_callback_room_list_update
 * @ref photon_realtime_remove_callback_app_stats_update
 * @ref photon_realtime_remove_callback_lobby_stats_update
 * @ref photon_realtime_remove_callback_cache_slice_changed
 * @ref photon_realtime_remove_callback_master_client_changed
 * @ref photon_realtime_remove_callback_properties_change_failed
 * @ref photon_realtime_remove_callback_custom_authentication_step
 * @ref photon_realtime_remove_callback_available_regions
 * @ref photon_realtime_remove_callback_secret_receival
 * @ref photon_realtime_remove_callback_direct_connection_established
 * @ref photon_realtime_remove_callback_direct_connection_failed
 * @ref photon_realtime_remove_callback_direct_message
 * @ref photon_realtime_remove_callback_custom_operation_response
 * @section_end
 *
 * @section_struct Structs
 * @desc The Realtime module uses the following structs:
 * @ref PhotonRealtimeConnectOptions
 * @ref PhotonRealtimeAuthenticationValues
 * @ref PhotonRealtimeRoomOptions
 * @ref PhotonRealtimeJoinRoomOptions
 * @ref PhotonRealtimeJoinRandomOptions
 * @ref PhotonRealtimeRaiseEventOptions
 * @ref PhotonRealtimeEventBufferReceived
 * @ref PhotonRealtimeRoomInfo
 * @ref PhotonRealtimeFriendInfo
 * @ref PhotonRealtimeLobbyStats
 * @section_end
 *
 * @section_const Constants
 * @desc The Realtime module defines the following constants:
 * @ref PhotonRealtimeState
 * @ref PhotonRealtimeDisconnectCause
 * @ref PhotonRealtimeAppErrorCode
 * @ref PhotonRealtimeLobbyType
 * @ref PhotonRealtimeMatchmakingMode
 * @ref PhotonRealtimeReceiverGroup
 * @ref PhotonRealtimeEventCache
 * @ref PhotonRealtimeCustomAuthType
 * @ref PhotonRealtimeDirectMode
 * @ref PhotonRealtimeRegionSelectionMode
 * @ref PhotonRealtimeServerType
 * @ref PhotonRealtimeLBOperationCode
 * @ref PhotonRealtimeLBEventCode
 * @section_end
 *
 * @module_end
 */
