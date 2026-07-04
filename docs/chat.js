// FUNCTIONS

// --- Lifecycle ---

/**
 * @function photon_chat_init
 * @desc Initialises the Chat client. Call this once before any other Chat function.
 * @returns {Bool} Whether initialisation succeeded.
 * @function_end
 */

/**
 * @function photon_chat_shutdown
 * @desc Shuts the Chat client down and releases its resources.
 * @returns {Bool} Whether the client was shut down.
 * @function_end
 */

/**
 * @function photon_chat_service
 * @desc Dispatches queued incoming and outgoing traffic for the Chat client. This **must** be called every step while connected.
 * @returns {Bool} Whether the client was serviced.
 * @function_end
 */

/**
 * @function photon_chat_connect
 * @desc Connects to the Photon Chat service using the given Application ID and application version. The result is delivered to ${function.photon_chat_set_callback_connected}.
 * @param {String} app_id Your Photon Chat Application ID.
 * @param {String} app_version A version string of your choosing for your game build.
 * @param {Struct.PhotonChatConnectOptions} [options] Optional connection options.
 * @returns {Bool} Whether the connection attempt started.
 * @example
 * ```gml
 * var _app_id = extension_get_option_value("GMPhoton", "appIdChat");
 * photon_chat_connect(_app_id, "1.0", new PhotonChatConnectOptions());
 * ```
 * @function_end
 */

/**
 * @function photon_chat_disconnect
 * @desc Disconnects the Chat client. The ${function.photon_chat_set_callback_disconnected} callback fires once the disconnect completes.
 * @returns {Bool} Whether the disconnect started.
 * @function_end
 */

// --- Operations ---

/**
 * @function photon_chat_operation_subscribe
 * @desc Subscribes to one or more chat channels. Messages then arrive via ${function.photon_chat_set_callback_get_messages}.
 * @param {Array<String>} channels The channel names to subscribe to.
 * @param {Real} [messages_from_history] How many historical messages to fetch per channel (0 for none).
 * @param {Function} [callback] Optional callback invoked with the subscription results.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Array<Struct.PhotonChatSubscribeResult>} results The per-channel subscription results.
 * @event_end
 * @function_end
 */

/**
 * @function photon_chat_operation_unsubscribe
 * @desc Unsubscribes from one or more chat channels.
 * @param {Array<String>} channels The channel names to unsubscribe from.
 * @param {Function} [callback] Optional callback invoked with the unsubscribed channels.
 * @returns {Bool} Whether the operation was sent.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Array<String>} channels The channel names that were unsubscribed.
 * @event_end
 * @function_end
 */

/**
 * @function photon_chat_operation_publish_message
 * @desc Publishes a message to a subscribed channel. Subscribers receive it via ${function.photon_chat_set_callback_get_messages}.
 * @param {String} channel_name The channel to publish to.
 * @param {String} message The message text.
 * @returns {Bool} Whether the operation was sent.
 * @function_end
 */

/**
 * @function photon_chat_operation_send_private_message
 * @desc Sends a private message to another user. The recipient receives it via ${function.photon_chat_set_callback_private_message}.
 * @param {String} user_name The recipient's user ID.
 * @param {String} message The message text.
 * @param {Bool} [encrypt] Whether to encrypt the message.
 * @returns {Bool} Whether the operation was sent.
 * @function_end
 */

/**
 * @function photon_chat_operation_set_online_status
 * @desc Sets the local user's online status, optionally with a status message. Friends are notified via ${function.photon_chat_set_callback_status_update}.
 * @param {Constant.PhotonChatUserStatus} status The status to broadcast.
 * @param {String} [message] An optional status message.
 * @returns {Bool} Whether the operation was sent.
 * @function_end
 */

/**
 * @function photon_chat_operation_add_friends
 * @desc Adds users to the local user's friend list to receive their status updates.
 * @param {Array<String>} user_ids The user IDs to add.
 * @returns {Bool} Whether the operation was sent.
 * @function_end
 */

