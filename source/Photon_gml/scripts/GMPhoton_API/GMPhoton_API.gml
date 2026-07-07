// ##### extgen :: Auto-generated file do not edit!! #####

// #####################################################################
// # Macros
// #####################################################################

// #####################################################################
// # Enums
// #####################################################################

enum PhotonRealtimeState
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
}

enum PhotonRealtimeLobbyType
{
    Default = 0,
    SqlLobby = 2,
    AsyncRandomLobby = 3
}

enum PhotonRealtimeMatchmakingMode
{
    FillRoom = 0,
    SerialMatching = 1,
    RandomMatching = 2
}

enum PhotonRealtimeDirectMode
{
    None = 0,
    AllToOthers = 1,
    MasterToOthers = 2,
    AllToAll = 3,
    MasterToAll = 4
}

enum PhotonRealtimeDisconnectCause
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
}

enum PhotonRealtimeRegionSelectionMode
{
    Default = 0,
    Select = 1,
    Best = 2
}

enum PhotonRealtimeServerType
{
    NameServer = 0,
    MasterServer = 1
}

enum PhotonRealtimeCustomAuthType
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
}

enum PhotonRealtimeReceiverGroup
{
    Others = 0,
    All = 1,
    MasterClient = 2
}

enum PhotonRealtimeEventCache
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
}

enum PhotonRealtimeLBOperationCode
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
}

enum PhotonRealtimeLBEventCode
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
}

enum PhotonRealtimeAppErrorCode
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
}

enum PhotonCommonDebugLevel
{
    Off = 0,
    Errors = 1,
    Warnings = 2,
    Info = 3,
    All = 4
}

enum PhotonCommonSerializationProtocol
{
    Protocol16 = 0,
    Protocol18 = 1
}

enum PhotonCommonTypeCode
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
}

enum PhotonCommonInternalLogLevel
{
    Off = 0,
    Fatal = 1,
    Error = 2,
    Warning = 3,
    Info = 4,
    Debug = 5,
    DebugVerbose = 6
}

enum PhotonPeerConnectionProtocol
{
    Udp = 0,
    Tcp = 1,
    Ws = 4,
    Wss = 5
}

enum PhotonPeerState
{
    Disconnected = 0,
    Connecting = 1,
    InitializingApplication = 2,
    Connected = 3,
    Disconnecting = 4
}

enum PhotonPeerStatusCode
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
}

enum PhotonPeerCoreErrorCode
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
}

enum PhotonPeerLiteOperationCode
{
    Join = 255,
    Leave = 254,
    RaiseEvent = 253,
    SetProperties = 252,
    GetProperties = 251,
    ChangeGroups = 248
}

enum PhotonPeerLiteEventCode
{
    Join = 255,
    Leave = 254,
    PropertiesChanged = 253
}

enum PhotonPeerLiteParameterCode
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
}

enum PhotonChatAppErrorCode
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
}

enum PhotonChatState
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
}

enum PhotonChatDisconnectCause
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
}

enum PhotonChatOperationCode
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
}

enum PhotonChatEventCode
{
    ChatMessages = 0,
    Users = 1,
    PrivateMessage = 2,
    FriendList = 3,
    StatusUpdate = 4,
    Subscribe = 5,
    Unsubscribe = 6
}

enum PhotonChatParameterCode
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
}

enum PhotonChatUserStatus
{
    Offline = 0,
    Invisible = 1,
    Online = 2,
    Away = 3,
    Dnd = 4,
    Lfg = 5,
    Playing = 6
}

enum PhotonVoiceCodec
{
    None = 0,
    AudioOpus = 11,
    VideoVp8 = 21,
    VideoVp9 = 22,
    VideoAv1 = 23,
    VideoH264 = 31,
    VideoH265 = 32
}

enum PhotonChatChannelType
{
    Public = 0,
    Private = 1
}

// #####################################################################
// # Constructors
// #####################################################################

/**
 * @returns {Struct.PhotonRealtimeEventBufferReceived}
 */
function PhotonRealtimeEventBufferReceived() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 367091323;

    self.ok = undefined;
    self.player_number = undefined;
    self.event_code = undefined;
    self.bytes_written = undefined;

}

/**
 * @returns {Struct.PhotonRealtimeJoinRandomOptions}
 */
function PhotonRealtimeJoinRandomOptions() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 3312312409;

    self.max_players = undefined;
    self.matchmaking_mode = undefined;
    self.lobby_name = undefined;
    self.lobby_type = undefined;
    self.sql_filter = undefined;
    self.expected_users = undefined;

}

/**
 * @returns {Struct.PhotonRealtimeRoomOptions}
 */
function PhotonRealtimeRoomOptions() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 3302987841;

    self.max_players = undefined;
    self.is_visible = undefined;
    self.is_open = undefined;
    self.lobby_name = undefined;
    self.lobby_type = undefined;
    self.player_ttl = undefined;
    self.empty_room_ttl = undefined;
    self.suppress_room_events = undefined;
    self.publish_user_id = undefined;
    self.lobby_keys = undefined;
    self.expected_users = undefined;

}

/**
 * @returns {Struct.PhotonRealtimeJoinRoomOptions}
 */
function PhotonRealtimeJoinRoomOptions() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 1668000541;

    self.rejoin = undefined;
    self.cache_slice_index = undefined;

}

/**
 * @returns {Struct.PhotonRealtimeRaiseEventOptions}
 */
function PhotonRealtimeRaiseEventOptions() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 1479735124;

    self.receiver_group = undefined;
    self.interest_group = undefined;
    self.event_cache = undefined;
    self.channel_id = undefined;
    self.cache_slice_index = undefined;
    self.encrypt = undefined;
    self.target_players = undefined;

}

/**
 * @returns {Struct.PhotonRealtimeAuthenticationValues}
 */
function PhotonRealtimeAuthenticationValues() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 1448014036;

    self.user_id = undefined;
    self.auth_type = undefined;
    self.parameters = undefined;

}

/**
 * @returns {Struct.PhotonRealtimeFriendInfo}
 */
function PhotonRealtimeFriendInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 898936086;

    self.user_id = undefined;
    self.is_online = undefined;
    self.room = undefined;
    self.is_in_room = undefined;

}

/**
 * @returns {Struct.PhotonRealtimeRoomInfo}
 */
function PhotonRealtimeRoomInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 611289889;

    self.name = undefined;
    self.player_count = undefined;
    self.max_players = undefined;
    self.is_open = undefined;
    self.custom_properties = undefined;

}

/**
 * @returns {Struct.PhotonRealtimeLobbyStats}
 */
function PhotonRealtimeLobbyStats() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 2651598281;

    self.name = undefined;
    self.type = undefined;
    self.peer_count = undefined;
    self.room_count = undefined;

}

/**
 * @returns {Struct.PhotonChatMessage}
 */
function PhotonChatMessage() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 495471680;

    self.sender = undefined;
    self.content = undefined;

}

/**
 * @returns {Struct.PhotonChatSubscribeResult}
 */
function PhotonChatSubscribeResult() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 619070166;

    self.channel_name = undefined;
    self.success = undefined;

}

/**
 * @returns {Struct.PhotonRealtimeConnectOptions}
 */
function PhotonRealtimeConnectOptions() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 3657087078;

    self.authentication_values = undefined;
    self.username = undefined;
    self.server_address = undefined;
    self.try_use_datagram_encryption = undefined;
    self.use_background_thread = undefined;

}

/**
 * @returns {Struct.PhotonChatConnectOptions}
 */
function PhotonChatConnectOptions() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore
     */
    static __uid = 333942797;

    self.authentication_values = undefined;
    self.server_address = undefined;
    self.use_background_thread = undefined;

}

// #####################################################################
// # Codecs
// #####################################################################

/**
 * @func __PhotonRealtimeEventBufferReceived_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeEventBufferReceived} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeEventBufferReceived_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: ok, type: Bool
        if (!is_bool(self.ok)) show_error($"{_where} :: self.ok expected bool", true);
        buffer_write(_buffer, buffer_bool, self.ok);

        // field: player_number, type: Int32
        if (!is_numeric(self.player_number)) show_error($"{_where} :: self.player_number expected number", true);
        buffer_write(_buffer, buffer_s32, self.player_number);

        // field: event_code, type: Int32
        if (!is_numeric(self.event_code)) show_error($"{_where} :: self.event_code expected number", true);
        buffer_write(_buffer, buffer_s32, self.event_code);

        // field: bytes_written, type: UInt32
        if (!is_numeric(self.bytes_written)) show_error($"{_where} :: self.bytes_written expected number", true);
        buffer_write(_buffer, buffer_u32, self.bytes_written);

    }
}

/**
 * @func __PhotonRealtimeEventBufferReceived_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeEventBufferReceived}
 * @ignore
 */
function __PhotonRealtimeEventBufferReceived_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeEventBufferReceived();
    with (_inst)
    {
        // field: ok, type: Bool
        self.ok = buffer_read(_buffer, buffer_bool);

        // field: player_number, type: Int32
        self.player_number = buffer_read(_buffer, buffer_s32);

        // field: event_code, type: Int32
        self.event_code = buffer_read(_buffer, buffer_s32);

        // field: bytes_written, type: UInt32
        self.bytes_written = buffer_read(_buffer, buffer_u32);

    }

    return _inst;
}

/**
 * @func __PhotonRealtimeJoinRandomOptions_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeJoinRandomOptions} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeJoinRandomOptions_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: max_players, type: optional<Float64>
        if (is_undefined(self.max_players))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_numeric(self.max_players)) show_error($"{_where} :: self.max_players expected number", true);
            buffer_write(_buffer, buffer_f64, self.max_players);
        }

        // field: matchmaking_mode, type: optional<enum PhotonRealtimeMatchmakingMode>
        if (is_undefined(self.matchmaking_mode))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);

            if (!is_numeric(self.matchmaking_mode)) show_error($"{_where} :: self.matchmaking_mode expected number", true);
            buffer_write(_buffer, buffer_s32, self.matchmaking_mode);
        }

        // field: lobby_name, type: optional<String>
        if (is_undefined(self.lobby_name))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_string(self.lobby_name)) show_error($"{_where} :: self.lobby_name expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.lobby_name));
            buffer_write(_buffer, buffer_string, self.lobby_name);
        }

        // field: lobby_type, type: optional<enum PhotonRealtimeLobbyType>
        if (is_undefined(self.lobby_type))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);

            if (!is_numeric(self.lobby_type)) show_error($"{_where} :: self.lobby_type expected number", true);
            buffer_write(_buffer, buffer_s32, self.lobby_type);
        }

        // field: sql_filter, type: optional<String>
        if (is_undefined(self.sql_filter))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_string(self.sql_filter)) show_error($"{_where} :: self.sql_filter expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.sql_filter));
            buffer_write(_buffer, buffer_string, self.sql_filter);
        }

        // field: expected_users, type: String[]
        if (!is_array(self.expected_users)) show_error($"{_where} :: self.expected_users expected array", true);
        var _length = array_length(self.expected_users);
        buffer_write(_buffer, buffer_u32, _length);
        for (var _i = 0; _i < _length; ++_i)
        {
            if (!is_string(self.expected_users[_i])) show_error($"{_where} :: self.expected_users[_i] expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.expected_users[_i]));
            buffer_write(_buffer, buffer_string, self.expected_users[_i]);
        }

    }
}

/**
 * @func __PhotonRealtimeJoinRandomOptions_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeJoinRandomOptions}
 * @ignore
 */
