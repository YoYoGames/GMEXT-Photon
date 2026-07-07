/**
 * @function_partial photon_realtime_init
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_shutdown
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_service
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_connect
 * @param {String} app_id
 * @param {String} app_version
 * @param {Struct.PhotonRealtimeConnectOptions} [options]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_disconnect
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_select_region
 * @param {String} region
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_reconnect_and_rejoin
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_fetch_server_timestamp
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_join_lobby
 * @param {String} lobby_name
 * @param {Enum.PhotonRealtimeLobbyType} lobby_type
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_leave_lobby
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_create_room
 * @param {String} room_name
 * @param {Struct.PhotonRealtimeRoomOptions} options
 * @param {Struct} custom_properties
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_join_or_create_room
 * @param {String} room_name
 * @param {Struct.PhotonRealtimeRoomOptions} options
 * @param {Struct} custom_properties
 * @param {Real} [cache_slice_index]
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_join_room
 * @param {String} room_name
 * @param {Struct.PhotonRealtimeJoinRoomOptions} options
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_join_random_room
 * @param {Struct.PhotonRealtimeJoinRandomOptions} options
 * @param {Struct} expected_properties
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_leave_room
 * @param {Bool} will_come_back
 * @param {Bool} send_authentication_cookie
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_join_random_or_create_room
 * @param {String} room_name
 * @param {Struct.PhotonRealtimeRoomOptions} options
 * @param {Struct} custom_properties
 * @param {Struct.PhotonRealtimeJoinRandomOptions} random_options
 * @param {Struct} expected_properties
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_get_room_list
 * @param {String} lobby_name
 * @param {String} sql_filter
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_lobby_stats
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_find_friends
 * @param {Array[String]} friends
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_web_rpc
 * @param {String} uri_path
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_change_groups
 * @param {Array[Real]} [groups_to_remove]
 * @param {Array[Real]} [groups_to_add]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_custom_auth_next_step
 * @param {Struct.PhotonRealtimeAuthenticationValues} authentication
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_raise_event_string
 * @param {Bool} reliable
 * @param {String} payload
 * @param {Real} event_code
 * @param {Struct.PhotonRealtimeRaiseEventOptions} [options]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_operation_raise_event_buffer
 * @param {Bool} reliable
 * @param {Buffer} data
 * @param {Real} bytes
 * @param {Real} event_code
 * @param {Struct.PhotonRealtimeRaiseEventOptions} [options]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_buffer_event_queue_count
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_clear_buffer_event_queue
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peek_next_buffer_event_size
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peek_next_buffer_event_code
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_receive_one_event_buffer
 * @param {Buffer} out_data
 * @param {Real} max_bytes
 * @param {Real} offset
 * @returns {Struct.PhotonRealtimeEventBufferReceived}
 * @function_end
 */