/**
 * @function photon_chat_operation_remove_friends
 * @desc Removes users from the local user's friend list.
 * @param {Array<String>} user_ids The user IDs to remove.
 * @returns {Bool} Whether the operation was sent.
 * @function_end
 */

// --- State & info ---

/**
 * @function photon_chat_is_initialized
 * @desc Returns whether the Chat client has been initialised.
 * @returns {Bool} Whether the client is initialised.
 * @function_end
 */

/**
 * @function photon_chat_is_connected
 * @desc Returns whether the Chat client is connected.
 * @returns {Bool} Whether the client is connected.
 * @function_end
 */

/**
 * @function photon_chat_get_state
 * @desc Returns the current Chat client state.
 * @returns {Constant.PhotonChatState} The current state.
 * @function_end
 */

/**
 * @function photon_chat_get_disconnect_cause
 * @desc Returns the cause of the most recent Chat disconnect.
 * @returns {Constant.PhotonChatDisconnectCause} The disconnect cause.
 * @function_end
 */

/**
 * @function photon_chat_get_user_id
 * @desc Returns the local user's ID.
 * @returns {String} The local user ID.
 * @function_end
 */

/**
 * @function photon_chat_get_region
 * @desc Returns the region the Chat client is connected to.
 * @returns {String} The current region.
 * @function_end
 */

/**
 * @function photon_chat_get_server_time
 * @desc Returns the current Chat server time in milliseconds.
 * @returns {Real} The server time in milliseconds.
 * @function_end
 */

/**
 * @function photon_chat_get_server_time_offset
 * @desc Returns the offset between local time and Chat server time, in milliseconds.
 * @returns {Real} The server time offset in milliseconds.
 * @function_end
 */

/**
 * @function photon_chat_get_bytes_in
 * @desc Returns the total number of bytes received by the Chat client.
 * @returns {Real} The number of bytes received.
 * @function_end
 */

/**
 * @function photon_chat_get_bytes_out
 * @desc Returns the total number of bytes sent by the Chat client.
 * @returns {Real} The number of bytes sent.
 * @function_end
 */

// --- Channels & messages ---

/**
 * @function photon_chat_get_channel_count
 * @desc Returns the number of channels of the given type the client is currently subscribed to.
 * @param {Constant.PhotonChatChannelType} channel_type The channel type (public or private).
 * @returns {Real} The number of channels.
 * @function_end
 */

/**
 * @function photon_chat_get_channel_name
 * @desc Returns the name of a subscribed channel of the given type by index.
 * @param {Constant.PhotonChatChannelType} channel_type The channel type.
 * @param {Real} index The zero-based channel index.
 * @returns {String} The channel name.
 * @function_end
 */

/**
 * @function photon_chat_get_channel_message_count
 * @desc Returns the number of cached messages in the given channel.
 * @param {Constant.PhotonChatChannelType} channel_type The channel type.
 * @param {String} channel_name The channel name.
 * @returns {Real} The number of cached messages.
 * @function_end
 */

/**
 * @function photon_chat_get_channel_message
 * @desc Returns a cached message from the given channel by index.
 * @param {Constant.PhotonChatChannelType} channel_type The channel type.
 * @param {String} channel_name The channel name.
 * @param {Real} index The zero-based message index.
 * @returns {String} The message text.
 * @function_end
 */

/**
 * @function photon_chat_get_channel_sender
 * @desc Returns the sender of a cached message from the given channel by index.
 * @param {Constant.PhotonChatChannelType} channel_type The channel type.
 * @param {String} channel_name The channel name.
 * @param {Real} index The zero-based message index.
 * @returns {String} The sender's user ID.
 * @function_end
 */

// --- Broadcast queue (binary broadcasts) ---

/**
 * @function photon_chat_get_broadcast_queue_count
 * @desc Returns the number of buffered binary broadcast messages waiting to be read.
 * @returns {Real} The number of queued broadcasts.
 * @function_end
 */

