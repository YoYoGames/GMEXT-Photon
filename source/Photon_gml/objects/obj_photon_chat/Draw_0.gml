
draw_set_font(fnt_gm_15);
draw_set_halign(fa_left);
draw_set_valign(fa_top);

var _x = 30;
var _y = 150;

draw_text(_x, _y, "=== PHOTON CHAT ===");
_y += 20;

draw_text(_x, _y, $"Initialized: {photon_chat_is_initialized()}");
_y += 20;
draw_text(_x, _y, $"Connected: {photon_chat_is_connected()}");
_y += 20;
draw_text(_x, _y, $"State: {photon_chat_get_state()}");
_y += 20;
draw_text(_x, _y, $"Disconnect Cause: {photon_chat_get_disconnect_cause()}");
_y += 20;
draw_text(_x, _y, $"User ID: {photon_chat_get_user_id()}");
_y += 20;
draw_text(_x, _y, $"Region: {photon_chat_get_region()}");
_y += 20;
draw_text(_x, _y, $"Server Time: {photon_chat_get_server_time()}");
_y += 20;
draw_text(_x, _y, $"Server Time Offset: {photon_chat_get_server_time_offset()}");
_y += 20;
draw_text(_x, _y, $"Bytes In: {photon_chat_get_bytes_in()}");
_y += 20;
draw_text(_x, _y, $"Bytes Out: {photon_chat_get_bytes_out()}");
_y += 30;

var _public_count = photon_chat_get_channel_count(PhotonChatChannelType.Public);
draw_text(_x, _y, $"Public Channels: {_public_count}");
_y += 20;

for (var i = 0; i < _public_count; ++i)
{
    var _ch = photon_chat_get_channel_name(PhotonChatChannelType.Public, i);
    draw_text(_x, _y, $"[{i}] {_ch}");
    _y += 20;

    var _msg_count = photon_chat_get_channel_message_count(PhotonChatChannelType.Public, _ch);
    var _start = max(0, _msg_count - 3);

    for (var j = _start; j < _msg_count; ++j)
    {
        var _sender = photon_chat_get_channel_sender(PhotonChatChannelType.Public, _ch, j);
        var _msg = photon_chat_get_channel_message(PhotonChatChannelType.Public, _ch, j);
        draw_text(_x + 20, _y, $"{_sender}: {_msg}");
        _y += 20;
    }
}