// ##### extgen :: Auto-generated file do not edit!! #####

#pragma once
#include <cstdint>
#include <string_view>
#include <vector>
#include <array>
#include <optional>
#include "core/GMExtWire.h"

namespace gm_consts
{
}


namespace gm_enums
{
    enum class PhotonRealtimeState : std::int32_t
    {
        Unknown = -1,
        Uninitialized = 0,
        PeerCreated = 1,
        ConnectingToNameserver = 2,
        ConnectedToNameserver = 3,
        DisconnectingFromNameserver = 4,
        Connecting = 5,
        Connected = 6,
        WaitingForCustomAuthNextStep = 7,
        Authenticated = 8,
        JoinedLobby = 9,
        DisconnectingFromMasterserver = 10,
        ConnectingToGameserver = 11,
        ConnectedToGameserver = 12,
        AuthenticatedOnGameServer = 13,
        Joining = 14,
        Joined = 15,
        Leaving = 16,
        Left = 17,
        DisconnectingFromGameserver = 18,
        ConnectingToMasterserver = 19,
        ConnectedComingFromGameserver = 20,
        AuthenticatedComingFromGameserver = 21,
        Disconnecting = 22,
        Disconnected = 23
    };

    enum class PhotonRealtimeLobbyType : std::int32_t
    {
        Default = 0,
        SqlLobby = 2,
        AsyncRandomLobby = 3
    };

    enum class PhotonRealtimeMatchmakingMode : std::int32_t
    {
        FillRoom = 0,
        SerialMatching = 1,
        RandomMatching = 2
    };

    enum class PhotonRealtimeDirectMode : std::int32_t
    {
        None = 0,
        AllToOthers = 1,
        MasterToOthers = 2,
        AllToAll = 3,
        MasterToAll = 4
    };

    enum class PhotonRealtimeDisconnectCause : std::int32_t
    {
        Unknown = -1,
        None = 0,
        ServerUserLimit = 1,
        ExceptionOnConnect = 2,
        DisconnectByServer = 3,
        DisconnectByServerLogic = 4,
        TimeoutDisconnect = 5,
        Exception = 6,
        InvalidAuthentication = 7,
        MaxCcuReached = 8,
        InvalidRegion = 9,
        OperationNotAllowed = 10,
        CustomAuthenticationFailed = 11,
        ClientVersionTooOld = 12,
        ClientVersionInvalid = 13,
        DashboardVersionInvalid = 14,
        AuthenticationTicketExpired = 15,
        OperationLimit = 16
    };

    enum class PhotonRealtimeRegionSelectionMode : std::int32_t
    {
        Default = 0,
        Select = 1,
        Best = 2
    };

    enum class PhotonRealtimeServerType : std::int32_t
    {
        NameServer = 0,
        MasterServer = 1
    };

    enum class PhotonRealtimeCustomAuthType : std::int32_t
    {
        Custom = 0,
        Steam = 1,
        Facebook = 2,
        Oculus = 3,
        PlayStation4 = 4,
        Xbox = 5,
        Viveport = 10,
        NintendoSwitch = 11,
        PlayStation5 = 12,
        Epic = 13,
        FacebookGaming = 15,
        None = 255
    };

    enum class PhotonRealtimeReceiverGroup : std::int32_t
    {
        Others = 0,
        All = 1,
        MasterClient = 2
    };

    enum class PhotonRealtimeEventCache : std::int32_t
    {
        DoNotCache = 0,
        MergeCache = 1,
        ReplaceCache = 2,
        RemoveCache = 3,
        AddToRoomCache = 4,
        AddToRoomCacheGlobal = 5,
        RemoveFromRoomCache = 6,
        RemoveFromRoomCacheForActorsLeft = 7,
        SliceIncIndex = 10,
        SliceSetIndex = 11,
        SlicePurgeIndex = 12,
        SlicePurgeUpToIndex = 13
    };

    enum class PhotonRealtimeLBOperationCode : std::int32_t
    {
        Leave = 254,
        RaiseEvent = 253,
        SetProperties = 252,
        GetProperties = 251,
        ChangeGroups = 248,
        AuthOnce = 231,
        Authenticate = 230,
        JoinLobby = 229,
        LeaveLobby = 228,
        CreateRoom = 227,
        JoinRoom = 226,
        JoinRandomRoom = 225,
        FindFriends = 222,
        LobbyStats = 221,
        GetRegions = 220,
        Rpc = 219,
        GetRoomList = 217
    };

    enum class PhotonRealtimeLBEventCode : std::int32_t
    {
        Join = 255,
        Leave = 254,
        PropertiesChanged = 253,
        ErrorInfo = 251,
        CacheSliceChanged = 250,
        RoomList = 230,
        RoomListUpdate = 229,
        AppStats = 226,
        LobbyStats = 224,
        Auth = 223,
        PunchMsg = 220,
        VoiceFrameData = 203,
        VoiceData = 202,
        MaxCustomEvCode = 200
    };

    enum class PhotonRealtimeAppErrorCode : std::int32_t
    {
        Ok = 0,
        InvalidAuthentication = 32767,
        GameIdAlreadyExists = 32766,
        GameFull = 32765,
        GameClosed = 32764,
        AlreadyMatched = 32763,
        ServerFull = 32762,
        UserBlocked = 32761,
        NoMatchFound = 32760,
        GameDoesNotExist = 32758,
        MaxCcuReached = 32757,
        InvalidRegion = 32756,
        CustomAuthenticationFailed = 32755,
        AuthTicketExpired = 32753,
        PluginReportedError = 32752,
        PluginMismatch = 32751,
        JoinFailedPeerAlreadyJoined = 32750,
        JoinFailedFoundInactiveJoiner = 32749,
        JoinFailedRejoinNotFound = 32748,
        JoinFailedFoundExcludedUserId = 32747,
        JoinFailedFoundActiveJoiner = 32746,
        HttpLimitReached = 32745,
        ExternalHttpCallFailed = 32744,
        OperationLimitReached = 32743,
        SlotError = 32742,
        InvalidEncryptionParameters = 32741,
        ClientVersionTooOld = 32667,
        ClientVersionInvalid = 32666,
        DashboardVersionInvalid = 32665
    };

    enum class PhotonCommonDebugLevel : std::int32_t
    {
        Off = 0,
        Errors = 1,
        Warnings = 2,
        Info = 3,
        All = 4
    };

    enum class PhotonCommonSerializationProtocol : std::int32_t
    {
        Protocol16 = 0,
        Protocol18 = 1
    };

