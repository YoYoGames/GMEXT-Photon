// ##### extgen :: Auto-generated file do not edit!! #####

#import "GMPhotonInternal_ios.h"
#import "native/GMPhotonInternal_exports.h"
#import <objc/runtime.h>


extern "C" const char* extOptGetString(char* _ext, char* _opt);

// Adapter: matches const signature expected by the C++ API
static const char* ExtOptGetString(const char* ext, const char* opt)
{
    return extOptGetString(const_cast<char*>(ext), const_cast<char*>(opt));
}

static BOOL GMIsSubclassOf(Class cls, Class base)
{
    for (Class c = cls; c != Nil; c = class_getSuperclass(c)) {
        if (c == base) return YES;
    }
    return NO;
}

static void GMInjectSelectorsIntoSubclass(Class subclass, Class base)
{
    // Build set of methods already defined on subclass
    unsigned subCount = 0;
    Method *subList = class_copyMethodList(subclass, &subCount);

    CFMutableSetRef owned = CFSetCreateMutable(kCFAllocatorDefault, 0, NULL);
    for (unsigned i = 0; i < subCount; ++i) {
        CFSetAddValue(owned, method_getName(subList[i]));
    }

    // Walk base class methods
    unsigned baseCount = 0;
    Method *baseList = class_copyMethodList(base, &baseCount);

    for (unsigned i = 0; i < baseCount; ++i) {
        SEL sel = method_getName(baseList[i]);
        const char *name = sel_getName(sel);

        // Only inject extension selectors (methods prefixed with __EXT_NATIVE__)
        if (!name || strncmp(name, "__EXT_NATIVE__", 13) != 0) continue;

        // Add only if subclass doesn't already have it
        if (!CFSetContainsValue(owned, sel)) {
            IMP imp = method_getImplementation(baseList[i]);
            const char *types = method_getTypeEncoding(baseList[i]);
            if (class_addMethod(subclass, sel, imp, types)) {
                CFSetAddValue(owned, sel);
            }
        }
    }

    if (subList) free(subList);
    if (baseList) free(baseList);
    if (owned) CFRelease(owned);
}

@implementation GMPhotonInternal

+ (void)load
{
    // Find all loaded classes
    int num = objc_getClassList(NULL, 0);
    if (num <= 0) return;

    Class *classes = (Class *)malloc(sizeof(Class) * (unsigned)num);
    num = objc_getClassList(classes, num);

    Class base = [GMPhotonInternal class];

    for (int i = 0; i < num; ++i) {
        Class cls = classes[i];
        if (cls == base) continue;

        // We only care about direct or indirect subclasses
        if (GMIsSubclassOf(cls, base)) {
            GMInjectSelectorsIntoSubclass(cls, base);
        }
    }

    free(classes);

    gm::details::GMRTRunnerInterface ri{};
    ri.ExtOptGetString = &ExtOptGetString;
    GMExtensionInitialise(&ri, sizeof(ri));
}

