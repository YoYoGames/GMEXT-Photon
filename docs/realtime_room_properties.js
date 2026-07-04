// FUNCTIONS

// --- Set / remove ---

/**
 * @function photon_realtime_room_properties_set_string
 * @desc Sets a string custom property on the current room and syncs it to everyone. Other clients are notified via ${function.photon_realtime_set_callback_room_properties_change}.
 * @param {String} key The property key.
 * @param {String} value The string value to set.
 * @returns {Bool} Whether the property was set.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_set_i32
 * @desc Sets a 32-bit integer custom property on the current room and syncs it to everyone.
 * @param {String} key The property key.
 * @param {Real} value The integer value to set.
 * @returns {Bool} Whether the property was set.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_set_f64
 * @desc Sets a 64-bit floating point custom property on the current room and syncs it to everyone.
 * @param {String} key The property key.
 * @param {Real} value The value to set.
 * @returns {Bool} Whether the property was set.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_set_bool
 * @desc Sets a boolean custom property on the current room and syncs it to everyone.
 * @param {String} key The property key.
 * @param {Bool} value The value to set.
 * @returns {Bool} Whether the property was set.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_remove
 * @desc Removes a custom property from the current room.
 * @param {String} key The property key to remove.
 * @returns {Bool} Whether the property was removed.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_clear
 * @desc Removes all custom properties from the current room.
 * @returns {Bool} Whether the properties were cleared.
 * @function_end
 */

// --- Query / get ---

/**
 * @function photon_realtime_room_properties_has
 * @desc Returns whether the current room has a custom property with the given key.
 * @param {String} key The property key.
 * @returns {Bool} Whether the property exists.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_get_string
 * @desc Returns a string custom property of the current room.
 * @param {String} key The property key.
 * @returns {String} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_get_i32
 * @desc Returns an integer custom property of the current room.
 * @param {String} key The property key.
 * @returns {Real} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_get_f64
 * @desc Returns a floating point custom property of the current room.
 * @param {String} key The property key.
 * @returns {Real} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_get_bool
 * @desc Returns a boolean custom property of the current room.
 * @param {String} key The property key.
 * @returns {Bool} The property value.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_to_string
 * @desc Returns a human-readable string of all the room's custom properties, useful for debugging.
 * @returns {String} A readable dump of the room properties.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_get_all
 * @desc Returns all of the room's custom properties as a GML struct.
 * @returns {Struct} A struct of all room custom properties.
 * @function_end
 */

// --- Compare-and-swap ---

/**
 * @function photon_realtime_room_properties_cas_string
 * @desc Atomically sets a string room property only if its current value equals the expected value (compare-and-swap). If the check fails on the server, ${function.photon_realtime_set_callback_properties_change_failed} fires. Returns `false` immediately if not in a room.
 * @param {String} key The property key.
 * @param {String} expected_value The value the property must currently have.
 * @param {String} new_value The value to set if the check passes.
 * @returns {Bool} Whether the request was sent.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_cas_i32
 * @desc Atomically sets an integer room property only if its current value equals the expected value (compare-and-swap). If the check fails on the server, ${function.photon_realtime_set_callback_properties_change_failed} fires. Returns `false` immediately if not in a room.
 * @param {String} key The property key.
 * @param {Real} expected_value The value the property must currently have.
 * @param {Real} new_value The value to set if the check passes.
 * @returns {Bool} Whether the request was sent.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_cas_f64
 * @desc Atomically sets a floating point room property only if its current value equals the expected value (compare-and-swap). If the check fails on the server, ${function.photon_realtime_set_callback_properties_change_failed} fires. Returns `false` immediately if not in a room.
 * @param {String} key The property key.
 * @param {Real} expected_value The value the property must currently have.
 * @param {Real} new_value The value to set if the check passes.
 * @returns {Bool} Whether the request was sent.
 * @function_end
 */

/**
 * @function photon_realtime_room_properties_cas_bool
 * @desc Atomically sets a boolean room property only if its current value equals the expected value (compare-and-swap). If the check fails on the server, ${function.photon_realtime_set_callback_properties_change_failed} fires. Returns `false` immediately if not in a room.
 * @param {String} key The property key.
 * @param {Bool} expected_value The value the property must currently have.
 * @param {Bool} new_value The value to set if the check passes.
 * @returns {Bool} Whether the request was sent.
 * @function_end
 */

// MODULES

/**
 * @module realtime_room_properties
 * @title Realtime Room Properties
 * @desc Room custom properties are shared key/value data attached to the current room and synced to all players. Any player can set them (subject to the room's rules), read them, and use compare-and-swap for safe concurrent updates. Changes are delivered to ${function.photon_realtime_set_callback_room_properties_change}.
 *
 * @section_func Set & remove
 * @desc Set or remove room custom properties:
 * @ref photon_realtime_room_properties_set_string
 * @ref photon_realtime_room_properties_set_i32
 * @ref photon_realtime_room_properties_set_f64
 * @ref photon_realtime_room_properties_set_bool
 * @ref photon_realtime_room_properties_remove
 * @ref photon_realtime_room_properties_clear
 * @section_end
 *
 * @section_func Query & get
 * @desc Read room custom properties:
 * @ref photon_realtime_room_properties_has
 * @ref photon_realtime_room_properties_get_string
 * @ref photon_realtime_room_properties_get_i32
 * @ref photon_realtime_room_properties_get_f64
 * @ref photon_realtime_room_properties_get_bool
 * @ref photon_realtime_room_properties_to_string
 * @ref photon_realtime_room_properties_get_all
 * @section_end
 *
 * @section_func Compare-and-swap
 * @desc Atomically update a property only if it still holds an expected value:
 * @ref photon_realtime_room_properties_cas_string
 * @ref photon_realtime_room_properties_cas_i32
 * @ref photon_realtime_room_properties_cas_f64
 * @ref photon_realtime_room_properties_cas_bool
 * @section_end
 *
 * @module_end
 */
