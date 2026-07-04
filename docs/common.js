// FUNCTIONS

/**
 * @function photon_common_set_debug_level
 * @desc Sets the verbosity of the Photon SDK's internal debug output. Higher levels print more diagnostic information from the underlying client and are useful while developing, but should usually be lowered for release builds.
 *
 * @param {Constant.PhotonCommonDebugLevel} level The debug output level to apply.
 *
 * @returns {Bool} Whether the level was applied successfully.
 *
 * @example
 * ```gml
 * photon_common_set_debug_level(PhotonCommonDebugLevel.Warnings);
 * ```
 * The above code limits the SDK debug output to warnings and errors.
 * @function_end
 */

/**
 * @function photon_common_get_debug_level
 * @desc Returns the current Photon SDK debug output level, as set by ${function.photon_common_set_debug_level}.
 *
 * @returns {Constant.PhotonCommonDebugLevel} The current debug output level.
 *
 * @function_end
 */

/**
 * @function photon_common_get_serialization_protocol
 * @desc Returns the serialization protocol the client uses to encode data on the wire.
 *
 * @returns {Constant.PhotonCommonSerializationProtocol} The active serialization protocol.
 *
 * @function_end
 */

/**
 * @function photon_common_type_code_to_string
 * @desc Converts a Photon wire type code into a human-readable string. This is primarily a debugging aid when inspecting the raw types received from custom events or properties.
 *
 * @param {Constant.PhotonCommonTypeCode} type_code The type code to convert.
 *
 * @returns {String} A readable name for the type code.
 *
 * @example
 * ```gml
 * show_debug_message(photon_common_type_code_to_string(PhotonCommonTypeCode.Integer)); // "Integer"
 * ```
 * @function_end
 */

/**
 * @function photon_common_get_sdk_version
 * @desc Returns the version string of the underlying Photon C++ SDK bundled with the extension.
 *
 * @returns {String} The Photon SDK version.
 *
 * @function_end
 */

/**
 * @function photon_common_client_state_to_string
 * @desc Converts a client state value into a human-readable string. Pass a ${constant.PhotonRealtimeState} or ${constant.PhotonChatState} value depending on which client the state came from.
 *
 * @param {Real} state The client state value to convert.
 *
 * @returns {String} A readable name for the state.
 *
 * @function_end
 */

/**
 * @function photon_common_disconnect_cause_to_string
 * @desc Converts a disconnect cause value into a human-readable string. Pass a ${constant.PhotonRealtimeDisconnectCause} or ${constant.PhotonChatDisconnectCause} value depending on which client reported the disconnect.
 *
 * @param {Real} cause The disconnect cause value to convert.
 *
 * @returns {String} A readable name for the disconnect cause.
 *
 * @function_end
 */

// CONSTANTS

/**
 * @const PhotonCommonDebugLevel
 * @desc The Photon SDK debug output levels, used with ${function.photon_common_set_debug_level} and ${function.photon_common_get_debug_level}.
 * @member Off No debug output.
 * @member Errors Only errors.
 * @member Warnings Errors and warnings.
 * @member Info Errors, warnings and informational messages.
 * @member All All debug output, including verbose messages.
 * @const_end
 */

/**
 * @const PhotonCommonSerializationProtocol
 * @desc The serialization protocols the client can use to encode data on the wire, returned by ${function.photon_common_get_serialization_protocol}.
 * @member Protocol16 Photon serialization protocol 1.6.
 * @member Protocol18 Photon serialization protocol 1.8.
 * @const_end
 */

/**
 * @const PhotonCommonTypeCode
 * @desc The wire type codes Photon uses to tag serialized values. Returned in the readable form by ${function.photon_common_type_code_to_string}, and useful when interpreting values received from custom events and properties.
 * @member Byte An 8-bit unsigned integer.
 * @member Short A 16-bit signed integer.
 * @member Integer A 32-bit signed integer.
 * @member Long A 64-bit signed integer.
 * @member Float A 32-bit floating point value.
 * @member Double A 64-bit floating point value.
 * @member Boolean A boolean value.
 * @member String A string value.
 * @member Hashtable A Photon hashtable.
 * @member Dictionary A typed dictionary.
 * @member Object A generic object.
 * @member Array An array of typed values.
 * @member ByteArray An array of bytes.
 * @member PhotonCommand An internal Photon command.
 * @member Null A null value.
 * @member Custom A registered custom type.
 * @member Unknown An unknown type.
 * @member Invalid An invalid type.
 * @const_end
 */

/**
 * @const PhotonCommonInternalLogLevel
 * @desc The extension's own logging levels (distinct from the Photon SDK debug level). This corresponds to the extension's **Log Level** option.
 * @member Off No logging.
 * @member Fatal Only fatal errors.
 * @member Error Errors and above.
 * @member Warning Warnings and above.
 * @member Info Informational messages and above.
 * @member Debug Debug messages and above.
 * @member DebugVerbose All messages, including verbose debug output.
 * @const_end
 */

// MODULES

/**
 * @module common
 * @title Common
 * @desc The Common module holds functionality shared across the Photon subsystems: SDK debug output control, serialization info, and helpers for turning Photon's numeric state, cause and type codes into readable strings.
 *
 * @section_func Functions
 * @desc The Common module provides the following functions:
 * @ref photon_common_set_debug_level
 * @ref photon_common_get_debug_level
 * @ref photon_common_get_serialization_protocol
 * @ref photon_common_type_code_to_string
 * @ref photon_common_get_sdk_version
 * @ref photon_common_client_state_to_string
 * @ref photon_common_disconnect_cause_to_string
 * @section_end
 *
 * @section_const Constants
 * @desc The Common module defines the following constants:
 * @ref PhotonCommonDebugLevel
 * @ref PhotonCommonSerializationProtocol
 * @ref PhotonCommonTypeCode
 * @ref PhotonCommonInternalLogLevel
 * @section_end
 *
 * @module_end
 */
