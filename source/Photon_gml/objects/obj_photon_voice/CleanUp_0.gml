if (voice_mic_record_channel >= 0)
{
    audio_stop_recording(voice_mic_record_channel);
    voice_mic_record_channel = -1;
}

if (voice_play_queue != -1)
{
    audio_stop_sound(voice_play_queue);
    audio_free_play_queue(voice_play_queue);
    voice_play_queue = -1;
}

for (var i = 0; i < array_length(voice_play_buffers); ++i)
{
    var _buf = voice_play_buffers[i];
    if (buffer_exists(_buf))
    {
        buffer_delete(_buf);
    }
}
voice_play_buffers = [];

if (voice_initialized)
{
    photon_voice_remove_callback_remote_voice_added();
    photon_voice_remove_callback_remote_voice_removed();
    photon_voice_remove_callback_speaking_changed();
    photon_voice_remove_callback_debug();

    photon_voice_shutdown();
    voice_initialized = false;
}

