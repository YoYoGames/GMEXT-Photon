// ##### extgen :: Auto-generated file do not edit!! #####

// #####################################################################
// # Macros
// #####################################################################

// #####################################################################
// # Enums
// #####################################################################

// #####################################################################
// # Constructors
// #####################################################################

// #####################################################################
// # Codecs
// #####################################################################

// #####################################################################
// # Functions
// #####################################################################

/**
 * @param {Function} _callback
 * @returns {Bool} 
 */
function photon_init(_callback)
{
    static __dispatcher = __GMPhoton_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __photon_init(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/// @ignore
function __GMPhoton_get_decoders()
{
    static __decoders = [];
    return __decoders;
}
/// @ignore
function __GMPhoton_get_dispatcher()
{
    static __dispatcher = new __GMNativeFunctionDispatcher(__GMPhoton_invocation_handler, __GMPhoton_get_decoders());
    return __dispatcher;
}