function __PhotonRealtimeJoinRandomOptions_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeJoinRandomOptions();
    with (_inst)
    {
        // field: max_players, type: optional<Float64>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.max_players = buffer_read(_buffer, buffer_f64);
        }
        else
        {
            self.max_players = undefined;
        }

        // field: matchmaking_mode, type: optional<enum PhotonRealtimeMatchmakingMode>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.matchmaking_mode = buffer_read(_buffer, buffer_s32);
        }
        else
        {
            self.matchmaking_mode = undefined;
        }

        // field: lobby_name, type: optional<String>
        if (buffer_read(_buffer, buffer_bool))
        {
            buffer_read(_buffer, buffer_u32);
            self.lobby_name = buffer_read(_buffer, buffer_string);
        }
        else
        {
            self.lobby_name = undefined;
        }

        // field: lobby_type, type: optional<enum PhotonRealtimeLobbyType>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.lobby_type = buffer_read(_buffer, buffer_s32);
        }
        else
        {
            self.lobby_type = undefined;
        }

        // field: sql_filter, type: optional<String>
        if (buffer_read(_buffer, buffer_bool))
        {
            buffer_read(_buffer, buffer_u32);
            self.sql_filter = buffer_read(_buffer, buffer_string);
        }
        else
        {
            self.sql_filter = undefined;
        }

        // field: expected_users, type: String[]
        var _length = buffer_read(_buffer, buffer_u32);
        self.expected_users = array_create(_length);
        for (var _i = 0; _i < _length; ++_i)
        {
            buffer_read(_buffer, buffer_u32);
            self.expected_users[_i] = buffer_read(_buffer, buffer_string);
        }

    }

    return _inst;
}

/**
 * @func __PhotonRealtimeRoomOptions_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeRoomOptions} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeRoomOptions_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: max_players, type: optional<Float64>
        if (is_undefined(self.max_players))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_numeric(self.max_players)) show_error($"{_where} :: self.max_players expected number", true);
            buffer_write(_buffer, buffer_f64, self.max_players);
        }

        // field: is_visible, type: optional<Bool>
        if (is_undefined(self.is_visible))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_bool(self.is_visible)) show_error($"{_where} :: self.is_visible expected bool", true);
            buffer_write(_buffer, buffer_bool, self.is_visible);
        }

        // field: is_open, type: optional<Bool>
        if (is_undefined(self.is_open))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_bool(self.is_open)) show_error($"{_where} :: self.is_open expected bool", true);
            buffer_write(_buffer, buffer_bool, self.is_open);
        }

        // field: lobby_name, type: optional<String>
        if (is_undefined(self.lobby_name))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_string(self.lobby_name)) show_error($"{_where} :: self.lobby_name expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.lobby_name));
            buffer_write(_buffer, buffer_string, self.lobby_name);
        }

        // field: lobby_type, type: optional<enum PhotonRealtimeLobbyType>
        if (is_undefined(self.lobby_type))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);

            if (!is_numeric(self.lobby_type)) show_error($"{_where} :: self.lobby_type expected number", true);
            buffer_write(_buffer, buffer_s32, self.lobby_type);
        }

        // field: player_ttl, type: optional<Float64>
        if (is_undefined(self.player_ttl))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_numeric(self.player_ttl)) show_error($"{_where} :: self.player_ttl expected number", true);
            buffer_write(_buffer, buffer_f64, self.player_ttl);
        }

        // field: empty_room_ttl, type: optional<Float64>
        if (is_undefined(self.empty_room_ttl))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_numeric(self.empty_room_ttl)) show_error($"{_where} :: self.empty_room_ttl expected number", true);
            buffer_write(_buffer, buffer_f64, self.empty_room_ttl);
        }

        // field: suppress_room_events, type: optional<Bool>
        if (is_undefined(self.suppress_room_events))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_bool(self.suppress_room_events)) show_error($"{_where} :: self.suppress_room_events expected bool", true);
            buffer_write(_buffer, buffer_bool, self.suppress_room_events);
        }

        // field: publish_user_id, type: optional<Bool>
        if (is_undefined(self.publish_user_id))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_bool(self.publish_user_id)) show_error($"{_where} :: self.publish_user_id expected bool", true);
            buffer_write(_buffer, buffer_bool, self.publish_user_id);
        }

        // field: lobby_keys, type: String[]
        if (!is_array(self.lobby_keys)) show_error($"{_where} :: self.lobby_keys expected array", true);
        var _length = array_length(self.lobby_keys);
        buffer_write(_buffer, buffer_u32, _length);
        for (var _i = 0; _i < _length; ++_i)
        {
            if (!is_string(self.lobby_keys[_i])) show_error($"{_where} :: self.lobby_keys[_i] expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.lobby_keys[_i]));
            buffer_write(_buffer, buffer_string, self.lobby_keys[_i]);
        }

        // field: expected_users, type: String[]
        if (!is_array(self.expected_users)) show_error($"{_where} :: self.expected_users expected array", true);
        var _length = array_length(self.expected_users);
        buffer_write(_buffer, buffer_u32, _length);
        for (var _i = 0; _i < _length; ++_i)
        {
            if (!is_string(self.expected_users[_i])) show_error($"{_where} :: self.expected_users[_i] expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.expected_users[_i]));
            buffer_write(_buffer, buffer_string, self.expected_users[_i]);
        }

    }
}

/**
 * @func __PhotonRealtimeRoomOptions_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeRoomOptions}
 * @ignore
 */
function __PhotonRealtimeRoomOptions_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeRoomOptions();
    with (_inst)
    {
        // field: max_players, type: optional<Float64>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.max_players = buffer_read(_buffer, buffer_f64);
        }
        else
        {
            self.max_players = undefined;
        }

        // field: is_visible, type: optional<Bool>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.is_visible = buffer_read(_buffer, buffer_bool);
        }
        else
        {
            self.is_visible = undefined;
        }

        // field: is_open, type: optional<Bool>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.is_open = buffer_read(_buffer, buffer_bool);
        }
        else
        {
            self.is_open = undefined;
        }

        // field: lobby_name, type: optional<String>
        if (buffer_read(_buffer, buffer_bool))
        {
            buffer_read(_buffer, buffer_u32);
            self.lobby_name = buffer_read(_buffer, buffer_string);
        }
        else
        {
            self.lobby_name = undefined;
        }

        // field: lobby_type, type: optional<enum PhotonRealtimeLobbyType>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.lobby_type = buffer_read(_buffer, buffer_s32);
        }
        else
        {
            self.lobby_type = undefined;
        }

        // field: player_ttl, type: optional<Float64>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.player_ttl = buffer_read(_buffer, buffer_f64);
        }
        else
        {
            self.player_ttl = undefined;
        }

        // field: empty_room_ttl, type: optional<Float64>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.empty_room_ttl = buffer_read(_buffer, buffer_f64);
        }
        else
        {
            self.empty_room_ttl = undefined;
        }

        // field: suppress_room_events, type: optional<Bool>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.suppress_room_events = buffer_read(_buffer, buffer_bool);
        }
        else
        {
            self.suppress_room_events = undefined;
        }

        // field: publish_user_id, type: optional<Bool>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.publish_user_id = buffer_read(_buffer, buffer_bool);
        }
        else
        {
            self.publish_user_id = undefined;
        }

        // field: lobby_keys, type: String[]
        var _length = buffer_read(_buffer, buffer_u32);
        self.lobby_keys = array_create(_length);
        for (var _i = 0; _i < _length; ++_i)
        {
            buffer_read(_buffer, buffer_u32);
            self.lobby_keys[_i] = buffer_read(_buffer, buffer_string);
        }

        // field: expected_users, type: String[]
        var _length = buffer_read(_buffer, buffer_u32);
        self.expected_users = array_create(_length);
        for (var _i = 0; _i < _length; ++_i)
        {
            buffer_read(_buffer, buffer_u32);
            self.expected_users[_i] = buffer_read(_buffer, buffer_string);
        }

    }

    return _inst;
}

/**
 * @func __PhotonRealtimeJoinRoomOptions_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeJoinRoomOptions} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeJoinRoomOptions_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: rejoin, type: optional<Bool>
        if (is_undefined(self.rejoin))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_bool(self.rejoin)) show_error($"{_where} :: self.rejoin expected bool", true);
            buffer_write(_buffer, buffer_bool, self.rejoin);
        }

        // field: cache_slice_index, type: optional<Float64>
        if (is_undefined(self.cache_slice_index))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_numeric(self.cache_slice_index)) show_error($"{_where} :: self.cache_slice_index expected number", true);
            buffer_write(_buffer, buffer_f64, self.cache_slice_index);
        }

    }
}

/**
 * @func __PhotonRealtimeJoinRoomOptions_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeJoinRoomOptions}
 * @ignore
 */
function __PhotonRealtimeJoinRoomOptions_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeJoinRoomOptions();
    with (_inst)
    {
        // field: rejoin, type: optional<Bool>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.rejoin = buffer_read(_buffer, buffer_bool);
        }
        else
        {
            self.rejoin = undefined;
        }

        // field: cache_slice_index, type: optional<Float64>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.cache_slice_index = buffer_read(_buffer, buffer_f64);
        }
        else
        {
            self.cache_slice_index = undefined;
        }

    }

    return _inst;
}

/**
 * @func __PhotonRealtimeRaiseEventOptions_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeRaiseEventOptions} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeRaiseEventOptions_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: receiver_group, type: optional<enum PhotonRealtimeReceiverGroup>
        if (is_undefined(self.receiver_group))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);

            if (!is_numeric(self.receiver_group)) show_error($"{_where} :: self.receiver_group expected number", true);
            buffer_write(_buffer, buffer_s32, self.receiver_group);
        }

        // field: interest_group, type: optional<Int32>
        if (is_undefined(self.interest_group))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_numeric(self.interest_group)) show_error($"{_where} :: self.interest_group expected number", true);
            buffer_write(_buffer, buffer_s32, self.interest_group);
        }

        // field: event_cache, type: optional<enum PhotonRealtimeEventCache>
        if (is_undefined(self.event_cache))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);

            if (!is_numeric(self.event_cache)) show_error($"{_where} :: self.event_cache expected number", true);
            buffer_write(_buffer, buffer_s32, self.event_cache);
        }

        // field: channel_id, type: optional<Int32>
        if (is_undefined(self.channel_id))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_numeric(self.channel_id)) show_error($"{_where} :: self.channel_id expected number", true);
            buffer_write(_buffer, buffer_s32, self.channel_id);
        }

        // field: cache_slice_index, type: optional<Int32>
        if (is_undefined(self.cache_slice_index))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_numeric(self.cache_slice_index)) show_error($"{_where} :: self.cache_slice_index expected number", true);
            buffer_write(_buffer, buffer_s32, self.cache_slice_index);
        }

        // field: encrypt, type: optional<Bool>
        if (is_undefined(self.encrypt))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_bool(self.encrypt)) show_error($"{_where} :: self.encrypt expected bool", true);
            buffer_write(_buffer, buffer_bool, self.encrypt);
        }

        // field: target_players, type: Int32[]
        if (!is_array(self.target_players)) show_error($"{_where} :: self.target_players expected array", true);
        var _length = array_length(self.target_players);
        buffer_write(_buffer, buffer_u32, _length);
        for (var _i = 0; _i < _length; ++_i)
        {
            if (!is_numeric(self.target_players[_i])) show_error($"{_where} :: self.target_players[_i] expected number", true);
            buffer_write(_buffer, buffer_s32, self.target_players[_i]);
        }

    }
}

/**
 * @func __PhotonRealtimeRaiseEventOptions_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeRaiseEventOptions}
 * @ignore
 */
