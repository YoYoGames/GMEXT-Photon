
var channel = ""
with(obj_photon_chat_channel_select)
if(locked)
{
	channel = text
	break
}


photon_chat_operation_subscribe([channel],false, function(_results) {
	    var _count = array_length(_results);
	    for (var i = 0; i < _count; ++i)
	    {
	        var _r = _results[i];
	        show_debug_message("[subscribe] " + _r.channel_name + " success=" + string(_r.success));
	        if (_r.success)
	        {
	            //chat_subscribed = true;
				show_debug_message("[SUBSCRIBED]");
	        }
	    }
	});
		