    enum class PhotonCommonTypeCode : std::int32_t
    {
        Byte = 98,
        Short = 107,
        Integer = 105,
        Long = 108,
        Float = 102,
        Double = 100,
        Boolean = 111,
        String = 115,
        Hashtable = 104,
        Dictionary = 68,
        Object = 122,
        Array = 121,
        ByteArray = 120,
        PhotonCommand = 112,
        Null = 42,
        Custom = 99,
        Unknown = 0,
        Invalid = 255
    };

    enum class PhotonCommonInternalLogLevel : std::int32_t
    {
        Off = 0,
        Fatal = 1,
        Error = 2,
        Warning = 3,
        Info = 4,
        Debug = 5,
        DebugVerbose = 6
    };

    enum class PhotonPeerConnectionProtocol : std::int32_t
    {
        Udp = 0,
        Tcp = 1,
        Ws = 4,
        Wss = 5
    };

    enum class PhotonPeerState : std::int32_t
    {
        Disconnected = 0,
        Connecting = 1,
        InitializingApplication = 2,
        Connected = 3,
        Disconnecting = 4
    };

    enum class PhotonPeerStatusCode : std::int32_t
    {
        ExceptionOnConnect = 1023,
        Connect = 1024,
        Disconnect = 1025,
        Exception = 1026,
        QueueOutgoingReliableWarning = 1027,
        QueueOutgoingUnreliableWarning = 1029,
        SendError = 1030,
        QueueOutgoingAcksWarning = 1031,
        QueueIncomingReliableWarning = 1033,
        QueueIncomingUnreliableWarning = 1035,
        QueueSentWarning = 1037,
        InternalReceiveException = 1039,
        TimeoutDisconnect = 1040,
        DisconnectByServer = 1041,
        DisconnectByServerUserLimit = 1042,
        DisconnectByServerLogic = 1043,
        EncryptionEstablished = 1048,
        EncryptionFailedToEstablish = 1049
    };

    enum class PhotonPeerCoreErrorCode : std::int32_t
    {
        Ok = 0,
        InternalServerError = -1,
        OperationInvalid = -2,
        OperationDenied = -3,
        ArgumentOutOfRange = -4,
        InvalidRequestParameters = -6,
        NotReady = -7,
        Overload = -8,
        Backoff = -9,
        Maintenance = -10,
        SendBufferFull = -11,
        UnexpectedData = -12,
        SerializationLimitError = -13,
        WrongInitRequestData = -14,
        ResponseParseError = -15,
        CryptoProviderNotSet = -16,
        DecryptionFailure = -17,
        InvalidEncryptionParameters = -18,
        IncomingDataRateExceeded = -30,
        IncomingMsgRateExceeded = -31,
        IncomingMaxMsgSizeExceeded = -32,
        OperationMaxCountExceeded = -34,
        OperationRateExceeded = -35,
        OperationDataRateExceeded = -36,
        OperationBlocked = -37,
        OperationSizeLimitExceeded = -38,
        OperationParametersLimit = -39,
        MessagesRateExceeded = -40,
        MessagesDataRateExceeded = -41,
        MessagesBlocked = -42,
        MessageSizeLimitExceeded = -43
    };

    enum class PhotonPeerLiteOperationCode : std::int32_t
    {
        Join = 255,
        Leave = 254,
        RaiseEvent = 253,
        SetProperties = 252,
        GetProperties = 251,
        ChangeGroups = 248
    };

    enum class PhotonPeerLiteEventCode : std::int32_t
    {
        Join = 255,
        Leave = 254,
        PropertiesChanged = 253
    };

    enum class PhotonPeerLiteParameterCode : std::int32_t
    {
        GameId = 255,
        ActorNr = 254,
        TargetActorNr = 253,
        ActorList = 252,
        Properties = 251,
        Broadcast = 250,
        ActorProperties = 249,
        GameProperties = 248,
        Cache = 247,
        ReceiverGroup = 246,
        Data = 245,
        Code = 244,
        Group = 240,
        Remove = 239,
        Add = 238
    };

    enum class PhotonChatAppErrorCode : std::int32_t
    {
        Ok = 0,
        OperationDenied = -3,
        OperationInvalid = -2,
        InternalServerError = -1,
        InvalidAuthentication = 32767,
        GameIdAlreadyExists = 32766,
        GameFull = 32765,
        GameClosed = 32764,
        AlreadyMatched = 32763,
        ServerFull = 32762,
        UserBlocked = 32761,
        NoMatchFound = 32760,
        GameDoesNotExist = 32758,
        MaxCcuReached = 32757,
        InvalidRegion = 32756,
        CustomAuthenticationFailed = 32755
    };

    enum class PhotonChatState : std::int32_t
    {
        Unknown = -1,
        Uninitialized = 0,
        ConnectingToNameServer = 1,
        ConnectedToNameServer = 2,
        Authenticating = 3,
        Authenticated = 4,
        DisconnectingFromNameServer = 5,
        ConnectingToFrontEnd = 6,
        ConnectedToFrontEnd = 7,
        Disconnecting = 8,
        Disconnected = 9
    };

    enum class PhotonChatDisconnectCause : std::int32_t
    {
        Unknown = -1,
        None = 0,
        ServerUserLimit = 1,
        ExceptionOnConnect = 2,
        DisconnectByServer = 3,
        DisconnectByServerLogic = 4,
        TimeoutDisconnect = 5,
        Exception = 6,
        InvalidAuthentication = 7,
        MaxCcuReached = 8,
        InvalidRegion = 9,
        OperationNotAllowed = 10,
        CustomAuthenticationFailed = 11
    };

    enum class PhotonChatOperationCode : std::int32_t
    {
        Authenticate = 230,
        Subscribe = 0,
        Unsubscribe = 1,
        Publish = 2,
        SendPrivate = 3,
        ChannelHistory = 4,
        UpdateStatus = 5,
        AddFriends = 6,
        RemoveFriends = 7
    };

    enum class PhotonChatEventCode : std::int32_t
    {
        ChatMessages = 0,
        Users = 1,
        PrivateMessage = 2,
        FriendList = 3,
        StatusUpdate = 4,
        Subscribe = 5,
        Unsubscribe = 6
    };

