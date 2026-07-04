
var _photonRoomOptions = new PhotonRealtimeRoomOptions()
_photonRoomOptions.max_players = 8
_photonRoomOptions.is_visible = true
_photonRoomOptions.is_open = true
_photonRoomOptions.lobby_name = "default"
_photonRoomOptions.lobby_type = PhotonRealtimeLobbyType.Default
_photonRoomOptions.lobby_keys = ["mode", "build", "party_size", "skill_bucket"]
_photonRoomOptions.expected_users = []

var custom_props = {
	};

photon_realtime_operation_join_or_create_room("default",_photonRoomOptions,custom_props,undefined,function(_error_code, _error_string, _room_name, _player_number){
		show_debug_message($"on join_or_create_room_return {{_error_code, _error_string, _room_name, _player_number}}")
		if(_error_code == PhotonRealtimeAppErrorCode.Ok)
		{
			room_goto(rm_photon_realtime_room)
		}
	});