/**
 * @function_partial photon_realtime_is_initialized
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_is_connected
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_is_in_game_room
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_is_in_room
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_is_in_lobby
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_current_room_name
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_local_player_number
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_server_time_offset
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_server_time
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_bytes_in
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_bytes_out
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_state
 * @returns {Enum.PhotonRealtimeState}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_round_trip_time
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_round_trip_time_variance
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_disconnected_cause
 * @returns {Enum.PhotonRealtimeDisconnectCause}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_user_id
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_count_players_ingame
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_count_games_running
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_count_players_online
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_master_server_address
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_region
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_region_with_best_ping
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_friend_list_age
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_disconnect_timeout
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_disconnect_timeout
 * @param {Real} milliseconds
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_ping_interval
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_ping_interval
 * @param {Real} milliseconds
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_auto_join_lobby
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_auto_join_lobby
 * @param {Bool} enabled
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_room_player_count
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_room_max_players
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_room_is_open
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_room_is_visible
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_master_client_number
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_master_client
 * @param {Real} player_number
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_room_list_count
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_room_info_by_index
 * @param {Real} index
 * @returns {Struct.PhotonRealtimeRoomInfo}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_player_count
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_player_number_by_index
 * @param {Real} index
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_get_name
 * @param {Real} player_number
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_get_user_id
 * @param {Real} player_number
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_is_inactive
 * @param {Real} player_number
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_is_master_client
 * @param {Real} player_number
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_get_player_numbers
 * @returns {Array[Real]}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_debug
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_connected
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_disconnected
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_connection_error
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_client_error
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_server_error
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_warning
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_join_room_event
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_leave_room_event
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_custom_event
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_room_properties_change
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_player_properties_change
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_room_list_update
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_app_stats_update
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_lobby_stats_update
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_cache_slice_changed
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_master_client_changed
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_properties_change_failed
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_custom_authentication_step
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_available_regions
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_secret_receival
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_direct_connection_established
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_direct_connection_failed
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_direct_message
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_set_callback_custom_operation_response
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_debug
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_connected
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_disconnected
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_connection_error
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_client_error
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_server_error
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_warning
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_join_room_event
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_leave_room_event
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_custom_event
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_room_properties_change
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_player_properties_change
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_room_list_update
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_app_stats_update
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_lobby_stats_update
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_cache_slice_changed
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_master_client_changed
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_properties_change_failed
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_custom_authentication_step
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_available_regions
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_secret_receival
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_direct_connection_established
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_direct_connection_failed
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_direct_message
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_remove_callback_custom_operation_response
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_set_string
 * @param {String} key
 * @param {String} value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_set_i32
 * @param {String} key
 * @param {Real} value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_set_f64
 * @param {String} key
 * @param {Real} value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_set_bool
 * @param {String} key
 * @param {Bool} value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_remove
 * @param {String} key
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_clear
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_has
 * @param {String} key
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_get_string
 * @param {String} key
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_get_i32
 * @param {String} key
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_get_f64
 * @param {String} key
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_get_bool
 * @param {String} key
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_to_string
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_get_all
 * @returns {Struct}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_cas_string
 * @param {String} key
 * @param {String} expected_value
 * @param {String} new_value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_cas_i32
 * @param {String} key
 * @param {Real} expected_value
 * @param {Real} new_value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_cas_f64
 * @param {String} key
 * @param {Real} expected_value
 * @param {Real} new_value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_room_properties_cas_bool
 * @param {String} key
 * @param {Bool} expected_value
 * @param {Bool} new_value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_set_local_string
 * @param {String} key
 * @param {String} value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_set_local_i32
 * @param {String} key
 * @param {Real} value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_set_local_f64
 * @param {String} key
 * @param {Real} value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_set_local_bool
 * @param {String} key
 * @param {Bool} value
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_remove_local
 * @param {String} key
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_clear_local
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_has_local
 * @param {String} key
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_local_string
 * @param {String} key
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_local_i32
 * @param {String} key
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_local_f64
 * @param {String} key
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_local_bool
 * @param {String} key
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_to_string_local
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_local_all
 * @returns {Struct}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_has_remote
 * @param {Real} player_number
 * @param {String} key
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_remote_string
 * @param {Real} player_number
 * @param {String} key
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_remote_i32
 * @param {Real} player_number
 * @param {String} key
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_remote_f64
 * @param {Real} player_number
 * @param {String} key
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_remote_bool
 * @param {Real} player_number
 * @param {String} key
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_to_string_remote
 * @param {Real} player_number
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_realtime_player_properties_get_remote_all
 * @param {Real} player_number
 * @returns {Struct}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peek_next_buffer_event_player_number
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_init
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_shutdown
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_service
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_select_region
 * @param {String} region
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_connect
 * @param {String} app_id
 * @param {String} app_version
 * @param {Struct.PhotonChatConnectOptions} [options]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_disconnect
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_operation_subscribe
 * @param {Array[String]} channels
 * @param {Real} [messages_from_history]
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_operation_unsubscribe
 * @param {Array[String]} channels
 * @param {Function} [callback]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_operation_publish_message
 * @param {String} channel_name
 * @param {String} message
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_operation_send_private_message
 * @param {String} user_name
 * @param {String} message
 * @param {Bool} [encrypt]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_operation_set_online_status
 * @param {Enum.PhotonChatUserStatus} status
 * @param {String} [message]
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_operation_add_friends
 * @param {Array[String]} user_ids
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_operation_remove_friends
 * @param {Array[String]} user_ids
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_is_initialized
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_is_connected
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_state
 * @returns {Enum.PhotonChatState}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_disconnect_cause
 * @returns {Enum.PhotonChatDisconnectCause}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_user_id
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_region
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_server_time
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_server_time_offset
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_bytes_in
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_bytes_out
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_channel_count
 * @param {Enum.PhotonChatChannelType} channel_type
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_channel_name
 * @param {Enum.PhotonChatChannelType} channel_type
 * @param {Real} index
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_channel_message_count
 * @param {Enum.PhotonChatChannelType} channel_type
 * @param {String} channel_name
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_channel_message
 * @param {Enum.PhotonChatChannelType} channel_type
 * @param {String} channel_name
 * @param {Real} index
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_channel_sender
 * @param {Enum.PhotonChatChannelType} channel_type
 * @param {String} channel_name
 * @param {Real} index
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_debug
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_connected
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_state_change
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_connection_error
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_client_error
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_warning
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_server_error
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_disconnected
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_status_update
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_get_messages
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_private_message
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_set_callback_receive_broadcast
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_get_broadcast_queue_count
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_clear_broadcast_queue
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_peek_next_broadcast_size
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peek_next_broadcast_channel
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_chat_receive_one_broadcast_buffer
 * @param {Buffer} out_data
 * @param {Real} max_bytes
 * @param {Real} offset
 * @returns {Struct.PhotonRealtimeEventBufferReceived}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_debug
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_connected
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_state_change
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_connection_error
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_client_error
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_warning
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_server_error
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_disconnected
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_status_update
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_get_messages
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_private_message
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_remove_callback_receive_broadcast
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_init
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_shutdown
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_service
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_is_initialized
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_notify_joined_room
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_on_join_channel
 * @param {Real} channel_id
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_on_leave_channel
 * @param {Real} channel_id
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_on_join_all_channels
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_on_leave_all_channels
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_on_player_join
 * @param {Real} channel_id
 * @param {Real} player_id
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_on_player_leave
 * @param {Real} channel_id
 * @param {Real} player_id
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_create_local_voice
 * @param {Real} channel_id
 * @param {Enum.PhotonVoiceCodec} codec
 * @param {Real} sample_rate
 * @param {Real} channels
 * @param {Real} bitrate
 * @param {Real} frames_per_packet
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_remove_local_voice
 * @param {Real} voice_id
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_push_frame_buffer
 * @param {Real} voice_id
 * @param {Buffer} data
 * @param {Real} bytes
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_frame_queue_count
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_clear_frame_queue
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_peek_next_frame_size
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_peek_next_frame_player_id
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_peek_next_frame_voice_id
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_receive_frame_buffer
 * @param {Buffer} out_data
 * @param {Real} max_bytes
 * @param {Real} offset
 * @returns {Struct.PhotonRealtimeEventBufferReceived}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_remote_voice_count
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_remote_voice_player_id
 * @param {Real} index
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_remote_voice_id
 * @param {Real} index
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_remote_voice_codec
 * @param {Real} index
 * @returns {Enum.PhotonVoiceCodec}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_remote_voice_sample_rate
 * @param {Real} index
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_remote_voice_channels
 * @param {Real} index
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_remote_voice_is_speaking
 * @param {Real} index
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_frames_sent
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_frames_received
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_frames_lost
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_round_trip_time
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_round_trip_time_variance
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_set_callback_remote_voice_added
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_set_callback_remote_voice_removed
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_set_callback_speaking_changed
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_set_callback_debug
 * @param {Function} callback
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_remove_callback_remote_voice_added
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_remove_callback_remote_voice_removed
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_remove_callback_speaking_changed
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_remove_callback_debug
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_local_voice_set_transmit
 * @param {Real} voice_id
 * @param {Bool} enabled
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_local_voice_get_transmit
 * @param {Real} voice_id
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_set_remote_player_muted
 * @param {Real} player_id
 * @param {Bool} muted
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_remote_player_muted
 * @param {Real} player_id
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_set_remote_player_volume
 * @param {Real} player_id
 * @param {Real} volume
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_remote_player_volume
 * @param {Real} player_id
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_debug_lost_percent
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_set_debug_lost_percent
 * @param {Real} percent
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_voice_get_speaking_threshold_ms
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_voice_set_speaking_threshold_ms
 * @param {Real} ms
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_state
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_round_trip_time
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_round_trip_time_variance
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_bytes_in
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_bytes_out
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_queued_incoming_commands
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_queued_outgoing_commands
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_debug_output_level
 * @returns {Enum.PhotonCommonDebugLevel}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_set_debug_output_level
 * @param {Enum.PhotonCommonDebugLevel} level
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_disconnect_timeout
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_set_disconnect_timeout
 * @param {Real} timeout_ms
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_time_ping_interval
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_set_time_ping_interval
 * @param {Real} interval_ms
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_crc_enabled
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_set_crc_enabled
 * @param {Bool} enabled
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_packet_loss_by_crc
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_get_timestamp_of_last_socket_receive
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_realtime_peer_reset_traffic_stats
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_state
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_round_trip_time
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_round_trip_time_variance
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_bytes_in
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_bytes_out
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_queued_incoming_commands
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_queued_outgoing_commands
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_debug_output_level
 * @returns {Enum.PhotonCommonDebugLevel}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_set_debug_output_level
 * @param {Enum.PhotonCommonDebugLevel} level
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_disconnect_timeout
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_set_disconnect_timeout
 * @param {Real} timeout_ms
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_time_ping_interval
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_set_time_ping_interval
 * @param {Real} interval_ms
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_crc_enabled
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_set_crc_enabled
 * @param {Bool} enabled
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_packet_loss_by_crc
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_get_timestamp_of_last_socket_receive
 * @returns {Real}
 * @function_end
 */

