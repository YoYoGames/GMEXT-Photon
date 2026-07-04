
if(os_type == os_android)
{
	if(!os_check_permission("android.permission.BLUETOOTH_CONNECT") or!os_check_permission("android.permission.RECORD_AUDIO"))
	{
		os_request_permission("android.permission.RECORD_AUDIO","android.permission.BLUETOOTH_CONNECT")
		room_goto(rm_playfab_menu)
	}
}


if(os_type == os_ios)
{
	if(MobilUtils_iOS_Mic_Check() != MobilUtils_iOS_Mic_Request_GRANTED)
		MobilUtils_iOS_Mic_Request()
}

