/**
 * @module home
 * @title Home
 * @desc The Photon extension wraps the ExitGames/Photon C++ SDK family for GameMaker, giving you real-time multiplayer, chat and voice through the Photon Cloud. It is split into the following subsystems, each with its own module of functions, structs and constants.
 *
 * [[NOTE: Before using any Photon feature you must supply the relevant Application ID. These are configured as extension options (${page.setup}) and read at runtime with ${function.extension_get_option_value}, so your App IDs stay out of source control.]]
 *
 * @section Guides
 * @desc These are the guides for the Photon extension:
 * @ref page.setup
 * @ref page.quick_start_guide
 * @section_end
 *
 * @section Management
 * @desc Each subsystem must be initialised and serviced independently. After connecting, you *must* call the matching `service` function every step so the client can send and receive:
 *
 *  * ${function.photon_realtime_service} :warning: REQUIRED while using Realtime
 *  * ${function.photon_chat_service} :warning: REQUIRED while using Chat
 *  * ${function.photon_voice_service} :warning: REQUIRED while using Voice
 * @section_end
 *
 * @section Modules
 * @desc The Photon API is grouped into the following modules:
 * @ref module.common
 * @ref module.realtime
 * @ref module.realtime_player_properties
 * @ref module.realtime_room_properties
 * @ref module.realtime_peer
 * @ref module.chat
 * @ref module.chat_peer
 * @ref module.voice
 * @ref module.peer
 * @section_end
 *
 * @module_end
 */
