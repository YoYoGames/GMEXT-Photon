// FUNCTIONS

// --- Lifecycle ---

/**
 * @function photon_voice_init
 * @desc Initialises the Voice client. Voice runs on top of a connected ${module.realtime} client, so connect Realtime first.
 * @returns {Bool} Whether initialisation succeeded.
 * @function_end
 */

/**
 * @function photon_voice_shutdown
 * @desc Shuts the Voice client down and releases its resources.
 * @returns {Bool} Whether the client was shut down.
 * @function_end
 */

/**
 * @function photon_voice_service
 * @desc Dispatches queued voice traffic. This **must** be called every step while using voice.
 * @returns {Bool} Whether the client was serviced.
 * @function_end
 */

/**
 * @function photon_voice_is_initialized
 * @desc Returns whether the Voice client has been initialised.
 * @returns {Bool} Whether the client is initialised.
 * @function_end
 */

// --- Channel & player membership ---

/**
 * @function photon_voice_notify_joined_room
 * @desc Notifies the voice system that the Realtime client has joined a room, so voice transport can start.
 * @returns {Bool} Whether the notification was handled.
 * @function_end
 */

/**
 * @function photon_voice_on_join_channel
 * @desc Notifies the voice system that the local client joined the given voice channel.
 * @param {Real} channel_id The channel ID.
 * @returns {Bool} Whether the notification was handled.
 * @function_end
 */

/**
 * @function photon_voice_on_leave_channel
 * @desc Notifies the voice system that the local client left the given voice channel.
 * @param {Real} channel_id The channel ID.
 * @returns {Bool} Whether the notification was handled.
 * @function_end
 */

/**
 * @function photon_voice_on_join_all_channels
 * @desc Notifies the voice system that the local client joined all voice channels.
 * @returns {Bool} Whether the notification was handled.
 * @function_end
 */

/**
 * @function photon_voice_on_leave_all_channels
 * @desc Notifies the voice system that the local client left all voice channels.
 * @returns {Bool} Whether the notification was handled.
 * @function_end
 */

/**
 * @function photon_voice_on_player_join
 * @desc Notifies the voice system that a player joined the given voice channel.
 * @param {Real} channel_id The channel ID.
 * @param {Real} player_id The player ID that joined.
 * @returns {Bool} Whether the notification was handled.
 * @function_end
 */

/**
 * @function photon_voice_on_player_leave
 * @desc Notifies the voice system that a player left the given voice channel.
 * @param {Real} channel_id The channel ID.
 * @param {Real} player_id The player ID that left.
 * @returns {Bool} Whether the notification was handled.
 * @function_end
 */

// --- Local voice (sending) ---

/**
 * @function photon_voice_create_local_voice
 * @desc Creates a local outgoing voice stream on the given channel and returns its voice ID. Feed it audio frames with ${function.photon_voice_push_frame_buffer}.
 * @param {Real} channel_id The channel to transmit on.
 * @param {Constant.PhotonVoiceCodec} codec The codec to encode with.
 * @param {Real} sample_rate The audio sample rate in Hz.
 * @param {Real} channels The number of audio channels.
 * @param {Real} bitrate The target bitrate.
 * @param {Real} frames_per_packet How many frames to bundle per network packet.
 * @returns {Real} The new local voice ID, or a negative value on failure.
 * @function_end
 */

/**
 * @function photon_voice_remove_local_voice
 * @desc Removes a local voice stream created with ${function.photon_voice_create_local_voice}.
 * @param {Real} voice_id The local voice ID to remove.
 * @returns {Bool} Whether the voice was removed.
 * @function_end
 */

/**
 * @function photon_voice_push_frame_buffer
 * @desc Pushes a buffer of audio samples into a local voice stream for encoding and transmission.
 * @param {Real} voice_id The local voice ID.
 * @param {Id.Buffer} data The buffer holding the audio samples.
 * @param {Real} bytes The number of bytes to read from the buffer.
 * @returns {Bool} Whether the frame was pushed.
 * @function_end
 */

/**
 * @function photon_voice_local_voice_set_transmit
 * @desc Enables or disables transmission for a local voice stream (for example to implement push-to-talk).
 * @param {Real} voice_id The local voice ID.
 * @param {Bool} enabled Whether the stream should transmit.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_voice_local_voice_get_transmit
 * @desc Returns whether a local voice stream is currently transmitting.
 * @param {Real} voice_id The local voice ID.
 * @returns {Bool} Whether the stream is transmitting.
 * @function_end
 */

