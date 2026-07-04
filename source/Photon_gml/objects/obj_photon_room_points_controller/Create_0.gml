game_state = "waiting";

// Every player starts NOT ready
photon_realtime_player_properties_set_local_bool("ready", false);

// Master initializes room state
if (photon_realtime_get_master_client_number() == photon_realtime_get_local_player_number())
{
    photon_realtime_room_properties_set_string("game_state", "waiting");
}

photon_realtime_set_callback_available_regions(function(_regions, _servers) {
    show_debug_message("on available regions: " + string(_regions) + " / " + string(_servers));
});

photon_realtime_set_callback_disconnected(function() {
    show_debug_message("on disconnected");
    room_goto(rm_photon_realtime_init);
});

photon_realtime_set_callback_connection_error(function(_code) {
    var str = "on connection_error: " + string(_code);
    show_debug_message(str);
});

photon_realtime_set_callback_client_error(function(_code) {
    show_debug_message("on client_error: " + string(_code));
});

photon_realtime_set_callback_server_error(function(_code) {
    show_debug_message("on server_error: " + string(_code));
});

photon_realtime_set_callback_warning(function(_code) {
    show_debug_message("on warning: " + string(_code));
});

photon_realtime_set_callback_join_room_event(function(_joining_player_number, _player_number, _player_name, _user_id_cb, _is_inactive, _is_master_client) {
    show_debug_message(
        "on join_room_event: " +
        "joining=" + string(_joining_player_number) +
        ", player=" + string(_player_number) +
        ", name=" + string(_player_name) +
        ", user_id=" + string(_user_id_cb) +
        ", inactive=" + string(_is_inactive) +
        ", master=" + string(_is_master_client)
    );
});

photon_realtime_set_callback_leave_room_event(function(_player_number, _is_inactive) {
    show_debug_message(
        "on leave_room_event: " +
        "player=" + string(_player_number) +
        ", inactive=" + string(_is_inactive)
    );
});

photon_realtime_set_callback_custom_event(function(_player_number, _event_code, _payload) {
    show_debug_message(
        "on custom_event: " +
        "player=" + string(_player_number) +
        ", event_code=" + string(_event_code) +
        ", payload=" + string(_payload)
    );
});

function func_updated_room(_game_state)
{
    game_state = _game_state;
}

photon_realtime_set_callback_room_properties_change(function(properties) {
    show_debug_message("on room_properties_change: " + string(properties));

    if (variable_struct_exists(properties, "game_state"))
    {
        // We should update locally, because if we update it ourselves we don't receive the callback.
        func_updated_room(properties.game_state);
    }
});

function func_updated_player()
{
    var me = photon_realtime_get_local_player_number();
    var master = photon_realtime_get_master_client_number();

    if (me != master) return;

    var count = photon_realtime_get_room_player_count();

    if (count < 2)
    {
        photon_realtime_room_properties_set_string("game_state", "waiting");
        func_updated_room("waiting");
        return;
    }

    var all_ready = true;

    for (var i = 1; i <= count; i++)
    {
        var ready;

        if (i == me)
        {
            ready = photon_realtime_player_properties_get_local_bool("ready");
        }
        else
        {
            ready = photon_realtime_player_properties_get_remote_bool(i, "ready");
        }

        if (!ready)
        {
            all_ready = false;
            break;
        }
    }

    if (all_ready)
    {
        show_debug_message("game_state: playing");
        photon_realtime_room_properties_set_string("game_state", "playing");
        func_updated_room("playing");
    }
    else
    {
        show_debug_message("game_state: waiting");
        photon_realtime_room_properties_set_string("game_state", "waiting");
        func_updated_room("waiting");
    }
}

photon_realtime_set_callback_player_properties_change(function(_player_number, properties) {
    show_debug_message(
        "on player_properties_change: player=" +
        string(_player_number) +
        ", properties=" +
        string(properties)
    );

    if (variable_struct_exists(properties, "ready"))
    {
        // We should update locally, because if we update it ourselves we don't receive the callback.
        func_updated_player();
    }
});

