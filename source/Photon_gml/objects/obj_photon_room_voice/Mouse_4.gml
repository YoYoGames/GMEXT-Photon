
function mic_permissions_granted()
{
	if(os_type == os_android)
	{
		if(!os_check_permission("android.permission.BLUETOOTH_CONNECT") or!os_check_permission("android.permission.RECORD_AUDIO"))
		{
			os_request_permission("android.permission.RECORD_AUDIO","android.permission.BLUETOOTH_CONNECT")
			return false
		}
	}


	if(os_type == os_ios)
	{
		if(MobilUtils_iOS_Mic_Check() != MobilUtils_iOS_Mic_Request_GRANTED)
		{
			MobilUtils_iOS_Mic_Request()
			return false
		}
	}
	
	return true
}

if(!mic_permissions_granted())
	exit


/// @func mic_permission_ensure()
/// @desc Returns true if mic permission is already granted.
///       If not granted, it requests it (when possible) and returns false.

function mic_permission_ensure()
{
    switch (os_type)
    {
        case os_android:
        {
            var perm = "android.permission.RECORD_AUDIO";
            var status = os_check_permission(perm);

            if (status == os_permission_granted)
                return true;

            // Not granted → request it
            if (status == os_permission_denied)
                os_request_permission(perm);

            return false;
        }

        case os_ios:
        {
            // GameMaker does NOT expose a direct permission check API for mic on iOS.
            // iOS shows the permission dialog automatically when recording starts.

            // Best practical approach:
            // Try to detect if audio input already works (if your system tracks it),
            // otherwise trigger request by starting mic once.

            // Minimal safe behavior:
            //if (audio_get_recording()) // if you're already recording
                return true;

            // Not guaranteed granted → trigger system popup indirectly
            // (you must start/stop mic once from user interaction)
            return false;
        }
    }

    // Other platforms (Windows, etc.)
    return true;
}



if(!mic_permission_ensure())
	{exit}

if(instance_number(obj_photon_voice))
{
	with(obj_photon_voice)
		instance_destroy()
}
else
{
	/// Returns the recorder index that best matches the given voice configuration.
	/// Scores each device: sample_rate + channels + data_format all have to match
	/// to be considered compatible. Among compatible devices, name_filter breaks ties.
	/// Returns -1 if no recording devices exist.
	function voice_pick_recorder(_sample_rate, _channels, _data_format, _name_filter)
	{
	    var _count = audio_get_recorder_count();
	    if (_count == 0) return -1;

	    var _best_index = -1;
	    var _best_score = -1;

	    for (var i = 0; i < _count; i++)
	    {
	        var _inf = audio_get_recorder_info(i);
			var mic_name = _inf[?"name"]
			var mic_sample_rate = _inf[?"sample_rate"]
			var mic_channels = _inf[?"channels"]
			var mic_data_format = _inf[?"data_format"]
				
	        show_debug_message($"[mic] index={i} name={mic_name} rate={mic_sample_rate} ch={mic_channels} fmt={mic_data_format}");

	        // Each matching property adds a point; mismatches on rate/channels/format
	        // are hard disqualifiers since the voice stream won't decode correctly.
	        if (mic_sample_rate  != _sample_rate)  continue;
	        if (mic_channels     != _channels)      continue;
	        if (mic_data_format  != _data_format)   continue;

	        var _score = 0;

	        // Name match is a bonus — prefer it but don't require it
	        if (_name_filter != "" && string_pos(string_lower(_name_filter), string_lower(_inf.name)) > 0)
	            _score += 1;

	        if (_score > _best_score)
	        {
	            _best_score = _score;
	            _best_index = i;
	        }
	    }

	    // No exact match found — fall back to index 0 with a warning
	    if (_best_index == -1)
	    {
	        show_debug_message("[mic] warning: no device matches voice config, falling back to index 0");
	        _best_index = 0;
	    }
		
	    show_debug_message($"[mic] selected({_best_index}): {json_encode(audio_get_recorder_info(_best_index))}");
	    return _best_index;
	}

	//Probably you want give this option to the users
	var _idx = voice_pick_recorder(16000, audio_mono, buffer_s16, "");

	if (_idx >= 0)
	    instance_create_depth(0, 0, 0, obj_photon_voice, { voice_mic_record_index: _idx });
	else
	    show_debug_message("[mic] no recording devices found");
}


