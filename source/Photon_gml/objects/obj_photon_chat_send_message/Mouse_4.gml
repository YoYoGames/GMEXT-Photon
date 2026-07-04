
var channel = ""
with(obj_photon_chat_channel_select)
if(locked)
{
	channel = text
	break
}


if (photon_chat_is_connected())// && chat_subscribed)
{
    var _msg = string_trim("HELLO WORLD");
    if (_msg != "")
    {
        if (photon_chat_operation_publish_message(channel, _msg))
        {
            //chat_input = "";
        }
        else
        {
            show_debug_message("[system] failed to publish message");
        }
    }
}
