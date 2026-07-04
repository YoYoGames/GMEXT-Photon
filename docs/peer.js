// FUNCTIONS

/**
 * @function photon_peer_network_sim_get_enabled
 * @desc Returns whether network simulation (artificial lag, jitter and packet loss) is enabled.
 * @returns {Bool} Whether network simulation is enabled.
 * @function_end
 */

/**
 * @function photon_peer_network_sim_set_enabled
 * @desc Enables or disables network simulation for testing poor network conditions.
 * @param {Bool} enabled Whether to enable network simulation.
 * @returns {Bool} Whether the value was set.
 * @function_end
 */

/**
 * @function photon_peer_network_sim_set_lag
 * @desc Sets the artificial incoming and outgoing lag, in milliseconds.
 * @param {Real} incoming_ms The incoming lag in milliseconds.
 * @param {Real} outgoing_ms The outgoing lag in milliseconds.
 * @returns {Bool} Whether the values were set.
 * @function_end
 */

/**
 * @function photon_peer_network_sim_set_jitter
 * @desc Sets the artificial incoming and outgoing jitter, in milliseconds.
 * @param {Real} incoming_ms The incoming jitter in milliseconds.
 * @param {Real} outgoing_ms The outgoing jitter in milliseconds.
 * @returns {Bool} Whether the values were set.
 * @function_end
 */

/**
 * @function photon_peer_network_sim_set_packet_loss
 * @desc Sets the artificial incoming and outgoing packet-loss percentages.
 * @param {Real} incoming_pct The incoming packet-loss percentage.
 * @param {Real} outgoing_pct The outgoing packet-loss percentage.
 * @returns {Bool} Whether the values were set.
 * @function_end
 */

// CONSTANTS

/**
 * @const PhotonPeerState
 * @desc The low-level peer connection states.
 * @member Disconnected The peer is disconnected.
 * @member Connecting The peer is connecting.
 * @member InitializingApplication The peer is initialising the application layer.
 * @member Connected The peer is connected.
 * @member Disconnecting The peer is disconnecting.
 * @const_end
 */

/**
 * @const PhotonPeerConnectionProtocol
 * @desc The transport protocols a peer can use.
 * @member Udp UDP transport.
 * @member Tcp TCP transport.
 * @member Ws WebSocket transport.
 * @member Wss Secure WebSocket transport.
 * @const_end
 */

/**
 * @const PhotonPeerStatusCode
 * @desc Low-level peer status codes. Primarily useful for diagnostics.
 * @member ExceptionOnConnect An exception occurred while connecting.
 * @member Connect The peer connected.
 * @member Disconnect The peer disconnected.
 * @member Exception A peer exception occurred.
 * @member QueueOutgoingReliableWarning The outgoing reliable queue is filling up.
 * @member QueueOutgoingUnreliableWarning The outgoing unreliable queue is filling up.
 * @member SendError A send error occurred.
 * @member QueueOutgoingAcksWarning The outgoing acknowledgement queue is filling up.
 * @member QueueIncomingReliableWarning The incoming reliable queue is filling up.
 * @member QueueIncomingUnreliableWarning The incoming unreliable queue is filling up.
 * @member QueueSentWarning The sent queue is filling up.
 * @member InternalReceiveException An internal receive exception occurred.
 * @member TimeoutDisconnect The connection timed out.
 * @member DisconnectByServer The server closed the connection.
 * @member DisconnectByServerUserLimit The server closed the connection due to its user limit.
 * @member DisconnectByServerLogic Server-side logic closed the connection.
 * @member EncryptionEstablished Encryption was established.
 * @member EncryptionFailedToEstablish Encryption failed to establish.
 * @const_end
 */

