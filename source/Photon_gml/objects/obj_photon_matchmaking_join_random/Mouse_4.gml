
var _photonJoinRandomOptions = new PhotonRealtimeJoinRandomOptions()

//_photonJoinRandomOptions.max_players = 8
_photonJoinRandomOptions.matchmaking_mode = PhotonRealtimeMatchmakingMode.FillRoom
_photonJoinRandomOptions.lobby_name = "default"
_photonJoinRandomOptions.lobby_type = PhotonRealtimeLobbyType.Default
_photonJoinRandomOptions.sql_filter = ""
_photonJoinRandomOptions.expected_users = []

var expected_props = {
	};

photon_realtime_operation_join_random_room(_photonJoinRandomOptions, expected_props,function(_error_code, _error_string, _room_name, _player_number){
		if(_error_code == PhotonRealtimeAppErrorCode.Ok)
		{
			room_goto(rm_photon_realtime_room)
		}
	});


