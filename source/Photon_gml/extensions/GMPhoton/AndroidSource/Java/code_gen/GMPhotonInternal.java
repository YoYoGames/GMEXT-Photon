package ${YYAndroidPackageName};
import static com.gamemaker.ExtensionCore.ExtBridge.GMPhotonBridge.*;
import java.lang.String;
import java.nio.ByteBuffer;

public class GMPhotonInternal extends RunnerSocial {
    public double __EXT_NATIVE__GMPhoton_invocation_handler(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__GMPhoton_invocation_handler(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__GMPhoton_queue_buffer(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__GMPhoton_queue_buffer(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_init()
    {
        return __EXT_JNI__photon_realtime_init();
    }
    public double __EXT_NATIVE__photon_realtime_shutdown()
    {
        return __EXT_JNI__photon_realtime_shutdown();
    }
    public double __EXT_NATIVE__photon_realtime_service()
    {
        return __EXT_JNI__photon_realtime_service();
    }
    public double __EXT_NATIVE__photon_realtime_connect(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_connect(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_disconnect()
    {
        return __EXT_JNI__photon_realtime_disconnect();
    }
    public double __EXT_NATIVE__photon_realtime_select_region(String region)
    {
        return __EXT_JNI__photon_realtime_select_region(region);
    }
    public double __EXT_NATIVE__photon_realtime_reconnect_and_rejoin()
    {
        return __EXT_JNI__photon_realtime_reconnect_and_rejoin();
    }
    public double __EXT_NATIVE__photon_realtime_fetch_server_timestamp()
    {
        return __EXT_JNI__photon_realtime_fetch_server_timestamp();
    }
    public double __EXT_NATIVE__photon_realtime_operation_join_lobby(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_join_lobby(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_leave_lobby(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_leave_lobby(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_create_room(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_create_room(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_join_or_create_room(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_join_or_create_room(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_join_room(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_join_room(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_join_random_room(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_join_random_room(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_leave_room(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_leave_room(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_join_random_or_create_room(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_join_random_or_create_room(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_get_room_list(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_get_room_list(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_lobby_stats(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_lobby_stats(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_find_friends(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_find_friends(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_web_rpc(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_web_rpc(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_change_groups(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_change_groups(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_custom_auth_next_step(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_custom_auth_next_step(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_raise_event_string(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_raise_event_string(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_operation_raise_event_buffer(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_operation_raise_event_buffer(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_get_buffer_event_queue_count()
    {
        return __EXT_JNI__photon_realtime_get_buffer_event_queue_count();
    }
    public double __EXT_NATIVE__photon_realtime_clear_buffer_event_queue()
    {
        return __EXT_JNI__photon_realtime_clear_buffer_event_queue();
    }
    public double __EXT_NATIVE__photon_realtime_peek_next_buffer_event_size()
    {
        return __EXT_JNI__photon_realtime_peek_next_buffer_event_size();
    }
    public double __EXT_NATIVE__photon_realtime_peek_next_buffer_event_code()
    {
        return __EXT_JNI__photon_realtime_peek_next_buffer_event_code();
    }
    public double __EXT_NATIVE__photon_realtime_receive_one_event_buffer(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_realtime_receive_one_event_buffer(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_is_initialized()
    {
        return __EXT_JNI__photon_realtime_is_initialized();
    }
    public double __EXT_NATIVE__photon_realtime_is_connected()
    {
        return __EXT_JNI__photon_realtime_is_connected();
    }
    public double __EXT_NATIVE__photon_realtime_is_in_game_room()
    {
        return __EXT_JNI__photon_realtime_is_in_game_room();
    }
    public double __EXT_NATIVE__photon_realtime_is_in_room()
    {
        return __EXT_JNI__photon_realtime_is_in_room();
    }
    public double __EXT_NATIVE__photon_realtime_is_in_lobby()
    {
        return __EXT_JNI__photon_realtime_is_in_lobby();
    }
    public String __EXT_NATIVE__photon_realtime_get_current_room_name()
    {
        return __EXT_JNI__photon_realtime_get_current_room_name();
    }
    public double __EXT_NATIVE__photon_realtime_get_local_player_number()
    {
        return __EXT_JNI__photon_realtime_get_local_player_number();
    }
    public double __EXT_NATIVE__photon_realtime_get_server_time_offset()
    {
        return __EXT_JNI__photon_realtime_get_server_time_offset();
    }
    public double __EXT_NATIVE__photon_realtime_get_server_time()
    {
        return __EXT_JNI__photon_realtime_get_server_time();
    }
    public double __EXT_NATIVE__photon_realtime_get_bytes_in()
    {
        return __EXT_JNI__photon_realtime_get_bytes_in();
    }
    public double __EXT_NATIVE__photon_realtime_get_bytes_out()
    {
        return __EXT_JNI__photon_realtime_get_bytes_out();
    }
    public double __EXT_NATIVE__photon_realtime_get_state(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_realtime_get_state(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_get_round_trip_time()
    {
        return __EXT_JNI__photon_realtime_get_round_trip_time();
    }
    public double __EXT_NATIVE__photon_realtime_get_round_trip_time_variance()
    {
        return __EXT_JNI__photon_realtime_get_round_trip_time_variance();
    }
    public double __EXT_NATIVE__photon_realtime_get_disconnected_cause(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_realtime_get_disconnected_cause(__ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__photon_realtime_get_user_id()
    {
        return __EXT_JNI__photon_realtime_get_user_id();
    }
    public double __EXT_NATIVE__photon_realtime_get_count_players_ingame()
    {
        return __EXT_JNI__photon_realtime_get_count_players_ingame();
    }
    public double __EXT_NATIVE__photon_realtime_get_count_games_running()
    {
        return __EXT_JNI__photon_realtime_get_count_games_running();
    }
    public double __EXT_NATIVE__photon_realtime_get_count_players_online()
    {
        return __EXT_JNI__photon_realtime_get_count_players_online();
    }
    public String __EXT_NATIVE__photon_realtime_get_master_server_address()
    {
        return __EXT_JNI__photon_realtime_get_master_server_address();
    }
    public String __EXT_NATIVE__photon_realtime_get_region()
    {
        return __EXT_JNI__photon_realtime_get_region();
    }
    public String __EXT_NATIVE__photon_realtime_get_region_with_best_ping()
    {
        return __EXT_JNI__photon_realtime_get_region_with_best_ping();
    }
    public double __EXT_NATIVE__photon_realtime_get_friend_list_age()
    {
        return __EXT_JNI__photon_realtime_get_friend_list_age();
    }
    public double __EXT_NATIVE__photon_realtime_get_disconnect_timeout()
    {
        return __EXT_JNI__photon_realtime_get_disconnect_timeout();
    }
    public double __EXT_NATIVE__photon_realtime_set_disconnect_timeout(double milliseconds)
    {
        return __EXT_JNI__photon_realtime_set_disconnect_timeout(milliseconds);
    }
    public double __EXT_NATIVE__photon_realtime_get_ping_interval()
    {
        return __EXT_JNI__photon_realtime_get_ping_interval();
    }
    public double __EXT_NATIVE__photon_realtime_set_ping_interval(double milliseconds)
    {
        return __EXT_JNI__photon_realtime_set_ping_interval(milliseconds);
    }
    public double __EXT_NATIVE__photon_realtime_get_auto_join_lobby()
    {
        return __EXT_JNI__photon_realtime_get_auto_join_lobby();
    }
    public double __EXT_NATIVE__photon_realtime_set_auto_join_lobby(double enabled)
    {
        return __EXT_JNI__photon_realtime_set_auto_join_lobby(enabled);
    }
    public double __EXT_NATIVE__photon_realtime_get_room_player_count()
    {
        return __EXT_JNI__photon_realtime_get_room_player_count();
    }
    public double __EXT_NATIVE__photon_realtime_get_room_max_players()
    {
        return __EXT_JNI__photon_realtime_get_room_max_players();
    }
    public double __EXT_NATIVE__photon_realtime_get_room_is_open()
    {
        return __EXT_JNI__photon_realtime_get_room_is_open();
    }
    public double __EXT_NATIVE__photon_realtime_get_room_is_visible()
    {
        return __EXT_JNI__photon_realtime_get_room_is_visible();
    }
    public double __EXT_NATIVE__photon_realtime_get_master_client_number()
    {
        return __EXT_JNI__photon_realtime_get_master_client_number();
    }
    public double __EXT_NATIVE__photon_realtime_set_master_client(double player_number)
    {
        return __EXT_JNI__photon_realtime_set_master_client(player_number);
    }
    public double __EXT_NATIVE__photon_realtime_get_room_list_count()
    {
        return __EXT_JNI__photon_realtime_get_room_list_count();
    }
    public double __EXT_NATIVE__photon_realtime_get_room_info_by_index(double index, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_realtime_get_room_info_by_index(index, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_get_player_count()
    {
        return __EXT_JNI__photon_realtime_get_player_count();
    }
    public double __EXT_NATIVE__photon_realtime_get_player_number_by_index(double index)
    {
        return __EXT_JNI__photon_realtime_get_player_number_by_index(index);
    }
    public String __EXT_NATIVE__photon_realtime_player_get_name(double player_number)
    {
        return __EXT_JNI__photon_realtime_player_get_name(player_number);
    }
    public String __EXT_NATIVE__photon_realtime_player_get_user_id(double player_number)
    {
        return __EXT_JNI__photon_realtime_player_get_user_id(player_number);
    }
    public double __EXT_NATIVE__photon_realtime_player_is_inactive(double player_number)
    {
        return __EXT_JNI__photon_realtime_player_is_inactive(player_number);
    }
    public double __EXT_NATIVE__photon_realtime_player_is_master_client(double player_number)
    {
        return __EXT_JNI__photon_realtime_player_is_master_client(player_number);
    }
    public double __EXT_NATIVE__photon_realtime_get_player_numbers(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_realtime_get_player_numbers(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_debug(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_debug(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_connected(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_connected(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_disconnected(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_disconnected(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_connection_error(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_connection_error(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_client_error(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_client_error(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_server_error(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_server_error(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_warning(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_warning(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_join_room_event(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_join_room_event(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_leave_room_event(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_leave_room_event(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_custom_event(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_custom_event(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_room_properties_change(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_room_properties_change(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_player_properties_change(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_player_properties_change(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_room_list_update(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_room_list_update(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_app_stats_update(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_app_stats_update(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_lobby_stats_update(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_lobby_stats_update(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_cache_slice_changed(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_cache_slice_changed(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_master_client_changed(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_master_client_changed(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_properties_change_failed(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_properties_change_failed(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_custom_authentication_step(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_custom_authentication_step(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_available_regions(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_available_regions(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_secret_receival(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_secret_receival(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_direct_connection_established(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_direct_connection_established(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_direct_connection_failed(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_direct_connection_failed(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_direct_message(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_direct_message(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_set_callback_custom_operation_response(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_set_callback_custom_operation_response(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_debug()
    {
        return __EXT_JNI__photon_realtime_remove_callback_debug();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_connected()
    {
        return __EXT_JNI__photon_realtime_remove_callback_connected();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_disconnected()
    {
        return __EXT_JNI__photon_realtime_remove_callback_disconnected();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_connection_error()
    {
        return __EXT_JNI__photon_realtime_remove_callback_connection_error();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_client_error()
    {
        return __EXT_JNI__photon_realtime_remove_callback_client_error();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_server_error()
    {
        return __EXT_JNI__photon_realtime_remove_callback_server_error();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_warning()
    {
        return __EXT_JNI__photon_realtime_remove_callback_warning();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_join_room_event()
    {
        return __EXT_JNI__photon_realtime_remove_callback_join_room_event();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_leave_room_event()
    {
        return __EXT_JNI__photon_realtime_remove_callback_leave_room_event();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_custom_event()
    {
        return __EXT_JNI__photon_realtime_remove_callback_custom_event();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_room_properties_change()
    {
        return __EXT_JNI__photon_realtime_remove_callback_room_properties_change();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_player_properties_change()
    {
        return __EXT_JNI__photon_realtime_remove_callback_player_properties_change();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_room_list_update()
    {
        return __EXT_JNI__photon_realtime_remove_callback_room_list_update();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_app_stats_update()
    {
        return __EXT_JNI__photon_realtime_remove_callback_app_stats_update();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_lobby_stats_update()
    {
        return __EXT_JNI__photon_realtime_remove_callback_lobby_stats_update();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_cache_slice_changed()
    {
        return __EXT_JNI__photon_realtime_remove_callback_cache_slice_changed();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_master_client_changed()
    {
        return __EXT_JNI__photon_realtime_remove_callback_master_client_changed();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_properties_change_failed()
    {
        return __EXT_JNI__photon_realtime_remove_callback_properties_change_failed();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_custom_authentication_step()
    {
        return __EXT_JNI__photon_realtime_remove_callback_custom_authentication_step();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_available_regions()
    {
        return __EXT_JNI__photon_realtime_remove_callback_available_regions();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_secret_receival()
    {
        return __EXT_JNI__photon_realtime_remove_callback_secret_receival();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_direct_connection_established()
    {
        return __EXT_JNI__photon_realtime_remove_callback_direct_connection_established();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_direct_connection_failed()
    {
        return __EXT_JNI__photon_realtime_remove_callback_direct_connection_failed();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_direct_message()
    {
        return __EXT_JNI__photon_realtime_remove_callback_direct_message();
    }
    public double __EXT_NATIVE__photon_realtime_remove_callback_custom_operation_response()
    {
        return __EXT_JNI__photon_realtime_remove_callback_custom_operation_response();
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_set_string(String key, String value)
    {
        return __EXT_JNI__photon_realtime_room_properties_set_string(key, value);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_set_i32(String key, double value)
    {
        return __EXT_JNI__photon_realtime_room_properties_set_i32(key, value);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_set_f64(String key, double value)
    {
        return __EXT_JNI__photon_realtime_room_properties_set_f64(key, value);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_set_bool(String key, double value)
    {
        return __EXT_JNI__photon_realtime_room_properties_set_bool(key, value);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_remove(String key)
    {
        return __EXT_JNI__photon_realtime_room_properties_remove(key);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_clear()
    {
        return __EXT_JNI__photon_realtime_room_properties_clear();
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_has(String key)
    {
        return __EXT_JNI__photon_realtime_room_properties_has(key);
    }
    public String __EXT_NATIVE__photon_realtime_room_properties_get_string(String key)
    {
        return __EXT_JNI__photon_realtime_room_properties_get_string(key);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_get_i32(String key)
    {
        return __EXT_JNI__photon_realtime_room_properties_get_i32(key);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_get_f64(String key)
    {
        return __EXT_JNI__photon_realtime_room_properties_get_f64(key);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_get_bool(String key)
    {
        return __EXT_JNI__photon_realtime_room_properties_get_bool(key);
    }
    public String __EXT_NATIVE__photon_realtime_room_properties_to_string()
    {
        return __EXT_JNI__photon_realtime_room_properties_to_string();
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_get_all(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_realtime_room_properties_get_all(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_cas_string(String key, String expected_value, String new_value)
    {
        return __EXT_JNI__photon_realtime_room_properties_cas_string(key, expected_value, new_value);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_cas_i32(String key, double expected_value, double new_value)
    {
        return __EXT_JNI__photon_realtime_room_properties_cas_i32(key, expected_value, new_value);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_cas_f64(String key, double expected_value, double new_value)
    {
        return __EXT_JNI__photon_realtime_room_properties_cas_f64(key, expected_value, new_value);
    }
    public double __EXT_NATIVE__photon_realtime_room_properties_cas_bool(String key, double expected_value, double new_value)
    {
        return __EXT_JNI__photon_realtime_room_properties_cas_bool(key, expected_value, new_value);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_set_local_string(String key, String value)
    {
        return __EXT_JNI__photon_realtime_player_properties_set_local_string(key, value);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_set_local_i32(String key, double value)
    {
        return __EXT_JNI__photon_realtime_player_properties_set_local_i32(key, value);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_set_local_f64(String key, double value)
    {
        return __EXT_JNI__photon_realtime_player_properties_set_local_f64(key, value);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_set_local_bool(String key, double value)
    {
        return __EXT_JNI__photon_realtime_player_properties_set_local_bool(key, value);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_remove_local(String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_remove_local(key);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_clear_local()
    {
        return __EXT_JNI__photon_realtime_player_properties_clear_local();
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_has_local(String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_has_local(key);
    }
    public String __EXT_NATIVE__photon_realtime_player_properties_get_local_string(String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_local_string(key);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_get_local_i32(String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_local_i32(key);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_get_local_f64(String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_local_f64(key);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_get_local_bool(String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_local_bool(key);
    }
    public String __EXT_NATIVE__photon_realtime_player_properties_to_string_local()
    {
        return __EXT_JNI__photon_realtime_player_properties_to_string_local();
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_get_local_all(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_local_all(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_has_remote(double player_number, String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_has_remote(player_number, key);
    }
    public String __EXT_NATIVE__photon_realtime_player_properties_get_remote_string(double player_number, String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_remote_string(player_number, key);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_get_remote_i32(double player_number, String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_remote_i32(player_number, key);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_get_remote_f64(double player_number, String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_remote_f64(player_number, key);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_get_remote_bool(double player_number, String key)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_remote_bool(player_number, key);
    }
    public String __EXT_NATIVE__photon_realtime_player_properties_to_string_remote(double player_number)
    {
        return __EXT_JNI__photon_realtime_player_properties_to_string_remote(player_number);
    }
    public double __EXT_NATIVE__photon_realtime_player_properties_get_remote_all(double player_number, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_realtime_player_properties_get_remote_all(player_number, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_peek_next_buffer_event_player_number()
    {
        return __EXT_JNI__photon_realtime_peek_next_buffer_event_player_number();
    }
    public double __EXT_NATIVE__photon_chat_init()
    {
        return __EXT_JNI__photon_chat_init();
    }
    public double __EXT_NATIVE__photon_chat_shutdown()
    {
        return __EXT_JNI__photon_chat_shutdown();
    }
    public double __EXT_NATIVE__photon_chat_service()
    {
        return __EXT_JNI__photon_chat_service();
    }
    public double __EXT_NATIVE__photon_chat_connect(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_connect(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_disconnect()
    {
        return __EXT_JNI__photon_chat_disconnect();
    }
    public double __EXT_NATIVE__photon_chat_operation_subscribe(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_operation_subscribe(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_operation_unsubscribe(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_operation_unsubscribe(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_operation_publish_message(String channel_name, String message)
    {
        return __EXT_JNI__photon_chat_operation_publish_message(channel_name, message);
    }
    public double __EXT_NATIVE__photon_chat_operation_send_private_message(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_operation_send_private_message(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_operation_set_online_status(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_operation_set_online_status(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_operation_add_friends(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_operation_add_friends(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_operation_remove_friends(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_operation_remove_friends(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_is_initialized()
    {
        return __EXT_JNI__photon_chat_is_initialized();
    }
    public double __EXT_NATIVE__photon_chat_is_connected()
    {
        return __EXT_JNI__photon_chat_is_connected();
    }
    public double __EXT_NATIVE__photon_chat_get_state(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_chat_get_state(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_get_disconnect_cause(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_chat_get_disconnect_cause(__ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__photon_chat_get_user_id()
    {
        return __EXT_JNI__photon_chat_get_user_id();
    }
    public String __EXT_NATIVE__photon_chat_get_region()
    {
        return __EXT_JNI__photon_chat_get_region();
    }
    public double __EXT_NATIVE__photon_chat_get_server_time()
    {
        return __EXT_JNI__photon_chat_get_server_time();
    }
    public double __EXT_NATIVE__photon_chat_get_server_time_offset()
    {
        return __EXT_JNI__photon_chat_get_server_time_offset();
    }
    public double __EXT_NATIVE__photon_chat_get_bytes_in()
    {
        return __EXT_JNI__photon_chat_get_bytes_in();
    }
    public double __EXT_NATIVE__photon_chat_get_bytes_out()
    {
        return __EXT_JNI__photon_chat_get_bytes_out();
    }
    public double __EXT_NATIVE__photon_chat_get_channel_count(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_get_channel_count(__arg_buffer, __arg_buffer_length);
    }
    public String __EXT_NATIVE__photon_chat_get_channel_name(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_get_channel_name(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_get_channel_message_count(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_get_channel_message_count(__arg_buffer, __arg_buffer_length);
    }
    public String __EXT_NATIVE__photon_chat_get_channel_message(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_get_channel_message(__arg_buffer, __arg_buffer_length);
    }
    public String __EXT_NATIVE__photon_chat_get_channel_sender(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_get_channel_sender(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_debug(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_debug(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_connected(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_connected(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_state_change(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_state_change(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_connection_error(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_connection_error(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_client_error(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_client_error(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_warning(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_warning(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_server_error(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_server_error(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_disconnected(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_disconnected(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_status_update(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_status_update(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_get_messages(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_get_messages(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_private_message(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_private_message(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_set_callback_receive_broadcast(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_set_callback_receive_broadcast(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_get_broadcast_queue_count()
    {
        return __EXT_JNI__photon_chat_get_broadcast_queue_count();
    }
    public double __EXT_NATIVE__photon_chat_clear_broadcast_queue()
    {
        return __EXT_JNI__photon_chat_clear_broadcast_queue();
    }
    public double __EXT_NATIVE__photon_chat_peek_next_broadcast_size()
    {
        return __EXT_JNI__photon_chat_peek_next_broadcast_size();
    }
    public String __EXT_NATIVE__photon_chat_peek_next_broadcast_channel()
    {
        return __EXT_JNI__photon_chat_peek_next_broadcast_channel();
    }
    public double __EXT_NATIVE__photon_chat_receive_one_broadcast_buffer(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_chat_receive_one_broadcast_buffer(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_debug()
    {
        return __EXT_JNI__photon_chat_remove_callback_debug();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_connected()
    {
        return __EXT_JNI__photon_chat_remove_callback_connected();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_state_change()
    {
        return __EXT_JNI__photon_chat_remove_callback_state_change();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_connection_error()
    {
        return __EXT_JNI__photon_chat_remove_callback_connection_error();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_client_error()
    {
        return __EXT_JNI__photon_chat_remove_callback_client_error();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_warning()
    {
        return __EXT_JNI__photon_chat_remove_callback_warning();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_server_error()
    {
        return __EXT_JNI__photon_chat_remove_callback_server_error();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_disconnected()
    {
        return __EXT_JNI__photon_chat_remove_callback_disconnected();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_status_update()
    {
        return __EXT_JNI__photon_chat_remove_callback_status_update();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_get_messages()
    {
        return __EXT_JNI__photon_chat_remove_callback_get_messages();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_private_message()
    {
        return __EXT_JNI__photon_chat_remove_callback_private_message();
    }
    public double __EXT_NATIVE__photon_chat_remove_callback_receive_broadcast()
    {
        return __EXT_JNI__photon_chat_remove_callback_receive_broadcast();
    }
    public double __EXT_NATIVE__photon_voice_init()
    {
        return __EXT_JNI__photon_voice_init();
    }
    public double __EXT_NATIVE__photon_voice_shutdown()
    {
        return __EXT_JNI__photon_voice_shutdown();
    }
    public double __EXT_NATIVE__photon_voice_service()
    {
        return __EXT_JNI__photon_voice_service();
    }
    public double __EXT_NATIVE__photon_voice_is_initialized()
    {
        return __EXT_JNI__photon_voice_is_initialized();
    }
    public double __EXT_NATIVE__photon_voice_notify_joined_room()
    {
        return __EXT_JNI__photon_voice_notify_joined_room();
    }
    public double __EXT_NATIVE__photon_voice_on_join_channel(double channel_id)
    {
        return __EXT_JNI__photon_voice_on_join_channel(channel_id);
    }
    public double __EXT_NATIVE__photon_voice_on_leave_channel(double channel_id)
    {
        return __EXT_JNI__photon_voice_on_leave_channel(channel_id);
    }
    public double __EXT_NATIVE__photon_voice_on_join_all_channels()
    {
        return __EXT_JNI__photon_voice_on_join_all_channels();
    }
    public double __EXT_NATIVE__photon_voice_on_leave_all_channels()
    {
        return __EXT_JNI__photon_voice_on_leave_all_channels();
    }
    public double __EXT_NATIVE__photon_voice_on_player_join(double channel_id, double player_id)
    {
        return __EXT_JNI__photon_voice_on_player_join(channel_id, player_id);
    }
    public double __EXT_NATIVE__photon_voice_on_player_leave(double channel_id, double player_id)
    {
        return __EXT_JNI__photon_voice_on_player_leave(channel_id, player_id);
    }
    public double __EXT_NATIVE__photon_voice_create_local_voice(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_voice_create_local_voice(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_voice_remove_local_voice(double voice_id)
    {
        return __EXT_JNI__photon_voice_remove_local_voice(voice_id);
    }
    public double __EXT_NATIVE__photon_voice_push_frame_buffer(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_voice_push_frame_buffer(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_voice_get_frame_queue_count()
    {
        return __EXT_JNI__photon_voice_get_frame_queue_count();
    }
    public double __EXT_NATIVE__photon_voice_clear_frame_queue()
    {
        return __EXT_JNI__photon_voice_clear_frame_queue();
    }
    public double __EXT_NATIVE__photon_voice_peek_next_frame_size()
    {
        return __EXT_JNI__photon_voice_peek_next_frame_size();
    }
    public double __EXT_NATIVE__photon_voice_peek_next_frame_player_id()
    {
        return __EXT_JNI__photon_voice_peek_next_frame_player_id();
    }
    public double __EXT_NATIVE__photon_voice_peek_next_frame_voice_id()
    {
        return __EXT_JNI__photon_voice_peek_next_frame_voice_id();
    }
    public double __EXT_NATIVE__photon_voice_receive_frame_buffer(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_voice_receive_frame_buffer(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_voice_get_remote_voice_count()
    {
        return __EXT_JNI__photon_voice_get_remote_voice_count();
    }
    public double __EXT_NATIVE__photon_voice_get_remote_voice_player_id(double index)
    {
        return __EXT_JNI__photon_voice_get_remote_voice_player_id(index);
    }
    public double __EXT_NATIVE__photon_voice_get_remote_voice_id(double index)
    {
        return __EXT_JNI__photon_voice_get_remote_voice_id(index);
    }
    public double __EXT_NATIVE__photon_voice_get_remote_voice_codec(double index, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_voice_get_remote_voice_codec(index, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_voice_get_remote_voice_sample_rate(double index)
    {
        return __EXT_JNI__photon_voice_get_remote_voice_sample_rate(index);
    }
    public double __EXT_NATIVE__photon_voice_get_remote_voice_channels(double index)
    {
        return __EXT_JNI__photon_voice_get_remote_voice_channels(index);
    }
    public double __EXT_NATIVE__photon_voice_get_remote_voice_is_speaking(double index)
    {
        return __EXT_JNI__photon_voice_get_remote_voice_is_speaking(index);
    }
    public double __EXT_NATIVE__photon_voice_get_frames_sent()
    {
        return __EXT_JNI__photon_voice_get_frames_sent();
    }
    public double __EXT_NATIVE__photon_voice_get_frames_received()
    {
        return __EXT_JNI__photon_voice_get_frames_received();
    }
    public double __EXT_NATIVE__photon_voice_get_frames_lost()
    {
        return __EXT_JNI__photon_voice_get_frames_lost();
    }
    public double __EXT_NATIVE__photon_voice_get_round_trip_time()
    {
        return __EXT_JNI__photon_voice_get_round_trip_time();
    }
    public double __EXT_NATIVE__photon_voice_get_round_trip_time_variance()
    {
        return __EXT_JNI__photon_voice_get_round_trip_time_variance();
    }
    public double __EXT_NATIVE__photon_voice_set_callback_remote_voice_added(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_voice_set_callback_remote_voice_added(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_voice_set_callback_remote_voice_removed(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_voice_set_callback_remote_voice_removed(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_voice_set_callback_speaking_changed(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_voice_set_callback_speaking_changed(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_voice_set_callback_debug(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_voice_set_callback_debug(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_voice_remove_callback_remote_voice_added()
    {
        return __EXT_JNI__photon_voice_remove_callback_remote_voice_added();
    }
    public double __EXT_NATIVE__photon_voice_remove_callback_remote_voice_removed()
    {
        return __EXT_JNI__photon_voice_remove_callback_remote_voice_removed();
    }
    public double __EXT_NATIVE__photon_voice_remove_callback_speaking_changed()
    {
        return __EXT_JNI__photon_voice_remove_callback_speaking_changed();
    }
    public double __EXT_NATIVE__photon_voice_remove_callback_debug()
    {
        return __EXT_JNI__photon_voice_remove_callback_debug();
    }
    public double __EXT_NATIVE__photon_voice_local_voice_set_transmit(double voice_id, double enabled)
    {
        return __EXT_JNI__photon_voice_local_voice_set_transmit(voice_id, enabled);
    }
    public double __EXT_NATIVE__photon_voice_local_voice_get_transmit(double voice_id)
    {
        return __EXT_JNI__photon_voice_local_voice_get_transmit(voice_id);
    }
    public double __EXT_NATIVE__photon_voice_set_remote_player_muted(double player_id, double muted)
    {
        return __EXT_JNI__photon_voice_set_remote_player_muted(player_id, muted);
    }
    public double __EXT_NATIVE__photon_voice_get_remote_player_muted(double player_id)
    {
        return __EXT_JNI__photon_voice_get_remote_player_muted(player_id);
    }
    public double __EXT_NATIVE__photon_voice_set_remote_player_volume(double player_id, double volume)
    {
        return __EXT_JNI__photon_voice_set_remote_player_volume(player_id, volume);
    }
    public double __EXT_NATIVE__photon_voice_get_remote_player_volume(double player_id)
    {
        return __EXT_JNI__photon_voice_get_remote_player_volume(player_id);
    }
    public double __EXT_NATIVE__photon_voice_get_debug_lost_percent()
    {
        return __EXT_JNI__photon_voice_get_debug_lost_percent();
    }
    public double __EXT_NATIVE__photon_voice_set_debug_lost_percent(double percent)
    {
        return __EXT_JNI__photon_voice_set_debug_lost_percent(percent);
    }
    public double __EXT_NATIVE__photon_voice_get_speaking_threshold_ms()
    {
        return __EXT_JNI__photon_voice_get_speaking_threshold_ms();
    }
    public double __EXT_NATIVE__photon_voice_set_speaking_threshold_ms(double ms)
    {
        return __EXT_JNI__photon_voice_set_speaking_threshold_ms(ms);
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_state()
    {
        return __EXT_JNI__photon_realtime_peer_get_state();
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_round_trip_time()
    {
        return __EXT_JNI__photon_realtime_peer_get_round_trip_time();
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_round_trip_time_variance()
    {
        return __EXT_JNI__photon_realtime_peer_get_round_trip_time_variance();
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_bytes_in()
    {
        return __EXT_JNI__photon_realtime_peer_get_bytes_in();
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_bytes_out()
    {
        return __EXT_JNI__photon_realtime_peer_get_bytes_out();
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_queued_incoming_commands()
    {
        return __EXT_JNI__photon_realtime_peer_get_queued_incoming_commands();
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_queued_outgoing_commands()
    {
        return __EXT_JNI__photon_realtime_peer_get_queued_outgoing_commands();
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_debug_output_level(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_realtime_peer_get_debug_output_level(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_peer_set_debug_output_level(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_realtime_peer_set_debug_output_level(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_disconnect_timeout()
    {
        return __EXT_JNI__photon_realtime_peer_get_disconnect_timeout();
    }
    public double __EXT_NATIVE__photon_realtime_peer_set_disconnect_timeout(double timeout_ms)
    {
        return __EXT_JNI__photon_realtime_peer_set_disconnect_timeout(timeout_ms);
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_time_ping_interval()
    {
        return __EXT_JNI__photon_realtime_peer_get_time_ping_interval();
    }
    public double __EXT_NATIVE__photon_realtime_peer_set_time_ping_interval(double interval_ms)
    {
        return __EXT_JNI__photon_realtime_peer_set_time_ping_interval(interval_ms);
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_crc_enabled()
    {
        return __EXT_JNI__photon_realtime_peer_get_crc_enabled();
    }
    public double __EXT_NATIVE__photon_realtime_peer_set_crc_enabled(double enabled)
    {
        return __EXT_JNI__photon_realtime_peer_set_crc_enabled(enabled);
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_packet_loss_by_crc()
    {
        return __EXT_JNI__photon_realtime_peer_get_packet_loss_by_crc();
    }
    public double __EXT_NATIVE__photon_realtime_peer_get_timestamp_of_last_socket_receive()
    {
        return __EXT_JNI__photon_realtime_peer_get_timestamp_of_last_socket_receive();
    }
    public double __EXT_NATIVE__photon_realtime_peer_reset_traffic_stats()
    {
        return __EXT_JNI__photon_realtime_peer_reset_traffic_stats();
    }
    public double __EXT_NATIVE__photon_chat_peer_get_state()
    {
        return __EXT_JNI__photon_chat_peer_get_state();
    }
    public double __EXT_NATIVE__photon_chat_peer_get_round_trip_time()
    {
        return __EXT_JNI__photon_chat_peer_get_round_trip_time();
    }
    public double __EXT_NATIVE__photon_chat_peer_get_round_trip_time_variance()
    {
        return __EXT_JNI__photon_chat_peer_get_round_trip_time_variance();
    }
    public double __EXT_NATIVE__photon_chat_peer_get_bytes_in()
    {
        return __EXT_JNI__photon_chat_peer_get_bytes_in();
    }
    public double __EXT_NATIVE__photon_chat_peer_get_bytes_out()
    {
        return __EXT_JNI__photon_chat_peer_get_bytes_out();
    }
    public double __EXT_NATIVE__photon_chat_peer_get_queued_incoming_commands()
    {
        return __EXT_JNI__photon_chat_peer_get_queued_incoming_commands();
    }
    public double __EXT_NATIVE__photon_chat_peer_get_queued_outgoing_commands()
    {
        return __EXT_JNI__photon_chat_peer_get_queued_outgoing_commands();
    }
    public double __EXT_NATIVE__photon_chat_peer_get_debug_output_level(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_chat_peer_get_debug_output_level(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_peer_set_debug_output_level(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_chat_peer_set_debug_output_level(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_chat_peer_get_disconnect_timeout()
    {
        return __EXT_JNI__photon_chat_peer_get_disconnect_timeout();
    }
    public double __EXT_NATIVE__photon_chat_peer_set_disconnect_timeout(double timeout_ms)
    {
        return __EXT_JNI__photon_chat_peer_set_disconnect_timeout(timeout_ms);
    }
    public double __EXT_NATIVE__photon_chat_peer_get_time_ping_interval()
    {
        return __EXT_JNI__photon_chat_peer_get_time_ping_interval();
    }
    public double __EXT_NATIVE__photon_chat_peer_set_time_ping_interval(double interval_ms)
    {
        return __EXT_JNI__photon_chat_peer_set_time_ping_interval(interval_ms);
    }
    public double __EXT_NATIVE__photon_chat_peer_get_crc_enabled()
    {
        return __EXT_JNI__photon_chat_peer_get_crc_enabled();
    }
    public double __EXT_NATIVE__photon_chat_peer_set_crc_enabled(double enabled)
    {
        return __EXT_JNI__photon_chat_peer_set_crc_enabled(enabled);
    }
    public double __EXT_NATIVE__photon_chat_peer_get_packet_loss_by_crc()
    {
        return __EXT_JNI__photon_chat_peer_get_packet_loss_by_crc();
    }
    public double __EXT_NATIVE__photon_chat_peer_get_timestamp_of_last_socket_receive()
    {
        return __EXT_JNI__photon_chat_peer_get_timestamp_of_last_socket_receive();
    }
    public double __EXT_NATIVE__photon_chat_peer_reset_traffic_stats()
    {
        return __EXT_JNI__photon_chat_peer_reset_traffic_stats();
    }
    public double __EXT_NATIVE__photon_peer_network_sim_get_enabled()
    {
        return __EXT_JNI__photon_peer_network_sim_get_enabled();
    }
    public double __EXT_NATIVE__photon_peer_network_sim_set_enabled(double enabled)
    {
        return __EXT_JNI__photon_peer_network_sim_set_enabled(enabled);
    }
    public double __EXT_NATIVE__photon_peer_network_sim_set_lag(double incoming_ms, double outgoing_ms)
    {
        return __EXT_JNI__photon_peer_network_sim_set_lag(incoming_ms, outgoing_ms);
    }
    public double __EXT_NATIVE__photon_peer_network_sim_set_jitter(double incoming_ms, double outgoing_ms)
    {
        return __EXT_JNI__photon_peer_network_sim_set_jitter(incoming_ms, outgoing_ms);
    }
    public double __EXT_NATIVE__photon_peer_network_sim_set_packet_loss(double incoming_pct, double outgoing_pct)
    {
        return __EXT_JNI__photon_peer_network_sim_set_packet_loss(incoming_pct, outgoing_pct);
    }
    public double __EXT_NATIVE__photon_common_set_debug_level(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_common_set_debug_level(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__photon_common_get_debug_level(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_common_get_debug_level(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__photon_common_get_serialization_protocol(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__photon_common_get_serialization_protocol(__ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__photon_common_type_code_to_string(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__photon_common_type_code_to_string(__arg_buffer, __arg_buffer_length);
    }
    public String __EXT_NATIVE__photon_common_get_sdk_version()
    {
        return __EXT_JNI__photon_common_get_sdk_version();
    }
    public String __EXT_NATIVE__photon_common_client_state_to_string(double state)
    {
        return __EXT_JNI__photon_common_client_state_to_string(state);
    }
    public String __EXT_NATIVE__photon_common_disconnect_cause_to_string(double cause)
    {
        return __EXT_JNI__photon_common_disconnect_cause_to_string(cause);
    }
}