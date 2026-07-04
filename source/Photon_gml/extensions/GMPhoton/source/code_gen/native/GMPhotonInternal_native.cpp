// ##### extgen :: Auto-generated file do not edit!! #####

#include "GMPhotonInternal_native.h"
#include "GMPhotonInternal_exports.h"

using namespace gm_structs;
using namespace gm::wire::codec;

static gm::runtime::DispatchQueue __dispatch_queue;

// Internal function used for fetching dispatched function calls to GML
GMEXPORT double __EXT_NATIVE__GMPhoton_invocation_handler(char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferWriter __bw{ __ret_buffer, static_cast<size_t>(__ret_buffer_length) };
    return __dispatch_queue.fetch(__bw);
}

static std::queue<gm::wire::GMBuffer> __buffer_queue;

// Internal function used for queueing buffers to native code
GMEXPORT double __EXT_NATIVE__GMPhoton_queue_buffer(char* __arg_buffer, double __arg_buffer_length)
{
    gm::wire::GMBuffer __buff{__arg_buffer, static_cast<uint64_t>(__arg_buffer_length)};
    __buffer_queue.push(__buff);

    return 1.0;
}

GMEXPORT double __EXT_NATIVE__photon_realtime_init()
{
    auto&& __result = photon_realtime_init();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_shutdown()
{
    auto&& __result = photon_realtime_shutdown();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_service()
{
    auto&& __result = photon_realtime_service();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_connect(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: app_id, type: String
    std::string_view app_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: app_version, type: String
    std::string_view app_version = gm::wire::codec::readValue<std::string_view>(__br);

    // field: options, type: optional<struct PhotonRealtimeConnectOptions>
    std::optional<gm_structs::PhotonRealtimeConnectOptions> options = gm::wire::codec::readOptional<gm_structs::PhotonRealtimeConnectOptions>(__br);

    auto&& __result = photon_realtime_connect(app_id, app_version, options);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_disconnect()
{
    auto&& __result = photon_realtime_disconnect();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_select_region(char* region)
{
    auto&& __result = photon_realtime_select_region(region);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_reconnect_and_rejoin()
{
    auto&& __result = photon_realtime_reconnect_and_rejoin();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_fetch_server_timestamp()
{
    auto&& __result = photon_realtime_fetch_server_timestamp();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_join_lobby(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_name, type: String
    std::string_view lobby_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: lobby_type, type: enum PhotonRealtimeLobbyType
    gm_enums::PhotonRealtimeLobbyType lobby_type = gm::wire::codec::readValue<gm_enums::PhotonRealtimeLobbyType>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_join_lobby(lobby_name, lobby_type, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_leave_lobby(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_leave_lobby(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_create_room(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: room_name, type: String
    std::string_view room_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: options, type: struct PhotonRealtimeRoomOptions
    gm_structs::PhotonRealtimeRoomOptions options = gm::wire::codec::readValue<gm_structs::PhotonRealtimeRoomOptions>(__br);

    // field: custom_properties, type: AnyMap
    gm::wire::GMObjectView custom_properties = gm::wire::codec::readValue<gm::wire::GMObjectView>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_create_room(room_name, options, custom_properties, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_join_or_create_room(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: room_name, type: String
    std::string_view room_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: options, type: struct PhotonRealtimeRoomOptions
    gm_structs::PhotonRealtimeRoomOptions options = gm::wire::codec::readValue<gm_structs::PhotonRealtimeRoomOptions>(__br);

    // field: custom_properties, type: AnyMap
    gm::wire::GMObjectView custom_properties = gm::wire::codec::readValue<gm::wire::GMObjectView>(__br);

    // field: cache_slice_index, type: optional<Int32>
    std::optional<std::int32_t> cache_slice_index = gm::wire::codec::readOptional<std::int32_t>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_join_or_create_room(room_name, options, custom_properties, cache_slice_index, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_join_room(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: room_name, type: String
    std::string_view room_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: options, type: struct PhotonRealtimeJoinRoomOptions
    gm_structs::PhotonRealtimeJoinRoomOptions options = gm::wire::codec::readValue<gm_structs::PhotonRealtimeJoinRoomOptions>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_join_room(room_name, options, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_join_random_room(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: options, type: struct PhotonRealtimeJoinRandomOptions
    gm_structs::PhotonRealtimeJoinRandomOptions options = gm::wire::codec::readValue<gm_structs::PhotonRealtimeJoinRandomOptions>(__br);

    // field: expected_properties, type: AnyMap
    gm::wire::GMObjectView expected_properties = gm::wire::codec::readValue<gm::wire::GMObjectView>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_join_random_room(options, expected_properties, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_leave_room(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: will_come_back, type: Bool
    bool will_come_back = gm::wire::codec::readValue<bool>(__br);

    // field: send_authentication_cookie, type: Bool
    bool send_authentication_cookie = gm::wire::codec::readValue<bool>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_leave_room(will_come_back, send_authentication_cookie, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_join_random_or_create_room(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: room_name, type: String
    std::string_view room_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: options, type: struct PhotonRealtimeRoomOptions
    gm_structs::PhotonRealtimeRoomOptions options = gm::wire::codec::readValue<gm_structs::PhotonRealtimeRoomOptions>(__br);

    // field: custom_properties, type: AnyMap
    gm::wire::GMObjectView custom_properties = gm::wire::codec::readValue<gm::wire::GMObjectView>(__br);

    // field: random_options, type: struct PhotonRealtimeJoinRandomOptions
    gm_structs::PhotonRealtimeJoinRandomOptions random_options = gm::wire::codec::readValue<gm_structs::PhotonRealtimeJoinRandomOptions>(__br);

    // field: expected_properties, type: AnyMap
    gm::wire::GMObjectView expected_properties = gm::wire::codec::readValue<gm::wire::GMObjectView>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_join_random_or_create_room(room_name, options, custom_properties, random_options, expected_properties, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_get_room_list(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_name, type: String
    std::string_view lobby_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: sql_filter, type: String
    std::string_view sql_filter = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_get_room_list(lobby_name, sql_filter, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_lobby_stats(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_lobby_stats(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_find_friends(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: friends, type: String[]
    std::vector<std::string_view> friends = gm::wire::codec::readVector<std::string_view>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_find_friends(friends, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_web_rpc(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: uri_path, type: String
    std::string_view uri_path = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_realtime_operation_web_rpc(uri_path, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_change_groups(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: groups_to_remove, type: optional<Int32[]>
    std::optional<std::vector<std::int32_t>> groups_to_remove = gm::wire::codec::readOptional<std::vector<std::int32_t>>(__br);

    // field: groups_to_add, type: optional<Int32[]>
    std::optional<std::vector<std::int32_t>> groups_to_add = gm::wire::codec::readOptional<std::vector<std::int32_t>>(__br);

    auto&& __result = photon_realtime_operation_change_groups(groups_to_remove, groups_to_add);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_custom_auth_next_step(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: authentication, type: struct PhotonRealtimeAuthenticationValues
    gm_structs::PhotonRealtimeAuthenticationValues authentication = gm::wire::codec::readValue<gm_structs::PhotonRealtimeAuthenticationValues>(__br);

    auto&& __result = photon_realtime_operation_custom_auth_next_step(authentication);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_raise_event_string(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: reliable, type: Bool
    bool reliable = gm::wire::codec::readValue<bool>(__br);

    // field: payload, type: String
    std::string_view payload = gm::wire::codec::readValue<std::string_view>(__br);

    // field: event_code, type: Int32
    std::int32_t event_code = gm::wire::codec::readValue<std::int32_t>(__br);

    // field: options, type: optional<struct PhotonRealtimeRaiseEventOptions>
    std::optional<gm_structs::PhotonRealtimeRaiseEventOptions> options = gm::wire::codec::readOptional<gm_structs::PhotonRealtimeRaiseEventOptions>(__br);

    auto&& __result = photon_realtime_operation_raise_event_string(reliable, payload, event_code, options);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_operation_raise_event_buffer(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: reliable, type: Bool
    bool reliable = gm::wire::codec::readValue<bool>(__br);

    // field: data, type: Buffer
    gm::wire::GMBuffer data = __buffer_queue.front();
    __buffer_queue.pop();

    // field: bytes, type: UInt32
    std::uint32_t bytes = gm::wire::codec::readValue<std::uint32_t>(__br);

    // field: event_code, type: Int32
    std::int32_t event_code = gm::wire::codec::readValue<std::int32_t>(__br);

    // field: options, type: optional<struct PhotonRealtimeRaiseEventOptions>
    std::optional<gm_structs::PhotonRealtimeRaiseEventOptions> options = gm::wire::codec::readOptional<gm_structs::PhotonRealtimeRaiseEventOptions>(__br);

    auto&& __result = photon_realtime_operation_raise_event_buffer(reliable, data, bytes, event_code, options);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_buffer_event_queue_count()
{
    auto&& __result = photon_realtime_get_buffer_event_queue_count();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_clear_buffer_event_queue()
{
    auto&& __result = photon_realtime_clear_buffer_event_queue();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peek_next_buffer_event_size()
{
    auto&& __result = photon_realtime_peek_next_buffer_event_size();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peek_next_buffer_event_code()
{
    auto&& __result = photon_realtime_peek_next_buffer_event_code();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_receive_one_event_buffer(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: out_data, type: Buffer
    gm::wire::GMBuffer out_data = __buffer_queue.front();
    __buffer_queue.pop();

    // field: max_bytes, type: UInt32
    std::uint32_t max_bytes = gm::wire::codec::readValue<std::uint32_t>(__br);

    // field: offset, type: UInt32
    std::uint32_t offset = gm::wire::codec::readValue<std::uint32_t>(__br);

    auto&& __result = photon_realtime_receive_one_event_buffer(out_data, max_bytes, offset);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct PhotonRealtimeEventBufferReceived
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_realtime_is_initialized()
{
    auto&& __result = photon_realtime_is_initialized();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_is_connected()
{
    auto&& __result = photon_realtime_is_connected();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_is_in_game_room()
{
    auto&& __result = photon_realtime_is_in_game_room();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_is_in_room()
{
    auto&& __result = photon_realtime_is_in_room();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_is_in_lobby()
{
    auto&& __result = photon_realtime_is_in_lobby();
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_get_current_room_name()
{
    static std::string __result;
    __result = photon_realtime_get_current_room_name();
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_local_player_number()
{
    auto&& __result = photon_realtime_get_local_player_number();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_server_time_offset()
{
    auto&& __result = photon_realtime_get_server_time_offset();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_server_time()
{
    auto&& __result = photon_realtime_get_server_time();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_bytes_in()
{
    auto&& __result = photon_realtime_get_bytes_in();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_bytes_out()
{
    auto&& __result = photon_realtime_get_bytes_out();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_state(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_realtime_get_state();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum PhotonRealtimeState
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_round_trip_time()
{
    auto&& __result = photon_realtime_get_round_trip_time();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_round_trip_time_variance()
{
    auto&& __result = photon_realtime_get_round_trip_time_variance();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_disconnected_cause(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_realtime_get_disconnected_cause();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum PhotonRealtimeDisconnectCause
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_get_user_id()
{
    static std::string __result;
    __result = photon_realtime_get_user_id();
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_count_players_ingame()
{
    auto&& __result = photon_realtime_get_count_players_ingame();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_count_games_running()
{
    auto&& __result = photon_realtime_get_count_games_running();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_count_players_online()
{
    auto&& __result = photon_realtime_get_count_players_online();
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_get_master_server_address()
{
    static std::string __result;
    __result = photon_realtime_get_master_server_address();
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_get_region()
{
    static std::string __result;
    __result = photon_realtime_get_region();
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_get_region_with_best_ping()
{
    static std::string __result;
    __result = photon_realtime_get_region_with_best_ping();
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_friend_list_age()
{
    auto&& __result = photon_realtime_get_friend_list_age();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_disconnect_timeout()
{
    auto&& __result = photon_realtime_get_disconnect_timeout();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_disconnect_timeout(double milliseconds)
{
    auto&& __result = photon_realtime_set_disconnect_timeout(static_cast<std::int32_t>(milliseconds));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_ping_interval()
{
    auto&& __result = photon_realtime_get_ping_interval();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_ping_interval(double milliseconds)
{
    auto&& __result = photon_realtime_set_ping_interval(static_cast<std::int32_t>(milliseconds));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_auto_join_lobby()
{
    auto&& __result = photon_realtime_get_auto_join_lobby();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_auto_join_lobby(double enabled)
{
    auto&& __result = photon_realtime_set_auto_join_lobby(static_cast<bool>(enabled));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_room_player_count()
{
    auto&& __result = photon_realtime_get_room_player_count();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_room_max_players()
{
    auto&& __result = photon_realtime_get_room_max_players();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_room_is_open()
{
    auto&& __result = photon_realtime_get_room_is_open();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_room_is_visible()
{
    auto&& __result = photon_realtime_get_room_is_visible();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_master_client_number()
{
    auto&& __result = photon_realtime_get_master_client_number();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_master_client(double player_number)
{
    auto&& __result = photon_realtime_set_master_client(static_cast<std::int32_t>(player_number));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_room_list_count()
{
    auto&& __result = photon_realtime_get_room_list_count();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_room_info_by_index(double index, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_realtime_get_room_info_by_index(static_cast<std::int32_t>(index));
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct PhotonRealtimeRoomInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_player_count()
{
    auto&& __result = photon_realtime_get_player_count();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_player_number_by_index(double index)
{
    auto&& __result = photon_realtime_get_player_number_by_index(static_cast<std::int32_t>(index));
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_player_get_name(double player_number)
{
    static std::string __result;
    __result = photon_realtime_player_get_name(static_cast<std::int32_t>(player_number));
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_player_get_user_id(double player_number)
{
    static std::string __result;
    __result = photon_realtime_player_get_user_id(static_cast<std::int32_t>(player_number));
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_is_inactive(double player_number)
{
    auto&& __result = photon_realtime_player_is_inactive(static_cast<std::int32_t>(player_number));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_is_master_client(double player_number)
{
    auto&& __result = photon_realtime_player_is_master_client(static_cast<std::int32_t>(player_number));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_get_player_numbers(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_realtime_get_player_numbers();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int32[]
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_debug(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_debug(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_connected(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_connected(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_disconnected(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_disconnected(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_connection_error(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_connection_error(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_client_error(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_client_error(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_server_error(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_server_error(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_warning(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_warning(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_join_room_event(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_join_room_event(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_leave_room_event(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_leave_room_event(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_custom_event(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_custom_event(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_room_properties_change(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_room_properties_change(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_player_properties_change(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_player_properties_change(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_room_list_update(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_room_list_update(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_app_stats_update(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_app_stats_update(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_lobby_stats_update(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_lobby_stats_update(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_cache_slice_changed(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_cache_slice_changed(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_master_client_changed(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_master_client_changed(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_properties_change_failed(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_properties_change_failed(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_custom_authentication_step(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_custom_authentication_step(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_available_regions(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_available_regions(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_secret_receival(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_secret_receival(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_direct_connection_established(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_direct_connection_established(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_direct_connection_failed(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_direct_connection_failed(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_direct_message(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_direct_message(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_set_callback_custom_operation_response(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_realtime_set_callback_custom_operation_response(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_debug()
{
    auto&& __result = photon_realtime_remove_callback_debug();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_connected()
{
    auto&& __result = photon_realtime_remove_callback_connected();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_disconnected()
{
    auto&& __result = photon_realtime_remove_callback_disconnected();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_connection_error()
{
    auto&& __result = photon_realtime_remove_callback_connection_error();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_client_error()
{
    auto&& __result = photon_realtime_remove_callback_client_error();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_server_error()
{
    auto&& __result = photon_realtime_remove_callback_server_error();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_warning()
{
    auto&& __result = photon_realtime_remove_callback_warning();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_join_room_event()
{
    auto&& __result = photon_realtime_remove_callback_join_room_event();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_leave_room_event()
{
    auto&& __result = photon_realtime_remove_callback_leave_room_event();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_custom_event()
{
    auto&& __result = photon_realtime_remove_callback_custom_event();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_room_properties_change()
{
    auto&& __result = photon_realtime_remove_callback_room_properties_change();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_player_properties_change()
{
    auto&& __result = photon_realtime_remove_callback_player_properties_change();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_room_list_update()
{
    auto&& __result = photon_realtime_remove_callback_room_list_update();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_app_stats_update()
{
    auto&& __result = photon_realtime_remove_callback_app_stats_update();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_lobby_stats_update()
{
    auto&& __result = photon_realtime_remove_callback_lobby_stats_update();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_cache_slice_changed()
{
    auto&& __result = photon_realtime_remove_callback_cache_slice_changed();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_master_client_changed()
{
    auto&& __result = photon_realtime_remove_callback_master_client_changed();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_properties_change_failed()
{
    auto&& __result = photon_realtime_remove_callback_properties_change_failed();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_custom_authentication_step()
{
    auto&& __result = photon_realtime_remove_callback_custom_authentication_step();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_available_regions()
{
    auto&& __result = photon_realtime_remove_callback_available_regions();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_secret_receival()
{
    auto&& __result = photon_realtime_remove_callback_secret_receival();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_direct_connection_established()
{
    auto&& __result = photon_realtime_remove_callback_direct_connection_established();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_direct_connection_failed()
{
    auto&& __result = photon_realtime_remove_callback_direct_connection_failed();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_direct_message()
{
    auto&& __result = photon_realtime_remove_callback_direct_message();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_remove_callback_custom_operation_response()
{
    auto&& __result = photon_realtime_remove_callback_custom_operation_response();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_set_string(char* key, char* value)
{
    auto&& __result = photon_realtime_room_properties_set_string(key, value);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_set_i32(char* key, double value)
{
    auto&& __result = photon_realtime_room_properties_set_i32(key, static_cast<std::int32_t>(value));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_set_f64(char* key, double value)
{
    auto&& __result = photon_realtime_room_properties_set_f64(key, static_cast<double>(value));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_set_bool(char* key, double value)
{
    auto&& __result = photon_realtime_room_properties_set_bool(key, static_cast<bool>(value));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_remove(char* key)
{
    auto&& __result = photon_realtime_room_properties_remove(key);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_clear()
{
    auto&& __result = photon_realtime_room_properties_clear();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_has(char* key)
{
    auto&& __result = photon_realtime_room_properties_has(key);
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_room_properties_get_string(char* key)
{
    static std::string __result;
    __result = photon_realtime_room_properties_get_string(key);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_get_i32(char* key)
{
    auto&& __result = photon_realtime_room_properties_get_i32(key);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_get_f64(char* key)
{
    auto&& __result = photon_realtime_room_properties_get_f64(key);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_get_bool(char* key)
{
    auto&& __result = photon_realtime_room_properties_get_bool(key);
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_room_properties_to_string()
{
    static std::string __result;
    __result = photon_realtime_room_properties_to_string();
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_get_all(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_realtime_room_properties_get_all();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: AnyMap
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_cas_string(char* key, char* expected_value, char* new_value)
{
    auto&& __result = photon_realtime_room_properties_cas_string(key, expected_value, new_value);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_cas_i32(char* key, double expected_value, double new_value)
{
    auto&& __result = photon_realtime_room_properties_cas_i32(key, static_cast<std::int32_t>(expected_value), static_cast<std::int32_t>(new_value));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_cas_f64(char* key, double expected_value, double new_value)
{
    auto&& __result = photon_realtime_room_properties_cas_f64(key, static_cast<double>(expected_value), static_cast<double>(new_value));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_room_properties_cas_bool(char* key, double expected_value, double new_value)
{
    auto&& __result = photon_realtime_room_properties_cas_bool(key, static_cast<bool>(expected_value), static_cast<bool>(new_value));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_set_local_string(char* key, char* value)
{
    auto&& __result = photon_realtime_player_properties_set_local_string(key, value);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_set_local_i32(char* key, double value)
{
    auto&& __result = photon_realtime_player_properties_set_local_i32(key, static_cast<std::int32_t>(value));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_set_local_f64(char* key, double value)
{
    auto&& __result = photon_realtime_player_properties_set_local_f64(key, static_cast<double>(value));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_set_local_bool(char* key, double value)
{
    auto&& __result = photon_realtime_player_properties_set_local_bool(key, static_cast<bool>(value));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_remove_local(char* key)
{
    auto&& __result = photon_realtime_player_properties_remove_local(key);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_clear_local()
{
    auto&& __result = photon_realtime_player_properties_clear_local();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_has_local(char* key)
{
    auto&& __result = photon_realtime_player_properties_has_local(key);
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_player_properties_get_local_string(char* key)
{
    static std::string __result;
    __result = photon_realtime_player_properties_get_local_string(key);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_get_local_i32(char* key)
{
    auto&& __result = photon_realtime_player_properties_get_local_i32(key);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_get_local_f64(char* key)
{
    auto&& __result = photon_realtime_player_properties_get_local_f64(key);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_get_local_bool(char* key)
{
    auto&& __result = photon_realtime_player_properties_get_local_bool(key);
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_player_properties_to_string_local()
{
    static std::string __result;
    __result = photon_realtime_player_properties_to_string_local();
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_get_local_all(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_realtime_player_properties_get_local_all();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: AnyMap
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_has_remote(double player_number, char* key)
{
    auto&& __result = photon_realtime_player_properties_has_remote(static_cast<std::int32_t>(player_number), key);
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_player_properties_get_remote_string(double player_number, char* key)
{
    static std::string __result;
    __result = photon_realtime_player_properties_get_remote_string(static_cast<std::int32_t>(player_number), key);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_get_remote_i32(double player_number, char* key)
{
    auto&& __result = photon_realtime_player_properties_get_remote_i32(static_cast<std::int32_t>(player_number), key);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_get_remote_f64(double player_number, char* key)
{
    auto&& __result = photon_realtime_player_properties_get_remote_f64(static_cast<std::int32_t>(player_number), key);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_get_remote_bool(double player_number, char* key)
{
    auto&& __result = photon_realtime_player_properties_get_remote_bool(static_cast<std::int32_t>(player_number), key);
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_realtime_player_properties_to_string_remote(double player_number)
{
    static std::string __result;
    __result = photon_realtime_player_properties_to_string_remote(static_cast<std::int32_t>(player_number));
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_realtime_player_properties_get_remote_all(double player_number, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_realtime_player_properties_get_remote_all(static_cast<std::int32_t>(player_number));
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: AnyMap
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peek_next_buffer_event_player_number()
{
    auto&& __result = photon_realtime_peek_next_buffer_event_player_number();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_init()
{
    auto&& __result = photon_chat_init();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_shutdown()
{
    auto&& __result = photon_chat_shutdown();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_service()
{
    auto&& __result = photon_chat_service();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_connect(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: app_id, type: String
    std::string_view app_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: app_version, type: String
    std::string_view app_version = gm::wire::codec::readValue<std::string_view>(__br);

    // field: options, type: optional<struct PhotonChatConnectOptions>
    std::optional<gm_structs::PhotonChatConnectOptions> options = gm::wire::codec::readOptional<gm_structs::PhotonChatConnectOptions>(__br);

    auto&& __result = photon_chat_connect(app_id, app_version, options);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_disconnect()
{
    auto&& __result = photon_chat_disconnect();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_operation_subscribe(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: channels, type: String[]
    std::vector<std::string_view> channels = gm::wire::codec::readVector<std::string_view>(__br);

    // field: messages_from_history, type: optional<Int32>
    std::optional<std::int32_t> messages_from_history = gm::wire::codec::readOptional<std::int32_t>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_chat_operation_subscribe(channels, messages_from_history, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_operation_unsubscribe(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: channels, type: String[]
    std::vector<std::string_view> channels = gm::wire::codec::readVector<std::string_view>(__br);

    // field: callback, type: optional<Function>
    std::optional<gm::wire::GMFunction> callback = std::nullopt;
    if (gm::wire::codec::readValue<bool>(__br))
    {
        callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);
    }

    auto&& __result = photon_chat_operation_unsubscribe(channels, callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_operation_publish_message(char* channel_name, char* message)
{
    auto&& __result = photon_chat_operation_publish_message(channel_name, message);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_operation_send_private_message(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: user_name, type: String
    std::string_view user_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: message, type: String
    std::string_view message = gm::wire::codec::readValue<std::string_view>(__br);

    // field: encrypt, type: optional<Bool>
    std::optional<bool> encrypt = gm::wire::codec::readOptional<bool>(__br);

    auto&& __result = photon_chat_operation_send_private_message(user_name, message, encrypt);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_operation_set_online_status(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: status, type: enum PhotonChatUserStatus
    gm_enums::PhotonChatUserStatus status = gm::wire::codec::readValue<gm_enums::PhotonChatUserStatus>(__br);

    // field: message, type: optional<String>
    std::optional<std::string_view> message = gm::wire::codec::readOptional<std::string_view>(__br);

    auto&& __result = photon_chat_operation_set_online_status(status, message);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_operation_add_friends(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: user_ids, type: String[]
    std::vector<std::string_view> user_ids = gm::wire::codec::readVector<std::string_view>(__br);

    auto&& __result = photon_chat_operation_add_friends(user_ids);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_operation_remove_friends(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: user_ids, type: String[]
    std::vector<std::string_view> user_ids = gm::wire::codec::readVector<std::string_view>(__br);

    auto&& __result = photon_chat_operation_remove_friends(user_ids);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_is_initialized()
{
    auto&& __result = photon_chat_is_initialized();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_is_connected()
{
    auto&& __result = photon_chat_is_connected();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_get_state(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_chat_get_state();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum PhotonChatState
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_chat_get_disconnect_cause(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_chat_get_disconnect_cause();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum PhotonChatDisconnectCause
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__photon_chat_get_user_id()
{
    static std::string __result;
    __result = photon_chat_get_user_id();
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__photon_chat_get_region()
{
    static std::string __result;
    __result = photon_chat_get_region();
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_chat_get_server_time()
{
    auto&& __result = photon_chat_get_server_time();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_get_server_time_offset()
{
    auto&& __result = photon_chat_get_server_time_offset();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_get_bytes_in()
{
    auto&& __result = photon_chat_get_bytes_in();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_get_bytes_out()
{
    auto&& __result = photon_chat_get_bytes_out();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_get_channel_count(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: channel_type, type: enum PhotonChatChannelType
    gm_enums::PhotonChatChannelType channel_type = gm::wire::codec::readValue<gm_enums::PhotonChatChannelType>(__br);

    auto&& __result = photon_chat_get_channel_count(channel_type);
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_chat_get_channel_name(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: channel_type, type: enum PhotonChatChannelType
    gm_enums::PhotonChatChannelType channel_type = gm::wire::codec::readValue<gm_enums::PhotonChatChannelType>(__br);

    // field: index, type: Int32
    std::int32_t index = gm::wire::codec::readValue<std::int32_t>(__br);

    static std::string __result;
    __result = photon_chat_get_channel_name(channel_type, index);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_chat_get_channel_message_count(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: channel_type, type: enum PhotonChatChannelType
    gm_enums::PhotonChatChannelType channel_type = gm::wire::codec::readValue<gm_enums::PhotonChatChannelType>(__br);

    // field: channel_name, type: String
    std::string_view channel_name = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = photon_chat_get_channel_message_count(channel_type, channel_name);
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_chat_get_channel_message(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: channel_type, type: enum PhotonChatChannelType
    gm_enums::PhotonChatChannelType channel_type = gm::wire::codec::readValue<gm_enums::PhotonChatChannelType>(__br);

    // field: channel_name, type: String
    std::string_view channel_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: index, type: Int32
    std::int32_t index = gm::wire::codec::readValue<std::int32_t>(__br);

    static std::string __result;
    __result = photon_chat_get_channel_message(channel_type, channel_name, index);
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__photon_chat_get_channel_sender(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: channel_type, type: enum PhotonChatChannelType
    gm_enums::PhotonChatChannelType channel_type = gm::wire::codec::readValue<gm_enums::PhotonChatChannelType>(__br);

    // field: channel_name, type: String
    std::string_view channel_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: index, type: Int32
    std::int32_t index = gm::wire::codec::readValue<std::int32_t>(__br);

    static std::string __result;
    __result = photon_chat_get_channel_sender(channel_type, channel_name, index);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_debug(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_debug(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_connected(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_connected(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_state_change(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_state_change(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_connection_error(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_connection_error(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_client_error(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_client_error(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_warning(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_warning(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_server_error(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_server_error(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_disconnected(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_disconnected(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_status_update(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_status_update(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_get_messages(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_get_messages(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_private_message(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_private_message(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_set_callback_receive_broadcast(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_chat_set_callback_receive_broadcast(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_get_broadcast_queue_count()
{
    auto&& __result = photon_chat_get_broadcast_queue_count();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_clear_broadcast_queue()
{
    auto&& __result = photon_chat_clear_broadcast_queue();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peek_next_broadcast_size()
{
    auto&& __result = photon_chat_peek_next_broadcast_size();
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__photon_chat_peek_next_broadcast_channel()
{
    static std::string __result;
    __result = photon_chat_peek_next_broadcast_channel();
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__photon_chat_receive_one_broadcast_buffer(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: out_data, type: Buffer
    gm::wire::GMBuffer out_data = __buffer_queue.front();
    __buffer_queue.pop();

    // field: max_bytes, type: UInt32
    std::uint32_t max_bytes = gm::wire::codec::readValue<std::uint32_t>(__br);

    // field: offset, type: UInt32
    std::uint32_t offset = gm::wire::codec::readValue<std::uint32_t>(__br);

    auto&& __result = photon_chat_receive_one_broadcast_buffer(out_data, max_bytes, offset);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct PhotonRealtimeEventBufferReceived
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_debug()
{
    auto&& __result = photon_chat_remove_callback_debug();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_connected()
{
    auto&& __result = photon_chat_remove_callback_connected();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_state_change()
{
    auto&& __result = photon_chat_remove_callback_state_change();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_connection_error()
{
    auto&& __result = photon_chat_remove_callback_connection_error();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_client_error()
{
    auto&& __result = photon_chat_remove_callback_client_error();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_warning()
{
    auto&& __result = photon_chat_remove_callback_warning();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_server_error()
{
    auto&& __result = photon_chat_remove_callback_server_error();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_disconnected()
{
    auto&& __result = photon_chat_remove_callback_disconnected();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_status_update()
{
    auto&& __result = photon_chat_remove_callback_status_update();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_get_messages()
{
    auto&& __result = photon_chat_remove_callback_get_messages();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_private_message()
{
    auto&& __result = photon_chat_remove_callback_private_message();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_remove_callback_receive_broadcast()
{
    auto&& __result = photon_chat_remove_callback_receive_broadcast();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_init()
{
    auto&& __result = photon_voice_init();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_shutdown()
{
    auto&& __result = photon_voice_shutdown();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_service()
{
    auto&& __result = photon_voice_service();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_is_initialized()
{
    auto&& __result = photon_voice_is_initialized();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_notify_joined_room()
{
    auto&& __result = photon_voice_notify_joined_room();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_on_join_channel(double channel_id)
{
    auto&& __result = photon_voice_on_join_channel(static_cast<std::int32_t>(channel_id));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_on_leave_channel(double channel_id)
{
    auto&& __result = photon_voice_on_leave_channel(static_cast<std::int32_t>(channel_id));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_on_join_all_channels()
{
    auto&& __result = photon_voice_on_join_all_channels();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_on_leave_all_channels()
{
    auto&& __result = photon_voice_on_leave_all_channels();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_on_player_join(double channel_id, double player_id)
{
    auto&& __result = photon_voice_on_player_join(static_cast<std::int32_t>(channel_id), static_cast<std::int32_t>(player_id));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_on_player_leave(double channel_id, double player_id)
{
    auto&& __result = photon_voice_on_player_leave(static_cast<std::int32_t>(channel_id), static_cast<std::int32_t>(player_id));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_create_local_voice(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: channel_id, type: Int32
    std::int32_t channel_id = gm::wire::codec::readValue<std::int32_t>(__br);

    // field: codec, type: enum PhotonVoiceCodec
    gm_enums::PhotonVoiceCodec codec = gm::wire::codec::readValue<gm_enums::PhotonVoiceCodec>(__br);

    // field: sample_rate, type: Int32
    std::int32_t sample_rate = gm::wire::codec::readValue<std::int32_t>(__br);

    // field: channels, type: Int32
    std::int32_t channels = gm::wire::codec::readValue<std::int32_t>(__br);

    // field: bitrate, type: Int32
    std::int32_t bitrate = gm::wire::codec::readValue<std::int32_t>(__br);

    // field: frames_per_packet, type: Int32
    std::int32_t frames_per_packet = gm::wire::codec::readValue<std::int32_t>(__br);

    auto&& __result = photon_voice_create_local_voice(channel_id, codec, sample_rate, channels, bitrate, frames_per_packet);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_remove_local_voice(double voice_id)
{
    auto&& __result = photon_voice_remove_local_voice(static_cast<std::int32_t>(voice_id));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_push_frame_buffer(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: voice_id, type: Int32
    std::int32_t voice_id = gm::wire::codec::readValue<std::int32_t>(__br);

    // field: data, type: Buffer
    gm::wire::GMBuffer data = __buffer_queue.front();
    __buffer_queue.pop();

    // field: bytes, type: UInt32
    std::uint32_t bytes = gm::wire::codec::readValue<std::uint32_t>(__br);

    auto&& __result = photon_voice_push_frame_buffer(voice_id, data, bytes);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_frame_queue_count()
{
    auto&& __result = photon_voice_get_frame_queue_count();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_clear_frame_queue()
{
    auto&& __result = photon_voice_clear_frame_queue();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_peek_next_frame_size()
{
    auto&& __result = photon_voice_peek_next_frame_size();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_peek_next_frame_player_id()
{
    auto&& __result = photon_voice_peek_next_frame_player_id();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_peek_next_frame_voice_id()
{
    auto&& __result = photon_voice_peek_next_frame_voice_id();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_receive_frame_buffer(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: out_data, type: Buffer
    gm::wire::GMBuffer out_data = __buffer_queue.front();
    __buffer_queue.pop();

    // field: max_bytes, type: UInt32
    std::uint32_t max_bytes = gm::wire::codec::readValue<std::uint32_t>(__br);

    // field: offset, type: UInt32
    std::uint32_t offset = gm::wire::codec::readValue<std::uint32_t>(__br);

    auto&& __result = photon_voice_receive_frame_buffer(out_data, max_bytes, offset);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct PhotonRealtimeEventBufferReceived
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_remote_voice_count()
{
    auto&& __result = photon_voice_get_remote_voice_count();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_remote_voice_player_id(double index)
{
    auto&& __result = photon_voice_get_remote_voice_player_id(static_cast<std::int32_t>(index));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_remote_voice_id(double index)
{
    auto&& __result = photon_voice_get_remote_voice_id(static_cast<std::int32_t>(index));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_remote_voice_codec(double index, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_voice_get_remote_voice_codec(static_cast<std::int32_t>(index));
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum PhotonVoiceCodec
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_remote_voice_sample_rate(double index)
{
    auto&& __result = photon_voice_get_remote_voice_sample_rate(static_cast<std::int32_t>(index));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_remote_voice_channels(double index)
{
    auto&& __result = photon_voice_get_remote_voice_channels(static_cast<std::int32_t>(index));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_remote_voice_is_speaking(double index)
{
    auto&& __result = photon_voice_get_remote_voice_is_speaking(static_cast<std::int32_t>(index));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_frames_sent()
{
    auto&& __result = photon_voice_get_frames_sent();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_frames_received()
{
    auto&& __result = photon_voice_get_frames_received();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_frames_lost()
{
    auto&& __result = photon_voice_get_frames_lost();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_round_trip_time()
{
    auto&& __result = photon_voice_get_round_trip_time();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_round_trip_time_variance()
{
    auto&& __result = photon_voice_get_round_trip_time_variance();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_set_callback_remote_voice_added(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_voice_set_callback_remote_voice_added(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_set_callback_remote_voice_removed(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_voice_set_callback_remote_voice_removed(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_set_callback_speaking_changed(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_voice_set_callback_speaking_changed(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_set_callback_debug(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = photon_voice_set_callback_debug(callback);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_remove_callback_remote_voice_added()
{
    auto&& __result = photon_voice_remove_callback_remote_voice_added();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_remove_callback_remote_voice_removed()
{
    auto&& __result = photon_voice_remove_callback_remote_voice_removed();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_remove_callback_speaking_changed()
{
    auto&& __result = photon_voice_remove_callback_speaking_changed();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_remove_callback_debug()
{
    auto&& __result = photon_voice_remove_callback_debug();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_local_voice_set_transmit(double voice_id, double enabled)
{
    auto&& __result = photon_voice_local_voice_set_transmit(static_cast<std::int32_t>(voice_id), static_cast<bool>(enabled));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_local_voice_get_transmit(double voice_id)
{
    auto&& __result = photon_voice_local_voice_get_transmit(static_cast<std::int32_t>(voice_id));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_set_remote_player_muted(double player_id, double muted)
{
    auto&& __result = photon_voice_set_remote_player_muted(static_cast<std::int32_t>(player_id), static_cast<bool>(muted));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_remote_player_muted(double player_id)
{
    auto&& __result = photon_voice_get_remote_player_muted(static_cast<std::int32_t>(player_id));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_set_remote_player_volume(double player_id, double volume)
{
    auto&& __result = photon_voice_set_remote_player_volume(static_cast<std::int32_t>(player_id), static_cast<double>(volume));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_remote_player_volume(double player_id)
{
    auto&& __result = photon_voice_get_remote_player_volume(static_cast<std::int32_t>(player_id));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_debug_lost_percent()
{
    auto&& __result = photon_voice_get_debug_lost_percent();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_set_debug_lost_percent(double percent)
{
    auto&& __result = photon_voice_set_debug_lost_percent(static_cast<std::int32_t>(percent));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_get_speaking_threshold_ms()
{
    auto&& __result = photon_voice_get_speaking_threshold_ms();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_voice_set_speaking_threshold_ms(double ms)
{
    auto&& __result = photon_voice_set_speaking_threshold_ms(static_cast<std::int32_t>(ms));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_state()
{
    auto&& __result = photon_realtime_peer_get_state();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_round_trip_time()
{
    auto&& __result = photon_realtime_peer_get_round_trip_time();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_round_trip_time_variance()
{
    auto&& __result = photon_realtime_peer_get_round_trip_time_variance();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_bytes_in()
{
    auto&& __result = photon_realtime_peer_get_bytes_in();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_bytes_out()
{
    auto&& __result = photon_realtime_peer_get_bytes_out();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_queued_incoming_commands()
{
    auto&& __result = photon_realtime_peer_get_queued_incoming_commands();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_queued_outgoing_commands()
{
    auto&& __result = photon_realtime_peer_get_queued_outgoing_commands();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_debug_output_level(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_realtime_peer_get_debug_output_level();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum PhotonCommonDebugLevel
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_set_debug_output_level(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: level, type: enum PhotonCommonDebugLevel
    gm_enums::PhotonCommonDebugLevel level = gm::wire::codec::readValue<gm_enums::PhotonCommonDebugLevel>(__br);

    auto&& __result = photon_realtime_peer_set_debug_output_level(level);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_disconnect_timeout()
{
    auto&& __result = photon_realtime_peer_get_disconnect_timeout();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_set_disconnect_timeout(double timeout_ms)
{
    auto&& __result = photon_realtime_peer_set_disconnect_timeout(static_cast<std::int32_t>(timeout_ms));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_time_ping_interval()
{
    auto&& __result = photon_realtime_peer_get_time_ping_interval();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_set_time_ping_interval(double interval_ms)
{
    auto&& __result = photon_realtime_peer_set_time_ping_interval(static_cast<std::int32_t>(interval_ms));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_crc_enabled()
{
    auto&& __result = photon_realtime_peer_get_crc_enabled();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_set_crc_enabled(double enabled)
{
    auto&& __result = photon_realtime_peer_set_crc_enabled(static_cast<bool>(enabled));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_packet_loss_by_crc()
{
    auto&& __result = photon_realtime_peer_get_packet_loss_by_crc();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_get_timestamp_of_last_socket_receive()
{
    auto&& __result = photon_realtime_peer_get_timestamp_of_last_socket_receive();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_realtime_peer_reset_traffic_stats()
{
    auto&& __result = photon_realtime_peer_reset_traffic_stats();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_state()
{
    auto&& __result = photon_chat_peer_get_state();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_round_trip_time()
{
    auto&& __result = photon_chat_peer_get_round_trip_time();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_round_trip_time_variance()
{
    auto&& __result = photon_chat_peer_get_round_trip_time_variance();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_bytes_in()
{
    auto&& __result = photon_chat_peer_get_bytes_in();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_bytes_out()
{
    auto&& __result = photon_chat_peer_get_bytes_out();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_queued_incoming_commands()
{
    auto&& __result = photon_chat_peer_get_queued_incoming_commands();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_queued_outgoing_commands()
{
    auto&& __result = photon_chat_peer_get_queued_outgoing_commands();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_debug_output_level(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_chat_peer_get_debug_output_level();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum PhotonCommonDebugLevel
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_set_debug_output_level(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: level, type: enum PhotonCommonDebugLevel
    gm_enums::PhotonCommonDebugLevel level = gm::wire::codec::readValue<gm_enums::PhotonCommonDebugLevel>(__br);

    auto&& __result = photon_chat_peer_set_debug_output_level(level);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_disconnect_timeout()
{
    auto&& __result = photon_chat_peer_get_disconnect_timeout();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_set_disconnect_timeout(double timeout_ms)
{
    auto&& __result = photon_chat_peer_set_disconnect_timeout(static_cast<std::int32_t>(timeout_ms));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_time_ping_interval()
{
    auto&& __result = photon_chat_peer_get_time_ping_interval();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_set_time_ping_interval(double interval_ms)
{
    auto&& __result = photon_chat_peer_set_time_ping_interval(static_cast<std::int32_t>(interval_ms));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_crc_enabled()
{
    auto&& __result = photon_chat_peer_get_crc_enabled();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_set_crc_enabled(double enabled)
{
    auto&& __result = photon_chat_peer_set_crc_enabled(static_cast<bool>(enabled));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_packet_loss_by_crc()
{
    auto&& __result = photon_chat_peer_get_packet_loss_by_crc();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_get_timestamp_of_last_socket_receive()
{
    auto&& __result = photon_chat_peer_get_timestamp_of_last_socket_receive();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_chat_peer_reset_traffic_stats()
{
    auto&& __result = photon_chat_peer_reset_traffic_stats();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_peer_network_sim_get_enabled()
{
    auto&& __result = photon_peer_network_sim_get_enabled();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_peer_network_sim_set_enabled(double enabled)
{
    auto&& __result = photon_peer_network_sim_set_enabled(static_cast<bool>(enabled));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_peer_network_sim_set_lag(double incoming_ms, double outgoing_ms)
{
    auto&& __result = photon_peer_network_sim_set_lag(static_cast<std::int32_t>(incoming_ms), static_cast<std::int32_t>(outgoing_ms));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_peer_network_sim_set_jitter(double incoming_ms, double outgoing_ms)
{
    auto&& __result = photon_peer_network_sim_set_jitter(static_cast<std::int32_t>(incoming_ms), static_cast<std::int32_t>(outgoing_ms));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_peer_network_sim_set_packet_loss(double incoming_pct, double outgoing_pct)
{
    auto&& __result = photon_peer_network_sim_set_packet_loss(static_cast<std::int32_t>(incoming_pct), static_cast<std::int32_t>(outgoing_pct));
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_common_set_debug_level(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: level, type: enum PhotonCommonDebugLevel
    gm_enums::PhotonCommonDebugLevel level = gm::wire::codec::readValue<gm_enums::PhotonCommonDebugLevel>(__br);

    auto&& __result = photon_common_set_debug_level(level);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__photon_common_get_debug_level(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_common_get_debug_level();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum PhotonCommonDebugLevel
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__photon_common_get_serialization_protocol(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = photon_common_get_serialization_protocol();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum PhotonCommonSerializationProtocol
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__photon_common_type_code_to_string(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: type_code, type: enum PhotonCommonTypeCode
    gm_enums::PhotonCommonTypeCode type_code = gm::wire::codec::readValue<gm_enums::PhotonCommonTypeCode>(__br);

    static std::string __result;
    __result = photon_common_type_code_to_string(type_code);
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__photon_common_get_sdk_version()
{
    static std::string __result;
    __result = photon_common_get_sdk_version();
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__photon_common_client_state_to_string(double state)
{
    static std::string __result;
    __result = photon_common_client_state_to_string(static_cast<std::int32_t>(state));
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__photon_common_disconnect_cause_to_string(double cause)
{
    static std::string __result;
    __result = photon_common_disconnect_cause_to_string(static_cast<std::int32_t>(cause));
    return (char*)__result.c_str();
}