    enum class PhotonChatParameterCode : std::int32_t
    {
        Channels = 0,
        Messages = 2,
        Message = 3,
        Senders = 4,
        Sender = 5,
        ChannelUserCount = 6,
        MessageId = 8,
        MessageIds = 9,
        Status = 10,
        Friends = 11,
        SkipMessage = 12,
        HistoryLength = 14,
        SubscribeResults = 15,
        Properties = 22,
        ChannelId = 29,
        Region = 210,
        AppVersion = 220,
        Secret = 221,
        AuthType = 217,
        AuthParams = 216,
        AuthData = 214,
        UserId = 225,
        AppId = 224,
        Address = 230
    };

    enum class PhotonChatUserStatus : std::int32_t
    {
        Offline = 0,
        Invisible = 1,
        Online = 2,
        Away = 3,
        Dnd = 4,
        Lfg = 5,
        Playing = 6
    };

    enum class PhotonVoiceCodec : std::int32_t
    {
        None = 0,
        AudioOpus = 11,
        VideoVp8 = 21,
        VideoVp9 = 22,
        VideoAv1 = 23,
        VideoH264 = 31,
        VideoH265 = 32
    };

    enum class PhotonChatChannelType : std::int32_t
    {
        Public = 0,
        Private = 1
    };

}


namespace gm_structs
{
    struct PhotonRealtimeEventBufferReceived;
    struct PhotonRealtimeJoinRandomOptions;
    struct PhotonRealtimeRoomOptions;
    struct PhotonRealtimeJoinRoomOptions;
    struct PhotonRealtimeRaiseEventOptions;
    struct PhotonRealtimeAuthenticationValues;
    struct PhotonRealtimeFriendInfo;
    struct PhotonRealtimeRoomInfo;
    struct PhotonRealtimeLobbyStats;
    struct PhotonChatMessage;
    struct PhotonChatSubscribeResult;
    struct PhotonRealtimeConnectOptions;
    struct PhotonChatConnectOptions;

    struct PhotonRealtimeEventBufferReceived
    {
        bool ok;
        std::int32_t player_number;
        std::int32_t event_code;
        std::uint32_t bytes_written;
    };

    struct PhotonRealtimeJoinRandomOptions
    {
        std::optional<double> max_players;
        std::optional<gm_enums::PhotonRealtimeMatchmakingMode> matchmaking_mode;
        std::optional<std::string> lobby_name;
        std::optional<gm_enums::PhotonRealtimeLobbyType> lobby_type;
        std::optional<std::string> sql_filter;
        std::vector<std::string> expected_users;
    };

    struct PhotonRealtimeRoomOptions
    {
        std::optional<double> max_players;
        std::optional<bool> is_visible;
        std::optional<bool> is_open;
        std::optional<std::string> lobby_name;
        std::optional<gm_enums::PhotonRealtimeLobbyType> lobby_type;
        std::optional<double> player_ttl;
        std::optional<double> empty_room_ttl;
        std::optional<bool> suppress_room_events;
        std::optional<bool> publish_user_id;
        std::vector<std::string> lobby_keys;
        std::vector<std::string> expected_users;
    };

    struct PhotonRealtimeJoinRoomOptions
    {
        std::optional<bool> rejoin;
        std::optional<double> cache_slice_index;
    };

    struct PhotonRealtimeRaiseEventOptions
    {
        std::optional<gm_enums::PhotonRealtimeReceiverGroup> receiver_group;
        std::optional<std::int32_t> interest_group;
        std::optional<gm_enums::PhotonRealtimeEventCache> event_cache;
        std::optional<std::int32_t> channel_id;
        std::optional<std::int32_t> cache_slice_index;
        std::optional<bool> encrypt;
        std::vector<std::int32_t> target_players;
    };

    struct PhotonRealtimeAuthenticationValues
    {
        std::optional<std::string> user_id;
        std::optional<gm_enums::PhotonRealtimeCustomAuthType> auth_type;
        std::optional<std::string> parameters;
    };

    struct PhotonRealtimeFriendInfo
    {
        std::string user_id;
        bool is_online;
        std::string room;
        bool is_in_room;
    };

    struct PhotonRealtimeRoomInfo
    {
        std::string name;
        std::int32_t player_count;
        std::int32_t max_players;
        bool is_open;
        gm::wire::StructStream custom_properties;
    };

    struct PhotonRealtimeLobbyStats
    {
        std::string name;
        gm_enums::PhotonRealtimeLobbyType type;
        std::int32_t peer_count;
        std::int32_t room_count;
    };

    struct PhotonChatMessage
    {
        std::string sender;
        std::string content;
    };

    struct PhotonChatSubscribeResult
    {
        std::string channel_name;
        bool success;
    };

    struct PhotonRealtimeConnectOptions
    {
        std::optional<gm_structs::PhotonRealtimeAuthenticationValues> authentication_values;
        std::optional<std::string> username;
        std::optional<std::string> server_address;
        std::optional<bool> try_use_datagram_encryption;
        std::optional<bool> use_background_thread;
    };

    struct PhotonChatConnectOptions
    {
        std::optional<gm_structs::PhotonRealtimeAuthenticationValues> authentication_values;
        std::optional<std::string> server_address;
        std::optional<bool> use_background_thread;
    };

}

