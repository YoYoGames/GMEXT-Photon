
var channel = ""
with(obj_photon_chat_channel_select)
if(locked)
{
	channel = text
	break
}

photon_chat_operation_unsubscribe([channel],function(_channels)
	    {
	        for (var i = 0; i < array_length(_channels); ++i)
	        {
	            show_debug_message($"[unsubscribe] {_channels[i]}");
	        }
	    }
	);