/**
 * @function_partial photon_chat_peer_reset_traffic_stats
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_peer_network_sim_get_enabled
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_peer_network_sim_set_enabled
 * @param {Bool} enabled
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_peer_network_sim_set_lag
 * @param {Real} incoming_ms
 * @param {Real} outgoing_ms
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_peer_network_sim_set_jitter
 * @param {Real} incoming_ms
 * @param {Real} outgoing_ms
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_peer_network_sim_set_packet_loss
 * @param {Real} incoming_pct
 * @param {Real} outgoing_pct
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_common_set_debug_level
 * @param {Enum.PhotonCommonDebugLevel} level
 * @returns {Bool}
 * @function_end
 */

/**
 * @function_partial photon_common_get_debug_level
 * @returns {Enum.PhotonCommonDebugLevel}
 * @function_end
 */

/**
 * @function_partial photon_common_get_serialization_protocol
 * @returns {Enum.PhotonCommonSerializationProtocol}
 * @function_end
 */

/**
 * @function_partial photon_common_type_code_to_string
 * @param {Enum.PhotonCommonTypeCode} type_code
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_common_get_sdk_version
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_common_client_state_to_string
 * @param {Real} state
 * @returns {String}
 * @function_end
 */

/**
 * @function_partial photon_common_disconnect_cause_to_string
 * @param {Real} cause
 * @returns {String}
 * @function_end
 */

