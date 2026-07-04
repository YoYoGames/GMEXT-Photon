
randomize()

photon_realtime_set_callback_available_regions(function(_regions, _servers) {
    // _regions = ["eu", "us", "asia", ...]
    // show UI, then:
    
	show_debug_message($"on available regions {{_regions, _servers}}")
});

photon_realtime_set_callback_client_error(function(_code){
		show_debug_message($"on client_error: {_code}")
	});

photon_realtime_set_callback_server_error(function(_code){
		show_debug_message($"on server_error")
	});

photon_realtime_set_callback_warning(function(_code){
		show_debug_message($"on warning: {_code}")
	});



photon_realtime_init();