namespace gm::wire::codec
{
    template<>
    inline void writeValue<gm_structs::PhotonRealtimeEventBufferReceived>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeEventBufferReceived& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.ok);
        gm::wire::codec::writeValue(_buf, obj.player_number);
        gm::wire::codec::writeValue(_buf, obj.event_code);
        gm::wire::codec::writeValue(_buf, obj.bytes_written);
    }

    template<>
    inline gm_structs::PhotonRealtimeEventBufferReceived readValue<gm_structs::PhotonRealtimeEventBufferReceived>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeEventBufferReceived obj;
        obj.ok = gm::wire::codec::readValue<bool>(_buf);
        obj.player_number = gm::wire::codec::readValue<std::int32_t>(_buf);
        obj.event_code = gm::wire::codec::readValue<std::int32_t>(_buf);
        obj.bytes_written = gm::wire::codec::readValue<std::uint32_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonRealtimeJoinRandomOptions>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeJoinRandomOptions& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.max_players);
        gm::wire::codec::writeValue(_buf, obj.matchmaking_mode);
        gm::wire::codec::writeValue(_buf, obj.lobby_name);
        gm::wire::codec::writeValue(_buf, obj.lobby_type);
        gm::wire::codec::writeValue(_buf, obj.sql_filter);
        gm::wire::codec::writeValue(_buf, obj.expected_users);
    }

    template<>
    inline gm_structs::PhotonRealtimeJoinRandomOptions readValue<gm_structs::PhotonRealtimeJoinRandomOptions>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeJoinRandomOptions obj;
        obj.max_players = gm::wire::codec::readOptional<double>(_buf);
        obj.matchmaking_mode = gm::wire::codec::readOptional<gm_enums::PhotonRealtimeMatchmakingMode>(_buf);
        obj.lobby_name = gm::wire::codec::readOptional<std::string>(_buf);
        obj.lobby_type = gm::wire::codec::readOptional<gm_enums::PhotonRealtimeLobbyType>(_buf);
        obj.sql_filter = gm::wire::codec::readOptional<std::string>(_buf);
        obj.expected_users = gm::wire::codec::readVector<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonRealtimeRoomOptions>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeRoomOptions& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.max_players);
        gm::wire::codec::writeValue(_buf, obj.is_visible);
        gm::wire::codec::writeValue(_buf, obj.is_open);
        gm::wire::codec::writeValue(_buf, obj.lobby_name);
        gm::wire::codec::writeValue(_buf, obj.lobby_type);
        gm::wire::codec::writeValue(_buf, obj.player_ttl);
        gm::wire::codec::writeValue(_buf, obj.empty_room_ttl);
        gm::wire::codec::writeValue(_buf, obj.suppress_room_events);
        gm::wire::codec::writeValue(_buf, obj.publish_user_id);
        gm::wire::codec::writeValue(_buf, obj.lobby_keys);
        gm::wire::codec::writeValue(_buf, obj.expected_users);
    }

    template<>
    inline gm_structs::PhotonRealtimeRoomOptions readValue<gm_structs::PhotonRealtimeRoomOptions>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeRoomOptions obj;
        obj.max_players = gm::wire::codec::readOptional<double>(_buf);
        obj.is_visible = gm::wire::codec::readOptional<bool>(_buf);
        obj.is_open = gm::wire::codec::readOptional<bool>(_buf);
        obj.lobby_name = gm::wire::codec::readOptional<std::string>(_buf);
        obj.lobby_type = gm::wire::codec::readOptional<gm_enums::PhotonRealtimeLobbyType>(_buf);
        obj.player_ttl = gm::wire::codec::readOptional<double>(_buf);
        obj.empty_room_ttl = gm::wire::codec::readOptional<double>(_buf);
        obj.suppress_room_events = gm::wire::codec::readOptional<bool>(_buf);
        obj.publish_user_id = gm::wire::codec::readOptional<bool>(_buf);
        obj.lobby_keys = gm::wire::codec::readVector<std::string>(_buf);
        obj.expected_users = gm::wire::codec::readVector<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonRealtimeJoinRoomOptions>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeJoinRoomOptions& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.rejoin);
        gm::wire::codec::writeValue(_buf, obj.cache_slice_index);
    }

    template<>
    inline gm_structs::PhotonRealtimeJoinRoomOptions readValue<gm_structs::PhotonRealtimeJoinRoomOptions>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeJoinRoomOptions obj;
        obj.rejoin = gm::wire::codec::readOptional<bool>(_buf);
        obj.cache_slice_index = gm::wire::codec::readOptional<double>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonRealtimeRaiseEventOptions>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeRaiseEventOptions& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.receiver_group);
        gm::wire::codec::writeValue(_buf, obj.interest_group);
        gm::wire::codec::writeValue(_buf, obj.event_cache);
        gm::wire::codec::writeValue(_buf, obj.channel_id);
        gm::wire::codec::writeValue(_buf, obj.cache_slice_index);
        gm::wire::codec::writeValue(_buf, obj.encrypt);
        gm::wire::codec::writeValue(_buf, obj.target_players);
    }

    template<>
    inline gm_structs::PhotonRealtimeRaiseEventOptions readValue<gm_structs::PhotonRealtimeRaiseEventOptions>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeRaiseEventOptions obj;
        obj.receiver_group = gm::wire::codec::readOptional<gm_enums::PhotonRealtimeReceiverGroup>(_buf);
        obj.interest_group = gm::wire::codec::readOptional<std::int32_t>(_buf);
        obj.event_cache = gm::wire::codec::readOptional<gm_enums::PhotonRealtimeEventCache>(_buf);
        obj.channel_id = gm::wire::codec::readOptional<std::int32_t>(_buf);
        obj.cache_slice_index = gm::wire::codec::readOptional<std::int32_t>(_buf);
        obj.encrypt = gm::wire::codec::readOptional<bool>(_buf);
        obj.target_players = gm::wire::codec::readVector<std::int32_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonRealtimeAuthenticationValues>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeAuthenticationValues& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.user_id);
        gm::wire::codec::writeValue(_buf, obj.auth_type);
        gm::wire::codec::writeValue(_buf, obj.parameters);
    }

    template<>
    inline gm_structs::PhotonRealtimeAuthenticationValues readValue<gm_structs::PhotonRealtimeAuthenticationValues>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeAuthenticationValues obj;
        obj.user_id = gm::wire::codec::readOptional<std::string>(_buf);
        obj.auth_type = gm::wire::codec::readOptional<gm_enums::PhotonRealtimeCustomAuthType>(_buf);
        obj.parameters = gm::wire::codec::readOptional<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonRealtimeFriendInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeFriendInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.user_id);
        gm::wire::codec::writeValue(_buf, obj.is_online);
        gm::wire::codec::writeValue(_buf, obj.room);
        gm::wire::codec::writeValue(_buf, obj.is_in_room);
    }

    template<>
    inline gm_structs::PhotonRealtimeFriendInfo readValue<gm_structs::PhotonRealtimeFriendInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeFriendInfo obj;
        obj.user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.is_online = gm::wire::codec::readValue<bool>(_buf);
        obj.room = gm::wire::codec::readValue<std::string>(_buf);
        obj.is_in_room = gm::wire::codec::readValue<bool>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonRealtimeRoomInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeRoomInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.name);
        gm::wire::codec::writeValue(_buf, obj.player_count);
        gm::wire::codec::writeValue(_buf, obj.max_players);
        gm::wire::codec::writeValue(_buf, obj.is_open);
        gm::wire::codec::writeValue(_buf, obj.custom_properties);
    }

    template<>
    inline gm_structs::PhotonRealtimeRoomInfo readValue<gm_structs::PhotonRealtimeRoomInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeRoomInfo obj;
        obj.name = gm::wire::codec::readValue<std::string>(_buf);
        obj.player_count = gm::wire::codec::readValue<std::int32_t>(_buf);
        obj.max_players = gm::wire::codec::readValue<std::int32_t>(_buf);
        obj.is_open = gm::wire::codec::readValue<bool>(_buf);
        obj.custom_properties = gm::wire::codec::readValue<gm::wire::StructStream>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonRealtimeLobbyStats>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeLobbyStats& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.name);
        gm::wire::codec::writeValue(_buf, obj.type);
        gm::wire::codec::writeValue(_buf, obj.peer_count);
        gm::wire::codec::writeValue(_buf, obj.room_count);
    }

    template<>
    inline gm_structs::PhotonRealtimeLobbyStats readValue<gm_structs::PhotonRealtimeLobbyStats>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeLobbyStats obj;
        obj.name = gm::wire::codec::readValue<std::string>(_buf);
        obj.type = gm::wire::codec::readValue<gm_enums::PhotonRealtimeLobbyType>(_buf);
        obj.peer_count = gm::wire::codec::readValue<std::int32_t>(_buf);
        obj.room_count = gm::wire::codec::readValue<std::int32_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonChatMessage>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonChatMessage& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.sender);
        gm::wire::codec::writeValue(_buf, obj.content);
    }

    template<>
    inline gm_structs::PhotonChatMessage readValue<gm_structs::PhotonChatMessage>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonChatMessage obj;
        obj.sender = gm::wire::codec::readValue<std::string>(_buf);
        obj.content = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonChatSubscribeResult>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonChatSubscribeResult& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.channel_name);
        gm::wire::codec::writeValue(_buf, obj.success);
    }

    template<>
    inline gm_structs::PhotonChatSubscribeResult readValue<gm_structs::PhotonChatSubscribeResult>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonChatSubscribeResult obj;
        obj.channel_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.success = gm::wire::codec::readValue<bool>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonRealtimeConnectOptions>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonRealtimeConnectOptions& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.authentication_values);
        gm::wire::codec::writeValue(_buf, obj.username);
        gm::wire::codec::writeValue(_buf, obj.server_address);
        gm::wire::codec::writeValue(_buf, obj.try_use_datagram_encryption);
        gm::wire::codec::writeValue(_buf, obj.use_background_thread);
    }

    template<>
    inline gm_structs::PhotonRealtimeConnectOptions readValue<gm_structs::PhotonRealtimeConnectOptions>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonRealtimeConnectOptions obj;
        obj.authentication_values = gm::wire::codec::readOptional<gm_structs::PhotonRealtimeAuthenticationValues>(_buf);
        obj.username = gm::wire::codec::readOptional<std::string>(_buf);
        obj.server_address = gm::wire::codec::readOptional<std::string>(_buf);
        obj.try_use_datagram_encryption = gm::wire::codec::readOptional<bool>(_buf);
        obj.use_background_thread = gm::wire::codec::readOptional<bool>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::PhotonChatConnectOptions>(gm::byteio::IByteWriter& _buf, const gm_structs::PhotonChatConnectOptions& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.authentication_values);
        gm::wire::codec::writeValue(_buf, obj.server_address);
        gm::wire::codec::writeValue(_buf, obj.use_background_thread);
    }

    template<>
    inline gm_structs::PhotonChatConnectOptions readValue<gm_structs::PhotonChatConnectOptions>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::PhotonChatConnectOptions obj;
        obj.authentication_values = gm::wire::codec::readOptional<gm_structs::PhotonRealtimeAuthenticationValues>(_buf);
        obj.server_address = gm::wire::codec::readOptional<std::string>(_buf);
        obj.use_background_thread = gm::wire::codec::readOptional<bool>(_buf);
        return obj;
    }

}

