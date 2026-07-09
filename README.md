# GMEXT-Photon

Repository for GameMaker's Photon Extension

This repository was created with the intent of presenting users with the latest version available of the extension (even previous to marketplace updates) and also provide a way for the community to contribute with bug fixes and feature implementation.

This extension wraps the [Photon C++ SDK](https://www.photonengine.com/) family (Realtime/LoadBalancing, Chat and Voice), bringing real-time multiplayer, text chat and voice to your game through the Photon Cloud.

This extension will work on Windows, macOS, Linux, Android and iOS.

SOURCE CODE: `source/Photon_gml/extensions/GMPhoton/source/`

GAMEMAKER PROJECT: `source/Photon_gml/Photon.yyp`

After compilation the exported dll/dylib/so/aar files are automatically copied into the extension folder inside the included GameMaker project folder.

## Requirements

To use Photon you need a free [Photon account](https://dashboard.photonengine.com/) and an **Application ID** for each product you use (Realtime, Chat and/or Voice). These are configured as Extension Options rather than hard-coded, so they stay out of source control.

> [!IMPORTANT]
> Open the **GMPhoton** extension in the IDE and fill in the **Realtime App ID** and/or **Chat App ID** under Extension Options. See the [Setup guide](https://github.com/YoYoGames/GMEXT-Photon/wiki/setup) for details.

To compile the native bridge locally you will need the Photon C++ SDKs. They are **not included** in this repository due to third-party distribution restrictions — [download them from the Photon website](https://www.photonengine.com/sdks) and place them under `source/photon_sdk/` following this structure:

* Windows: `source/photon_sdk/Photon-Windows/`
* macOS: `source/photon_sdk/Photon-MacOSX/`
* Linux: `source/photon_sdk/Photon-Linux/`
* Android: `source/photon_sdk/Photon-AndroidNDK/`
* iOS: `source/photon_sdk/Photon-iOS/`

> [!IMPORTANT]
> The Photon SDKs cannot be redistributed. You must download them directly from Exit Games and agree to their terms before use.

> [!IMPORTANT]
> This extension requires Photon C++ SDK **v5.0.14.3**. Using a different SDK version is not supported and may not compile or behave correctly against the native bridge.

**Important**

The public API surface is defined in `source/Photon_gml/extensions/GMPhoton/source/spec.gmidl` and the GML wrappers, extension manifest entries, C++ bridge stubs and documentation stubs are generated from it via the **extgen** tool. Do not edit any generated file directly (`extensions/GMPhoton/source/code_gen/`, `docs/extgen_docs.js`); regenerate them from the spec instead.

## Documentation

* Check [the documentation](https://github.com/YoYoGames/GMEXT-Photon/wiki)

The online documentation is regularly updated to ensure it contains the most current information. For those who prefer a different format, we also offer a HTML version. This HTML is directly converted from the GitHub Wiki content, ensuring consistency, although it may follow slightly behind in updates.

We encourage users to refer primarily to the GitHub Wiki for the latest information and updates. The HTML version, included with the extension and within the demo project's data files, serves as a secondary, static reference.

Additionally, if you're contributing new features through PR (Pull Requests), we kindly ask that you also provide accompanying documentation for these features, to maintain the comprehensiveness and usefulness of our resources.