/**
 * @function photon_chat_clear_broadcast_queue
 * @desc Clears all buffered binary broadcast messages without reading them.
 * @returns {Bool} Whether the queue was cleared.
 * @function_end
 */

/**
 * @function photon_chat_peek_next_broadcast_size
 * @desc Returns the size in bytes of the next buffered broadcast without removing it from the queue.
 * @returns {Real} The size of the next broadcast in bytes.
 * @function_end
 */

/**
 * @function photon_chat_peek_next_broadcast_channel
 * @desc Returns the channel name of the next buffered broadcast without removing it from the queue.
 * @returns {String} The channel of the next broadcast.
 * @function_end
 */

/**
 * @function photon_chat_receive_one_broadcast_buffer
 * @desc Removes the next buffered broadcast from the queue and writes its payload into the given buffer.
 * @param {Id.Buffer} out_data The buffer to write the payload into.
 * @param {Real} max_bytes The maximum number of bytes to write.
 * @param {Real} offset The offset within the buffer to start writing at.
 * @returns {Struct.PhotonRealtimeEventBufferReceived} A struct describing the received broadcast.
 * @function_end
 */

// --- Callbacks ---

/**
 * @function photon_chat_set_callback_debug
 * @desc Registers the callback fired with Chat SDK debug output.
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
 * @function photon_chat_set_callback_connected
 * @desc Registers the callback fired when the Chat client finishes connecting.
 * @param {Function} callback The function to call on connect.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} error_code The connect result code (`0` on success).
 * @member {String} error_string A human-readable result message.
 * @event_end
 * @function_end
 */

/**
 * @function photon_chat_set_callback_state_change
 * @desc Registers the callback fired when the Chat client state changes.
 * @param {Function} callback The function to call on a state change.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Constant.PhotonChatState} state The new client state.
 * @event_end
 * @function_end
 */

/**
 * @function photon_chat_set_callback_connection_error
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
 * @function photon_chat_set_callback_client_error
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
 * @function photon_chat_set_callback_warning
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
 * @function photon_chat_set_callback_server_error
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
 * @function photon_chat_set_callback_disconnected
 * @desc Registers the callback fired when the Chat client has disconnected. The callback takes no arguments.
 * @param {Function} callback The function to call on disconnect.
 * @returns {Bool} Whether the callback was set.
 * @function_end
 */

/**
 * @function photon_chat_set_callback_status_update
 * @desc Registers the callback fired when a friend's status changes.
 * @param {Function} callback The function to call on a status update.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {String} user The user whose status changed.
 * @member {Constant.PhotonChatUserStatus} status The user's new status.
 * @member {Bool} got_message Whether a status message accompanied the update.
 * @member {String} message The status message, or empty if none.
 * @event_end
 * @function_end
 */

/**
 * @function photon_chat_set_callback_get_messages
 * @desc Registers the callback fired when messages are received on a subscribed channel.
 * @param {Function} callback The function to call when messages arrive.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {String} channel_name The channel the messages arrived on.
 * @member {Array<Struct.PhotonChatMessage>} messages The received messages.
 * @event_end
 * @function_end
 */

/**
 * @function photon_chat_set_callback_private_message
 * @desc Registers the callback fired when a private message is received.
 * @param {Function} callback The function to call on a private message.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {String} sender The sender's user ID.
 * @member {String} channel_name The private channel name.
 * @member {String} message The message text.
 * @event_end
 * @function_end
 */