/**
 * @struct_partial PhotonRealtimeEventBufferReceived
 * @member {Bool} ok
 * @member {Real} player_number
 * @member {Real} event_code
 * @member {Real} bytes_written
 * @struct_end
 */

/**
 * @struct_partial PhotonRealtimeJoinRandomOptions
 * @member {Real} [max_players]
 * @member {Enum.PhotonRealtimeMatchmakingMode} [matchmaking_mode]
 * @member {String} [lobby_name]
 * @member {Enum.PhotonRealtimeLobbyType} [lobby_type]
 * @member {String} [sql_filter]
 * @member {Array[String]} expected_users
 * @struct_end
 */

/**
 * @struct_partial PhotonRealtimeRoomOptions
 * @member {Real} [max_players]
 * @member {Bool} [is_visible]
 * @member {Bool} [is_open]
 * @member {String} [lobby_name]
 * @member {Enum.PhotonRealtimeLobbyType} [lobby_type]
 * @member {Real} [player_ttl]
 * @member {Real} [empty_room_ttl]
 * @member {Bool} [suppress_room_events]
 * @member {Bool} [publish_user_id]
 * @member {Array[String]} lobby_keys
 * @member {Array[String]} expected_users
 * @struct_end
 */

/**
 * @struct_partial PhotonRealtimeJoinRoomOptions
 * @member {Bool} [rejoin]
 * @member {Real} [cache_slice_index]
 * @struct_end
 */