// --- Remote voice (receiving) ---

/**
 * @function photon_voice_get_frame_queue_count
 * @desc Returns the number of received audio frames waiting to be read from the queue.
 * @returns {Real} The number of queued frames.
 * @function_end
 */

/**
 * @function photon_voice_clear_frame_queue
 * @desc Clears all received audio frames from the queue without reading them.
 * @returns {Bool} Whether the queue was cleared.
 * @function_end
 */

/**
 * @function photon_voice_peek_next_frame_size
 * @desc Returns the size in bytes of the next queued audio frame without removing it.
 * @returns {Real} The size of the next frame in bytes.
 * @function_end
 */

/**
 * @function photon_voice_peek_next_frame_player_id
 * @desc Returns the player ID of the next queued audio frame without removing it.
 * @returns {Real} The player ID of the next frame.
 * @function_end
 */

/**
 * @function photon_voice_peek_next_frame_voice_id
 * @desc Returns the voice ID of the next queued audio frame without removing it.
 * @returns {Real} The voice ID of the next frame.
 * @function_end
 */

/**
 * @function photon_voice_receive_frame_buffer
 * @desc Removes the next received audio frame from the queue and writes its decoded samples into the given buffer.
 * @param {Id.Buffer} out_data The buffer to write the samples into.
 * @param {Real} max_bytes The maximum number of bytes to write.
 * @param {Real} offset The offset within the buffer to start writing at.
 * @returns {Struct.PhotonRealtimeEventBufferReceived} A struct describing the received frame.
 * @function_end
 */

/**
 * @function photon_voice_get_remote_voice_count
 * @desc Returns the number of remote voice streams currently being received.
 * @returns {Real} The number of remote voices.
 * @function_end
 */

/**
 * @function photon_voice_get_remote_voice_player_id
 * @desc Returns the player ID of a remote voice stream by index.
 * @param {Real} index The zero-based remote-voice index.
 * @returns {Real} The player ID.
 * @function_end
 */

/**
 * @function photon_voice_get_remote_voice_id
 * @desc Returns the voice ID of a remote voice stream by index.
 * @param {Real} index The zero-based remote-voice index.
 * @returns {Real} The voice ID.
 * @function_end
 */

/**
 * @function photon_voice_get_remote_voice_codec
 * @desc Returns the codec of a remote voice stream by index.
 * @param {Real} index The zero-based remote-voice index.
 * @returns {Constant.PhotonVoiceCodec} The codec.
 * @function_end
 */

/**
 * @function photon_voice_get_remote_voice_sample_rate
 * @desc Returns the sample rate of a remote voice stream by index.
 * @param {Real} index The zero-based remote-voice index.
 * @returns {Real} The sample rate in Hz.
 * @function_end
 */

/**
 * @function photon_voice_get_remote_voice_channels
 * @desc Returns the channel count of a remote voice stream by index.
 * @param {Real} index The zero-based remote-voice index.
 * @returns {Real} The number of audio channels.
 * @function_end
 */

/**
 * @function photon_voice_get_remote_voice_is_speaking
 * @desc Returns whether a remote voice stream is currently speaking, by index.
 * @param {Real} index The zero-based remote-voice index.
 * @returns {Bool} Whether the remote voice is speaking.
 * @function_end
 */

// --- Remote player mixing ---

/**
 * @function photon_voice_set_remote_player_muted
 * @desc Mutes or unmutes a remote player locally.
 * @param {Real} player_id The remote player ID.
 * @param {Bool} muted Whether to mute the player.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_voice_get_remote_player_muted
 * @desc Returns whether a remote player is muted locally.
 * @param {Real} player_id The remote player ID.
 * @returns {Bool} Whether the player is muted.
 * @function_end
 */

/**
 * @function photon_voice_set_remote_player_volume
 * @desc Sets the local playback volume for a remote player.
 * @param {Real} player_id The remote player ID.
 * @param {Real} volume The playback volume.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_voice_get_remote_player_volume
 * @desc Returns the local playback volume for a remote player.
 * @param {Real} player_id The remote player ID.
 * @returns {Real} The playback volume.
 * @function_end
 */

