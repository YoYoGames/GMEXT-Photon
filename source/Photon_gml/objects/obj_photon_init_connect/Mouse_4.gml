


//TODO?????
//photon_select_region(obj_photon_init_connect_region.code)


photon_realtime_set_callback_connected(function(_error_code, _error_string, _region) {
    show_debug_message($"[REALTIME CONNECT] code={_error_code} error={_error_string} region={_region}");
    if (_error_code == PhotonRealtimeAppErrorCode.Ok)
    {
        room_goto(rm_photon_realtime_matchmaking)
    }
})

photon_realtime_set_callback_disconnected(function() {
    show_debug_message("[REALTIME] Disconnected");
	room_goto(rm_photon_realtime_init)
})

photon_realtime_set_callback_connection_error(function(_error_code) {
    show_debug_message($"[REALTIME] Connection error: {_error_code}");
})

show_debug_message($"Connecting into region: {obj_photon_init_connect_region.code} - {obj_photon_init_connect_region.location}")

var _photonConnectOptions = new PhotonRealtimeConnectOptions()
var _photonAuthenticationValues = new PhotonRealtimeAuthenticationValues()
//_photonAuthenticationValues.user_id = "user_" + string(irandom_range(1000000,9999999))

_photonConnectOptions.authentication_values = _photonAuthenticationValues

var _appId = extension_get_option_value("GMPhoton", "appIdRealtime")
photon_realtime_connect(_appId, "1.0", _photonConnectOptions)