/**
 * @const PhotonPeerCoreErrorCode
 * @desc Core (protocol-level) error codes. Primarily useful for diagnostics.
 * @member Ok No error.
 * @member InternalServerError An internal server error occurred.
 * @member OperationInvalid The operation was invalid.
 * @member OperationDenied The operation was denied.
 * @member ArgumentOutOfRange An argument was out of range.
 * @member InvalidRequestParameters The request parameters were invalid.
 * @member NotReady The server is not ready.
 * @member Overload The server is overloaded.
 * @member Backoff The client should back off and retry later.
 * @member Maintenance The server is under maintenance.
 * @member SendBufferFull The send buffer is full.
 * @member UnexpectedData Unexpected data was received.
 * @member SerializationLimitError A serialization limit was exceeded.
 * @member WrongInitRequestData The initialization request data was wrong.
 * @member ResponseParseError A response could not be parsed.
 * @member CryptoProviderNotSet The crypto provider was not set.
 * @member DecryptionFailure Decryption failed.
 * @member InvalidEncryptionParameters The encryption parameters were invalid.
 * @member IncomingDataRateExceeded The incoming data rate was exceeded.
 * @member IncomingMsgRateExceeded The incoming message rate was exceeded.
 * @member IncomingMaxMsgSizeExceeded The incoming maximum message size was exceeded.
 * @member OperationMaxCountExceeded The operation count limit was exceeded.
 * @member OperationRateExceeded The operation rate was exceeded.
 * @member OperationDataRateExceeded The operation data rate was exceeded.
 * @member OperationBlocked The operation was blocked.
 * @member OperationSizeLimitExceeded The operation size limit was exceeded.
 * @member OperationParametersLimit The operation parameters limit was exceeded.
 * @member MessagesRateExceeded The message rate was exceeded.
 * @member MessagesDataRateExceeded The message data rate was exceeded.
 * @member MessagesBlocked Messages were blocked.
 * @member MessageSizeLimitExceeded The message size limit was exceeded.
 * @const_end
 */

/**
 * @const PhotonPeerLiteOperationCode
 * @desc The Lite protocol operation codes. Primarily useful for diagnostics.
 * @member Join Join a room.
 * @member Leave Leave a room.
 * @member RaiseEvent Raise an event.
 * @member SetProperties Set properties.
 * @member GetProperties Get properties.
 * @member ChangeGroups Change interest groups.
 * @const_end
 */

/**
 * @const PhotonPeerLiteEventCode
 * @desc The Lite protocol event codes. Primarily useful for diagnostics.
 * @member Join A player joined.
 * @member Leave A player left.
 * @member PropertiesChanged Properties changed.
 * @const_end
 */

/**
 * @const PhotonPeerLiteParameterCode
 * @desc The Lite protocol parameter codes. Primarily useful for diagnostics.
 * @member GameId The game ID parameter.
 * @member ActorNr The actor number parameter.
 * @member TargetActorNr The target actor number parameter.
 * @member ActorList The actor list parameter.
 * @member Properties The properties parameter.
 * @member Broadcast The broadcast flag parameter.
 * @member ActorProperties The actor properties parameter.
 * @member GameProperties The game properties parameter.
 * @member Cache The cache parameter.
 * @member ReceiverGroup The receiver group parameter.
 * @member Data The data parameter.
 * @member Code The code parameter.
 * @member Group The group parameter.
 * @member Remove The remove parameter.
 * @member Add The add parameter.
 * @const_end
 */

// MODULES

/**
 * @module peer
 * @title Peer & Network Simulation
 * @desc This module holds the QA network-simulation controls and the shared low-level peer constants used across the extension.
 *
 * [[WARNING: Network simulation is a QA/debug aid. It is not supported by the bundled SDK build and the getters report as disabled; treat these functions as no-ops on the shipping platforms.]]
 *
 * @section_func Network simulation
 * @desc Simulate poor network conditions for testing:
 * @ref photon_peer_network_sim_get_enabled
 * @ref photon_peer_network_sim_set_enabled
 * @ref photon_peer_network_sim_set_lag
 * @ref photon_peer_network_sim_set_jitter
 * @ref photon_peer_network_sim_set_packet_loss
 * @section_end
 *
 * @section_const Constants
 * @desc The Peer module defines the following shared constants:
 * @ref PhotonPeerState
 * @ref PhotonPeerConnectionProtocol
 * @ref PhotonPeerStatusCode
 * @ref PhotonPeerCoreErrorCode
 * @ref PhotonPeerLiteOperationCode
 * @ref PhotonPeerLiteEventCode
 * @ref PhotonPeerLiteParameterCode
 * @section_end
 *
 * @module_end
 */
