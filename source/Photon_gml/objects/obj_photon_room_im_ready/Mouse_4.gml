
var ready = photon_realtime_player_properties_get_local_bool("ready");
photon_realtime_player_properties_set_local_bool("ready", !ready);

locked = !ready

//We should update locally, due if we update we don't get updated....
obj_photon_room_points_controller.func_updated_player()
