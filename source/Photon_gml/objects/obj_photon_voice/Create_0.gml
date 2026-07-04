
// ==========================================================
// PHOTON VOICE CONFIG
// ==========================================================
voice_channel_id = 0;
voice_codec = PhotonVoiceCodec.AudioOpus;
voice_sample_rate = 16000;
voice_channels = 1;
voice_bitrate = 16000;
voice_frames_per_packet = 2; // 2 * 10ms = 20ms
voice_speaking_threshold_ms = 200;

voice_local_id = -1;
voice_initialized = false;
voice_joined_channel = false;

// ==========================================================
// MIC CAPTURE STATE
// ==========================================================
if(!variable_instance_exists(id,"voice_mic_record_index"))
	voice_mic_record_index = 0;
voice_mic_record_channel = -1;

voice_mic_accum = [];
voice_mic_accum_count = 0;
voice_mic_samples_per_frame = 320; // 20ms @ 16000 mono
voice_mic_debug_chunks = 0;

// ==========================================================
// PLAYBACK STATE
// ==========================================================
voice_play_queue = audio_create_play_queue(buffer_s16, 16000, audio_mono);
voice_play_buffers = [];

// ==========================================================
// HELPERS
// ==========================================================
function voice_mic_push_sample(_s)
{
    voice_mic_accum[voice_mic_accum_count] = _s;
    voice_mic_accum_count += 1;
}

function voice_mic_on_recording(_async_load)
{
    if (!voice_initialized) return;
    if (voice_local_id < 0) return;
    if (voice_mic_record_channel < 0) return;

    var _channel = _async_load[? "channel_index"];
    if (_channel != voice_mic_record_channel) return;

    var _src = _async_load[? "buffer_id"];
    var _len = _async_load[? "data_len"];
    if (_len <= 1) return;

    voice_mic_debug_chunks += 1;

    // Keep s16 alignment
    var _safe_len = _len - (_len mod 2);
    if (_safe_len <= 0) return;

    // Copy async buffer so it is safe to inspect
    var _buf = buffer_create(_safe_len, buffer_fixed, 1);
    buffer_copy(_src, 0, _safe_len, _buf, 0);
    buffer_seek(_buf, buffer_seek_start, 0);

    // First-pass assumption:
    // mic buffer can be consumed as s16 PCM samples.
    var _sample_count = _safe_len div 2;

    for (var i = 0; i < _sample_count; ++i)
    {
        var _s = buffer_read(_buf, buffer_s16);
        voice_mic_push_sample(_s);
    }

    buffer_delete(_buf);

    if ((voice_mic_debug_chunks mod 30) == 0)
    {
        show_debug_message($"[mic] chunks={voice_mic_debug_chunks} accum_samples={voice_mic_accum_count}");
    }
}

// ==========================================================
// PHOTON CALLBACKS
// ==========================================================
photon_voice_set_callback_remote_voice_added(function(_player_id, _voice_id, _codec, _sample_rate, _channels) {
    show_debug_message($"[voice added] player={_player_id} voice={_voice_id} codec={_codec} rate={_sample_rate} ch={_channels}");
});

photon_voice_set_callback_remote_voice_removed(function(_player_id, _voice_id) {
    show_debug_message($"[voice removed] player={_player_id} voice={_voice_id}");
});

photon_voice_set_callback_speaking_changed(function(_player_id, _voice_id, _is_speaking) {
    show_debug_message($"[speaking] player={_player_id} voice={_voice_id} speaking={_is_speaking}");
});

photon_voice_set_callback_debug(function(_level, _message) {
    show_debug_message($"[voice sdk] level={_level} {_message}");
});

// ==========================================================
// INIT PHOTON VOICE
// ==========================================================
voice_initialized = photon_voice_init();

if (voice_initialized)
{
    voice_joined_channel = photon_voice_on_join_channel(voice_channel_id);

    voice_local_id = photon_voice_create_local_voice(
        voice_channel_id,
        voice_codec,
        voice_sample_rate,
        voice_channels,
        voice_bitrate,
        voice_frames_per_packet
    );

    photon_voice_set_speaking_threshold_ms(voice_speaking_threshold_ms);

    // Announce our local voice to all players and trigger the voice-info exchange.
    // Called after create_local_voice so onJoinAllChannels has a voice to broadcast.
    // Buffered 202 events from existing players are replayed inside photon_voice_init(),
    // so remote voice discovery happens even when this object is created late.
    photon_voice_notify_joined_room();

    show_debug_message($"[voice init] init={voice_initialized} joined={voice_joined_channel} local_id={voice_local_id}");

    // Start mic only after voice is ready
    var _inf = audio_get_recorder_info(voice_mic_record_index);
    show_debug_message("[mic info] " + json_encode(_inf));

    voice_mic_record_channel = audio_start_recording(voice_mic_record_index);
    show_debug_message($"[mic] started channel={voice_mic_record_channel}");
}
else
{
    show_debug_message("[voice init] failed");
}