// --- Statistics & tuning ---

/**
 * @function photon_voice_get_frames_sent
 * @desc Returns the total number of audio frames sent.
 * @returns {Real} The number of frames sent.
 * @function_end
 */

/**
 * @function photon_voice_get_frames_received
 * @desc Returns the total number of audio frames received.
 * @returns {Real} The number of frames received.
 * @function_end
 */

/**
 * @function photon_voice_get_frames_lost
 * @desc Returns the total number of audio frames lost.
 * @returns {Real} The number of frames lost.
 * @function_end
 */

/**
 * @function photon_voice_get_round_trip_time
 * @desc Returns the voice transport's round-trip time, in milliseconds.
 * @returns {Real} The round-trip time in milliseconds.
 * @function_end
 */

/**
 * @function photon_voice_get_round_trip_time_variance
 * @desc Returns the variance of the voice transport's round-trip time, in milliseconds.
 * @returns {Real} The round-trip time variance.
 * @function_end
 */

/**
 * @function photon_voice_get_debug_lost_percent
 * @desc Returns the artificial packet-loss percentage used for debugging.
 * @returns {Real} The debug packet-loss percentage.
 * @function_end
 */

/**
 * @function photon_voice_set_debug_lost_percent
 * @desc Sets an artificial packet-loss percentage for debugging voice resilience.
 * @param {Real} percent The packet-loss percentage to simulate.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_voice_get_speaking_threshold_ms
 * @desc Returns the speaking-detection threshold, in milliseconds.
 * @returns {Real} The speaking threshold in milliseconds.
 * @function_end
 */

/**
 * @function photon_voice_set_speaking_threshold_ms
 * @desc Sets the speaking-detection threshold: how long audio must be present before a voice is considered "speaking".
 * @param {Real} ms The threshold in milliseconds.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

// --- Callbacks ---

/**
 * @function photon_voice_set_callback_remote_voice_added
 * @desc Registers the callback fired when a new remote voice stream is added.
 * @param {Function} callback The function to call when a remote voice is added.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} player_id The remote player's ID.
 * @member {Real} voice_id The remote voice ID.
 * @member {Constant.PhotonVoiceCodec} codec The codec of the remote voice.
 * @member {Real} sample_rate The sample rate of the remote voice.
 * @member {Real} channels The channel count of the remote voice.
 * @event_end
 * @function_end
 */

/**
 * @function photon_voice_set_callback_remote_voice_removed
 * @desc Registers the callback fired when a remote voice stream is removed.
 * @param {Function} callback The function to call when a remote voice is removed.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} player_id The remote player's ID.
 * @member {Real} voice_id The remote voice ID.
 * @event_end
 * @function_end
 */

/**
 * @function photon_voice_set_callback_speaking_changed
 * @desc Registers the callback fired when a remote voice starts or stops speaking.
 * @param {Function} callback The function to call on a speaking-state change.
 * @returns {Bool} Whether the callback was set.
 * @event callback
 * @desc The callback is invoked with the following arguments:
 * @member {Real} player_id The remote player's ID.
 * @member {Real} voice_id The remote voice ID.
 * @member {Bool} is_speaking Whether the remote voice is now speaking.
 * @event_end
 * @function_end
 */

/**
 * @function photon_voice_set_callback_debug
 * @desc Registers the callback fired with Voice SDK debug output.
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
 * @function photon_voice_remove_callback_remote_voice_added
 * @desc Removes the remote-voice-added callback registered with ${function.photon_voice_set_callback_remote_voice_added}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_voice_remove_callback_remote_voice_removed
 * @desc Removes the remote-voice-removed callback registered with ${function.photon_voice_set_callback_remote_voice_removed}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_voice_remove_callback_speaking_changed
 * @desc Removes the speaking-changed callback registered with ${function.photon_voice_set_callback_speaking_changed}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

/**
 * @function photon_voice_remove_callback_debug
 * @desc Removes the debug callback registered with ${function.photon_voice_set_callback_debug}.
 * @returns {Bool} Whether the callback was removed.
 * @function_end
 */

// CONSTANTS

