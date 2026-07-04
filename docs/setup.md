# Setup

This guide covers installing the Photon extension and configuring it for your project.

## Getting a Photon Application ID

Photon is a cloud service. Before you can connect you need a free Photon account and one **Application ID** per product you use (Realtime/LoadBalancing, Chat and Voice each have their own App ID):

1. Create an account at the [Photon dashboard](https://dashboard.photonengine.com/).
2. Create an application for each product you need (a *Realtime* app, a *Chat* app and/or a *Voice* app).
3. Copy each application's App ID (a GUID such as `00000000-0000-0000-0000-000000000000`).

## Configuring the App IDs

The App IDs are **credentials** and must not be committed to source control. The extension exposes them as **extension options** so their values live in your local project settings only:

1. In the GameMaker IDE, select the **GMPhoton** extension in the Asset Browser.
2. Under **Application IDs**, fill in **Realtime App ID** and/or **Chat App ID**.

At runtime the demo reads them with ${function.extension_get_option_value}:

```gml
var _app_id = extension_get_option_value("GMPhoton", "appIdRealtime");
photon_realtime_connect(_app_id, "1.0", new PhotonRealtimeConnectOptions());
```

[[TIP: Because the values are stored in the (git-ignored) project options rather than in your scripts, each developer sets their own App IDs and nothing sensitive ends up in your repository.]]

## Other extension options

* **iOS SDK Path** (`sdkPathiOS`) — path to the vendored Photon iOS SDK, used by the build-step scripts to stage the static libraries when targeting iOS. The default points at the SDK bundled with the extension.
* **Log Level** (`logLevel`) — verbosity of the extension's own build/log output (`1`–`3`).

## Supported platforms

The Photon extension supports **Windows, macOS, Linux, Android and iOS**. On Windows, macOS and Linux the Photon SDK is linked statically into the extension library; on iOS the static libraries are staged into the project at build time (see **iOS SDK Path** above); on Android the native libraries are built from the bundled `AndroidSource`.

## Servicing the client

Photon dispatches incoming and outgoing traffic on the game thread. After you connect, call the matching `service` function **every step** for each subsystem you use — ${function.photon_realtime_service}, ${function.photon_chat_service} and ${function.photon_voice_service}. Without this the client will neither send nor receive.