/**
 * @struct_partial PhotonRealtimeRaiseEventOptions
 * @member {Enum.PhotonRealtimeReceiverGroup} [receiver_group]
 * @member {Real} [interest_group]
 * @member {Enum.PhotonRealtimeEventCache} [event_cache]
 * @member {Real} [channel_id]
 * @member {Real} [cache_slice_index]
 * @member {Bool} [encrypt]
 * @member {Array[Real]} target_players
 * @struct_end
 */

/**
 * @struct_partial PhotonRealtimeAuthenticationValues
 * @member {String} [user_id]
 * @member {Enum.PhotonRealtimeCustomAuthType} [auth_type]
 * @member {String} [parameters]
 * @struct_end
 */

/**
 * @struct_partial PhotonRealtimeFriendInfo
 * @member {String} user_id
 * @member {Bool} is_online
 * @member {String} room
 * @member {Bool} is_in_room
 * @struct_end
 */

/**
 * @struct_partial PhotonRealtimeRoomInfo
 * @member {String} name
 * @member {Real} player_count
 * @member {Real} max_players
 * @member {Bool} is_open
 * @member {Struct} custom_properties
 * @struct_end
 */

/**
 * @struct_partial PhotonRealtimeLobbyStats
 * @member {String} name
 * @member {Enum.PhotonRealtimeLobbyType} type
 * @member {Real} peer_count
 * @member {Real} room_count
 * @struct_end
 */

/**
 * @struct_partial PhotonChatMessage
 * @member {String} sender
 * @member {String} content
 * @struct_end
 */

/**
 * @struct_partial PhotonChatSubscribeResult
 * @member {String} channel_name
 * @member {Bool} success
 * @struct_end
 */

/**
 * @struct_partial PhotonRealtimeConnectOptions
 * @member {Struct.PhotonRealtimeAuthenticationValues} [authentication_values]
 * @member {String} [username]
 * @member {String} [server_address]
 * @member {Bool} [try_use_datagram_encryption]
 * @member {Bool} [use_background_thread]
 * @struct_end
 */

/**
 * @struct_partial PhotonChatConnectOptions
 * @member {Struct.PhotonRealtimeAuthenticationValues} [authentication_values]
 * @member {String} [server_address]
 * @member {Bool} [use_background_thread]
 * @struct_end
 */

