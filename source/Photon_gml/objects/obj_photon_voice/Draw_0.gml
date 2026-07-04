
draw_set_font(fnt_gm_15);
draw_set_halign(fa_left);
draw_set_valign(fa_top);

var _x = 500;
var _y = 100;

draw_text(_x, _y, "=== PHOTON VOICE ===");
_y += 20;

draw_text(_x, _y, $"Initialized: {photon_voice_is_initialized()}");
_y += 20;

draw_text(_x, _y, $"Local Voice ID: {voice_local_id}");
_y += 20;

draw_text(_x, _y, $"Voice Channel: {voice_channel_id}");
_y += 20;

draw_text(_x, _y, $"Queued Frames: {photon_voice_get_frame_queue_count()}");
_y += 20;

draw_text(_x, _y, $"Remote Voice Count: {photon_voice_get_remote_voice_count()}");
_y += 20;

draw_text(_x, _y, $"Peer RTT: {photon_realtime_peer_get_round_trip_time()}");
_y += 20;

draw_text(_x, _y, $"Peer Bytes In: {photon_realtime_peer_get_bytes_in()}");
_y += 20;

draw_text(_x, _y, $"Peer Bytes Out: {photon_realtime_peer_get_bytes_out()}");
_y += 30;

