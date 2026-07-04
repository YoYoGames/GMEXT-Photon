
if(mouse_check_button(mb_left))
{
	var b = buffer_create(64, buffer_grow, 1);
	buffer_seek(b, buffer_seek_start, 0);
	
	buffer_write(b, buffer_u16, mouse_x);
	buffer_write(b, buffer_u16, mouse_y);
	
	instance_create_depth(mouse_x,mouse_y,0,obj_photon_room_points_point)
	
	photon_realtime_operation_raise_event_buffer(true, b, buffer_tell(b), 100);
	
	buffer_delete(b)
}



repeat(photon_realtime_get_buffer_event_queue_count())
{
	var recv = buffer_create(256, buffer_fixed, 1);
	var r = photon_realtime_receive_one_event_buffer(recv, 256, 0);

	if (r.ok)
	{
	
	
	    buffer_seek(recv, buffer_seek_start, 0);

	    var _x = buffer_read(recv, buffer_u16);
	    var _y = buffer_read(recv, buffer_u16);
	
		instance_create_depth(_x,_y,0,obj_photon_room_points_point)
	}

	buffer_delete(recv)
}