/**
 * @enum_partial PhotonRealtimeState
 * @member Unknown
 * @member Uninitialized
 * @member PeerCreated
 * @member ConnectingToNameserver
 * @member ConnectedToNameserver
 * @member DisconnectingFromNameserver
 * @member Connecting
 * @member Connected
 * @member WaitingForCustomAuthNextStep
 * @member Authenticated
 * @member JoinedLobby
 * @member DisconnectingFromMasterserver
 * @member ConnectingToGameserver
 * @member ConnectedToGameserver
 * @member AuthenticatedOnGameServer
 * @member Joining
 * @member Joined
 * @member Leaving
 * @member Left
 * @member DisconnectingFromGameserver
 * @member ConnectingToMasterserver
 * @member ConnectedComingFromGameserver
 * @member AuthenticatedComingFromGameserver
 * @member Disconnecting
 * @member Disconnected
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeLobbyType
 * @member Default
 * @member SqlLobby
 * @member AsyncRandomLobby
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeMatchmakingMode
 * @member FillRoom
 * @member SerialMatching
 * @member RandomMatching
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeDirectMode
 * @member None
 * @member AllToOthers
 * @member MasterToOthers
 * @member AllToAll
 * @member MasterToAll
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeDisconnectCause
 * @member Unknown
 * @member None
 * @member ServerUserLimit
 * @member ExceptionOnConnect
 * @member DisconnectByServer
 * @member DisconnectByServerLogic
 * @member TimeoutDisconnect
 * @member Exception
 * @member InvalidAuthentication
 * @member MaxCcuReached
 * @member InvalidRegion
 * @member OperationNotAllowed
 * @member CustomAuthenticationFailed
 * @member ClientVersionTooOld
 * @member ClientVersionInvalid
 * @member DashboardVersionInvalid
 * @member AuthenticationTicketExpired
 * @member OperationLimit
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeRegionSelectionMode
 * @member Default
 * @member Select
 * @member Best
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeServerType
 * @member NameServer
 * @member MasterServer
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeCustomAuthType
 * @member Custom
 * @member Steam
 * @member Facebook
 * @member Oculus
 * @member PlayStation4
 * @member Xbox
 * @member Viveport
 * @member NintendoSwitch
 * @member PlayStation5
 * @member Epic
 * @member FacebookGaming
 * @member None
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeReceiverGroup
 * @member Others
 * @member All
 * @member MasterClient
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeEventCache
 * @member DoNotCache
 * @member MergeCache
 * @member ReplaceCache
 * @member RemoveCache
 * @member AddToRoomCache
 * @member AddToRoomCacheGlobal
 * @member RemoveFromRoomCache
 * @member RemoveFromRoomCacheForActorsLeft
 * @member SliceIncIndex
 * @member SliceSetIndex
 * @member SlicePurgeIndex
 * @member SlicePurgeUpToIndex
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeLBOperationCode
 * @member Leave
 * @member RaiseEvent
 * @member SetProperties
 * @member GetProperties
 * @member ChangeGroups
 * @member AuthOnce
 * @member Authenticate
 * @member JoinLobby
 * @member LeaveLobby
 * @member CreateRoom
 * @member JoinRoom
 * @member JoinRandomRoom
 * @member FindFriends
 * @member LobbyStats
 * @member GetRegions
 * @member Rpc
 * @member GetRoomList
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeLBEventCode
 * @member Join
 * @member Leave
 * @member PropertiesChanged
 * @member ErrorInfo
 * @member CacheSliceChanged
 * @member RoomList
 * @member RoomListUpdate
 * @member AppStats
 * @member LobbyStats
 * @member Auth
 * @member PunchMsg
 * @member VoiceFrameData
 * @member VoiceData
 * @member MaxCustomEvCode
 * @enum_end
 */

/**
 * @enum_partial PhotonRealtimeAppErrorCode
 * @member Ok
 * @member InvalidAuthentication
 * @member GameIdAlreadyExists
 * @member GameFull
 * @member GameClosed
 * @member AlreadyMatched
 * @member ServerFull
 * @member UserBlocked
 * @member NoMatchFound
 * @member GameDoesNotExist
 * @member MaxCcuReached
 * @member InvalidRegion
 * @member CustomAuthenticationFailed
 * @member AuthTicketExpired
 * @member PluginReportedError
 * @member PluginMismatch
 * @member JoinFailedPeerAlreadyJoined
 * @member JoinFailedFoundInactiveJoiner
 * @member JoinFailedRejoinNotFound
 * @member JoinFailedFoundExcludedUserId
 * @member JoinFailedFoundActiveJoiner
 * @member HttpLimitReached
 * @member ExternalHttpCallFailed
 * @member OperationLimitReached
 * @member SlotError
 * @member InvalidEncryptionParameters
 * @member ClientVersionTooOld
 * @member ClientVersionInvalid
 * @member DashboardVersionInvalid
 * @enum_end
 */

