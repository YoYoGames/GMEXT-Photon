
photon_realtime_operation_leave_room(false,false,function(_error_code,_error_string){
		
		if(_error_code == PhotonRealtimeAppErrorCode.Ok)
		{
			room_goto(rm_photon_realtime_matchmaking)
		}
	});