function __PhotonRealtimeRaiseEventOptions_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeRaiseEventOptions();
    with (_inst)
    {
        // field: receiver_group, type: optional<enum PhotonRealtimeReceiverGroup>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.receiver_group = buffer_read(_buffer, buffer_s32);
        }
        else
        {
            self.receiver_group = undefined;
        }

        // field: interest_group, type: optional<Int32>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.interest_group = buffer_read(_buffer, buffer_s32);
        }
        else
        {
            self.interest_group = undefined;
        }

        // field: event_cache, type: optional<enum PhotonRealtimeEventCache>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.event_cache = buffer_read(_buffer, buffer_s32);
        }
        else
        {
            self.event_cache = undefined;
        }

        // field: channel_id, type: optional<Int32>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.channel_id = buffer_read(_buffer, buffer_s32);
        }
        else
        {
            self.channel_id = undefined;
        }

        // field: cache_slice_index, type: optional<Int32>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.cache_slice_index = buffer_read(_buffer, buffer_s32);
        }
        else
        {
            self.cache_slice_index = undefined;
        }

        // field: encrypt, type: optional<Bool>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.encrypt = buffer_read(_buffer, buffer_bool);
        }
        else
        {
            self.encrypt = undefined;
        }

        // field: target_players, type: Int32[]
        var _length = buffer_read(_buffer, buffer_u32);
        self.target_players = array_create(_length);
        for (var _i = 0; _i < _length; ++_i)
        {
            self.target_players[_i] = buffer_read(_buffer, buffer_s32);
        }

    }

    return _inst;
}

/**
 * @func __PhotonRealtimeAuthenticationValues_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeAuthenticationValues} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeAuthenticationValues_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: user_id, type: optional<String>
        if (is_undefined(self.user_id))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_string(self.user_id)) show_error($"{_where} :: self.user_id expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.user_id));
            buffer_write(_buffer, buffer_string, self.user_id);
        }

        // field: auth_type, type: optional<enum PhotonRealtimeCustomAuthType>
        if (is_undefined(self.auth_type))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);

            if (!is_numeric(self.auth_type)) show_error($"{_where} :: self.auth_type expected number", true);
            buffer_write(_buffer, buffer_s32, self.auth_type);
        }

        // field: parameters, type: optional<String>
        if (is_undefined(self.parameters))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_string(self.parameters)) show_error($"{_where} :: self.parameters expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.parameters));
            buffer_write(_buffer, buffer_string, self.parameters);
        }

    }
}

/**
 * @func __PhotonRealtimeAuthenticationValues_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeAuthenticationValues}
 * @ignore
 */
function __PhotonRealtimeAuthenticationValues_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeAuthenticationValues();
    with (_inst)
    {
        // field: user_id, type: optional<String>
        if (buffer_read(_buffer, buffer_bool))
        {
            buffer_read(_buffer, buffer_u32);
            self.user_id = buffer_read(_buffer, buffer_string);
        }
        else
        {
            self.user_id = undefined;
        }

        // field: auth_type, type: optional<enum PhotonRealtimeCustomAuthType>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.auth_type = buffer_read(_buffer, buffer_s32);
        }
        else
        {
            self.auth_type = undefined;
        }

        // field: parameters, type: optional<String>
        if (buffer_read(_buffer, buffer_bool))
        {
            buffer_read(_buffer, buffer_u32);
            self.parameters = buffer_read(_buffer, buffer_string);
        }
        else
        {
            self.parameters = undefined;
        }

    }

    return _inst;
}

/**
 * @func __PhotonRealtimeFriendInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeFriendInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeFriendInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: user_id, type: String
        if (!is_string(self.user_id)) show_error($"{_where} :: self.user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_byte_length(self.user_id));
        buffer_write(_buffer, buffer_string, self.user_id);

        // field: is_online, type: Bool
        if (!is_bool(self.is_online)) show_error($"{_where} :: self.is_online expected bool", true);
        buffer_write(_buffer, buffer_bool, self.is_online);

        // field: room, type: String
        if (!is_string(self.room)) show_error($"{_where} :: self.room expected string", true);
        buffer_write(_buffer, buffer_u32, string_byte_length(self.room));
        buffer_write(_buffer, buffer_string, self.room);

        // field: is_in_room, type: Bool
        if (!is_bool(self.is_in_room)) show_error($"{_where} :: self.is_in_room expected bool", true);
        buffer_write(_buffer, buffer_bool, self.is_in_room);

    }
}

/**
 * @func __PhotonRealtimeFriendInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeFriendInfo}
 * @ignore
 */
function __PhotonRealtimeFriendInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeFriendInfo();
    with (_inst)
    {
        // field: user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.user_id = buffer_read(_buffer, buffer_string);

        // field: is_online, type: Bool
        self.is_online = buffer_read(_buffer, buffer_bool);

        // field: room, type: String
        buffer_read(_buffer, buffer_u32);
        self.room = buffer_read(_buffer, buffer_string);

        // field: is_in_room, type: Bool
        self.is_in_room = buffer_read(_buffer, buffer_bool);

    }

    return _inst;
}

/**
 * @func __PhotonRealtimeRoomInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeRoomInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeRoomInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: name, type: String
        if (!is_string(self.name)) show_error($"{_where} :: self.name expected string", true);
        buffer_write(_buffer, buffer_u32, string_byte_length(self.name));
        buffer_write(_buffer, buffer_string, self.name);

        // field: player_count, type: Int32
        if (!is_numeric(self.player_count)) show_error($"{_where} :: self.player_count expected number", true);
        buffer_write(_buffer, buffer_s32, self.player_count);

        // field: max_players, type: Int32
        if (!is_numeric(self.max_players)) show_error($"{_where} :: self.max_players expected number", true);
        buffer_write(_buffer, buffer_s32, self.max_players);

        // field: is_open, type: Bool
        if (!is_bool(self.is_open)) show_error($"{_where} :: self.is_open expected bool", true);
        buffer_write(_buffer, buffer_bool, self.is_open);

        // field: custom_properties, type: AnyMap

        __ext_core_buffer_marshal_value(_buffer, self.custom_properties);

    }
}

/**
 * @func __PhotonRealtimeRoomInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeRoomInfo}
 * @ignore
 */
function __PhotonRealtimeRoomInfo_decode(_buffer, _offset)
{
    static __decoders = __GMPhoton_get_decoders();

    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeRoomInfo();
    with (_inst)
    {
        // field: name, type: String
        buffer_read(_buffer, buffer_u32);
        self.name = buffer_read(_buffer, buffer_string);

        // field: player_count, type: Int32
        self.player_count = buffer_read(_buffer, buffer_s32);

        // field: max_players, type: Int32
        self.max_players = buffer_read(_buffer, buffer_s32);

        // field: is_open, type: Bool
        self.is_open = buffer_read(_buffer, buffer_bool);

        // field: custom_properties, type: AnyMap
        self.custom_properties = __ext_core_buffer_unmarshal_value(_buffer, __decoders);

    }

    return _inst;
}

/**
 * @func __PhotonRealtimeLobbyStats_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeLobbyStats} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeLobbyStats_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: name, type: String
        if (!is_string(self.name)) show_error($"{_where} :: self.name expected string", true);
        buffer_write(_buffer, buffer_u32, string_byte_length(self.name));
        buffer_write(_buffer, buffer_string, self.name);

        // field: type, type: enum PhotonRealtimeLobbyType

        if (!is_numeric(self.type)) show_error($"{_where} :: self.type expected number", true);
        buffer_write(_buffer, buffer_s32, self.type);

        // field: peer_count, type: Int32
        if (!is_numeric(self.peer_count)) show_error($"{_where} :: self.peer_count expected number", true);
        buffer_write(_buffer, buffer_s32, self.peer_count);

        // field: room_count, type: Int32
        if (!is_numeric(self.room_count)) show_error($"{_where} :: self.room_count expected number", true);
        buffer_write(_buffer, buffer_s32, self.room_count);

    }
}

/**
 * @func __PhotonRealtimeLobbyStats_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeLobbyStats}
 * @ignore
 */
function __PhotonRealtimeLobbyStats_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeLobbyStats();
    with (_inst)
    {
        // field: name, type: String
        buffer_read(_buffer, buffer_u32);
        self.name = buffer_read(_buffer, buffer_string);

        // field: type, type: enum PhotonRealtimeLobbyType
        self.type = buffer_read(_buffer, buffer_s32);

        // field: peer_count, type: Int32
        self.peer_count = buffer_read(_buffer, buffer_s32);

        // field: room_count, type: Int32
        self.room_count = buffer_read(_buffer, buffer_s32);

    }

    return _inst;
}

/**
 * @func __PhotonChatMessage_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonChatMessage} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonChatMessage_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: sender, type: String
        if (!is_string(self.sender)) show_error($"{_where} :: self.sender expected string", true);
        buffer_write(_buffer, buffer_u32, string_byte_length(self.sender));
        buffer_write(_buffer, buffer_string, self.sender);

        // field: content, type: String
        if (!is_string(self.content)) show_error($"{_where} :: self.content expected string", true);
        buffer_write(_buffer, buffer_u32, string_byte_length(self.content));
        buffer_write(_buffer, buffer_string, self.content);

    }
}

/**
 * @func __PhotonChatMessage_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonChatMessage}
 * @ignore
 */
function __PhotonChatMessage_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonChatMessage();
    with (_inst)
    {
        // field: sender, type: String
        buffer_read(_buffer, buffer_u32);
        self.sender = buffer_read(_buffer, buffer_string);

        // field: content, type: String
        buffer_read(_buffer, buffer_u32);
        self.content = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __PhotonChatSubscribeResult_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonChatSubscribeResult} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonChatSubscribeResult_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: channel_name, type: String
        if (!is_string(self.channel_name)) show_error($"{_where} :: self.channel_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_byte_length(self.channel_name));
        buffer_write(_buffer, buffer_string, self.channel_name);

        // field: success, type: Bool
        if (!is_bool(self.success)) show_error($"{_where} :: self.success expected bool", true);
        buffer_write(_buffer, buffer_bool, self.success);

    }
}

/**
 * @func __PhotonChatSubscribeResult_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonChatSubscribeResult}
 * @ignore
 */
function __PhotonChatSubscribeResult_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonChatSubscribeResult();
    with (_inst)
    {
        // field: channel_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.channel_name = buffer_read(_buffer, buffer_string);

        // field: success, type: Bool
        self.success = buffer_read(_buffer, buffer_bool);

    }

    return _inst;
}

