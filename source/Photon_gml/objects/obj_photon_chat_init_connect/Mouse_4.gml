photon_chat_set_callback_connected(function(_error_code, _error_string) {
    show_debug_message($"[CHAT CONNECT] code={_error_code} error={_error_string}");
    if (_error_code == 0)
    {
        room_goto(rm_photon_chat_connected)
    }
})

photon_chat_set_callback_disconnected(function() {
    show_debug_message("[CHAT] Disconnected");
	room_goto(rm_photon_chat)
})

photon_chat_set_callback_connection_error(function(_error_code) {
    show_debug_message($"[CHAT] Connection error: {_error_code}");
})

var opts = new PhotonChatConnectOptions();
opts.authentication_values = new PhotonRealtimeAuthenticationValues();
//opts.authentication_values.user_id = "user_" + string(irandom_range(1000000,9999999))
var _appId = extension_get_option_value("GMPhoton", "appIdChat");
photon_chat_connect(_appId, "1.0", opts)
