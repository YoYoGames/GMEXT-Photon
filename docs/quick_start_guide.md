# Quick Start Guide

This guide walks through a minimal Realtime connection: initialise the client, register callbacks, connect, and join a room. It assumes you have already configured your **Realtime App ID** (see ${page.setup}).

## 1. Initialise and connect

In the **Create** event of a controller object, register the callbacks you care about, then connect. `photon_realtime_connect` takes the App ID, an application version string of your choosing (used to keep incompatible client builds apart), and an optional ${struct.PhotonRealtimeConnectOptions}.

```gml
/// Create Event
photon_realtime_init();

photon_realtime_set_callback_connected(function(_error_code, _error_string, _region) {
    if (_error_code == PhotonRealtimeAppErrorCode.Ok) {
        show_debug_message($"Connected to region {_region}");
        photon_realtime_operation_join_or_create_room("my_room", new PhotonRealtimeRoomOptions(), {});
    } else {
        show_debug_message($"Connect failed: {_error_string}");
    }
});

photon_realtime_set_callback_disconnected(function() {
    show_debug_message("Disconnected");
});

var _app_id = extension_get_option_value("GMPhoton", "appIdRealtime");
photon_realtime_connect(_app_id, "1.0", new PhotonRealtimeConnectOptions());
```

## 2. Service the client every step

Photon only sends and receives when you service it. Call ${function.photon_realtime_service} once per step:

```gml
/// Step Event
photon_realtime_service();
```

## 3. Send and receive events

Once in a room, broadcast events to the other players and read them back. See the ${module.realtime} module for the full event, room and matchmaking API, ${module.realtime_room_properties} and ${module.realtime_player_properties} for shared state, and ${module.chat} / ${module.voice} for text chat and voice.

## 4. Shut down

When you are done, disconnect and shut the client down to release resources:

```gml
photon_realtime_disconnect();
photon_realtime_shutdown();
```
