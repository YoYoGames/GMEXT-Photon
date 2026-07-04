
event_inherited();

text = "Refresh"


photon_realtime_set_callback_join_room_event(function()
{
    show_debug_message("JOIN LOBBY RETURN");
});

photon_realtime_set_callback_room_list_update(function()
{
	with(obj_photon_matchmaking_room)
		instance_destroy()
	
	show_debug_message("photon_set_callback_room_list_update CALLED")
    var _count = photon_realtime_get_room_list_count();
    for (var _i = 0; _i < _count; _i++)
    {
        var _struct = photon_realtime_get_room_info_by_index(_i)
        //show_debug_message(_struct)
		//{ max_players : 8, is_open : 1, custom_properties : {  }, name : "default", player_count : 1 }
		instance_create_depth(500,200+_i*80,0,obj_photon_matchmaking_room,{image_xscale:4,data: _struct})
    }
});


photon_realtime_operation_join_lobby("default", PhotonRealtimeLobbyType.Default, function()
	{
		show_debug_message($"photon_operation_join_lobby")
	});


