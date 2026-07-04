
if(goto == rm_photon)
{
	with(obj_photon_realtime)
		instance_destroy()
	with(obj_photon_voice)
		instance_destroy()
	with(obj_photon_chat)
		instance_destroy()
}

room_goto(goto)