/**
 * @function photon_chat_set_callback_receive_broadcast
 * @desc Registers the callback fired when a binary broadcast is received. The payload is queued; read it with ${function.photon_chat_receive_one_broadcast_buffer}.
 * @param {Function} callback The function to call on a broadcast.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {String} channel_name The channel the broadcast arrived on.
 * @member {Real} byte_length The size of the broadcast payload in bytes.
 * @event_end
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_debug
 * @desc Removes the debug callback registered with ${function.photon_chat_set_callback_debug}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_connected
 * @desc Removes the connected callback registered with ${function.photon_chat_set_callback_connected}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_state_change
 * @desc Removes the state-change callback registered with ${function.photon_chat_set_callback_state_change}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_connection_error
 * @desc Removes the connection-error callback registered with ${function.photon_chat_set_callback_connection_error}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_client_error
 * @desc Removes the client-error callback registered with ${function.photon_chat_set_callback_client_error}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_warning
 * @desc Removes the warning callback registered with ${function.photon_chat_set_callback_warning}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_server_error
 * @desc Removes the server-error callback registered with ${function.photon_chat_set_callback_server_error}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_disconnected
 * @desc Removes the disconnected callback registered with ${function.photon_chat_set_callback_disconnected}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_status_update
 * @desc Removes the status-update callback registered with ${function.photon_chat_set_callback_status_update}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_get_messages
 * @desc Removes the get-messages callback registered with ${function.photon_chat_set_callback_get_messages}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_private_message
 * @desc Removes the private-message callback registered with ${function.photon_chat_set_callback_private_message}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_chat_remove_callback_receive_broadcast
 * @desc Removes the receive-broadcast callback registered with ${function.photon_chat_set_callback_receive_broadcast}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

// STRUCTS

/**
 * @struct PhotonChatConnectOptions
 * @desc Options passed to ${function.photon_chat_connect}.
 * @member {Struct.PhotonRealtimeAuthenticationValues} [authentication_values] Authentication values for a custom auth provider.
 * @member {String} [server_address] Override the Photon name server address. Leave unset to use the default cloud.
 * @member {Bool} [use_background_thread] Whether to use a background send/receive thread. Honored only on Nintendo Switch; ignored on other platforms.
 * @struct_end
 */

/**
 * @struct PhotonChatMessage
 * @desc A single chat message delivered by ${function.photon_chat_set_callback_get_messages}.
 * @member {String} sender The sender's user ID.
 * @member {String} content The message text.
 * @struct_end
 */

/**
 * @struct PhotonChatSubscribeResult
 * @desc A per-channel result delivered by the ${function.photon_chat_operation_subscribe} callback.
 * @member {String} channel_name The channel name.
 * @member {Bool} success Whether the subscription to this channel succeeded.
 * @struct_end
 */

// CONSTANTS

/**
 * @const PhotonChatState
 * @desc The states the Chat client moves through, returned by ${function.photon_chat_get_state}.
 * @member Unknown Unknown state.
 * @member Uninitialized The client has not been initialised.
 * @member ConnectingToNameServer Connecting to the name server.
 * @member ConnectedToNameServer Connected to the name server.
 * @member Authenticating Authenticating.
 * @member Authenticated Authenticated.
 * @member DisconnectingFromNameServer Disconnecting from the name server.
 * @member ConnectingToFrontEnd Connecting to the chat front-end server.
 * @member ConnectedToFrontEnd Connected to the chat front-end server (ready to chat).
 * @member Disconnecting Disconnecting.
 * @member Disconnected Fully disconnected.
 * @const_end
 */

/**
 * @const PhotonChatDisconnectCause
 * @desc The reasons the Chat client can be disconnected, returned by ${function.photon_chat_get_disconnect_cause}.
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
 * @const_end
 */

/**
 * @const PhotonChatAppErrorCode
 * @desc Application-level result codes reported by the Chat service.
 * @member Ok The operation succeeded.
 * @member OperationDenied The operation was denied.
 * @member OperationInvalid The operation was invalid.
 * @member InternalServerError An internal server error occurred.
 * @member InvalidAuthentication Authentication was invalid.
 * @member GameIdAlreadyExists The game ID already exists.
 * @member GameFull The game is full.
 * @member GameClosed The game is closed.
 * @member AlreadyMatched Already matched.
 * @member ServerFull The server is full.
 * @member UserBlocked The user is blocked.
 * @member NoMatchFound No match was found.
 * @member GameDoesNotExist The game does not exist.
 * @member MaxCcuReached The maximum concurrent-user limit was reached.
 * @member InvalidRegion The region was invalid.
 * @member CustomAuthenticationFailed Custom authentication failed.
 * @const_end
 */