/**
 * @const PhotonVoiceCodec
 * @desc The codecs a voice stream can use. Audio uses Opus; the video codecs are listed for completeness.
 * @member None No codec.
 * @member AudioOpus The Opus audio codec.
 * @member VideoVp8 The VP8 video codec.
 * @member VideoVp9 The VP9 video codec.
 * @member VideoAv1 The AV1 video codec.
 * @member VideoH264 The H.264 video codec.
 * @member VideoH265 The H.265 video codec.
 * @const_end
 */

// MODULES

/**
 * @module voice
 * @title Voice
 * @desc The Voice module carries real-time audio between players on top of a connected ${module.realtime} client. Create a local voice to transmit captured audio, receive remote voices from the frame queue, and mix or mute remote players locally.
 *
 * [[NOTE: Voice runs alongside Realtime. Connect and service the Realtime client, and also call ${function.photon_voice_service} every step.]]
 *
 * @section_func Lifecycle
 * @desc Initialise and service the Voice client:
 * @ref photon_voice_init
 * @ref photon_voice_shutdown
 * @ref photon_voice_service
 * @ref photon_voice_is_initialized
 * @section_end
 *
 * @section_func Channel & player membership
 * @desc Notify the voice system about room, channel and player events:
 * @ref photon_voice_notify_joined_room
 * @ref photon_voice_on_join_channel
 * @ref photon_voice_on_leave_channel
 * @ref photon_voice_on_join_all_channels
 * @ref photon_voice_on_leave_all_channels
 * @ref photon_voice_on_player_join
 * @ref photon_voice_on_player_leave
 * @section_end
 *
 * @section_func Local voice
 * @desc Create and drive an outgoing voice stream:
 * @ref photon_voice_create_local_voice
 * @ref photon_voice_remove_local_voice
 * @ref photon_voice_push_frame_buffer
 * @ref photon_voice_local_voice_set_transmit
 * @ref photon_voice_local_voice_get_transmit
 * @section_end
 *
 * @section_func Remote voice
 * @desc Read incoming audio frames and inspect remote streams:
 * @ref photon_voice_get_frame_queue_count
 * @ref photon_voice_clear_frame_queue
 * @ref photon_voice_peek_next_frame_size
 * @ref photon_voice_peek_next_frame_player_id
 * @ref photon_voice_peek_next_frame_voice_id
 * @ref photon_voice_receive_frame_buffer
 * @ref photon_voice_get_remote_voice_count
 * @ref photon_voice_get_remote_voice_player_id
 * @ref photon_voice_get_remote_voice_id
 * @ref photon_voice_get_remote_voice_codec
 * @ref photon_voice_get_remote_voice_sample_rate
 * @ref photon_voice_get_remote_voice_channels
 * @ref photon_voice_get_remote_voice_is_speaking
 * @section_end
 *
 * @section_func Remote player mixing
 * @desc Mute and set the volume of remote players locally:
 * @ref photon_voice_set_remote_player_muted
 * @ref photon_voice_get_remote_player_muted
 * @ref photon_voice_set_remote_player_volume
 * @ref photon_voice_get_remote_player_volume
 * @section_end
 *
 * @section_func Statistics & tuning
 * @desc Inspect voice statistics and tune behaviour:
 * @ref photon_voice_get_frames_sent
 * @ref photon_voice_get_frames_received
 * @ref photon_voice_get_frames_lost
 * @ref photon_voice_get_round_trip_time
 * @ref photon_voice_get_round_trip_time_variance
 * @ref photon_voice_get_debug_lost_percent
 * @ref photon_voice_set_debug_lost_percent
 * @ref photon_voice_get_speaking_threshold_ms
 * @ref photon_voice_set_speaking_threshold_ms
 * @section_end
 *
 * @section_func Callbacks
 * @desc Register and remove the Voice event callbacks:
 * @ref photon_voice_set_callback_remote_voice_added
 * @ref photon_voice_set_callback_remote_voice_removed
 * @ref photon_voice_set_callback_speaking_changed
 * @ref photon_voice_set_callback_debug
 * @ref photon_voice_remove_callback_remote_voice_added
 * @ref photon_voice_remove_callback_remote_voice_removed
 * @ref photon_voice_remove_callback_speaking_changed
 * @ref photon_voice_remove_callback_debug
 * @section_end
 *
 * @section_const Constants
 * @desc The Voice module defines the following constants:
 * @ref PhotonVoiceCodec
 * @section_end
 *
 * @module_end
 */
