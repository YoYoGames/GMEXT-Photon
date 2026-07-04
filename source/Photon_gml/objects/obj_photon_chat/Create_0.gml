
randomize()

chat_user_id = "user_" + string(irandom_range(1000, 9999));

photon_chat_set_callback_debug(function(_level, _text) {
    show_debug_message($"[CHAT DEBUG] level={_level} text={_text}");
});

photon_chat_set_callback_state_change(function(_state) {
    show_debug_message($"[CHAT STATE] {_state}");
});


photon_chat_set_callback_client_error(function(_error_code) {
    show_debug_message($"[CHAT CLIENT ERROR] {_error_code}");
});

photon_chat_set_callback_warning(function(_warning_code) {
    show_debug_message($"[CHAT WARNING] {_warning_code}");
});

photon_chat_set_callback_server_error(function(_error_code) {
    show_debug_message($"[CHAT SERVER ERROR] {_error_code}");
});

photon_chat_set_callback_get_messages(function(_channel_name, _messages) {
    var _count = array_length(_messages);
    for (var i = 0; i < _count; ++i)
    {
        var _msg = _messages[i];
        show_debug_message("[" + _channel_name + "] " + _msg.sender + ": " + _msg.content);
    }
});

photon_chat_set_callback_private_message(function(_sender, _channel_name, _message) {
    show_debug_message("[pm] " + _sender + ": " + _message);
});

photon_chat_set_callback_status_update(function(_user, _status, _got_message, _message) {
    var _txt = "[status] " + _user + " -> " + string(_status);
    if (_got_message) _txt += " (" + _message + ")";
    show_debug_message(_txt);
});


photon_chat_init();