/**
 * @const PhotonChatUserStatus
 * @desc The user statuses that can be broadcast with ${function.photon_chat_operation_set_online_status}.
 * @member Offline The user is offline.
 * @member Invisible The user appears offline to others.
 * @member Online The user is online.
 * @member Away The user is away.
 * @member Dnd The user does not want to be disturbed.
 * @member Lfg The user is looking for a game.
 * @member Playing The user is playing.
 * @const_end
 */

/**
 * @const PhotonChatChannelType
 * @desc The chat channel types.
 * @member Public A public channel (subscribed via ${function.photon_chat_operation_subscribe}).
 * @member Private A private channel (created by private messages).
 * @const_end
 */

/**
 * @const PhotonChatOperationCode
 * @desc The Chat operation codes. Primarily useful for low-level diagnostics.
 * @member Authenticate Authenticate with the chat service.
 * @member Subscribe Subscribe to channels.
 * @member Unsubscribe Unsubscribe from channels.
 * @member Publish Publish a message.
 * @member SendPrivate Send a private message.
 * @member ChannelHistory Fetch channel history.
 * @member UpdateStatus Update the user's status.
 * @member AddFriends Add friends.
 * @member RemoveFriends Remove friends.
 * @const_end
 */

/**
 * @const PhotonChatEventCode
 * @desc The Chat event codes. Primarily useful for low-level diagnostics.
 * @member ChatMessages Channel messages were received.
 * @member Users A user list was received.
 * @member PrivateMessage A private message was received.
 * @member FriendList A friend list was received.
 * @member StatusUpdate A friend status update was received.
 * @member Subscribe A subscribe result was received.
 * @member Unsubscribe An unsubscribe result was received.
 * @const_end
 */

/**
 * @const PhotonChatParameterCode
 * @desc The Chat protocol parameter codes. Primarily useful for low-level diagnostics.
 * @member Channels The channels parameter.
 * @member Messages The messages parameter.
 * @member Message A single message parameter.
 * @member Senders The senders parameter.
 * @member Sender A single sender parameter.
 * @member ChannelUserCount The channel user count parameter.
 * @member MessageId A message ID parameter.
 * @member MessageIds A message IDs parameter.
 * @member Status A status parameter.
 * @member Friends The friends parameter.
 * @member SkipMessage The skip-message flag parameter.
 * @member HistoryLength The history-length parameter.
 * @member SubscribeResults The subscribe-results parameter.
 * @member Properties The properties parameter.
 * @member ChannelId A channel ID parameter.
 * @member Region The region parameter.
 * @member AppVersion The application version parameter.
 * @member Secret The authentication secret parameter.
 * @member AuthType The authentication type parameter.
 * @member AuthParams The authentication parameters parameter.
 * @member AuthData The authentication data parameter.
 * @member UserId The user ID parameter.
 * @member AppId The application ID parameter.
 * @member Address The address parameter.
 * @const_end
 */

// MODULES

