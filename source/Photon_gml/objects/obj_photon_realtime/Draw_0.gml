
draw_set_font(fnt_gm_15)
draw_set_halign(fa_left)
draw_set_valign(fa_left)

var _x = 30
var _y = 100


draw_text(_x,_y,$"Version: {photon_common_get_sdk_version()}")
_y+=20
draw_text(_x,_y,$"Initialized: {photon_realtime_is_initialized()}")
_y+=20
draw_text(_x,_y,$"Connected: {photon_realtime_is_connected()}")
_y+=20
draw_text(_x,_y,$"In Room: {photon_realtime_is_in_room()}")
_y+=20
draw_text(_x,_y,$"in Lobby: {photon_realtime_is_in_lobby()}")
_y+=20
draw_text(_x,_y,$"Room Name: {photon_realtime_get_current_room_name()}")
_y+=20
draw_text(_x,_y,$"Local PLayer: {photon_realtime_get_local_player_number()}")
_y+=20

draw_text(_x,_y,$"Bytes In: {photon_realtime_get_bytes_in()}")
_y+=20
draw_text(_x,_y,$"Bytes Out: {photon_realtime_get_bytes_out()}")
_y+=20
draw_text(_x,_y,$"Server On: {photon_realtime_get_server_time()}")
_y+=20
draw_text(_x,_y,$"Get State: {photon_realtime_get_state()}")
_y+=20
draw_text(_x,_y,$"Get Region: {photon_realtime_get_region()}")
_y+=20




draw_text(_x,_y,$"Peer State: {photon_realtime_peer_get_state()}")
_y+=20
draw_text(_x,_y,$"Get Round Trip Time: {photon_realtime_peer_get_round_trip_time()}")
_y+=20
draw_text(_x,_y,$"Get Round Trip Time Variance: {photon_realtime_peer_get_round_trip_time_variance()}")
_y+=20
draw_text(_x,_y,$"Peer Bytes In: {photon_realtime_peer_get_bytes_in()}")
_y+=20
draw_text(_x,_y,$"Peer Bytes Out: {photon_realtime_peer_get_bytes_out()}")
_y+=20
draw_text(_x,_y,$"Packet Loss By CRC: {photon_realtime_peer_get_packet_loss_by_crc()}")
_y+=20

