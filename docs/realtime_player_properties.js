// FUNCTIONS

// --- Local player properties (get/set the local player's custom properties) ---

/**
 * @function photon_realtime_player_properties_set_local_string
 * @desc Sets a string custom property on the local player and syncs it to the room. Other clients are notified via ${function.photon_realtime_set_callback_player_properties_change}.
 * @param {String} key The property key.
 * @param {String} value The string value to set.
 * @returns {Bool} Whether the property was set.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_set_local_i32
 * @desc Sets a 32-bit integer custom property on the local player and syncs it to the room.
 * @param {String} key The property key.
 * @param {Real} value The integer value to set.
 * @returns {Bool} Whether the property was set.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_set_local_f64
 * @desc Sets a 64-bit floating point custom property on the local player and syncs it to the room.
 * @param {String} key The property key.
 * @param {Real} value The value to set.
 * @returns {Bool} Whether the property was set.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_set_local_bool
 * @desc Sets a boolean custom property on the local player and syncs it to the room.
 * @param {String} key The property key.
 * @param {Bool} value The value to set.
 * @returns {Bool} Whether the property was set.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_remove_local
 * @desc Removes a custom property from the local player.
 * @param {String} key The property key to remove.
 * @returns {Bool} Whether the property was removed.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_clear_local
 * @desc Removes all custom properties from the local player.
 * @returns {Bool} Whether the properties were cleared.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_has_local
 * @desc Returns whether the local player has a custom property with the given key.
 * @param {String} key The property key.
 * @returns {Bool} Whether the property exists.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_local_string
 * @desc Returns a string custom property of the local player.
 * @param {String} key The property key.
 * @returns {String} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_local_i32
 * @desc Returns an integer custom property of the local player.
 * @param {String} key The property key.
 * @returns {Real} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_local_f64
 * @desc Returns a floating point custom property of the local player.
 * @param {String} key The property key.
 * @returns {Real} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_local_bool
 * @desc Returns a boolean custom property of the local player.
 * @param {String} key The property key.
 * @returns {Bool} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_to_string_local
 * @desc Returns a human-readable string of all the local player's custom properties, useful for debugging.
 * @returns {String} A readable dump of the local properties.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_local_all
 * @desc Returns all of the local player's custom properties as a GML struct.
 * @returns {Struct} A struct of all local custom properties.
 * @function_end
 */

// --- Remote player properties (read cached properties of other players) ---

/**
 * @function photon_realtime_player_properties_has_remote
 * @desc Returns whether the given player has a cached custom property with the given key.
 * @param {Real} player_number The player number to query.
 * @param {String} key The property key.
 * @returns {Bool} Whether the property exists.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_remote_string
 * @desc Returns a cached string custom property of the given player.
 * @param {Real} player_number The player number to query.
 * @param {String} key The property key.
 * @returns {String} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_remote_i32
 * @desc Returns a cached integer custom property of the given player.
 * @param {Real} player_number The player number to query.
 * @param {String} key The property key.
 * @returns {Real} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_remote_f64
 * @desc Returns a cached floating point custom property of the given player.
 * @param {Real} player_number The player number to query.
 * @param {String} key The property key.
 * @returns {Real} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_remote_bool
 * @desc Returns a cached boolean custom property of the given player.
 * @param {Real} player_number The player number to query.
 * @param {String} key The property key.
 * @returns {Bool} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_to_string_remote
 * @desc Returns a human-readable string of all the given player's cached custom properties, useful for debugging.
 * @param {Real} player_number The player number to query.
 * @returns {String} A readable dump of the player's properties.
 * @function_end
 */

/**
 * @function photon_realtime_player_properties_get_remote_all
 * @desc Returns all of the given player's cached custom properties as a GML struct.
 * @param {Real} player_number The player number to query.
 * @returns {Struct} A struct of all the player's custom properties.
 * @function_end
 */

// MODULES

/**
 * @module realtime_player_properties
 * @title Realtime Player Properties
 * @desc Player custom properties are per-player key/value data synced across the room. Set them on the **local** player (they are broadcast to everyone), and read the **remote** cached values of other players. Changes to any player's properties are delivered to ${function.photon_realtime_set_callback_player_properties_change}.
 *
 * @section_func Local player properties
 * @desc Get and set the local player's custom properties:
 * @ref photon_realtime_player_properties_set_local_string
 * @ref photon_realtime_player_properties_set_local_i32
 * @ref photon_realtime_player_properties_set_local_f64
 * @ref photon_realtime_player_properties_set_local_bool
 * @ref photon_realtime_player_properties_remove_local
 * @ref photon_realtime_player_properties_clear_local
 * @ref photon_realtime_player_properties_has_local
 * @ref photon_realtime_player_properties_get_local_string
 * @ref photon_realtime_player_properties_get_local_i32
 * @ref photon_realtime_player_properties_get_local_f64
 * @ref photon_realtime_player_properties_get_local_bool
 * @ref photon_realtime_player_properties_to_string_local
 * @ref photon_realtime_player_properties_get_local_all
 * @section_end
 *
 * @section_func Remote player properties
 * @desc Read the cached custom properties of other players:
 * @ref photon_realtime_player_properties_has_remote
 * @ref photon_realtime_player_properties_get_remote_string
 * @ref photon_realtime_player_properties_get_remote_i32
 * @ref photon_realtime_player_properties_get_remote_f64
 * @ref photon_realtime_player_properties_get_remote_bool
 * @ref photon_realtime_player_properties_to_string_remote
 * @ref photon_realtime_player_properties_get_remote_all
 * @section_end
 *
 * @module_end
 */
