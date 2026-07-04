
if (photon_realtime_is_in_room())
{
    photon_realtime_operation_leave_room(false, false,function(){});
}

if (photon_realtime_is_connected())
{
    photon_realtime_disconnect();
}

photon_realtime_shutdown()
