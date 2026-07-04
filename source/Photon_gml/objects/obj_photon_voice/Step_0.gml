if (!voice_initialized)
{
    exit;
}

photon_voice_service();

// ==========================================================
// SEND REAL MIC FRAMES TO PHOTON
// ==========================================================
if (voice_local_id >= 0)
{
    while (voice_mic_accum_count >= voice_mic_samples_per_frame)
    {
        var _samples = voice_mic_samples_per_frame; // 320
        var _bytes = _samples * 2; // 640
        var _buf = buffer_create(_bytes, buffer_fixed, 1);

        buffer_seek(_buf, buffer_seek_start, 0);

        for (var i = 0; i < _samples; ++i)
        {
            buffer_write(_buf, buffer_s16, voice_mic_accum[i]);
        }

        var _ok = photon_voice_push_frame_buffer(voice_local_id, _buf, _bytes);

        if (_ok)
        {
            show_debug_message("[voice send] frame sent");
        }
        else
        {
            show_debug_message("[voice send] push failed");
        }

        buffer_delete(_buf);

        // Shift remaining samples down
        var _remain = voice_mic_accum_count - _samples;
        for (var j = 0; j < _remain; ++j)
        {
            voice_mic_accum[j] = voice_mic_accum[j + _samples];
        }
        voice_mic_accum_count = _remain;
    }
}

// ==========================================================
// RECEIVE DECODED PCM FROM PHOTON AND PLAY IT
// ==========================================================
while (photon_voice_get_frame_queue_count() > 0)
{
    var _size = photon_voice_peek_next_frame_size();
    var _player_id = photon_voice_peek_next_frame_player_id();
    var _voice_id = photon_voice_peek_next_frame_voice_id();

    show_debug_message($"RECV {{ _player_id : {_player_id}, _size : {_size}, _voice_id : {_voice_id} }}");

    if (_size <= 0)
    {
        break;
    }

    // Use grow buffer, and prefill it so GM does not consider it empty
    var _out = buffer_create(_size, buffer_fixed, 1024);

    for (var i = 0; i < _size; ++i)
    {
        buffer_write(_out, buffer_u8, 0);
    }

    buffer_seek(_out, buffer_seek_start, 0);

    var _result = photon_voice_receive_frame_buffer(_out, _size, 0);

    if (_result.ok && _result.bytes_written > 0)
    {
        show_debug_message($"[voice recv] player={_player_id} voice={_voice_id} bytes={_result.bytes_written}");

        buffer_seek(_out, buffer_seek_start, 0);

        audio_queue_sound(voice_play_queue, _out, 0, _result.bytes_written);

        // Keep queued buffer alive
        array_push(voice_play_buffers, _out);

        if (!audio_is_playing(voice_play_queue))
        {
            audio_play_sound(voice_play_queue, 0, true);
        }
    }
    else
    {
        buffer_delete(_out);
    }
}
// Optional debug every step or occasionally
// show_debug_message($"sent={photon_voice_get_frames_sent()} recv={photon_voice_get_frames_received()}");	