/**
 * @module chat
 * @title Chat
 * @desc The Chat module connects to the Photon Chat service for channel-based and private text messaging, presence and friend status. It is independent of ${module.realtime}: initialise, connect and service it separately. Connection diagnostics live in ${module.chat_peer}.
 *
 * [[NOTE: After connecting you must call ${function.photon_chat_service} every step for the Chat client to send and receive.]]
 *
 * @section_func Lifecycle
 * @desc Initialise, connect and service the Chat client:
 * @ref photon_chat_init
 * @ref photon_chat_shutdown
 * @ref photon_chat_service
 * @ref photon_chat_connect
 * @ref photon_chat_disconnect
 * @section_end
 *
 * @section_func Operations
 * @desc Subscribe to channels, send messages and manage friends:
 * @ref photon_chat_operation_subscribe
 * @ref photon_chat_operation_unsubscribe
 * @ref photon_chat_operation_publish_message
 * @ref photon_chat_operation_send_private_message
 * @ref photon_chat_operation_set_online_status
 * @ref photon_chat_operation_add_friends
 * @ref photon_chat_operation_remove_friends
 * @section_end
 *
 * @section_func State & info
 * @desc Query Chat connection state:
 * @ref photon_chat_is_initialized
 * @ref photon_chat_is_connected
 * @ref photon_chat_get_state
 * @ref photon_chat_get_disconnect_cause
 * @ref photon_chat_get_user_id
 * @ref photon_chat_get_region
 * @ref photon_chat_get_server_time
 * @ref photon_chat_get_server_time_offset
 * @ref photon_chat_get_bytes_in
 * @ref photon_chat_get_bytes_out
 * @section_end
 *
 * @section_func Channels & messages
 * @desc Inspect subscribed channels and their cached messages:
 * @ref photon_chat_get_channel_count
 * @ref photon_chat_get_channel_name
 * @ref photon_chat_get_channel_message_count
 * @ref photon_chat_get_channel_message
 * @ref photon_chat_get_channel_sender
 * @section_end
 *
 * @section_func Broadcast queue
 * @desc Read binary broadcast payloads:
 * @ref photon_chat_get_broadcast_queue_count
 * @ref photon_chat_clear_broadcast_queue
 * @ref photon_chat_peek_next_broadcast_size
 * @ref photon_chat_peek_next_broadcast_channel
 * @ref photon_chat_receive_one_broadcast_buffer
 * @section_end
 *
 * @section_func Callbacks
 * @desc Register and remove the Chat event callbacks:
 * @ref photon_chat_set_callback_debug
 * @ref photon_chat_set_callback_connected
 * @ref photon_chat_set_callback_state_change
 * @ref photon_chat_set_callback_connection_error
 * @ref photon_chat_set_callback_client_error
 * @ref photon_chat_set_callback_warning
 * @ref photon_chat_set_callback_server_error
 * @ref photon_chat_set_callback_disconnected
 * @ref photon_chat_set_callback_status_update
 * @ref photon_chat_set_callback_get_messages
 * @ref photon_chat_set_callback_private_message
 * @ref photon_chat_set_callback_receive_broadcast
 * @ref photon_chat_remove_callback_debug
 * @ref photon_chat_remove_callback_connected
 * @ref photon_chat_remove_callback_state_change
 * @ref photon_chat_remove_callback_connection_error
 * @ref photon_chat_remove_callback_client_error
 * @ref photon_chat_remove_callback_warning
 * @ref photon_chat_remove_callback_server_error
 * @ref photon_chat_remove_callback_disconnected
 * @ref photon_chat_remove_callback_status_update
 * @ref photon_chat_remove_callback_get_messages
 * @ref photon_chat_remove_callback_private_message
 * @ref photon_chat_remove_callback_receive_broadcast
 * @section_end
 *
 * @section_struct Structs
 * @desc The Chat module uses the following structs:
 * @ref PhotonChatConnectOptions
 * @ref PhotonChatMessage
 * @ref PhotonChatSubscribeResult
 * @section_end
 *
 * @section_const Constants
 * @desc The Chat module defines the following constants:
 * @ref PhotonChatState
 * @ref PhotonChatDisconnectCause
 * @ref PhotonChatAppErrorCode
 * @ref PhotonChatUserStatus
 * @ref PhotonChatChannelType
 * @ref PhotonChatOperationCode
 * @ref PhotonChatEventCode
 * @ref PhotonChatParameterCode
 * @section_end
 *
 * @module_end
 */
