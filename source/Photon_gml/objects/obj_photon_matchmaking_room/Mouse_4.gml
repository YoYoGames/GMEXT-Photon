
var _photonJoinRoomOptions = new PhotonRealtimeJoinRoomOptions()
_photonJoinRoomOptions.rejoin = false
_photonJoinRoomOptions.cache_slice_index = 0

photon_realtime_operation_join_room(data.name, _photonJoinRoomOptions, function(_error_code, _error_string, _room_name, _player_number){
		if(_error_code == PhotonRealtimeAppErrorCode.Ok)
		{
			room_goto(rm_photon_realtime_room)
		}
	});