/**
 * @enum_partial PhotonCommonDebugLevel
 * @member Off
 * @member Errors
 * @member Warnings
 * @member Info
 * @member All
 * @enum_end
 */

/**
 * @enum_partial PhotonCommonSerializationProtocol
 * @member Protocol16
 * @member Protocol18
 * @enum_end
 */

/**
 * @enum_partial PhotonCommonTypeCode
 * @member Byte
 * @member Short
 * @member Integer
 * @member Long
 * @member Float
 * @member Double
 * @member Boolean
 * @member String
 * @member Hashtable
 * @member Dictionary
 * @member Object
 * @member Array
 * @member ByteArray
 * @member PhotonCommand
 * @member Null
 * @member Custom
 * @member Unknown
 * @member Invalid
 * @enum_end
 */

/**
 * @enum_partial PhotonCommonInternalLogLevel
 * @member Off
 * @member Fatal
 * @member Error
 * @member Warning
 * @member Info
 * @member Debug
 * @member DebugVerbose
 * @enum_end
 */

/**
 * @enum_partial PhotonPeerConnectionProtocol
 * @member Udp
 * @member Tcp
 * @member Ws
 * @member Wss
 * @enum_end
 */

/**
 * @enum_partial PhotonPeerState
 * @member Disconnected
 * @member Connecting
 * @member InitializingApplication
 * @member Connected
 * @member Disconnecting
 * @enum_end
 */

/**
 * @enum_partial PhotonPeerStatusCode
 * @member ExceptionOnConnect
 * @member Connect
 * @member Disconnect
 * @member Exception
 * @member QueueOutgoingReliableWarning
 * @member QueueOutgoingUnreliableWarning
 * @member SendError
 * @member QueueOutgoingAcksWarning
 * @member QueueIncomingReliableWarning
 * @member QueueIncomingUnreliableWarning
 * @member QueueSentWarning
 * @member InternalReceiveException
 * @member TimeoutDisconnect
 * @member DisconnectByServer
 * @member DisconnectByServerUserLimit
 * @member DisconnectByServerLogic
 * @member EncryptionEstablished
 * @member EncryptionFailedToEstablish
 * @enum_end
 */

/**
 * @enum_partial PhotonPeerCoreErrorCode
 * @member Ok
 * @member InternalServerError
 * @member OperationInvalid
 * @member OperationDenied
 * @member ArgumentOutOfRange
 * @member InvalidRequestParameters
 * @member NotReady
 * @member Overload
 * @member Backoff
 * @member Maintenance
 * @member SendBufferFull
 * @member UnexpectedData
 * @member SerializationLimitError
 * @member WrongInitRequestData
 * @member ResponseParseError
 * @member CryptoProviderNotSet
 * @member DecryptionFailure
 * @member InvalidEncryptionParameters
 * @member IncomingDataRateExceeded
 * @member IncomingMsgRateExceeded
 * @member IncomingMaxMsgSizeExceeded
 * @member OperationMaxCountExceeded
 * @member OperationRateExceeded
 * @member OperationDataRateExceeded
 * @member OperationBlocked
 * @member OperationSizeLimitExceeded
 * @member OperationParametersLimit
 * @member MessagesRateExceeded
 * @member MessagesDataRateExceeded
 * @member MessagesBlocked
 * @member MessageSizeLimitExceeded
 * @enum_end
 */

/**
 * @enum_partial PhotonPeerLiteOperationCode
 * @member Join
 * @member Leave
 * @member RaiseEvent
 * @member SetProperties
 * @member GetProperties
 * @member ChangeGroups
 * @enum_end
 */