namespace gm::wire::details
{
    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeEventBufferReceived>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 0;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeJoinRandomOptions>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 1;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeRoomOptions>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 2;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeJoinRoomOptions>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 3;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeRaiseEventOptions>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 4;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeAuthenticationValues>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 5;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeFriendInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 6;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeRoomInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 7;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeLobbyStats>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 8;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonChatMessage>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 9;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonChatSubscribeResult>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 10;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonRealtimeConnectOptions>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 11;
    };

    template<>
    struct gm_struct_traits<gm_structs::PhotonChatConnectOptions>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 12;
    };

}

bool photon_realtime_init();
bool photon_realtime_shutdown();
bool photon_realtime_service();
bool photon_realtime_connect(std::string_view app_id, std::string_view app_version, const std::optional<gm_structs::PhotonRealtimeConnectOptions>& options);
bool photon_realtime_disconnect();
bool photon_realtime_select_region(std::string_view region);
bool photon_realtime_reconnect_and_rejoin();
bool photon_realtime_fetch_server_timestamp();
bool photon_realtime_operation_join_lobby(std::string_view lobby_name, gm_enums::PhotonRealtimeLobbyType lobby_type, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_leave_lobby(const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_create_room(std::string_view room_name, const gm_structs::PhotonRealtimeRoomOptions& options, const gm::wire::GMObjectView& custom_properties, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_join_or_create_room(std::string_view room_name, const gm_structs::PhotonRealtimeRoomOptions& options, const gm::wire::GMObjectView& custom_properties, std::optional<std::int32_t> cache_slice_index, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_join_room(std::string_view room_name, const gm_structs::PhotonRealtimeJoinRoomOptions& options, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_join_random_room(const gm_structs::PhotonRealtimeJoinRandomOptions& options, const gm::wire::GMObjectView& expected_properties, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_leave_room(bool will_come_back, bool send_authentication_cookie, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_join_random_or_create_room(std::string_view room_name, const gm_structs::PhotonRealtimeRoomOptions& options, const gm::wire::GMObjectView& custom_properties, const gm_structs::PhotonRealtimeJoinRandomOptions& random_options, const gm::wire::GMObjectView& expected_properties, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_get_room_list(std::string_view lobby_name, std::string_view sql_filter, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_lobby_stats(const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_find_friends(const std::vector<std::string_view>& friends, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_web_rpc(std::string_view uri_path, const std::optional<gm::wire::GMFunction>& callback);
bool photon_realtime_operation_change_groups(const std::optional<std::vector<std::int32_t>>& groups_to_remove, const std::optional<std::vector<std::int32_t>>& groups_to_add);
bool photon_realtime_operation_custom_auth_next_step(const gm_structs::PhotonRealtimeAuthenticationValues& authentication);
bool photon_realtime_operation_raise_event_string(bool reliable, std::string_view payload, std::int32_t event_code, const std::optional<gm_structs::PhotonRealtimeRaiseEventOptions>& options);
bool photon_realtime_operation_raise_event_buffer(bool reliable, gm::wire::GMBuffer data, std::uint32_t bytes, std::int32_t event_code, const std::optional<gm_structs::PhotonRealtimeRaiseEventOptions>& options);
std::int32_t photon_realtime_get_buffer_event_queue_count();
bool photon_realtime_clear_buffer_event_queue();
std::int32_t photon_realtime_peek_next_buffer_event_size();
std::int32_t photon_realtime_peek_next_buffer_event_code();
gm_structs::PhotonRealtimeEventBufferReceived photon_realtime_receive_one_event_buffer(gm::wire::GMBuffer out_data, std::uint32_t max_bytes, std::uint32_t offset);
bool photon_realtime_is_initialized();
bool photon_realtime_is_connected();
bool photon_realtime_is_in_game_room();
bool photon_realtime_is_in_room();
bool photon_realtime_is_in_lobby();
std::string photon_realtime_get_current_room_name();
std::int32_t photon_realtime_get_local_player_number();
std::int32_t photon_realtime_get_server_time_offset();
std::int32_t photon_realtime_get_server_time();
std::int32_t photon_realtime_get_bytes_in();
std::int32_t photon_realtime_get_bytes_out();
gm_enums::PhotonRealtimeState photon_realtime_get_state();
std::int32_t photon_realtime_get_round_trip_time();
std::int32_t photon_realtime_get_round_trip_time_variance();
gm_enums::PhotonRealtimeDisconnectCause photon_realtime_get_disconnected_cause();
std::string photon_realtime_get_user_id();
std::int32_t photon_realtime_get_count_players_ingame();
std::int32_t photon_realtime_get_count_games_running();
std::int32_t photon_realtime_get_count_players_online();
std::string photon_realtime_get_master_server_address();
std::string photon_realtime_get_region();
std::string photon_realtime_get_region_with_best_ping();
std::int32_t photon_realtime_get_friend_list_age();
std::int32_t photon_realtime_get_disconnect_timeout();
bool photon_realtime_set_disconnect_timeout(std::int32_t milliseconds);
std::int32_t photon_realtime_get_ping_interval();
bool photon_realtime_set_ping_interval(std::int32_t milliseconds);
bool photon_realtime_get_auto_join_lobby();
bool photon_realtime_set_auto_join_lobby(bool enabled);
std::int32_t photon_realtime_get_room_player_count();
std::int32_t photon_realtime_get_room_max_players();
bool photon_realtime_get_room_is_open();
bool photon_realtime_get_room_is_visible();
std::int32_t photon_realtime_get_master_client_number();
bool photon_realtime_set_master_client(std::int32_t player_number);
std::int32_t photon_realtime_get_room_list_count();
gm_structs::PhotonRealtimeRoomInfo photon_realtime_get_room_info_by_index(std::int32_t index);
std::int32_t photon_realtime_get_player_count();
std::int32_t photon_realtime_get_player_number_by_index(std::int32_t index);
std::string photon_realtime_player_get_name(std::int32_t player_number);
std::string photon_realtime_player_get_user_id(std::int32_t player_number);
bool photon_realtime_player_is_inactive(std::int32_t player_number);
bool photon_realtime_player_is_master_client(std::int32_t player_number);
std::vector<std::int32_t> photon_realtime_get_player_numbers();
bool photon_realtime_set_callback_debug(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_connected(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_disconnected(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_connection_error(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_client_error(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_server_error(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_warning(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_join_room_event(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_leave_room_event(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_custom_event(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_room_properties_change(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_player_properties_change(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_room_list_update(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_app_stats_update(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_lobby_stats_update(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_cache_slice_changed(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_master_client_changed(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_properties_change_failed(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_custom_authentication_step(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_available_regions(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_secret_receival(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_direct_connection_established(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_direct_connection_failed(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_direct_message(const gm::wire::GMFunction& callback);
bool photon_realtime_set_callback_custom_operation_response(const gm::wire::GMFunction& callback);
bool photon_realtime_remove_callback_debug();
bool photon_realtime_remove_callback_connected();
bool photon_realtime_remove_callback_disconnected();
bool photon_realtime_remove_callback_connection_error();
bool photon_realtime_remove_callback_client_error();
bool photon_realtime_remove_callback_server_error();
bool photon_realtime_remove_callback_warning();
bool photon_realtime_remove_callback_join_room_event();
bool photon_realtime_remove_callback_leave_room_event();
bool photon_realtime_remove_callback_custom_event();
bool photon_realtime_remove_callback_room_properties_change();
bool photon_realtime_remove_callback_player_properties_change();
bool photon_realtime_remove_callback_room_list_update();
bool photon_realtime_remove_callback_app_stats_update();
bool photon_realtime_remove_callback_lobby_stats_update();
bool photon_realtime_remove_callback_cache_slice_changed();
bool photon_realtime_remove_callback_master_client_changed();
bool photon_realtime_remove_callback_properties_change_failed();
bool photon_realtime_remove_callback_custom_authentication_step();
bool photon_realtime_remove_callback_available_regions();
bool photon_realtime_remove_callback_secret_receival();
bool photon_realtime_remove_callback_direct_connection_established();
bool photon_realtime_remove_callback_direct_connection_failed();
bool photon_realtime_remove_callback_direct_message();
bool photon_realtime_remove_callback_custom_operation_response();
bool photon_realtime_room_properties_set_string(std::string_view key, std::string_view value);
bool photon_realtime_room_properties_set_i32(std::string_view key, std::int32_t value);
bool photon_realtime_room_properties_set_f64(std::string_view key, double value);
bool photon_realtime_room_properties_set_bool(std::string_view key, bool value);
bool photon_realtime_room_properties_remove(std::string_view key);
bool photon_realtime_room_properties_clear();
bool photon_realtime_room_properties_has(std::string_view key);
std::string photon_realtime_room_properties_get_string(std::string_view key);
std::int32_t photon_realtime_room_properties_get_i32(std::string_view key);
double photon_realtime_room_properties_get_f64(std::string_view key);
bool photon_realtime_room_properties_get_bool(std::string_view key);
std::string photon_realtime_room_properties_to_string();
gm::wire::StructStream photon_realtime_room_properties_get_all();
bool photon_realtime_room_properties_cas_string(std::string_view key, std::string_view expected_value, std::string_view new_value);
bool photon_realtime_room_properties_cas_i32(std::string_view key, std::int32_t expected_value, std::int32_t new_value);
bool photon_realtime_room_properties_cas_f64(std::string_view key, double expected_value, double new_value);
bool photon_realtime_room_properties_cas_bool(std::string_view key, bool expected_value, bool new_value);
bool photon_realtime_player_properties_set_local_string(std::string_view key, std::string_view value);
bool photon_realtime_player_properties_set_local_i32(std::string_view key, std::int32_t value);
bool photon_realtime_player_properties_set_local_f64(std::string_view key, double value);
bool photon_realtime_player_properties_set_local_bool(std::string_view key, bool value);
bool photon_realtime_player_properties_remove_local(std::string_view key);
bool photon_realtime_player_properties_clear_local();
bool photon_realtime_player_properties_has_local(std::string_view key);
std::string photon_realtime_player_properties_get_local_string(std::string_view key);
std::int32_t photon_realtime_player_properties_get_local_i32(std::string_view key);
double photon_realtime_player_properties_get_local_f64(std::string_view key);
bool photon_realtime_player_properties_get_local_bool(std::string_view key);
std::string photon_realtime_player_properties_to_string_local();
gm::wire::StructStream photon_realtime_player_properties_get_local_all();
bool photon_realtime_player_properties_has_remote(std::int32_t player_number, std::string_view key);
std::string photon_realtime_player_properties_get_remote_string(std::int32_t player_number, std::string_view key);
std::int32_t photon_realtime_player_properties_get_remote_i32(std::int32_t player_number, std::string_view key);
double photon_realtime_player_properties_get_remote_f64(std::int32_t player_number, std::string_view key);
bool photon_realtime_player_properties_get_remote_bool(std::int32_t player_number, std::string_view key);
std::string photon_realtime_player_properties_to_string_remote(std::int32_t player_number);
gm::wire::StructStream photon_realtime_player_properties_get_remote_all(std::int32_t player_number);
std::int32_t photon_realtime_peek_next_buffer_event_player_number();
bool photon_chat_init();
bool photon_chat_shutdown();
bool photon_chat_service();
bool photon_chat_select_region(std::string_view region);
bool photon_chat_connect(std::string_view app_id, std::string_view app_version, const std::optional<gm_structs::PhotonChatConnectOptions>& options);
bool photon_chat_disconnect();
bool photon_chat_operation_subscribe(const std::vector<std::string_view>& channels, std::optional<std::int32_t> messages_from_history, const std::optional<gm::wire::GMFunction>& callback);
bool photon_chat_operation_unsubscribe(const std::vector<std::string_view>& channels, const std::optional<gm::wire::GMFunction>& callback);
bool photon_chat_operation_publish_message(std::string_view channel_name, std::string_view message);
bool photon_chat_operation_send_private_message(std::string_view user_name, std::string_view message, std::optional<bool> encrypt);
bool photon_chat_operation_set_online_status(gm_enums::PhotonChatUserStatus status, std::optional<std::string_view> message);
bool photon_chat_operation_add_friends(const std::vector<std::string_view>& user_ids);
bool photon_chat_operation_remove_friends(const std::vector<std::string_view>& user_ids);
bool photon_chat_is_initialized();
bool photon_chat_is_connected();
gm_enums::PhotonChatState photon_chat_get_state();
gm_enums::PhotonChatDisconnectCause photon_chat_get_disconnect_cause();
std::string photon_chat_get_user_id();
std::string photon_chat_get_region();
std::int32_t photon_chat_get_server_time();
std::int32_t photon_chat_get_server_time_offset();
std::int32_t photon_chat_get_bytes_in();
std::int32_t photon_chat_get_bytes_out();
std::int32_t photon_chat_get_channel_count(gm_enums::PhotonChatChannelType channel_type);
std::string photon_chat_get_channel_name(gm_enums::PhotonChatChannelType channel_type, std::int32_t index);
std::int32_t photon_chat_get_channel_message_count(gm_enums::PhotonChatChannelType channel_type, std::string_view channel_name);
std::string photon_chat_get_channel_message(gm_enums::PhotonChatChannelType channel_type, std::string_view channel_name, std::int32_t index);
std::string photon_chat_get_channel_sender(gm_enums::PhotonChatChannelType channel_type, std::string_view channel_name, std::int32_t index);
bool photon_chat_set_callback_debug(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_connected(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_state_change(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_connection_error(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_client_error(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_warning(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_server_error(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_disconnected(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_status_update(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_get_messages(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_private_message(const gm::wire::GMFunction& callback);
bool photon_chat_set_callback_receive_broadcast(const gm::wire::GMFunction& callback);
std::int32_t photon_chat_get_broadcast_queue_count();
bool photon_chat_clear_broadcast_queue();
std::int32_t photon_chat_peek_next_broadcast_size();
std::string photon_chat_peek_next_broadcast_channel();
gm_structs::PhotonRealtimeEventBufferReceived photon_chat_receive_one_broadcast_buffer(gm::wire::GMBuffer out_data, std::uint32_t max_bytes, std::uint32_t offset);
bool photon_chat_remove_callback_debug();
bool photon_chat_remove_callback_connected();
bool photon_chat_remove_callback_state_change();
bool photon_chat_remove_callback_connection_error();
bool photon_chat_remove_callback_client_error();
bool photon_chat_remove_callback_warning();
bool photon_chat_remove_callback_server_error();
bool photon_chat_remove_callback_disconnected();
bool photon_chat_remove_callback_status_update();
bool photon_chat_remove_callback_get_messages();
bool photon_chat_remove_callback_private_message();
bool photon_chat_remove_callback_receive_broadcast();
bool photon_voice_init();
bool photon_voice_shutdown();
bool photon_voice_service();
bool photon_voice_is_initialized();
bool photon_voice_notify_joined_room();
bool photon_voice_on_join_channel(std::int32_t channel_id);
bool photon_voice_on_leave_channel(std::int32_t channel_id);
bool photon_voice_on_join_all_channels();
bool photon_voice_on_leave_all_channels();
bool photon_voice_on_player_join(std::int32_t channel_id, std::int32_t player_id);
bool photon_voice_on_player_leave(std::int32_t channel_id, std::int32_t player_id);
std::int32_t photon_voice_create_local_voice(std::int32_t channel_id, gm_enums::PhotonVoiceCodec codec, std::int32_t sample_rate, std::int32_t channels, std::int32_t bitrate, std::int32_t frames_per_packet);
bool photon_voice_remove_local_voice(std::int32_t voice_id);
bool photon_voice_push_frame_buffer(std::int32_t voice_id, gm::wire::GMBuffer data, std::uint32_t bytes);
std::int32_t photon_voice_get_frame_queue_count();
bool photon_voice_clear_frame_queue();
std::int32_t photon_voice_peek_next_frame_size();
std::int32_t photon_voice_peek_next_frame_player_id();
std::int32_t photon_voice_peek_next_frame_voice_id();
gm_structs::PhotonRealtimeEventBufferReceived photon_voice_receive_frame_buffer(gm::wire::GMBuffer out_data, std::uint32_t max_bytes, std::uint32_t offset);
std::int32_t photon_voice_get_remote_voice_count();
std::int32_t photon_voice_get_remote_voice_player_id(std::int32_t index);
std::int32_t photon_voice_get_remote_voice_id(std::int32_t index);
gm_enums::PhotonVoiceCodec photon_voice_get_remote_voice_codec(std::int32_t index);
std::int32_t photon_voice_get_remote_voice_sample_rate(std::int32_t index);
std::int32_t photon_voice_get_remote_voice_channels(std::int32_t index);
bool photon_voice_get_remote_voice_is_speaking(std::int32_t index);
std::int32_t photon_voice_get_frames_sent();
std::int32_t photon_voice_get_frames_received();
std::int32_t photon_voice_get_frames_lost();
std::int32_t photon_voice_get_round_trip_time();
std::int32_t photon_voice_get_round_trip_time_variance();
bool photon_voice_set_callback_remote_voice_added(const gm::wire::GMFunction& callback);
bool photon_voice_set_callback_remote_voice_removed(const gm::wire::GMFunction& callback);
bool photon_voice_set_callback_speaking_changed(const gm::wire::GMFunction& callback);
bool photon_voice_set_callback_debug(const gm::wire::GMFunction& callback);
bool photon_voice_remove_callback_remote_voice_added();
bool photon_voice_remove_callback_remote_voice_removed();
bool photon_voice_remove_callback_speaking_changed();
bool photon_voice_remove_callback_debug();
bool photon_voice_local_voice_set_transmit(std::int32_t voice_id, bool enabled);
bool photon_voice_local_voice_get_transmit(std::int32_t voice_id);
bool photon_voice_set_remote_player_muted(std::int32_t player_id, bool muted);
bool photon_voice_get_remote_player_muted(std::int32_t player_id);
bool photon_voice_set_remote_player_volume(std::int32_t player_id, double volume);
double photon_voice_get_remote_player_volume(std::int32_t player_id);
std::int32_t photon_voice_get_debug_lost_percent();
bool photon_voice_set_debug_lost_percent(std::int32_t percent);
std::int32_t photon_voice_get_speaking_threshold_ms();
bool photon_voice_set_speaking_threshold_ms(std::int32_t ms);
std::int32_t photon_realtime_peer_get_state();
std::int32_t photon_realtime_peer_get_round_trip_time();
std::int32_t photon_realtime_peer_get_round_trip_time_variance();
std::int32_t photon_realtime_peer_get_bytes_in();
std::int32_t photon_realtime_peer_get_bytes_out();
std::int32_t photon_realtime_peer_get_queued_incoming_commands();
std::int32_t photon_realtime_peer_get_queued_outgoing_commands();
gm_enums::PhotonCommonDebugLevel photon_realtime_peer_get_debug_output_level();
bool photon_realtime_peer_set_debug_output_level(gm_enums::PhotonCommonDebugLevel level);
std::int32_t photon_realtime_peer_get_disconnect_timeout();
bool photon_realtime_peer_set_disconnect_timeout(std::int32_t timeout_ms);
std::int32_t photon_realtime_peer_get_time_ping_interval();
bool photon_realtime_peer_set_time_ping_interval(std::int32_t interval_ms);
bool photon_realtime_peer_get_crc_enabled();
bool photon_realtime_peer_set_crc_enabled(bool enabled);
std::int32_t photon_realtime_peer_get_packet_loss_by_crc();
std::int32_t photon_realtime_peer_get_timestamp_of_last_socket_receive();
bool photon_realtime_peer_reset_traffic_stats();
std::int32_t photon_chat_peer_get_state();
std::int32_t photon_chat_peer_get_round_trip_time();
std::int32_t photon_chat_peer_get_round_trip_time_variance();
std::int32_t photon_chat_peer_get_bytes_in();
std::int32_t photon_chat_peer_get_bytes_out();
std::int32_t photon_chat_peer_get_queued_incoming_commands();
std::int32_t photon_chat_peer_get_queued_outgoing_commands();
gm_enums::PhotonCommonDebugLevel photon_chat_peer_get_debug_output_level();
bool photon_chat_peer_set_debug_output_level(gm_enums::PhotonCommonDebugLevel level);
std::int32_t photon_chat_peer_get_disconnect_timeout();
bool photon_chat_peer_set_disconnect_timeout(std::int32_t timeout_ms);
std::int32_t photon_chat_peer_get_time_ping_interval();
bool photon_chat_peer_set_time_ping_interval(std::int32_t interval_ms);
bool photon_chat_peer_get_crc_enabled();
bool photon_chat_peer_set_crc_enabled(bool enabled);
std::int32_t photon_chat_peer_get_packet_loss_by_crc();
std::int32_t photon_chat_peer_get_timestamp_of_last_socket_receive();
bool photon_chat_peer_reset_traffic_stats();
bool photon_peer_network_sim_get_enabled();
bool photon_peer_network_sim_set_enabled(bool enabled);
bool photon_peer_network_sim_set_lag(std::int32_t incoming_ms, std::int32_t outgoing_ms);
bool photon_peer_network_sim_set_jitter(std::int32_t incoming_ms, std::int32_t outgoing_ms);
bool photon_peer_network_sim_set_packet_loss(std::int32_t incoming_pct, std::int32_t outgoing_pct);
bool photon_common_set_debug_level(gm_enums::PhotonCommonDebugLevel level);
gm_enums::PhotonCommonDebugLevel photon_common_get_debug_level();
gm_enums::PhotonCommonSerializationProtocol photon_common_get_serialization_protocol();
std::string photon_common_type_code_to_string(gm_enums::PhotonCommonTypeCode type_code);
std::string photon_common_get_sdk_version();
std::string photon_common_client_state_to_string(std::int32_t state);
std::string photon_common_disconnect_cause_to_string(std::int32_t cause);