- (double)__EXT_NATIVE__photon_realtime_init
{
    return __EXT_NATIVE__photon_realtime_init();
}
- (double)__EXT_NATIVE__photon_realtime_shutdown
{
    return __EXT_NATIVE__photon_realtime_shutdown();
}
- (double)__EXT_NATIVE__photon_realtime_service
{
    return __EXT_NATIVE__photon_realtime_service();
}
- (double)__EXT_NATIVE__photon_realtime_connect:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_connect(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_disconnect
{
    return __EXT_NATIVE__photon_realtime_disconnect();
}
- (double)__EXT_NATIVE__photon_realtime_select_region:(char*)region
{
    return __EXT_NATIVE__photon_realtime_select_region(region);
}
- (double)__EXT_NATIVE__photon_realtime_reconnect_and_rejoin
{
    return __EXT_NATIVE__photon_realtime_reconnect_and_rejoin();
}
- (double)__EXT_NATIVE__photon_realtime_fetch_server_timestamp
{
    return __EXT_NATIVE__photon_realtime_fetch_server_timestamp();
}
- (double)__EXT_NATIVE__photon_realtime_operation_join_lobby:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_join_lobby(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_leave_lobby:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_leave_lobby(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_create_room:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_create_room(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_join_or_create_room:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_join_or_create_room(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_join_room:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_join_room(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_join_random_room:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_join_random_room(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_leave_room:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_leave_room(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_join_random_or_create_room:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_join_random_or_create_room(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_get_room_list:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_get_room_list(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_lobby_stats:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_lobby_stats(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_find_friends:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_find_friends(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_web_rpc:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_web_rpc(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_change_groups:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_change_groups(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_custom_auth_next_step:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_custom_auth_next_step(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_raise_event_string:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_raise_event_string(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_operation_raise_event_buffer:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_operation_raise_event_buffer(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_get_buffer_event_queue_count
{
    return __EXT_NATIVE__photon_realtime_get_buffer_event_queue_count();
}
- (double)__EXT_NATIVE__photon_realtime_clear_buffer_event_queue
{
    return __EXT_NATIVE__photon_realtime_clear_buffer_event_queue();
}
- (double)__EXT_NATIVE__photon_realtime_peek_next_buffer_event_size
{
    return __EXT_NATIVE__photon_realtime_peek_next_buffer_event_size();
}
- (double)__EXT_NATIVE__photon_realtime_peek_next_buffer_event_code
{
    return __EXT_NATIVE__photon_realtime_peek_next_buffer_event_code();
}
- (double)__EXT_NATIVE__photon_realtime_receive_one_event_buffer:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_realtime_receive_one_event_buffer(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_is_initialized
{
    return __EXT_NATIVE__photon_realtime_is_initialized();
}
- (double)__EXT_NATIVE__photon_realtime_is_connected
{
    return __EXT_NATIVE__photon_realtime_is_connected();
}
- (double)__EXT_NATIVE__photon_realtime_is_in_game_room
{
    return __EXT_NATIVE__photon_realtime_is_in_game_room();
}
- (double)__EXT_NATIVE__photon_realtime_is_in_room
{
    return __EXT_NATIVE__photon_realtime_is_in_room();
}
- (double)__EXT_NATIVE__photon_realtime_is_in_lobby
{
    return __EXT_NATIVE__photon_realtime_is_in_lobby();
}
- (char*)__EXT_NATIVE__photon_realtime_get_current_room_name
{
    return __EXT_NATIVE__photon_realtime_get_current_room_name();
}
- (double)__EXT_NATIVE__photon_realtime_get_local_player_number
{
    return __EXT_NATIVE__photon_realtime_get_local_player_number();
}
- (double)__EXT_NATIVE__photon_realtime_get_server_time_offset
{
    return __EXT_NATIVE__photon_realtime_get_server_time_offset();
}
- (double)__EXT_NATIVE__photon_realtime_get_server_time
{
    return __EXT_NATIVE__photon_realtime_get_server_time();
}
- (double)__EXT_NATIVE__photon_realtime_get_bytes_in
{
    return __EXT_NATIVE__photon_realtime_get_bytes_in();
}
- (double)__EXT_NATIVE__photon_realtime_get_bytes_out
{
    return __EXT_NATIVE__photon_realtime_get_bytes_out();
}
- (double)__EXT_NATIVE__photon_realtime_get_state:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_realtime_get_state(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_get_round_trip_time
{
    return __EXT_NATIVE__photon_realtime_get_round_trip_time();
}
- (double)__EXT_NATIVE__photon_realtime_get_round_trip_time_variance
{
    return __EXT_NATIVE__photon_realtime_get_round_trip_time_variance();
}
- (double)__EXT_NATIVE__photon_realtime_get_disconnected_cause:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_realtime_get_disconnected_cause(__ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__photon_realtime_get_user_id
{
    return __EXT_NATIVE__photon_realtime_get_user_id();
}
- (double)__EXT_NATIVE__photon_realtime_get_count_players_ingame
{
    return __EXT_NATIVE__photon_realtime_get_count_players_ingame();
}
- (double)__EXT_NATIVE__photon_realtime_get_count_games_running
{
    return __EXT_NATIVE__photon_realtime_get_count_games_running();
}
- (double)__EXT_NATIVE__photon_realtime_get_count_players_online
{
    return __EXT_NATIVE__photon_realtime_get_count_players_online();
}
- (char*)__EXT_NATIVE__photon_realtime_get_master_server_address
{
    return __EXT_NATIVE__photon_realtime_get_master_server_address();
}
- (char*)__EXT_NATIVE__photon_realtime_get_region
{
    return __EXT_NATIVE__photon_realtime_get_region();
}
- (char*)__EXT_NATIVE__photon_realtime_get_region_with_best_ping
{
    return __EXT_NATIVE__photon_realtime_get_region_with_best_ping();
}
- (double)__EXT_NATIVE__photon_realtime_get_friend_list_age
{
    return __EXT_NATIVE__photon_realtime_get_friend_list_age();
}
- (double)__EXT_NATIVE__photon_realtime_get_disconnect_timeout
{
    return __EXT_NATIVE__photon_realtime_get_disconnect_timeout();
}
- (double)__EXT_NATIVE__photon_realtime_set_disconnect_timeout:(double)milliseconds
{
    return __EXT_NATIVE__photon_realtime_set_disconnect_timeout(milliseconds);
}
- (double)__EXT_NATIVE__photon_realtime_get_ping_interval
{
    return __EXT_NATIVE__photon_realtime_get_ping_interval();
}
- (double)__EXT_NATIVE__photon_realtime_set_ping_interval:(double)milliseconds
{
    return __EXT_NATIVE__photon_realtime_set_ping_interval(milliseconds);
}
- (double)__EXT_NATIVE__photon_realtime_get_auto_join_lobby
{
    return __EXT_NATIVE__photon_realtime_get_auto_join_lobby();
}
- (double)__EXT_NATIVE__photon_realtime_set_auto_join_lobby:(double)enabled
{
    return __EXT_NATIVE__photon_realtime_set_auto_join_lobby(enabled);
}
- (double)__EXT_NATIVE__photon_realtime_get_room_player_count
{
    return __EXT_NATIVE__photon_realtime_get_room_player_count();
}
- (double)__EXT_NATIVE__photon_realtime_get_room_max_players
{
    return __EXT_NATIVE__photon_realtime_get_room_max_players();
}
- (double)__EXT_NATIVE__photon_realtime_get_room_is_open
{
    return __EXT_NATIVE__photon_realtime_get_room_is_open();
}
- (double)__EXT_NATIVE__photon_realtime_get_room_is_visible
{
    return __EXT_NATIVE__photon_realtime_get_room_is_visible();
}
- (double)__EXT_NATIVE__photon_realtime_get_master_client_number
{
    return __EXT_NATIVE__photon_realtime_get_master_client_number();
}
- (double)__EXT_NATIVE__photon_realtime_set_master_client:(double)player_number
{
    return __EXT_NATIVE__photon_realtime_set_master_client(player_number);
}
- (double)__EXT_NATIVE__photon_realtime_get_room_list_count
{
    return __EXT_NATIVE__photon_realtime_get_room_list_count();
}
- (double)__EXT_NATIVE__photon_realtime_get_room_info_by_index:(double)index arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_realtime_get_room_info_by_index(index, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_get_player_count
{
    return __EXT_NATIVE__photon_realtime_get_player_count();
}
- (double)__EXT_NATIVE__photon_realtime_get_player_number_by_index:(double)index
{
    return __EXT_NATIVE__photon_realtime_get_player_number_by_index(index);
}
- (char*)__EXT_NATIVE__photon_realtime_player_get_name:(double)player_number
{
    return __EXT_NATIVE__photon_realtime_player_get_name(player_number);
}
- (char*)__EXT_NATIVE__photon_realtime_player_get_user_id:(double)player_number
{
    return __EXT_NATIVE__photon_realtime_player_get_user_id(player_number);
}
- (double)__EXT_NATIVE__photon_realtime_player_is_inactive:(double)player_number
{
    return __EXT_NATIVE__photon_realtime_player_is_inactive(player_number);
}
- (double)__EXT_NATIVE__photon_realtime_player_is_master_client:(double)player_number
{
    return __EXT_NATIVE__photon_realtime_player_is_master_client(player_number);
}
- (double)__EXT_NATIVE__photon_realtime_get_player_numbers:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_realtime_get_player_numbers(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_debug:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_debug(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_connected:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_connected(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_disconnected:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_disconnected(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_connection_error:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_connection_error(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_client_error:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_client_error(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_server_error:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_server_error(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_warning:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_warning(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_join_room_event:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_join_room_event(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_leave_room_event:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_leave_room_event(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_custom_event:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_custom_event(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_room_properties_change:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_room_properties_change(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_player_properties_change:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_player_properties_change(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_room_list_update:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_room_list_update(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_app_stats_update:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_app_stats_update(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_lobby_stats_update:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_lobby_stats_update(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_cache_slice_changed:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_cache_slice_changed(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_master_client_changed:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_master_client_changed(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_properties_change_failed:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_properties_change_failed(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_custom_authentication_step:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_custom_authentication_step(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_available_regions:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_available_regions(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_secret_receival:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_secret_receival(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_direct_connection_established:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_direct_connection_established(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_direct_connection_failed:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_direct_connection_failed(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_direct_message:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_direct_message(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_set_callback_custom_operation_response:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_set_callback_custom_operation_response(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_debug
{
    return __EXT_NATIVE__photon_realtime_remove_callback_debug();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_connected
{
    return __EXT_NATIVE__photon_realtime_remove_callback_connected();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_disconnected
{
    return __EXT_NATIVE__photon_realtime_remove_callback_disconnected();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_connection_error
{
    return __EXT_NATIVE__photon_realtime_remove_callback_connection_error();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_client_error
{
    return __EXT_NATIVE__photon_realtime_remove_callback_client_error();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_server_error
{
    return __EXT_NATIVE__photon_realtime_remove_callback_server_error();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_warning
{
    return __EXT_NATIVE__photon_realtime_remove_callback_warning();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_join_room_event
{
    return __EXT_NATIVE__photon_realtime_remove_callback_join_room_event();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_leave_room_event
{
    return __EXT_NATIVE__photon_realtime_remove_callback_leave_room_event();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_custom_event
{
    return __EXT_NATIVE__photon_realtime_remove_callback_custom_event();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_room_properties_change
{
    return __EXT_NATIVE__photon_realtime_remove_callback_room_properties_change();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_player_properties_change
{
    return __EXT_NATIVE__photon_realtime_remove_callback_player_properties_change();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_room_list_update
{
    return __EXT_NATIVE__photon_realtime_remove_callback_room_list_update();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_app_stats_update
{
    return __EXT_NATIVE__photon_realtime_remove_callback_app_stats_update();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_lobby_stats_update
{
    return __EXT_NATIVE__photon_realtime_remove_callback_lobby_stats_update();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_cache_slice_changed
{
    return __EXT_NATIVE__photon_realtime_remove_callback_cache_slice_changed();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_master_client_changed
{
    return __EXT_NATIVE__photon_realtime_remove_callback_master_client_changed();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_properties_change_failed
{
    return __EXT_NATIVE__photon_realtime_remove_callback_properties_change_failed();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_custom_authentication_step
{
    return __EXT_NATIVE__photon_realtime_remove_callback_custom_authentication_step();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_available_regions
{
    return __EXT_NATIVE__photon_realtime_remove_callback_available_regions();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_secret_receival
{
    return __EXT_NATIVE__photon_realtime_remove_callback_secret_receival();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_direct_connection_established
{
    return __EXT_NATIVE__photon_realtime_remove_callback_direct_connection_established();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_direct_connection_failed
{
    return __EXT_NATIVE__photon_realtime_remove_callback_direct_connection_failed();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_direct_message
{
    return __EXT_NATIVE__photon_realtime_remove_callback_direct_message();
}
- (double)__EXT_NATIVE__photon_realtime_remove_callback_custom_operation_response
{
    return __EXT_NATIVE__photon_realtime_remove_callback_custom_operation_response();
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_set_string:(char*)key arg1:(char*)value
{
    return __EXT_NATIVE__photon_realtime_room_properties_set_string(key, value);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_set_i32:(char*)key arg1:(double)value
{
    return __EXT_NATIVE__photon_realtime_room_properties_set_i32(key, value);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_set_f64:(char*)key arg1:(double)value
{
    return __EXT_NATIVE__photon_realtime_room_properties_set_f64(key, value);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_set_bool:(char*)key arg1:(double)value
{
    return __EXT_NATIVE__photon_realtime_room_properties_set_bool(key, value);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_remove:(char*)key
{
    return __EXT_NATIVE__photon_realtime_room_properties_remove(key);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_clear
{
    return __EXT_NATIVE__photon_realtime_room_properties_clear();
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_has:(char*)key
{
    return __EXT_NATIVE__photon_realtime_room_properties_has(key);
}
- (char*)__EXT_NATIVE__photon_realtime_room_properties_get_string:(char*)key
{
    return __EXT_NATIVE__photon_realtime_room_properties_get_string(key);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_get_i32:(char*)key
{
    return __EXT_NATIVE__photon_realtime_room_properties_get_i32(key);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_get_f64:(char*)key
{
    return __EXT_NATIVE__photon_realtime_room_properties_get_f64(key);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_get_bool:(char*)key
{
    return __EXT_NATIVE__photon_realtime_room_properties_get_bool(key);
}
- (char*)__EXT_NATIVE__photon_realtime_room_properties_to_string
{
    return __EXT_NATIVE__photon_realtime_room_properties_to_string();
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_get_all:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_realtime_room_properties_get_all(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_cas_string:(char*)key arg1:(char*)expected_value arg2:(char*)new_value
{
    return __EXT_NATIVE__photon_realtime_room_properties_cas_string(key, expected_value, new_value);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_cas_i32:(char*)key arg1:(double)expected_value arg2:(double)new_value
{
    return __EXT_NATIVE__photon_realtime_room_properties_cas_i32(key, expected_value, new_value);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_cas_f64:(char*)key arg1:(double)expected_value arg2:(double)new_value
{
    return __EXT_NATIVE__photon_realtime_room_properties_cas_f64(key, expected_value, new_value);
}
- (double)__EXT_NATIVE__photon_realtime_room_properties_cas_bool:(char*)key arg1:(double)expected_value arg2:(double)new_value
{
    return __EXT_NATIVE__photon_realtime_room_properties_cas_bool(key, expected_value, new_value);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_set_local_string:(char*)key arg1:(char*)value
{
    return __EXT_NATIVE__photon_realtime_player_properties_set_local_string(key, value);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_set_local_i32:(char*)key arg1:(double)value
{
    return __EXT_NATIVE__photon_realtime_player_properties_set_local_i32(key, value);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_set_local_f64:(char*)key arg1:(double)value
{
    return __EXT_NATIVE__photon_realtime_player_properties_set_local_f64(key, value);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_set_local_bool:(char*)key arg1:(double)value
{
    return __EXT_NATIVE__photon_realtime_player_properties_set_local_bool(key, value);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_remove_local:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_remove_local(key);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_clear_local
{
    return __EXT_NATIVE__photon_realtime_player_properties_clear_local();
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_has_local:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_has_local(key);
}
- (char*)__EXT_NATIVE__photon_realtime_player_properties_get_local_string:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_local_string(key);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_get_local_i32:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_local_i32(key);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_get_local_f64:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_local_f64(key);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_get_local_bool:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_local_bool(key);
}
- (char*)__EXT_NATIVE__photon_realtime_player_properties_to_string_local
{
    return __EXT_NATIVE__photon_realtime_player_properties_to_string_local();
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_get_local_all:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_local_all(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_has_remote:(double)player_number arg1:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_has_remote(player_number, key);
}
- (char*)__EXT_NATIVE__photon_realtime_player_properties_get_remote_string:(double)player_number arg1:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_remote_string(player_number, key);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_get_remote_i32:(double)player_number arg1:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_remote_i32(player_number, key);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_get_remote_f64:(double)player_number arg1:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_remote_f64(player_number, key);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_get_remote_bool:(double)player_number arg1:(char*)key
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_remote_bool(player_number, key);
}
- (char*)__EXT_NATIVE__photon_realtime_player_properties_to_string_remote:(double)player_number
{
    return __EXT_NATIVE__photon_realtime_player_properties_to_string_remote(player_number);
}
- (double)__EXT_NATIVE__photon_realtime_player_properties_get_remote_all:(double)player_number arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_realtime_player_properties_get_remote_all(player_number, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_peek_next_buffer_event_player_number
{
    return __EXT_NATIVE__photon_realtime_peek_next_buffer_event_player_number();
}
- (double)__EXT_NATIVE__photon_chat_init
{
    return __EXT_NATIVE__photon_chat_init();
}
- (double)__EXT_NATIVE__photon_chat_shutdown
{
    return __EXT_NATIVE__photon_chat_shutdown();
}
- (double)__EXT_NATIVE__photon_chat_service
{
    return __EXT_NATIVE__photon_chat_service();
}
- (double)__EXT_NATIVE__photon_chat_connect:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_connect(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_disconnect
{
    return __EXT_NATIVE__photon_chat_disconnect();
}
- (double)__EXT_NATIVE__photon_chat_operation_subscribe:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_operation_subscribe(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_operation_unsubscribe:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_operation_unsubscribe(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_operation_publish_message:(char*)channel_name arg1:(char*)message
{
    return __EXT_NATIVE__photon_chat_operation_publish_message(channel_name, message);
}
- (double)__EXT_NATIVE__photon_chat_operation_send_private_message:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_operation_send_private_message(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_operation_set_online_status:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_operation_set_online_status(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_operation_add_friends:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_operation_add_friends(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_operation_remove_friends:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_operation_remove_friends(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_is_initialized
{
    return __EXT_NATIVE__photon_chat_is_initialized();
}
- (double)__EXT_NATIVE__photon_chat_is_connected
{
    return __EXT_NATIVE__photon_chat_is_connected();
}
- (double)__EXT_NATIVE__photon_chat_get_state:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_chat_get_state(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_get_disconnect_cause:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_chat_get_disconnect_cause(__ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__photon_chat_get_user_id
{
    return __EXT_NATIVE__photon_chat_get_user_id();
}
- (char*)__EXT_NATIVE__photon_chat_get_region
{
    return __EXT_NATIVE__photon_chat_get_region();
}
- (double)__EXT_NATIVE__photon_chat_get_server_time
{
    return __EXT_NATIVE__photon_chat_get_server_time();
}
- (double)__EXT_NATIVE__photon_chat_get_server_time_offset
{
    return __EXT_NATIVE__photon_chat_get_server_time_offset();
}
- (double)__EXT_NATIVE__photon_chat_get_bytes_in
{
    return __EXT_NATIVE__photon_chat_get_bytes_in();
}
- (double)__EXT_NATIVE__photon_chat_get_bytes_out
{
    return __EXT_NATIVE__photon_chat_get_bytes_out();
}
- (double)__EXT_NATIVE__photon_chat_get_channel_count:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_get_channel_count(__arg_buffer, __arg_buffer_length);
}
- (char*)__EXT_NATIVE__photon_chat_get_channel_name:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_get_channel_name(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_get_channel_message_count:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_get_channel_message_count(__arg_buffer, __arg_buffer_length);
}
- (char*)__EXT_NATIVE__photon_chat_get_channel_message:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_get_channel_message(__arg_buffer, __arg_buffer_length);
}
- (char*)__EXT_NATIVE__photon_chat_get_channel_sender:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_get_channel_sender(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_debug:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_debug(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_connected:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_connected(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_state_change:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_state_change(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_connection_error:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_connection_error(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_client_error:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_client_error(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_warning:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_warning(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_server_error:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_server_error(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_disconnected:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_disconnected(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_status_update:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_status_update(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_get_messages:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_get_messages(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_private_message:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_private_message(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_set_callback_receive_broadcast:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_set_callback_receive_broadcast(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_get_broadcast_queue_count
{
    return __EXT_NATIVE__photon_chat_get_broadcast_queue_count();
}
- (double)__EXT_NATIVE__photon_chat_clear_broadcast_queue
{
    return __EXT_NATIVE__photon_chat_clear_broadcast_queue();
}
- (double)__EXT_NATIVE__photon_chat_peek_next_broadcast_size
{
    return __EXT_NATIVE__photon_chat_peek_next_broadcast_size();
}
- (char*)__EXT_NATIVE__photon_chat_peek_next_broadcast_channel
{
    return __EXT_NATIVE__photon_chat_peek_next_broadcast_channel();
}
- (double)__EXT_NATIVE__photon_chat_receive_one_broadcast_buffer:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_chat_receive_one_broadcast_buffer(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_debug
{
    return __EXT_NATIVE__photon_chat_remove_callback_debug();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_connected
{
    return __EXT_NATIVE__photon_chat_remove_callback_connected();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_state_change
{
    return __EXT_NATIVE__photon_chat_remove_callback_state_change();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_connection_error
{
    return __EXT_NATIVE__photon_chat_remove_callback_connection_error();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_client_error
{
    return __EXT_NATIVE__photon_chat_remove_callback_client_error();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_warning
{
    return __EXT_NATIVE__photon_chat_remove_callback_warning();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_server_error
{
    return __EXT_NATIVE__photon_chat_remove_callback_server_error();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_disconnected
{
    return __EXT_NATIVE__photon_chat_remove_callback_disconnected();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_status_update
{
    return __EXT_NATIVE__photon_chat_remove_callback_status_update();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_get_messages
{
    return __EXT_NATIVE__photon_chat_remove_callback_get_messages();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_private_message
{
    return __EXT_NATIVE__photon_chat_remove_callback_private_message();
}
- (double)__EXT_NATIVE__photon_chat_remove_callback_receive_broadcast
{
    return __EXT_NATIVE__photon_chat_remove_callback_receive_broadcast();
}
- (double)__EXT_NATIVE__photon_voice_init
{
    return __EXT_NATIVE__photon_voice_init();
}
- (double)__EXT_NATIVE__photon_voice_shutdown
{
    return __EXT_NATIVE__photon_voice_shutdown();
}
- (double)__EXT_NATIVE__photon_voice_service
{
    return __EXT_NATIVE__photon_voice_service();
}
- (double)__EXT_NATIVE__photon_voice_is_initialized
{
    return __EXT_NATIVE__photon_voice_is_initialized();
}
- (double)__EXT_NATIVE__photon_voice_notify_joined_room
{
    return __EXT_NATIVE__photon_voice_notify_joined_room();
}
- (double)__EXT_NATIVE__photon_voice_on_join_channel:(double)channel_id
{
    return __EXT_NATIVE__photon_voice_on_join_channel(channel_id);
}
- (double)__EXT_NATIVE__photon_voice_on_leave_channel:(double)channel_id
{
    return __EXT_NATIVE__photon_voice_on_leave_channel(channel_id);
}
- (double)__EXT_NATIVE__photon_voice_on_join_all_channels
{
    return __EXT_NATIVE__photon_voice_on_join_all_channels();
}
- (double)__EXT_NATIVE__photon_voice_on_leave_all_channels
{
    return __EXT_NATIVE__photon_voice_on_leave_all_channels();
}
- (double)__EXT_NATIVE__photon_voice_on_player_join:(double)channel_id arg1:(double)player_id
{
    return __EXT_NATIVE__photon_voice_on_player_join(channel_id, player_id);
}
- (double)__EXT_NATIVE__photon_voice_on_player_leave:(double)channel_id arg1:(double)player_id
{
    return __EXT_NATIVE__photon_voice_on_player_leave(channel_id, player_id);
}
- (double)__EXT_NATIVE__photon_voice_create_local_voice:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_voice_create_local_voice(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_voice_remove_local_voice:(double)voice_id
{
    return __EXT_NATIVE__photon_voice_remove_local_voice(voice_id);
}
- (double)__EXT_NATIVE__photon_voice_push_frame_buffer:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_voice_push_frame_buffer(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_voice_get_frame_queue_count
{
    return __EXT_NATIVE__photon_voice_get_frame_queue_count();
}
- (double)__EXT_NATIVE__photon_voice_clear_frame_queue
{
    return __EXT_NATIVE__photon_voice_clear_frame_queue();
}
- (double)__EXT_NATIVE__photon_voice_peek_next_frame_size
{
    return __EXT_NATIVE__photon_voice_peek_next_frame_size();
}
- (double)__EXT_NATIVE__photon_voice_peek_next_frame_player_id
{
    return __EXT_NATIVE__photon_voice_peek_next_frame_player_id();
}
- (double)__EXT_NATIVE__photon_voice_peek_next_frame_voice_id
{
    return __EXT_NATIVE__photon_voice_peek_next_frame_voice_id();
}
- (double)__EXT_NATIVE__photon_voice_receive_frame_buffer:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_voice_receive_frame_buffer(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_voice_get_remote_voice_count
{
    return __EXT_NATIVE__photon_voice_get_remote_voice_count();
}
- (double)__EXT_NATIVE__photon_voice_get_remote_voice_player_id:(double)index
{
    return __EXT_NATIVE__photon_voice_get_remote_voice_player_id(index);
}
- (double)__EXT_NATIVE__photon_voice_get_remote_voice_id:(double)index
{
    return __EXT_NATIVE__photon_voice_get_remote_voice_id(index);
}
- (double)__EXT_NATIVE__photon_voice_get_remote_voice_codec:(double)index arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_voice_get_remote_voice_codec(index, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_voice_get_remote_voice_sample_rate:(double)index
{
    return __EXT_NATIVE__photon_voice_get_remote_voice_sample_rate(index);
}
- (double)__EXT_NATIVE__photon_voice_get_remote_voice_channels:(double)index
{
    return __EXT_NATIVE__photon_voice_get_remote_voice_channels(index);
}
- (double)__EXT_NATIVE__photon_voice_get_remote_voice_is_speaking:(double)index
{
    return __EXT_NATIVE__photon_voice_get_remote_voice_is_speaking(index);
}
- (double)__EXT_NATIVE__photon_voice_get_frames_sent
{
    return __EXT_NATIVE__photon_voice_get_frames_sent();
}
- (double)__EXT_NATIVE__photon_voice_get_frames_received
{
    return __EXT_NATIVE__photon_voice_get_frames_received();
}
- (double)__EXT_NATIVE__photon_voice_get_frames_lost
{
    return __EXT_NATIVE__photon_voice_get_frames_lost();
}
- (double)__EXT_NATIVE__photon_voice_get_round_trip_time
{
    return __EXT_NATIVE__photon_voice_get_round_trip_time();
}
- (double)__EXT_NATIVE__photon_voice_get_round_trip_time_variance
{
    return __EXT_NATIVE__photon_voice_get_round_trip_time_variance();
}
- (double)__EXT_NATIVE__photon_voice_set_callback_remote_voice_added:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_voice_set_callback_remote_voice_added(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_voice_set_callback_remote_voice_removed:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_voice_set_callback_remote_voice_removed(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_voice_set_callback_speaking_changed:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_voice_set_callback_speaking_changed(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_voice_set_callback_debug:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_voice_set_callback_debug(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_voice_remove_callback_remote_voice_added
{
    return __EXT_NATIVE__photon_voice_remove_callback_remote_voice_added();
}
- (double)__EXT_NATIVE__photon_voice_remove_callback_remote_voice_removed
{
    return __EXT_NATIVE__photon_voice_remove_callback_remote_voice_removed();
}
- (double)__EXT_NATIVE__photon_voice_remove_callback_speaking_changed
{
    return __EXT_NATIVE__photon_voice_remove_callback_speaking_changed();
}
- (double)__EXT_NATIVE__photon_voice_remove_callback_debug
{
    return __EXT_NATIVE__photon_voice_remove_callback_debug();
}
- (double)__EXT_NATIVE__photon_voice_local_voice_set_transmit:(double)voice_id arg1:(double)enabled
{
    return __EXT_NATIVE__photon_voice_local_voice_set_transmit(voice_id, enabled);
}
- (double)__EXT_NATIVE__photon_voice_local_voice_get_transmit:(double)voice_id
{
    return __EXT_NATIVE__photon_voice_local_voice_get_transmit(voice_id);
}
- (double)__EXT_NATIVE__photon_voice_set_remote_player_muted:(double)player_id arg1:(double)muted
{
    return __EXT_NATIVE__photon_voice_set_remote_player_muted(player_id, muted);
}
- (double)__EXT_NATIVE__photon_voice_get_remote_player_muted:(double)player_id
{
    return __EXT_NATIVE__photon_voice_get_remote_player_muted(player_id);
}
- (double)__EXT_NATIVE__photon_voice_set_remote_player_volume:(double)player_id arg1:(double)volume
{
    return __EXT_NATIVE__photon_voice_set_remote_player_volume(player_id, volume);
}
- (double)__EXT_NATIVE__photon_voice_get_remote_player_volume:(double)player_id
{
    return __EXT_NATIVE__photon_voice_get_remote_player_volume(player_id);
}
- (double)__EXT_NATIVE__photon_voice_get_debug_lost_percent
{
    return __EXT_NATIVE__photon_voice_get_debug_lost_percent();
}
- (double)__EXT_NATIVE__photon_voice_set_debug_lost_percent:(double)percent
{
    return __EXT_NATIVE__photon_voice_set_debug_lost_percent(percent);
}
- (double)__EXT_NATIVE__photon_voice_get_speaking_threshold_ms
{
    return __EXT_NATIVE__photon_voice_get_speaking_threshold_ms();
}
- (double)__EXT_NATIVE__photon_voice_set_speaking_threshold_ms:(double)ms
{
    return __EXT_NATIVE__photon_voice_set_speaking_threshold_ms(ms);
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_state
{
    return __EXT_NATIVE__photon_realtime_peer_get_state();
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_round_trip_time
{
    return __EXT_NATIVE__photon_realtime_peer_get_round_trip_time();
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_round_trip_time_variance
{
    return __EXT_NATIVE__photon_realtime_peer_get_round_trip_time_variance();
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_bytes_in
{
    return __EXT_NATIVE__photon_realtime_peer_get_bytes_in();
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_bytes_out
{
    return __EXT_NATIVE__photon_realtime_peer_get_bytes_out();
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_queued_incoming_commands
{
    return __EXT_NATIVE__photon_realtime_peer_get_queued_incoming_commands();
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_queued_outgoing_commands
{
    return __EXT_NATIVE__photon_realtime_peer_get_queued_outgoing_commands();
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_debug_output_level:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_realtime_peer_get_debug_output_level(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_peer_set_debug_output_level:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_realtime_peer_set_debug_output_level(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_disconnect_timeout
{
    return __EXT_NATIVE__photon_realtime_peer_get_disconnect_timeout();
}
- (double)__EXT_NATIVE__photon_realtime_peer_set_disconnect_timeout:(double)timeout_ms
{
    return __EXT_NATIVE__photon_realtime_peer_set_disconnect_timeout(timeout_ms);
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_time_ping_interval
{
    return __EXT_NATIVE__photon_realtime_peer_get_time_ping_interval();
}
- (double)__EXT_NATIVE__photon_realtime_peer_set_time_ping_interval:(double)interval_ms
{
    return __EXT_NATIVE__photon_realtime_peer_set_time_ping_interval(interval_ms);
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_crc_enabled
{
    return __EXT_NATIVE__photon_realtime_peer_get_crc_enabled();
}
- (double)__EXT_NATIVE__photon_realtime_peer_set_crc_enabled:(double)enabled
{
    return __EXT_NATIVE__photon_realtime_peer_set_crc_enabled(enabled);
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_packet_loss_by_crc
{
    return __EXT_NATIVE__photon_realtime_peer_get_packet_loss_by_crc();
}
- (double)__EXT_NATIVE__photon_realtime_peer_get_timestamp_of_last_socket_receive
{
    return __EXT_NATIVE__photon_realtime_peer_get_timestamp_of_last_socket_receive();
}
- (double)__EXT_NATIVE__photon_realtime_peer_reset_traffic_stats
{
    return __EXT_NATIVE__photon_realtime_peer_reset_traffic_stats();
}
- (double)__EXT_NATIVE__photon_chat_peer_get_state
{
    return __EXT_NATIVE__photon_chat_peer_get_state();
}
- (double)__EXT_NATIVE__photon_chat_peer_get_round_trip_time
{
    return __EXT_NATIVE__photon_chat_peer_get_round_trip_time();
}
- (double)__EXT_NATIVE__photon_chat_peer_get_round_trip_time_variance
{
    return __EXT_NATIVE__photon_chat_peer_get_round_trip_time_variance();
}
- (double)__EXT_NATIVE__photon_chat_peer_get_bytes_in
{
    return __EXT_NATIVE__photon_chat_peer_get_bytes_in();
}
- (double)__EXT_NATIVE__photon_chat_peer_get_bytes_out
{
    return __EXT_NATIVE__photon_chat_peer_get_bytes_out();
}
- (double)__EXT_NATIVE__photon_chat_peer_get_queued_incoming_commands
{
    return __EXT_NATIVE__photon_chat_peer_get_queued_incoming_commands();
}
- (double)__EXT_NATIVE__photon_chat_peer_get_queued_outgoing_commands
{
    return __EXT_NATIVE__photon_chat_peer_get_queued_outgoing_commands();
}
- (double)__EXT_NATIVE__photon_chat_peer_get_debug_output_level:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_chat_peer_get_debug_output_level(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_peer_set_debug_output_level:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_chat_peer_set_debug_output_level(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_chat_peer_get_disconnect_timeout
{
    return __EXT_NATIVE__photon_chat_peer_get_disconnect_timeout();
}
- (double)__EXT_NATIVE__photon_chat_peer_set_disconnect_timeout:(double)timeout_ms
{
    return __EXT_NATIVE__photon_chat_peer_set_disconnect_timeout(timeout_ms);
}
- (double)__EXT_NATIVE__photon_chat_peer_get_time_ping_interval
{
    return __EXT_NATIVE__photon_chat_peer_get_time_ping_interval();
}
- (double)__EXT_NATIVE__photon_chat_peer_set_time_ping_interval:(double)interval_ms
{
    return __EXT_NATIVE__photon_chat_peer_set_time_ping_interval(interval_ms);
}
- (double)__EXT_NATIVE__photon_chat_peer_get_crc_enabled
{
    return __EXT_NATIVE__photon_chat_peer_get_crc_enabled();
}
- (double)__EXT_NATIVE__photon_chat_peer_set_crc_enabled:(double)enabled
{
    return __EXT_NATIVE__photon_chat_peer_set_crc_enabled(enabled);
}
- (double)__EXT_NATIVE__photon_chat_peer_get_packet_loss_by_crc
{
    return __EXT_NATIVE__photon_chat_peer_get_packet_loss_by_crc();
}
- (double)__EXT_NATIVE__photon_chat_peer_get_timestamp_of_last_socket_receive
{
    return __EXT_NATIVE__photon_chat_peer_get_timestamp_of_last_socket_receive();
}
- (double)__EXT_NATIVE__photon_chat_peer_reset_traffic_stats
{
    return __EXT_NATIVE__photon_chat_peer_reset_traffic_stats();
}
- (double)__EXT_NATIVE__photon_peer_network_sim_get_enabled
{
    return __EXT_NATIVE__photon_peer_network_sim_get_enabled();
}
- (double)__EXT_NATIVE__photon_peer_network_sim_set_enabled:(double)enabled
{
    return __EXT_NATIVE__photon_peer_network_sim_set_enabled(enabled);
}
- (double)__EXT_NATIVE__photon_peer_network_sim_set_lag:(double)incoming_ms arg1:(double)outgoing_ms
{
    return __EXT_NATIVE__photon_peer_network_sim_set_lag(incoming_ms, outgoing_ms);
}
- (double)__EXT_NATIVE__photon_peer_network_sim_set_jitter:(double)incoming_ms arg1:(double)outgoing_ms
{
    return __EXT_NATIVE__photon_peer_network_sim_set_jitter(incoming_ms, outgoing_ms);
}
- (double)__EXT_NATIVE__photon_peer_network_sim_set_packet_loss:(double)incoming_pct arg1:(double)outgoing_pct
{
    return __EXT_NATIVE__photon_peer_network_sim_set_packet_loss(incoming_pct, outgoing_pct);
}
- (double)__EXT_NATIVE__photon_common_set_debug_level:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_common_set_debug_level(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__photon_common_get_debug_level:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_common_get_debug_level(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__photon_common_get_serialization_protocol:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__photon_common_get_serialization_protocol(__ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__photon_common_type_code_to_string:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__photon_common_type_code_to_string(__arg_buffer, __arg_buffer_length);
}
- (char*)__EXT_NATIVE__photon_common_get_sdk_version
{
    return __EXT_NATIVE__photon_common_get_sdk_version();
}
- (char*)__EXT_NATIVE__photon_common_client_state_to_string:(double)state
{
    return __EXT_NATIVE__photon_common_client_state_to_string(state);
}
- (char*)__EXT_NATIVE__photon_common_disconnect_cause_to_string:(double)cause
{
    return __EXT_NATIVE__photon_common_disconnect_cause_to_string(cause);
}
- (double)__EXT_NATIVE__GMPhoton_invocation_handler:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__GMPhoton_invocation_handler(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__GMPhoton_queue_buffer:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__GMPhoton_queue_buffer(__arg_buffer, __arg_buffer_length);
}
@end