/**
 * @enum_partial PhotonPeerLiteEventCode
 * @member Join
 * @member Leave
 * @member PropertiesChanged
 * @enum_end
 */

/**
 * @enum_partial PhotonPeerLiteParameterCode
 * @member GameId
 * @member ActorNr
 * @member TargetActorNr
 * @member ActorList
 * @member Properties
 * @member Broadcast
 * @member ActorProperties
 * @member GameProperties
 * @member Cache
 * @member ReceiverGroup
 * @member Data
 * @member Code
 * @member Group
 * @member Remove
 * @member Add
 * @enum_end
 */

/**
 * @enum_partial PhotonChatAppErrorCode
 * @member Ok
 * @member OperationDenied
 * @member OperationInvalid
 * @member InternalServerError
 * @member InvalidAuthentication
 * @member GameIdAlreadyExists
 * @member GameFull
 * @member GameClosed
 * @member AlreadyMatched
 * @member ServerFull
 * @member UserBlocked
 * @member NoMatchFound
 * @member GameDoesNotExist
 * @member MaxCcuReached
 * @member InvalidRegion
 * @member CustomAuthenticationFailed
 * @enum_end
 */

/**
 * @enum_partial PhotonChatState
 * @member Unknown
 * @member Uninitialized
 * @member ConnectingToNameServer
 * @member ConnectedToNameServer
 * @member Authenticating
 * @member Authenticated
 * @member DisconnectingFromNameServer
 * @member ConnectingToFrontEnd
 * @member ConnectedToFrontEnd
 * @member Disconnecting
 * @member Disconnected
 * @enum_end
 */

/**
 * @enum_partial PhotonChatDisconnectCause
 * @member Unknown
 * @member None
 * @member ServerUserLimit
 * @member ExceptionOnConnect
 * @member DisconnectByServer
 * @member DisconnectByServerLogic
 * @member TimeoutDisconnect
 * @member Exception
 * @member InvalidAuthentication
 * @member MaxCcuReached
 * @member InvalidRegion
 * @member OperationNotAllowed
 * @member CustomAuthenticationFailed
 * @enum_end
 */

/**
 * @enum_partial PhotonChatOperationCode
 * @member Authenticate
 * @member Subscribe
 * @member Unsubscribe
 * @member Publish
 * @member SendPrivate
 * @member ChannelHistory
 * @member UpdateStatus
 * @member AddFriends
 * @member RemoveFriends
 * @enum_end
 */

/**
 * @enum_partial PhotonChatEventCode
 * @member ChatMessages
 * @member Users
 * @member PrivateMessage
 * @member FriendList
 * @member StatusUpdate
 * @member Subscribe
 * @member Unsubscribe
 * @enum_end
 */

/**
 * @enum_partial PhotonChatParameterCode
 * @member Channels
 * @member Messages
 * @member Message
 * @member Senders
 * @member Sender
 * @member ChannelUserCount
 * @member MessageId
 * @member MessageIds
 * @member Status
 * @member Friends
 * @member SkipMessage
 * @member HistoryLength
 * @member SubscribeResults
 * @member Properties
 * @member ChannelId
 * @member Region
 * @member AppVersion
 * @member Secret
 * @member AuthType
 * @member AuthParams
 * @member AuthData
 * @member UserId
 * @member AppId
 * @member Address
 * @enum_end
 */

/**
 * @enum_partial PhotonChatUserStatus
 * @member Offline
 * @member Invisible
 * @member Online
 * @member Away
 * @member Dnd
 * @member Lfg
 * @member Playing
 * @enum_end
 */

/**
 * @enum_partial PhotonVoiceCodec
 * @member None
 * @member AudioOpus
 * @member VideoVp8
 * @member VideoVp9
 * @member VideoAv1
 * @member VideoH264
 * @member VideoH265
 * @enum_end
 */

/**
 * @enum_partial PhotonChatChannelType
 * @member Public
 * @member Private
 * @enum_end
 */

/**
 * @const_partial macros
 * @const_end
 */