/**
 * @func __PhotonRealtimeConnectOptions_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonRealtimeConnectOptions} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonRealtimeConnectOptions_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: authentication_values, type: optional<struct PhotonRealtimeAuthenticationValues>
        if (is_undefined(self.authentication_values))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (self.authentication_values.__uid != 1448014036) show_error($"{_where} :: self.authentication_values expected PhotonRealtimeAuthenticationValues", true);
            __PhotonRealtimeAuthenticationValues_encode(self.authentication_values, _buffer, buffer_tell(_buffer), _where);
        }

        // field: username, type: optional<String>
        if (is_undefined(self.username))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_string(self.username)) show_error($"{_where} :: self.username expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.username));
            buffer_write(_buffer, buffer_string, self.username);
        }

        // field: server_address, type: optional<String>
        if (is_undefined(self.server_address))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_string(self.server_address)) show_error($"{_where} :: self.server_address expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.server_address));
            buffer_write(_buffer, buffer_string, self.server_address);
        }

        // field: try_use_datagram_encryption, type: optional<Bool>
        if (is_undefined(self.try_use_datagram_encryption))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_bool(self.try_use_datagram_encryption)) show_error($"{_where} :: self.try_use_datagram_encryption expected bool", true);
            buffer_write(_buffer, buffer_bool, self.try_use_datagram_encryption);
        }

        // field: use_background_thread, type: optional<Bool>
        if (is_undefined(self.use_background_thread))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_bool(self.use_background_thread)) show_error($"{_where} :: self.use_background_thread expected bool", true);
            buffer_write(_buffer, buffer_bool, self.use_background_thread);
        }

    }
}

/**
 * @func __PhotonRealtimeConnectOptions_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeConnectOptions}
 * @ignore
 */
function __PhotonRealtimeConnectOptions_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonRealtimeConnectOptions();
    with (_inst)
    {
        // field: authentication_values, type: optional<struct PhotonRealtimeAuthenticationValues>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.authentication_values = __PhotonRealtimeAuthenticationValues_decode(_buffer, buffer_tell(_buffer));
        }
        else
        {
            self.authentication_values = undefined;
        }

        // field: username, type: optional<String>
        if (buffer_read(_buffer, buffer_bool))
        {
            buffer_read(_buffer, buffer_u32);
            self.username = buffer_read(_buffer, buffer_string);
        }
        else
        {
            self.username = undefined;
        }

        // field: server_address, type: optional<String>
        if (buffer_read(_buffer, buffer_bool))
        {
            buffer_read(_buffer, buffer_u32);
            self.server_address = buffer_read(_buffer, buffer_string);
        }
        else
        {
            self.server_address = undefined;
        }

        // field: try_use_datagram_encryption, type: optional<Bool>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.try_use_datagram_encryption = buffer_read(_buffer, buffer_bool);
        }
        else
        {
            self.try_use_datagram_encryption = undefined;
        }

        // field: use_background_thread, type: optional<Bool>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.use_background_thread = buffer_read(_buffer, buffer_bool);
        }
        else
        {
            self.use_background_thread = undefined;
        }

    }

    return _inst;
}

/**
 * @func __PhotonChatConnectOptions_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.PhotonChatConnectOptions} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore
 */
function __PhotonChatConnectOptions_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: authentication_values, type: optional<struct PhotonRealtimeAuthenticationValues>
        if (is_undefined(self.authentication_values))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (self.authentication_values.__uid != 1448014036) show_error($"{_where} :: self.authentication_values expected PhotonRealtimeAuthenticationValues", true);
            __PhotonRealtimeAuthenticationValues_encode(self.authentication_values, _buffer, buffer_tell(_buffer), _where);
        }

        // field: server_address, type: optional<String>
        if (is_undefined(self.server_address))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_string(self.server_address)) show_error($"{_where} :: self.server_address expected string", true);
            buffer_write(_buffer, buffer_u32, string_byte_length(self.server_address));
            buffer_write(_buffer, buffer_string, self.server_address);
        }

        // field: use_background_thread, type: optional<Bool>
        if (is_undefined(self.use_background_thread))
        {
            buffer_write(_buffer, buffer_bool, false);
        }
        else
        {
            buffer_write(_buffer, buffer_bool, true);
            if (!is_bool(self.use_background_thread)) show_error($"{_where} :: self.use_background_thread expected bool", true);
            buffer_write(_buffer, buffer_bool, self.use_background_thread);
        }

    }
}

/**
 * @func __PhotonChatConnectOptions_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.PhotonChatConnectOptions}
 * @ignore
 */
function __PhotonChatConnectOptions_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new PhotonChatConnectOptions();
    with (_inst)
    {
        // field: authentication_values, type: optional<struct PhotonRealtimeAuthenticationValues>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.authentication_values = __PhotonRealtimeAuthenticationValues_decode(_buffer, buffer_tell(_buffer));
        }
        else
        {
            self.authentication_values = undefined;
        }

        // field: server_address, type: optional<String>
        if (buffer_read(_buffer, buffer_bool))
        {
            buffer_read(_buffer, buffer_u32);
            self.server_address = buffer_read(_buffer, buffer_string);
        }
        else
        {
            self.server_address = undefined;
        }

        // field: use_background_thread, type: optional<Bool>
        if (buffer_read(_buffer, buffer_bool))
        {
            self.use_background_thread = buffer_read(_buffer, buffer_bool);
        }
        else
        {
            self.use_background_thread = undefined;
        }

    }

    return _inst;
}

// #####################################################################
// # Functions
// #####################################################################

// Skipping function photon_realtime_init (no wrapper is required)


// Skipping function photon_realtime_shutdown (no wrapper is required)


// Skipping function photon_realtime_service (no wrapper is required)


/**
 * @param {String} _app_id
 * @param {String} _app_version
 * @param {Struct.PhotonRealtimeConnectOptions} _options
 * @returns {Bool}
 */
function photon_realtime_connect(_app_id, _app_version, _options)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _app_id, type: String
    if (!is_string(_app_id)) show_error($"{_GMFUNCTION_} :: _app_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_app_id));
    buffer_write(__args_buffer, buffer_string, _app_id);

    // param: _app_version, type: String
    if (!is_string(_app_version)) show_error($"{_GMFUNCTION_} :: _app_version expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_app_version));
    buffer_write(__args_buffer, buffer_string, _app_version);

    // param: _options, type: optional<struct PhotonRealtimeConnectOptions>
    if (is_undefined(_options))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (_options.__uid != 3657087078) show_error($"{_GMFUNCTION_} :: _options expected PhotonRealtimeConnectOptions", true);
        __PhotonRealtimeConnectOptions_encode(_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);
    }

    var _return_value = __photon_realtime_connect(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_realtime_disconnect (no wrapper is required)


// Skipping function photon_realtime_select_region (no wrapper is required)


// Skipping function photon_realtime_reconnect_and_rejoin (no wrapper is required)


// Skipping function photon_realtime_fetch_server_timestamp (no wrapper is required)


/**
 * @param {String} _lobby_name
 * @param {Enum.PhotonRealtimeLobbyType} _lobby_type
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_join_lobby(_lobby_name, _lobby_type, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_name, type: String
    if (!is_string(_lobby_name)) show_error($"{_GMFUNCTION_} :: _lobby_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_lobby_name));
    buffer_write(__args_buffer, buffer_string, _lobby_name);

    // param: _lobby_type, type: enum PhotonRealtimeLobbyType

    if (!is_numeric(_lobby_type)) show_error($"{_GMFUNCTION_} :: _lobby_type expected number", true);
    buffer_write(__args_buffer, buffer_s32, _lobby_type);

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_join_lobby(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_leave_lobby(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_leave_lobby(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _room_name
 * @param {Struct.PhotonRealtimeRoomOptions} _options
 * @param {Struct} _custom_properties
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_create_room(_room_name, _options, _custom_properties, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    static __decoders = __GMPhoton_get_decoders();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _room_name, type: String
    if (!is_string(_room_name)) show_error($"{_GMFUNCTION_} :: _room_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_room_name));
    buffer_write(__args_buffer, buffer_string, _room_name);

    // param: _options, type: struct PhotonRealtimeRoomOptions
    if (_options.__uid != 3302987841) show_error($"{_GMFUNCTION_} :: _options expected PhotonRealtimeRoomOptions", true);
    __PhotonRealtimeRoomOptions_encode(_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);

    // param: _custom_properties, type: AnyMap

    __ext_core_buffer_marshal_value(__args_buffer, _custom_properties);

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_create_room(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _room_name
 * @param {Struct.PhotonRealtimeRoomOptions} _options
 * @param {Struct} _custom_properties
 * @param {Real} _cache_slice_index
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_join_or_create_room(_room_name, _options, _custom_properties, _cache_slice_index, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    static __decoders = __GMPhoton_get_decoders();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _room_name, type: String
    if (!is_string(_room_name)) show_error($"{_GMFUNCTION_} :: _room_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_room_name));
    buffer_write(__args_buffer, buffer_string, _room_name);

    // param: _options, type: struct PhotonRealtimeRoomOptions
    if (_options.__uid != 3302987841) show_error($"{_GMFUNCTION_} :: _options expected PhotonRealtimeRoomOptions", true);
    __PhotonRealtimeRoomOptions_encode(_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);

    // param: _custom_properties, type: AnyMap

    __ext_core_buffer_marshal_value(__args_buffer, _custom_properties);

    // param: _cache_slice_index, type: optional<Int32>
    if (is_undefined(_cache_slice_index))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_numeric(_cache_slice_index)) show_error($"{_GMFUNCTION_} :: _cache_slice_index expected number", true);
        buffer_write(__args_buffer, buffer_s32, _cache_slice_index);
    }

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_join_or_create_room(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _room_name
 * @param {Struct.PhotonRealtimeJoinRoomOptions} _options
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_join_room(_room_name, _options, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _room_name, type: String
    if (!is_string(_room_name)) show_error($"{_GMFUNCTION_} :: _room_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_room_name));
    buffer_write(__args_buffer, buffer_string, _room_name);

    // param: _options, type: struct PhotonRealtimeJoinRoomOptions
    if (_options.__uid != 1668000541) show_error($"{_GMFUNCTION_} :: _options expected PhotonRealtimeJoinRoomOptions", true);
    __PhotonRealtimeJoinRoomOptions_encode(_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_join_room(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Struct.PhotonRealtimeJoinRandomOptions} _options
 * @param {Struct} _expected_properties
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_join_random_room(_options, _expected_properties, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    static __decoders = __GMPhoton_get_decoders();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _options, type: struct PhotonRealtimeJoinRandomOptions
    if (_options.__uid != 3312312409) show_error($"{_GMFUNCTION_} :: _options expected PhotonRealtimeJoinRandomOptions", true);
    __PhotonRealtimeJoinRandomOptions_encode(_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);

    // param: _expected_properties, type: AnyMap

    __ext_core_buffer_marshal_value(__args_buffer, _expected_properties);

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_join_random_room(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Bool} _will_come_back
 * @param {Bool} _send_authentication_cookie
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_leave_room(_will_come_back, _send_authentication_cookie, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _will_come_back, type: Bool
    if (!is_bool(_will_come_back)) show_error($"{_GMFUNCTION_} :: _will_come_back expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _will_come_back);

    // param: _send_authentication_cookie, type: Bool
    if (!is_bool(_send_authentication_cookie)) show_error($"{_GMFUNCTION_} :: _send_authentication_cookie expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _send_authentication_cookie);

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_leave_room(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _room_name
 * @param {Struct.PhotonRealtimeRoomOptions} _options
 * @param {Struct} _custom_properties
 * @param {Struct.PhotonRealtimeJoinRandomOptions} _random_options
 * @param {Struct} _expected_properties
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_join_random_or_create_room(_room_name, _options, _custom_properties, _random_options, _expected_properties, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    static __decoders = __GMPhoton_get_decoders();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _room_name, type: String
    if (!is_string(_room_name)) show_error($"{_GMFUNCTION_} :: _room_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_room_name));
    buffer_write(__args_buffer, buffer_string, _room_name);

    // param: _options, type: struct PhotonRealtimeRoomOptions
    if (_options.__uid != 3302987841) show_error($"{_GMFUNCTION_} :: _options expected PhotonRealtimeRoomOptions", true);
    __PhotonRealtimeRoomOptions_encode(_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);

    // param: _custom_properties, type: AnyMap

    __ext_core_buffer_marshal_value(__args_buffer, _custom_properties);

    // param: _random_options, type: struct PhotonRealtimeJoinRandomOptions
    if (_random_options.__uid != 3312312409) show_error($"{_GMFUNCTION_} :: _random_options expected PhotonRealtimeJoinRandomOptions", true);
    __PhotonRealtimeJoinRandomOptions_encode(_random_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);

    // param: _expected_properties, type: AnyMap

    __ext_core_buffer_marshal_value(__args_buffer, _expected_properties);

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_join_random_or_create_room(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _lobby_name
 * @param {String} _sql_filter
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_get_room_list(_lobby_name, _sql_filter, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_name, type: String
    if (!is_string(_lobby_name)) show_error($"{_GMFUNCTION_} :: _lobby_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_lobby_name));
    buffer_write(__args_buffer, buffer_string, _lobby_name);

    // param: _sql_filter, type: String
    if (!is_string(_sql_filter)) show_error($"{_GMFUNCTION_} :: _sql_filter expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_sql_filter));
    buffer_write(__args_buffer, buffer_string, _sql_filter);

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_get_room_list(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_lobby_stats(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_lobby_stats(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Array[String]} _friends
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_find_friends(_friends, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _friends, type: String[]
    if (!is_array(_friends)) show_error($"{_GMFUNCTION_} :: _friends expected array", true);
    var _length = array_length(_friends);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_friends[_i])) show_error($"{_GMFUNCTION_} :: _friends[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_byte_length(_friends[_i]));
        buffer_write(__args_buffer, buffer_string, _friends[_i]);
    }

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_find_friends(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _uri_path
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_operation_web_rpc(_uri_path, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _uri_path, type: String
    if (!is_string(_uri_path)) show_error($"{_GMFUNCTION_} :: _uri_path expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_uri_path));
    buffer_write(__args_buffer, buffer_string, _uri_path);

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_realtime_operation_web_rpc(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Array[Real]} _groups_to_remove
 * @param {Array[Real]} _groups_to_add
 * @returns {Bool}
 */
function photon_realtime_operation_change_groups(_groups_to_remove, _groups_to_add)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _groups_to_remove, type: optional<Int32[]>
    if (is_undefined(_groups_to_remove))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_array(_groups_to_remove)) show_error($"{_GMFUNCTION_} :: _groups_to_remove expected array", true);
        var _length = array_length(_groups_to_remove);
        buffer_write(__args_buffer, buffer_u32, _length);
        for (var _i = 0; _i < _length; ++_i)
        {
            if (!is_numeric(_groups_to_remove[_i])) show_error($"{_GMFUNCTION_} :: _groups_to_remove[_i] expected number", true);
            buffer_write(__args_buffer, buffer_s32, _groups_to_remove[_i]);
        }
    }

    // param: _groups_to_add, type: optional<Int32[]>
    if (is_undefined(_groups_to_add))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_array(_groups_to_add)) show_error($"{_GMFUNCTION_} :: _groups_to_add expected array", true);
        var _length = array_length(_groups_to_add);
        buffer_write(__args_buffer, buffer_u32, _length);
        for (var _i = 0; _i < _length; ++_i)
        {
            if (!is_numeric(_groups_to_add[_i])) show_error($"{_GMFUNCTION_} :: _groups_to_add[_i] expected number", true);
            buffer_write(__args_buffer, buffer_s32, _groups_to_add[_i]);
        }
    }

    var _return_value = __photon_realtime_operation_change_groups(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Struct.PhotonRealtimeAuthenticationValues} _authentication
 * @returns {Bool}
 */
function photon_realtime_operation_custom_auth_next_step(_authentication)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _authentication, type: struct PhotonRealtimeAuthenticationValues
    if (_authentication.__uid != 1448014036) show_error($"{_GMFUNCTION_} :: _authentication expected PhotonRealtimeAuthenticationValues", true);
    __PhotonRealtimeAuthenticationValues_encode(_authentication, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);

    var _return_value = __photon_realtime_operation_custom_auth_next_step(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Bool} _reliable
 * @param {String} _payload
 * @param {Real} _event_code
 * @param {Struct.PhotonRealtimeRaiseEventOptions} _options
 * @returns {Bool}
 */
function photon_realtime_operation_raise_event_string(_reliable, _payload, _event_code, _options)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _reliable, type: Bool
    if (!is_bool(_reliable)) show_error($"{_GMFUNCTION_} :: _reliable expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _reliable);

    // param: _payload, type: String
    if (!is_string(_payload)) show_error($"{_GMFUNCTION_} :: _payload expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_payload));
    buffer_write(__args_buffer, buffer_string, _payload);

    // param: _event_code, type: Int32
    if (!is_numeric(_event_code)) show_error($"{_GMFUNCTION_} :: _event_code expected number", true);
    buffer_write(__args_buffer, buffer_s32, _event_code);

    // param: _options, type: optional<struct PhotonRealtimeRaiseEventOptions>
    if (is_undefined(_options))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (_options.__uid != 1479735124) show_error($"{_GMFUNCTION_} :: _options expected PhotonRealtimeRaiseEventOptions", true);
        __PhotonRealtimeRaiseEventOptions_encode(_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);
    }

    var _return_value = __photon_realtime_operation_raise_event_string(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Bool} _reliable
 * @param {Id.Buffer} _data
 * @param {Real} _bytes
 * @param {Real} _event_code
 * @param {Struct.PhotonRealtimeRaiseEventOptions} _options
 * @returns {Bool}
 */
function photon_realtime_operation_raise_event_buffer(_reliable, _data, _bytes, _event_code, _options)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _reliable, type: Bool
    if (!is_bool(_reliable)) show_error($"{_GMFUNCTION_} :: _reliable expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _reliable);

    // param: _data, type: Buffer
    if (!buffer_exists(_data)) show_error($"{_GMFUNCTION_} :: _data expected Id.Buffer", true);
    __GMPhoton_queue_buffer(buffer_get_address(_data), buffer_get_size(_data));

    // param: _bytes, type: UInt32
    if (!is_numeric(_bytes)) show_error($"{_GMFUNCTION_} :: _bytes expected number", true);
    buffer_write(__args_buffer, buffer_u32, _bytes);

    // param: _event_code, type: Int32
    if (!is_numeric(_event_code)) show_error($"{_GMFUNCTION_} :: _event_code expected number", true);
    buffer_write(__args_buffer, buffer_s32, _event_code);

    // param: _options, type: optional<struct PhotonRealtimeRaiseEventOptions>
    if (is_undefined(_options))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (_options.__uid != 1479735124) show_error($"{_GMFUNCTION_} :: _options expected PhotonRealtimeRaiseEventOptions", true);
        __PhotonRealtimeRaiseEventOptions_encode(_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);
    }

    var _return_value = __photon_realtime_operation_raise_event_buffer(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_realtime_get_buffer_event_queue_count (no wrapper is required)


// Skipping function photon_realtime_clear_buffer_event_queue (no wrapper is required)


// Skipping function photon_realtime_peek_next_buffer_event_size (no wrapper is required)


// Skipping function photon_realtime_peek_next_buffer_event_code (no wrapper is required)


/**
 * @param {Id.Buffer} _out_data
 * @param {Real} _max_bytes
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeEventBufferReceived}
 */
function photon_realtime_receive_one_event_buffer(_out_data, _max_bytes, _offset)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _out_data, type: Buffer
    if (!buffer_exists(_out_data)) show_error($"{_GMFUNCTION_} :: _out_data expected Id.Buffer", true);
    __GMPhoton_queue_buffer(buffer_get_address(_out_data), buffer_get_size(_out_data));

    // param: _max_bytes, type: UInt32
    if (!is_numeric(_max_bytes)) show_error($"{_GMFUNCTION_} :: _max_bytes expected number", true);
    buffer_write(__args_buffer, buffer_u32, _max_bytes);

    // param: _offset, type: UInt32
    if (!is_numeric(_offset)) show_error($"{_GMFUNCTION_} :: _offset expected number", true);
    buffer_write(__args_buffer, buffer_u32, _offset);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_realtime_receive_one_event_buffer(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __PhotonRealtimeEventBufferReceived_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

// Skipping function photon_realtime_is_initialized (no wrapper is required)


// Skipping function photon_realtime_is_connected (no wrapper is required)


// Skipping function photon_realtime_is_in_game_room (no wrapper is required)


// Skipping function photon_realtime_is_in_room (no wrapper is required)


// Skipping function photon_realtime_is_in_lobby (no wrapper is required)


// Skipping function photon_realtime_get_current_room_name (no wrapper is required)


// Skipping function photon_realtime_get_local_player_number (no wrapper is required)


// Skipping function photon_realtime_get_server_time_offset (no wrapper is required)


// Skipping function photon_realtime_get_server_time (no wrapper is required)


// Skipping function photon_realtime_get_bytes_in (no wrapper is required)


// Skipping function photon_realtime_get_bytes_out (no wrapper is required)


/**
 * @returns {Enum.PhotonRealtimeState}
 */
function photon_realtime_get_state()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_realtime_get_state(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_s32);
    return _result;
}

// Skipping function photon_realtime_get_round_trip_time (no wrapper is required)


// Skipping function photon_realtime_get_round_trip_time_variance (no wrapper is required)


/**
 * @returns {Enum.PhotonRealtimeDisconnectCause}
 */
function photon_realtime_get_disconnected_cause()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_realtime_get_disconnected_cause(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_s32);
    return _result;
}

// Skipping function photon_realtime_get_user_id (no wrapper is required)


// Skipping function photon_realtime_get_count_players_ingame (no wrapper is required)


// Skipping function photon_realtime_get_count_games_running (no wrapper is required)


// Skipping function photon_realtime_get_count_players_online (no wrapper is required)


// Skipping function photon_realtime_get_master_server_address (no wrapper is required)


// Skipping function photon_realtime_get_region (no wrapper is required)


// Skipping function photon_realtime_get_region_with_best_ping (no wrapper is required)


// Skipping function photon_realtime_get_friend_list_age (no wrapper is required)


// Skipping function photon_realtime_get_disconnect_timeout (no wrapper is required)


// Skipping function photon_realtime_set_disconnect_timeout (no wrapper is required)


// Skipping function photon_realtime_get_ping_interval (no wrapper is required)


// Skipping function photon_realtime_set_ping_interval (no wrapper is required)


// Skipping function photon_realtime_get_auto_join_lobby (no wrapper is required)


// Skipping function photon_realtime_set_auto_join_lobby (no wrapper is required)


// Skipping function photon_realtime_get_room_player_count (no wrapper is required)


// Skipping function photon_realtime_get_room_max_players (no wrapper is required)


// Skipping function photon_realtime_get_room_is_open (no wrapper is required)


// Skipping function photon_realtime_get_room_is_visible (no wrapper is required)


// Skipping function photon_realtime_get_master_client_number (no wrapper is required)


// Skipping function photon_realtime_set_master_client (no wrapper is required)


// Skipping function photon_realtime_get_room_list_count (no wrapper is required)


/**
 * @param {Real} _index
 * @returns {Struct.PhotonRealtimeRoomInfo}
 */
function photon_realtime_get_room_info_by_index(_index)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_realtime_get_room_info_by_index(_index, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __PhotonRealtimeRoomInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

// Skipping function photon_realtime_get_player_count (no wrapper is required)


// Skipping function photon_realtime_get_player_number_by_index (no wrapper is required)


// Skipping function photon_realtime_player_get_name (no wrapper is required)


// Skipping function photon_realtime_player_get_user_id (no wrapper is required)


// Skipping function photon_realtime_player_is_inactive (no wrapper is required)


// Skipping function photon_realtime_player_is_master_client (no wrapper is required)


/**
 * @returns {Array[Real]}
 */
function photon_realtime_get_player_numbers()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_realtime_get_player_numbers(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    var _length = buffer_read(__ret_buffer, buffer_u32);
    _result = array_create(_length);
    for (var _i = 0; _i < _length; ++_i)
    {
        _result[_i] = buffer_read(__ret_buffer, buffer_s32);
    }
    return _result;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_debug(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_debug(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_connected(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_connected(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_disconnected(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_disconnected(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_connection_error(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_connection_error(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_client_error(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_client_error(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_server_error(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_server_error(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_warning(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_warning(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_join_room_event(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_join_room_event(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_leave_room_event(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_leave_room_event(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_custom_event(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_custom_event(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_room_properties_change(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_room_properties_change(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_player_properties_change(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_player_properties_change(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_room_list_update(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_room_list_update(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_app_stats_update(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_app_stats_update(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_lobby_stats_update(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_lobby_stats_update(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_cache_slice_changed(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_cache_slice_changed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_master_client_changed(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_master_client_changed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_properties_change_failed(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_properties_change_failed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_custom_authentication_step(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_custom_authentication_step(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_available_regions(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_available_regions(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_secret_receival(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_secret_receival(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_direct_connection_established(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_direct_connection_established(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_direct_connection_failed(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_direct_connection_failed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_direct_message(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_direct_message(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_realtime_set_callback_custom_operation_response(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_realtime_set_callback_custom_operation_response(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_realtime_remove_callback_debug (no wrapper is required)


// Skipping function photon_realtime_remove_callback_connected (no wrapper is required)


// Skipping function photon_realtime_remove_callback_disconnected (no wrapper is required)


// Skipping function photon_realtime_remove_callback_connection_error (no wrapper is required)


// Skipping function photon_realtime_remove_callback_client_error (no wrapper is required)


// Skipping function photon_realtime_remove_callback_server_error (no wrapper is required)


// Skipping function photon_realtime_remove_callback_warning (no wrapper is required)


// Skipping function photon_realtime_remove_callback_join_room_event (no wrapper is required)


// Skipping function photon_realtime_remove_callback_leave_room_event (no wrapper is required)


// Skipping function photon_realtime_remove_callback_custom_event (no wrapper is required)


// Skipping function photon_realtime_remove_callback_room_properties_change (no wrapper is required)


// Skipping function photon_realtime_remove_callback_player_properties_change (no wrapper is required)


// Skipping function photon_realtime_remove_callback_room_list_update (no wrapper is required)


// Skipping function photon_realtime_remove_callback_app_stats_update (no wrapper is required)


// Skipping function photon_realtime_remove_callback_lobby_stats_update (no wrapper is required)


// Skipping function photon_realtime_remove_callback_cache_slice_changed (no wrapper is required)


// Skipping function photon_realtime_remove_callback_master_client_changed (no wrapper is required)


// Skipping function photon_realtime_remove_callback_properties_change_failed (no wrapper is required)


// Skipping function photon_realtime_remove_callback_custom_authentication_step (no wrapper is required)


// Skipping function photon_realtime_remove_callback_available_regions (no wrapper is required)


// Skipping function photon_realtime_remove_callback_secret_receival (no wrapper is required)


// Skipping function photon_realtime_remove_callback_direct_connection_established (no wrapper is required)


// Skipping function photon_realtime_remove_callback_direct_connection_failed (no wrapper is required)


// Skipping function photon_realtime_remove_callback_direct_message (no wrapper is required)


// Skipping function photon_realtime_remove_callback_custom_operation_response (no wrapper is required)


// Skipping function photon_realtime_room_properties_set_string (no wrapper is required)


// Skipping function photon_realtime_room_properties_set_i32 (no wrapper is required)


// Skipping function photon_realtime_room_properties_set_f64 (no wrapper is required)


// Skipping function photon_realtime_room_properties_set_bool (no wrapper is required)


// Skipping function photon_realtime_room_properties_remove (no wrapper is required)


// Skipping function photon_realtime_room_properties_clear (no wrapper is required)


// Skipping function photon_realtime_room_properties_has (no wrapper is required)


// Skipping function photon_realtime_room_properties_get_string (no wrapper is required)


// Skipping function photon_realtime_room_properties_get_i32 (no wrapper is required)


// Skipping function photon_realtime_room_properties_get_f64 (no wrapper is required)


// Skipping function photon_realtime_room_properties_get_bool (no wrapper is required)


// Skipping function photon_realtime_room_properties_to_string (no wrapper is required)


/**
 * @returns {Struct}
 */
function photon_realtime_room_properties_get_all()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_realtime_room_properties_get_all(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __ext_core_buffer_unmarshal_value(__ret_buffer, __decoders);
    return _result;
}

// Skipping function photon_realtime_room_properties_cas_string (no wrapper is required)


// Skipping function photon_realtime_room_properties_cas_i32 (no wrapper is required)


// Skipping function photon_realtime_room_properties_cas_f64 (no wrapper is required)


// Skipping function photon_realtime_room_properties_cas_bool (no wrapper is required)


// Skipping function photon_realtime_player_properties_set_local_string (no wrapper is required)


// Skipping function photon_realtime_player_properties_set_local_i32 (no wrapper is required)


// Skipping function photon_realtime_player_properties_set_local_f64 (no wrapper is required)


// Skipping function photon_realtime_player_properties_set_local_bool (no wrapper is required)


// Skipping function photon_realtime_player_properties_remove_local (no wrapper is required)


// Skipping function photon_realtime_player_properties_clear_local (no wrapper is required)


// Skipping function photon_realtime_player_properties_has_local (no wrapper is required)


// Skipping function photon_realtime_player_properties_get_local_string (no wrapper is required)


// Skipping function photon_realtime_player_properties_get_local_i32 (no wrapper is required)


// Skipping function photon_realtime_player_properties_get_local_f64 (no wrapper is required)


// Skipping function photon_realtime_player_properties_get_local_bool (no wrapper is required)


// Skipping function photon_realtime_player_properties_to_string_local (no wrapper is required)


/**
 * @returns {Struct}
 */
function photon_realtime_player_properties_get_local_all()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_realtime_player_properties_get_local_all(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __ext_core_buffer_unmarshal_value(__ret_buffer, __decoders);
    return _result;
}

// Skipping function photon_realtime_player_properties_has_remote (no wrapper is required)


// Skipping function photon_realtime_player_properties_get_remote_string (no wrapper is required)


// Skipping function photon_realtime_player_properties_get_remote_i32 (no wrapper is required)


// Skipping function photon_realtime_player_properties_get_remote_f64 (no wrapper is required)


// Skipping function photon_realtime_player_properties_get_remote_bool (no wrapper is required)


// Skipping function photon_realtime_player_properties_to_string_remote (no wrapper is required)


/**
 * @param {Real} _player_number
 * @returns {Struct}
 */
function photon_realtime_player_properties_get_remote_all(_player_number)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_realtime_player_properties_get_remote_all(_player_number, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __ext_core_buffer_unmarshal_value(__ret_buffer, __decoders);
    return _result;
}

// Skipping function photon_realtime_peek_next_buffer_event_player_number (no wrapper is required)


// Skipping function photon_chat_init (no wrapper is required)


// Skipping function photon_chat_shutdown (no wrapper is required)


// Skipping function photon_chat_service (no wrapper is required)


// Skipping function photon_chat_select_region (no wrapper is required)


/**
 * @param {String} _app_id
 * @param {String} _app_version
 * @param {Struct.PhotonChatConnectOptions} _options
 * @returns {Bool}
 */
function photon_chat_connect(_app_id, _app_version, _options)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _app_id, type: String
    if (!is_string(_app_id)) show_error($"{_GMFUNCTION_} :: _app_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_app_id));
    buffer_write(__args_buffer, buffer_string, _app_id);

    // param: _app_version, type: String
    if (!is_string(_app_version)) show_error($"{_GMFUNCTION_} :: _app_version expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_app_version));
    buffer_write(__args_buffer, buffer_string, _app_version);

    // param: _options, type: optional<struct PhotonChatConnectOptions>
    if (is_undefined(_options))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (_options.__uid != 333942797) show_error($"{_GMFUNCTION_} :: _options expected PhotonChatConnectOptions", true);
        __PhotonChatConnectOptions_encode(_options, __args_buffer, buffer_tell(__args_buffer), _GMFUNCTION_);
    }

    var _return_value = __photon_chat_connect(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_chat_disconnect (no wrapper is required)


/**
 * @param {Array[String]} _channels
 * @param {Real} _messages_from_history
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_operation_subscribe(_channels, _messages_from_history, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _channels, type: String[]
    if (!is_array(_channels)) show_error($"{_GMFUNCTION_} :: _channels expected array", true);
    var _length = array_length(_channels);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_channels[_i])) show_error($"{_GMFUNCTION_} :: _channels[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_byte_length(_channels[_i]));
        buffer_write(__args_buffer, buffer_string, _channels[_i]);
    }

    // param: _messages_from_history, type: optional<Int32>
    if (is_undefined(_messages_from_history))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_numeric(_messages_from_history)) show_error($"{_GMFUNCTION_} :: _messages_from_history expected number", true);
        buffer_write(__args_buffer, buffer_s32, _messages_from_history);
    }

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_chat_operation_subscribe(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Array[String]} _channels
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_operation_unsubscribe(_channels, _callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _channels, type: String[]
    if (!is_array(_channels)) show_error($"{_GMFUNCTION_} :: _channels expected array", true);
    var _length = array_length(_channels);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_channels[_i])) show_error($"{_GMFUNCTION_} :: _channels[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_byte_length(_channels[_i]));
        buffer_write(__args_buffer, buffer_string, _channels[_i]);
    }

    // param: _callback, type: optional<Function>
    if (is_undefined(_callback))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
        var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
        buffer_write(__args_buffer, buffer_u64, _callback_handle);
    }

    var _return_value = __photon_chat_operation_unsubscribe(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_chat_operation_publish_message (no wrapper is required)


/**
 * @param {String} _user_name
 * @param {String} _message
 * @param {Bool} _encrypt
 * @returns {Bool}
 */
function photon_chat_operation_send_private_message(_user_name, _message, _encrypt)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _user_name, type: String
    if (!is_string(_user_name)) show_error($"{_GMFUNCTION_} :: _user_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_user_name));
    buffer_write(__args_buffer, buffer_string, _user_name);

    // param: _message, type: String
    if (!is_string(_message)) show_error($"{_GMFUNCTION_} :: _message expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_message));
    buffer_write(__args_buffer, buffer_string, _message);

    // param: _encrypt, type: optional<Bool>
    if (is_undefined(_encrypt))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_bool(_encrypt)) show_error($"{_GMFUNCTION_} :: _encrypt expected bool", true);
        buffer_write(__args_buffer, buffer_bool, _encrypt);
    }

    var _return_value = __photon_chat_operation_send_private_message(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Enum.PhotonChatUserStatus} _status
 * @param {String} _message
 * @returns {Bool}
 */
function photon_chat_operation_set_online_status(_status, _message)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _status, type: enum PhotonChatUserStatus

    if (!is_numeric(_status)) show_error($"{_GMFUNCTION_} :: _status expected number", true);
    buffer_write(__args_buffer, buffer_s32, _status);

    // param: _message, type: optional<String>
    if (is_undefined(_message))
    {
        buffer_write(__args_buffer, buffer_bool, false);
    }
    else
    {
        buffer_write(__args_buffer, buffer_bool, true);
        if (!is_string(_message)) show_error($"{_GMFUNCTION_} :: _message expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_byte_length(_message));
        buffer_write(__args_buffer, buffer_string, _message);
    }

    var _return_value = __photon_chat_operation_set_online_status(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Array[String]} _user_ids
 * @returns {Bool}
 */
function photon_chat_operation_add_friends(_user_ids)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _user_ids, type: String[]
    if (!is_array(_user_ids)) show_error($"{_GMFUNCTION_} :: _user_ids expected array", true);
    var _length = array_length(_user_ids);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_user_ids[_i])) show_error($"{_GMFUNCTION_} :: _user_ids[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_byte_length(_user_ids[_i]));
        buffer_write(__args_buffer, buffer_string, _user_ids[_i]);
    }

    var _return_value = __photon_chat_operation_add_friends(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Array[String]} _user_ids
 * @returns {Bool}
 */
function photon_chat_operation_remove_friends(_user_ids)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _user_ids, type: String[]
    if (!is_array(_user_ids)) show_error($"{_GMFUNCTION_} :: _user_ids expected array", true);
    var _length = array_length(_user_ids);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_user_ids[_i])) show_error($"{_GMFUNCTION_} :: _user_ids[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_byte_length(_user_ids[_i]));
        buffer_write(__args_buffer, buffer_string, _user_ids[_i]);
    }

    var _return_value = __photon_chat_operation_remove_friends(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_chat_is_initialized (no wrapper is required)


// Skipping function photon_chat_is_connected (no wrapper is required)


/**
 * @returns {Enum.PhotonChatState}
 */
function photon_chat_get_state()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_chat_get_state(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_s32);
    return _result;
}

/**
 * @returns {Enum.PhotonChatDisconnectCause}
 */
function photon_chat_get_disconnect_cause()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_chat_get_disconnect_cause(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_s32);
    return _result;
}

// Skipping function photon_chat_get_user_id (no wrapper is required)


// Skipping function photon_chat_get_region (no wrapper is required)


// Skipping function photon_chat_get_server_time (no wrapper is required)


// Skipping function photon_chat_get_server_time_offset (no wrapper is required)


// Skipping function photon_chat_get_bytes_in (no wrapper is required)


// Skipping function photon_chat_get_bytes_out (no wrapper is required)


/**
 * @param {Enum.PhotonChatChannelType} _channel_type
 * @returns {Real}
 */
function photon_chat_get_channel_count(_channel_type)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _channel_type, type: enum PhotonChatChannelType

    if (!is_numeric(_channel_type)) show_error($"{_GMFUNCTION_} :: _channel_type expected number", true);
    buffer_write(__args_buffer, buffer_s32, _channel_type);

    var _return_value = __photon_chat_get_channel_count(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Enum.PhotonChatChannelType} _channel_type
 * @param {Real} _index
 * @returns {String}
 */
function photon_chat_get_channel_name(_channel_type, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _channel_type, type: enum PhotonChatChannelType

    if (!is_numeric(_channel_type)) show_error($"{_GMFUNCTION_} :: _channel_type expected number", true);
    buffer_write(__args_buffer, buffer_s32, _channel_type);

    // param: _index, type: Int32
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_s32, _index);

    var _return_value = __photon_chat_get_channel_name(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Enum.PhotonChatChannelType} _channel_type
 * @param {String} _channel_name
 * @returns {Real}
 */
function photon_chat_get_channel_message_count(_channel_type, _channel_name)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _channel_type, type: enum PhotonChatChannelType

    if (!is_numeric(_channel_type)) show_error($"{_GMFUNCTION_} :: _channel_type expected number", true);
    buffer_write(__args_buffer, buffer_s32, _channel_type);

    // param: _channel_name, type: String
    if (!is_string(_channel_name)) show_error($"{_GMFUNCTION_} :: _channel_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_channel_name));
    buffer_write(__args_buffer, buffer_string, _channel_name);

    var _return_value = __photon_chat_get_channel_message_count(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Enum.PhotonChatChannelType} _channel_type
 * @param {String} _channel_name
 * @param {Real} _index
 * @returns {String}
 */
function photon_chat_get_channel_message(_channel_type, _channel_name, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _channel_type, type: enum PhotonChatChannelType

    if (!is_numeric(_channel_type)) show_error($"{_GMFUNCTION_} :: _channel_type expected number", true);
    buffer_write(__args_buffer, buffer_s32, _channel_type);

    // param: _channel_name, type: String
    if (!is_string(_channel_name)) show_error($"{_GMFUNCTION_} :: _channel_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_channel_name));
    buffer_write(__args_buffer, buffer_string, _channel_name);

    // param: _index, type: Int32
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_s32, _index);

    var _return_value = __photon_chat_get_channel_message(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Enum.PhotonChatChannelType} _channel_type
 * @param {String} _channel_name
 * @param {Real} _index
 * @returns {String}
 */
function photon_chat_get_channel_sender(_channel_type, _channel_name, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _channel_type, type: enum PhotonChatChannelType

    if (!is_numeric(_channel_type)) show_error($"{_GMFUNCTION_} :: _channel_type expected number", true);
    buffer_write(__args_buffer, buffer_s32, _channel_type);

    // param: _channel_name, type: String
    if (!is_string(_channel_name)) show_error($"{_GMFUNCTION_} :: _channel_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_byte_length(_channel_name));
    buffer_write(__args_buffer, buffer_string, _channel_name);

    // param: _index, type: Int32
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_s32, _index);

    var _return_value = __photon_chat_get_channel_sender(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_debug(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_debug(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_connected(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_connected(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_state_change(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_state_change(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_connection_error(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_connection_error(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_client_error(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_client_error(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_warning(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_warning(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_server_error(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_server_error(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_disconnected(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_disconnected(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_status_update(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_status_update(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_get_messages(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_get_messages(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_private_message(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_private_message(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_chat_set_callback_receive_broadcast(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_chat_set_callback_receive_broadcast(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_chat_get_broadcast_queue_count (no wrapper is required)


// Skipping function photon_chat_clear_broadcast_queue (no wrapper is required)


// Skipping function photon_chat_peek_next_broadcast_size (no wrapper is required)


// Skipping function photon_chat_peek_next_broadcast_channel (no wrapper is required)


/**
 * @param {Id.Buffer} _out_data
 * @param {Real} _max_bytes
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeEventBufferReceived}
 */
function photon_chat_receive_one_broadcast_buffer(_out_data, _max_bytes, _offset)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _out_data, type: Buffer
    if (!buffer_exists(_out_data)) show_error($"{_GMFUNCTION_} :: _out_data expected Id.Buffer", true);
    __GMPhoton_queue_buffer(buffer_get_address(_out_data), buffer_get_size(_out_data));

    // param: _max_bytes, type: UInt32
    if (!is_numeric(_max_bytes)) show_error($"{_GMFUNCTION_} :: _max_bytes expected number", true);
    buffer_write(__args_buffer, buffer_u32, _max_bytes);

    // param: _offset, type: UInt32
    if (!is_numeric(_offset)) show_error($"{_GMFUNCTION_} :: _offset expected number", true);
    buffer_write(__args_buffer, buffer_u32, _offset);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_chat_receive_one_broadcast_buffer(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __PhotonRealtimeEventBufferReceived_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

// Skipping function photon_chat_remove_callback_debug (no wrapper is required)


// Skipping function photon_chat_remove_callback_connected (no wrapper is required)


// Skipping function photon_chat_remove_callback_state_change (no wrapper is required)


// Skipping function photon_chat_remove_callback_connection_error (no wrapper is required)


// Skipping function photon_chat_remove_callback_client_error (no wrapper is required)


// Skipping function photon_chat_remove_callback_warning (no wrapper is required)


// Skipping function photon_chat_remove_callback_server_error (no wrapper is required)


// Skipping function photon_chat_remove_callback_disconnected (no wrapper is required)


// Skipping function photon_chat_remove_callback_status_update (no wrapper is required)


// Skipping function photon_chat_remove_callback_get_messages (no wrapper is required)


// Skipping function photon_chat_remove_callback_private_message (no wrapper is required)


// Skipping function photon_chat_remove_callback_receive_broadcast (no wrapper is required)


// Skipping function photon_voice_init (no wrapper is required)


// Skipping function photon_voice_shutdown (no wrapper is required)


// Skipping function photon_voice_service (no wrapper is required)


// Skipping function photon_voice_is_initialized (no wrapper is required)


// Skipping function photon_voice_notify_joined_room (no wrapper is required)


// Skipping function photon_voice_on_join_channel (no wrapper is required)


// Skipping function photon_voice_on_leave_channel (no wrapper is required)


// Skipping function photon_voice_on_join_all_channels (no wrapper is required)


// Skipping function photon_voice_on_leave_all_channels (no wrapper is required)


// Skipping function photon_voice_on_player_join (no wrapper is required)


// Skipping function photon_voice_on_player_leave (no wrapper is required)


/**
 * @param {Real} _channel_id
 * @param {Enum.PhotonVoiceCodec} _codec
 * @param {Real} _sample_rate
 * @param {Real} _channels
 * @param {Real} _bitrate
 * @param {Real} _frames_per_packet
 * @returns {Real}
 */
function photon_voice_create_local_voice(_channel_id, _codec, _sample_rate, _channels, _bitrate, _frames_per_packet)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _channel_id, type: Int32
    if (!is_numeric(_channel_id)) show_error($"{_GMFUNCTION_} :: _channel_id expected number", true);
    buffer_write(__args_buffer, buffer_s32, _channel_id);

    // param: _codec, type: enum PhotonVoiceCodec

    if (!is_numeric(_codec)) show_error($"{_GMFUNCTION_} :: _codec expected number", true);
    buffer_write(__args_buffer, buffer_s32, _codec);

    // param: _sample_rate, type: Int32
    if (!is_numeric(_sample_rate)) show_error($"{_GMFUNCTION_} :: _sample_rate expected number", true);
    buffer_write(__args_buffer, buffer_s32, _sample_rate);

    // param: _channels, type: Int32
    if (!is_numeric(_channels)) show_error($"{_GMFUNCTION_} :: _channels expected number", true);
    buffer_write(__args_buffer, buffer_s32, _channels);

    // param: _bitrate, type: Int32
    if (!is_numeric(_bitrate)) show_error($"{_GMFUNCTION_} :: _bitrate expected number", true);
    buffer_write(__args_buffer, buffer_s32, _bitrate);

    // param: _frames_per_packet, type: Int32
    if (!is_numeric(_frames_per_packet)) show_error($"{_GMFUNCTION_} :: _frames_per_packet expected number", true);
    buffer_write(__args_buffer, buffer_s32, _frames_per_packet);

    var _return_value = __photon_voice_create_local_voice(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_voice_remove_local_voice (no wrapper is required)


/**
 * @param {Real} _voice_id
 * @param {Id.Buffer} _data
 * @param {Real} _bytes
 * @returns {Bool}
 */
function photon_voice_push_frame_buffer(_voice_id, _data, _bytes)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _voice_id, type: Int32
    if (!is_numeric(_voice_id)) show_error($"{_GMFUNCTION_} :: _voice_id expected number", true);
    buffer_write(__args_buffer, buffer_s32, _voice_id);

    // param: _data, type: Buffer
    if (!buffer_exists(_data)) show_error($"{_GMFUNCTION_} :: _data expected Id.Buffer", true);
    __GMPhoton_queue_buffer(buffer_get_address(_data), buffer_get_size(_data));

    // param: _bytes, type: UInt32
    if (!is_numeric(_bytes)) show_error($"{_GMFUNCTION_} :: _bytes expected number", true);
    buffer_write(__args_buffer, buffer_u32, _bytes);

    var _return_value = __photon_voice_push_frame_buffer(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_voice_get_frame_queue_count (no wrapper is required)


// Skipping function photon_voice_clear_frame_queue (no wrapper is required)


// Skipping function photon_voice_peek_next_frame_size (no wrapper is required)


// Skipping function photon_voice_peek_next_frame_player_id (no wrapper is required)


// Skipping function photon_voice_peek_next_frame_voice_id (no wrapper is required)


/**
 * @param {Id.Buffer} _out_data
 * @param {Real} _max_bytes
 * @param {Real} _offset
 * @returns {Struct.PhotonRealtimeEventBufferReceived}
 */
function photon_voice_receive_frame_buffer(_out_data, _max_bytes, _offset)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _out_data, type: Buffer
    if (!buffer_exists(_out_data)) show_error($"{_GMFUNCTION_} :: _out_data expected Id.Buffer", true);
    __GMPhoton_queue_buffer(buffer_get_address(_out_data), buffer_get_size(_out_data));

    // param: _max_bytes, type: UInt32
    if (!is_numeric(_max_bytes)) show_error($"{_GMFUNCTION_} :: _max_bytes expected number", true);
    buffer_write(__args_buffer, buffer_u32, _max_bytes);

    // param: _offset, type: UInt32
    if (!is_numeric(_offset)) show_error($"{_GMFUNCTION_} :: _offset expected number", true);
    buffer_write(__args_buffer, buffer_u32, _offset);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_voice_receive_frame_buffer(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __PhotonRealtimeEventBufferReceived_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

// Skipping function photon_voice_get_remote_voice_count (no wrapper is required)


// Skipping function photon_voice_get_remote_voice_player_id (no wrapper is required)


// Skipping function photon_voice_get_remote_voice_id (no wrapper is required)


/**
 * @param {Real} _index
 * @returns {Enum.PhotonVoiceCodec}
 */
function photon_voice_get_remote_voice_codec(_index)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_voice_get_remote_voice_codec(_index, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_s32);
    return _result;
}

// Skipping function photon_voice_get_remote_voice_sample_rate (no wrapper is required)


// Skipping function photon_voice_get_remote_voice_channels (no wrapper is required)


// Skipping function photon_voice_get_remote_voice_is_speaking (no wrapper is required)


// Skipping function photon_voice_get_frames_sent (no wrapper is required)


// Skipping function photon_voice_get_frames_received (no wrapper is required)


// Skipping function photon_voice_get_frames_lost (no wrapper is required)


// Skipping function photon_voice_get_round_trip_time (no wrapper is required)


// Skipping function photon_voice_get_round_trip_time_variance (no wrapper is required)


/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_voice_set_callback_remote_voice_added(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_voice_set_callback_remote_voice_added(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_voice_set_callback_remote_voice_removed(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_voice_set_callback_remote_voice_removed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_voice_set_callback_speaking_changed(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_voice_set_callback_speaking_changed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Bool}
 */
function photon_voice_set_callback_debug(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_voice_set_callback_debug(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_voice_remove_callback_remote_voice_added (no wrapper is required)


// Skipping function photon_voice_remove_callback_remote_voice_removed (no wrapper is required)


// Skipping function photon_voice_remove_callback_speaking_changed (no wrapper is required)


// Skipping function photon_voice_remove_callback_debug (no wrapper is required)


// Skipping function photon_voice_local_voice_set_transmit (no wrapper is required)


// Skipping function photon_voice_local_voice_get_transmit (no wrapper is required)


// Skipping function photon_voice_set_remote_player_muted (no wrapper is required)


// Skipping function photon_voice_get_remote_player_muted (no wrapper is required)


// Skipping function photon_voice_set_remote_player_volume (no wrapper is required)


// Skipping function photon_voice_get_remote_player_volume (no wrapper is required)


// Skipping function photon_voice_get_debug_lost_percent (no wrapper is required)


// Skipping function photon_voice_set_debug_lost_percent (no wrapper is required)


// Skipping function photon_voice_get_speaking_threshold_ms (no wrapper is required)


// Skipping function photon_voice_set_speaking_threshold_ms (no wrapper is required)


// Skipping function photon_realtime_peer_get_state (no wrapper is required)


// Skipping function photon_realtime_peer_get_round_trip_time (no wrapper is required)


// Skipping function photon_realtime_peer_get_round_trip_time_variance (no wrapper is required)


// Skipping function photon_realtime_peer_get_bytes_in (no wrapper is required)


// Skipping function photon_realtime_peer_get_bytes_out (no wrapper is required)


// Skipping function photon_realtime_peer_get_queued_incoming_commands (no wrapper is required)


// Skipping function photon_realtime_peer_get_queued_outgoing_commands (no wrapper is required)


/**
 * @returns {Enum.PhotonCommonDebugLevel}
 */
function photon_realtime_peer_get_debug_output_level()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_realtime_peer_get_debug_output_level(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_s32);
    return _result;
}

/**
 * @param {Enum.PhotonCommonDebugLevel} _level
 * @returns {Bool}
 */
function photon_realtime_peer_set_debug_output_level(_level)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _level, type: enum PhotonCommonDebugLevel

    if (!is_numeric(_level)) show_error($"{_GMFUNCTION_} :: _level expected number", true);
    buffer_write(__args_buffer, buffer_s32, _level);

    var _return_value = __photon_realtime_peer_set_debug_output_level(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_realtime_peer_get_disconnect_timeout (no wrapper is required)


// Skipping function photon_realtime_peer_set_disconnect_timeout (no wrapper is required)


// Skipping function photon_realtime_peer_get_time_ping_interval (no wrapper is required)


// Skipping function photon_realtime_peer_set_time_ping_interval (no wrapper is required)


// Skipping function photon_realtime_peer_get_crc_enabled (no wrapper is required)


// Skipping function photon_realtime_peer_set_crc_enabled (no wrapper is required)


// Skipping function photon_realtime_peer_get_packet_loss_by_crc (no wrapper is required)


// Skipping function photon_realtime_peer_get_timestamp_of_last_socket_receive (no wrapper is required)


// Skipping function photon_realtime_peer_reset_traffic_stats (no wrapper is required)


// Skipping function photon_chat_peer_get_state (no wrapper is required)


// Skipping function photon_chat_peer_get_round_trip_time (no wrapper is required)


// Skipping function photon_chat_peer_get_round_trip_time_variance (no wrapper is required)


// Skipping function photon_chat_peer_get_bytes_in (no wrapper is required)


// Skipping function photon_chat_peer_get_bytes_out (no wrapper is required)


// Skipping function photon_chat_peer_get_queued_incoming_commands (no wrapper is required)


// Skipping function photon_chat_peer_get_queued_outgoing_commands (no wrapper is required)


/**
 * @returns {Enum.PhotonCommonDebugLevel}
 */
function photon_chat_peer_get_debug_output_level()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_chat_peer_get_debug_output_level(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_s32);
    return _result;
}

/**
 * @param {Enum.PhotonCommonDebugLevel} _level
 * @returns {Bool}
 */
function photon_chat_peer_set_debug_output_level(_level)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _level, type: enum PhotonCommonDebugLevel

    if (!is_numeric(_level)) show_error($"{_GMFUNCTION_} :: _level expected number", true);
    buffer_write(__args_buffer, buffer_s32, _level);

    var _return_value = __photon_chat_peer_set_debug_output_level(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_chat_peer_get_disconnect_timeout (no wrapper is required)


// Skipping function photon_chat_peer_set_disconnect_timeout (no wrapper is required)


// Skipping function photon_chat_peer_get_time_ping_interval (no wrapper is required)


// Skipping function photon_chat_peer_set_time_ping_interval (no wrapper is required)


// Skipping function photon_chat_peer_get_crc_enabled (no wrapper is required)


// Skipping function photon_chat_peer_set_crc_enabled (no wrapper is required)


// Skipping function photon_chat_peer_get_packet_loss_by_crc (no wrapper is required)


// Skipping function photon_chat_peer_get_timestamp_of_last_socket_receive (no wrapper is required)


// Skipping function photon_chat_peer_reset_traffic_stats (no wrapper is required)


// Skipping function photon_peer_network_sim_get_enabled (no wrapper is required)


// Skipping function photon_peer_network_sim_set_enabled (no wrapper is required)


// Skipping function photon_peer_network_sim_set_lag (no wrapper is required)


// Skipping function photon_peer_network_sim_set_jitter (no wrapper is required)


// Skipping function photon_peer_network_sim_set_packet_loss (no wrapper is required)


/**
 * @param {Enum.PhotonCommonDebugLevel} _level
 * @returns {Bool}
 */
function photon_common_set_debug_level(_level)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _level, type: enum PhotonCommonDebugLevel

    if (!is_numeric(_level)) show_error($"{_GMFUNCTION_} :: _level expected number", true);
    buffer_write(__args_buffer, buffer_s32, _level);

    var _return_value = __photon_common_set_debug_level(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @returns {Enum.PhotonCommonDebugLevel}
 */
function photon_common_get_debug_level()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_common_get_debug_level(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_s32);
    return _result;
}

/**
 * @returns {Enum.PhotonCommonSerializationProtocol}
 */
function photon_common_get_serialization_protocol()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __photon_common_get_serialization_protocol(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_s32);
    return _result;
}

/**
 * @param {Enum.PhotonCommonTypeCode} _type_code
 * @returns {String}
 */
function photon_common_type_code_to_string(_type_code)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _type_code, type: enum PhotonCommonTypeCode

    if (!is_numeric(_type_code)) show_error($"{_GMFUNCTION_} :: _type_code expected number", true);
    buffer_write(__args_buffer, buffer_s32, _type_code);

    var _return_value = __photon_common_type_code_to_string(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function photon_common_get_sdk_version (no wrapper is required)


// Skipping function photon_common_client_state_to_string (no wrapper is required)


// Skipping function photon_common_disconnect_cause_to_string (no wrapper is required)


/// @ignore
function __GMPhoton_get_decoders()
{
    static __decoders = [
        __PhotonRealtimeEventBufferReceived_decode,
        __PhotonRealtimeJoinRandomOptions_decode,
        __PhotonRealtimeRoomOptions_decode,
        __PhotonRealtimeJoinRoomOptions_decode,
        __PhotonRealtimeRaiseEventOptions_decode,
        __PhotonRealtimeAuthenticationValues_decode,
        __PhotonRealtimeFriendInfo_decode,
        __PhotonRealtimeRoomInfo_decode,
        __PhotonRealtimeLobbyStats_decode,
        __PhotonChatMessage_decode,
        __PhotonChatSubscribeResult_decode,
        __PhotonRealtimeConnectOptions_decode,
        __PhotonChatConnectOptions_decode
    ];
    return __decoders;
}
/// @ignore
function __GMPhoton_get_dispatcher()
{
    static __dispatcher = new __GMNativeFunctionDispatcher(__GMPhoton_invocation_handler, __GMPhoton_get_decoders());
    return __dispatcher;
}
