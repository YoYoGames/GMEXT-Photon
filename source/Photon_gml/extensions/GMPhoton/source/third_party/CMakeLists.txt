cmake_minimum_required(VERSION 3.18)

# -----------------------------------------------------------------------------
# Core bag-of-usage-requirements target
# -----------------------------------------------------------------------------
add_library(ext_third_party INTERFACE)

# -----------------------------------------------------------------------------
# Per-platform SDK root
#
# Each platform requires its own Photon C++ SDK download, placed under:
#   photon_sdk/
#     Photon-Windows/                             (Windows)
#     photon-macosx/                              (macOS)
#     photon-linux/                                (Linux)
#     photon-androidndk/                           (Android)
#     photon-ios/                                  (iOS / tvOS)
#     Photon-PS4/                                  (PS4 / ORBIS)
#     Photon-PS5/                                  (PS5 / Prospero)
#     Photon-NintendoSwitch/NintendoSDK_20_5_21/   (Switch / NX64 — override SDK_ROOT
#                                                    to point at NintendoSDK_21_4_2 instead)
#
# Override at configure time with: -DSDK_ROOT=<path>
#
# EXTGEN_IS_SWITCH / EXTGEN_IS_PS4 / EXTGEN_IS_PS5 are computed in the parent
# CMakeLists.txt (before add_subdirectory(third_party)) and inherited here.
# They must be checked before WIN32: Switch builds run through the Visual
# Studio generator with CMAKE_SYSTEM_NAME left as "Windows", so WIN32 is TRUE
# there too.
# -----------------------------------------------------------------------------
if(EXTGEN_IS_SWITCH)
    set(_SDK_DEFAULT "${CMAKE_CURRENT_LIST_DIR}/../../../../../photon_sdk/Photon-NintendoSwitch/NintendoSDK_20_5_21")
elseif(EXTGEN_IS_PS4)
    set(_SDK_DEFAULT "${CMAKE_CURRENT_LIST_DIR}/../../../../../photon_sdk/Photon-PS4")
elseif(EXTGEN_IS_PS5)
    set(_SDK_DEFAULT "${CMAKE_CURRENT_LIST_DIR}/../../../../../photon_sdk/Photon-PS5")
elseif(WIN32)
    set(_SDK_DEFAULT "${CMAKE_CURRENT_LIST_DIR}/../../../../../photon_sdk/Photon-Windows")
elseif(ANDROID)
    set(_SDK_DEFAULT "${CMAKE_CURRENT_LIST_DIR}/../../../../../photon_sdk/photon-androidndk")
elseif(APPLE AND CMAKE_OSX_SYSROOT MATCHES "iphone|appletv")
    set(_SDK_DEFAULT "${CMAKE_CURRENT_LIST_DIR}/../../../../../photon_sdk/photon-ios")
elseif(APPLE)
    set(_SDK_DEFAULT "${CMAKE_CURRENT_LIST_DIR}/../../../../../photon_sdk/photon-macosx")
elseif(UNIX)
    set(_SDK_DEFAULT "${CMAKE_CURRENT_LIST_DIR}/../../../../../photon_sdk/photon-linux")
else()
    set(_SDK_DEFAULT "")
endif()

set(SDK_ROOT "${_SDK_DEFAULT}" CACHE PATH "Path to the Photon C++ SDK root for the current platform")
get_filename_component(SDK_ROOT "${SDK_ROOT}" ABSOLUTE)
message(STATUS "[photon] SDK_ROOT = ${SDK_ROOT}")

# -----------------------------------------------------------------------------
# Debug / Release tag
#
# Windows (MSVC): driven by CMAKE_MSVC_RUNTIME_LIBRARY set in the preset.
# Other platforms: driven by CMAKE_BUILD_TYPE.
# -----------------------------------------------------------------------------
if(MSVC)
    if(CMAKE_MSVC_RUNTIME_LIBRARY MATCHES "Debug")
        set(_CFG "debug")
    else()
        set(_CFG "release")
    endif()
else()
    string(TOLOWER "${CMAKE_BUILD_TYPE}" _build_type_lc)
    if(_build_type_lc STREQUAL "debug")
        set(_CFG "debug")
    else()
        set(_CFG "release")
    endif()
endif()

# Capitalised variant used by Linux filenames (e.g. libCommonRelease64.a)
string(SUBSTRING "${_CFG}" 0 1 _first)
string(TOUPPER "${_first}" _first)
string(SUBSTRING "${_CFG}" 1 -1 _rest)
set(_CFG_CAP "${_first}${_rest}")   # "Debug" or "Release"

message(STATUS "[photon] Build config: ${_CFG}")

# -----------------------------------------------------------------------------
# Include directories — same layout across all platforms
# -----------------------------------------------------------------------------
target_include_directories(ext_third_party INTERFACE
    "${SDK_ROOT}"
    "${SDK_ROOT}/Common-cpp/inc"
    "${SDK_ROOT}/Photon-cpp/inc"
    "${SDK_ROOT}/LoadBalancing-cpp/inc"
    "${SDK_ROOT}/Chat-cpp/inc"
    "${SDK_ROOT}/PhotonVoice-cpp/inc"
    "${SDK_ROOT}/PhotonVoice-cpp/opus/include"
)

target_compile_definitions(ext_third_party INTERFACE
    HAVE_PHOTON_REALTIME=1
    HAVE_PHOTON_CHAT=1
    HAVE_PHOTON_VOICE=1
)

# =============================================================================
# Nintendo Switch (NX64)
# Layout: {Module}-cpp/lib/lib{Module}-cpp_{cfg}_NX64.a
# =============================================================================
if(EXTGEN_IS_SWITCH)

    set(_TAG "${_CFG}_NX64")

    set(PHOTON_COMMON_LIB        "${SDK_ROOT}/Common-cpp/lib/libCommon-cpp_${_TAG}.a"           CACHE FILEPATH "Common-cpp library")
    set(PHOTON_PHOTON_LIB        "${SDK_ROOT}/Photon-cpp/lib/libPhoton-cpp_${_TAG}.a"           CACHE FILEPATH "Photon-cpp library")
    set(PHOTON_LOADBALANCING_LIB "${SDK_ROOT}/LoadBalancing-cpp/lib/libLoadBalancing-cpp_${_TAG}.a" CACHE FILEPATH "LoadBalancing-cpp library")
    set(PHOTON_CHAT_LIB          "${SDK_ROOT}/Chat-cpp/lib/libChat-cpp_${_TAG}.a"               CACHE FILEPATH "Chat-cpp library")
    set(PHOTON_VOICE_LIB         "${SDK_ROOT}/PhotonVoice-cpp/lib/libPhotonVoice-cpp_${_TAG}.a" CACHE FILEPATH "PhotonVoice-cpp library")
    set(PHOTON_OPUS_LIB          "${SDK_ROOT}/PhotonVoice-cpp/opus/switch/switch/lib/libopus_egpv_${_TAG}.a" CACHE FILEPATH "Opus library")

    foreach(_lib PHOTON_COMMON_LIB PHOTON_PHOTON_LIB PHOTON_LOADBALANCING_LIB
                 PHOTON_CHAT_LIB PHOTON_VOICE_LIB PHOTON_OPUS_LIB)
        if(NOT EXISTS "${${_lib}}")
            message(FATAL_ERROR "[photon] Missing library: ${${_lib}}\n"
                "  Set -D${_lib}=<path> or point -DSDK_ROOT= at the correct SDK folder.")
        endif()
    endforeach()

    target_link_libraries(ext_third_party INTERFACE
        "${PHOTON_COMMON_LIB}"
        "${PHOTON_PHOTON_LIB}"
        "${PHOTON_LOADBALANCING_LIB}"
        "${PHOTON_CHAT_LIB}"
        "${PHOTON_VOICE_LIB}"
        "${PHOTON_OPUS_LIB}"
    )

    # Photon's Switch build also needs the Nintendo SDK's own websocket/TLS
    # libraries — these come from the Nintendo SDK itself, not from photon_sdk/,
    # and are resolved via the NintendoSdkLibSuffix MSBuild macro imported by
    # Directory.Build.props. Verified against the 'release|NX64' ItemDefinitionGroup
    # in photon_sdk/Photon-NintendoSwitch/NintendoSDK_20_5_21/Demos/demo_loadBalancing
    # (the real hardware/lld config group — a separate, older 'release|x64' group in
    # the same file also lists libz, but NX64/lld does not need it, so it's omitted).
    # "-l:" (exact filename, GNU/lld syntax) so CMake passes these through
    # unmodified instead of guessing a ".lib" suffix — bare names produced
    # "-llibnn_websocket.a.lib" and failed with "unable to find library".
    target_link_libraries(ext_third_party INTERFACE
        "-l:libnn_websocket$(NintendoSdkLibSuffix)"
        "-l:libopenssl$(NintendoSdkLibSuffix)"
    )

# =============================================================================
# PS4 (ORBIS)
# Layout: {Module}-cpp/lib/lib{Module}-cpp_{cfg}_ps4_ORBIS.a
# =============================================================================
elseif(EXTGEN_IS_PS4)

    set(_TAG "${_CFG}_ps4_ORBIS")

    set(PHOTON_COMMON_LIB        "${SDK_ROOT}/Common-cpp/lib/libCommon-cpp_${_TAG}.a"           CACHE FILEPATH "Common-cpp library")
    set(PHOTON_PHOTON_LIB        "${SDK_ROOT}/Photon-cpp/lib/libPhoton-cpp_${_TAG}.a"           CACHE FILEPATH "Photon-cpp library")
    set(PHOTON_LOADBALANCING_LIB "${SDK_ROOT}/LoadBalancing-cpp/lib/libLoadBalancing-cpp_${_TAG}.a" CACHE FILEPATH "LoadBalancing-cpp library")
    set(PHOTON_CHAT_LIB          "${SDK_ROOT}/Chat-cpp/lib/libChat-cpp_${_TAG}.a"               CACHE FILEPATH "Chat-cpp library")
    set(PHOTON_VOICE_LIB         "${SDK_ROOT}/PhotonVoice-cpp/lib/libPhotonVoice-cpp_${_TAG}.a" CACHE FILEPATH "PhotonVoice-cpp library")
    set(PHOTON_OPUS_LIB          "${SDK_ROOT}/PhotonVoice-cpp/opus/ps4/ps4/lib/libopus_egpv_${_TAG}.a" CACHE FILEPATH "Opus library")
    set(PHOTON_CRYPTO_LIB        "${SDK_ROOT}/3rdparty/lib/ps4/libcrypto_${_TAG}.a"             CACHE FILEPATH "Photon bundled OpenSSL crypto")

    foreach(_lib PHOTON_COMMON_LIB PHOTON_PHOTON_LIB PHOTON_LOADBALANCING_LIB
                 PHOTON_CHAT_LIB PHOTON_VOICE_LIB PHOTON_OPUS_LIB PHOTON_CRYPTO_LIB)
        if(NOT EXISTS "${${_lib}}")
            message(FATAL_ERROR "[photon] Missing library: ${${_lib}}\n"
                "  Set -D${_lib}=<path> or point -DSDK_ROOT= at the correct SDK folder.")
        endif()
    endforeach()

    target_link_libraries(ext_third_party INTERFACE
        "${PHOTON_COMMON_LIB}"
        "${PHOTON_PHOTON_LIB}"
        "${PHOTON_LOADBALANCING_LIB}"
        "${PHOTON_CHAT_LIB}"
        "${PHOTON_VOICE_LIB}"
        "${PHOTON_OPUS_LIB}"
        "${PHOTON_CRYPTO_LIB}"
    )

    # The ORBIS platform toolset does not auto-link the Sce* system modules
    # Common/Photon/LoadBalancing/Chat-cpp need (character-set conversion,
    # sockets, TLS, HTTP/2, sysmodule loading, user service, PSN auth).
    # This list is the bundled demo's AdditionalDependencies
    # (photon_sdk/Photon-PS4/Demos/demo_loadBalancing) with the UI/graphics-only
    # entries dropped (SceFont/SceFontFt, SceGnm/SceGnmDriver/SceGpuAddress,
    # SceImeDialog, ScePad, SceVideoOut, SceDbgEnC) — confirmed against the PS5
    # demo, which needs the same networking subset without any graphics libs.
    # Raw "-l" flags (not bare names) so CMake passes them through unmodified
    # instead of guessing a ".lib" suffix for this non-standard VS platform.
    target_link_libraries(ext_third_party INTERFACE
        "-lSceCes"
        "-lSceCesCs_stub_weak"
        "-lSceNet_stub_weak"
        "-lSceNetCtl_stub_weak"
        "-lScePosix_stub_weak"
        "-lSceSysmodule_stub_weak"
        "-lSceUserService_stub_weak"
        "-lSceNpAuth_stub_weak"
        "-lSceHttp2_stub_weak"
        "-lSceSsl_stub_weak"
    )

# =============================================================================
# PS5 (Prospero)
# Layout: {Module}-cpp/lib/lib{Module}-cpp_{cfg}_ps5_Prospero.a
# =============================================================================
elseif(EXTGEN_IS_PS5)

    set(_TAG "${_CFG}_ps5_Prospero")

    set(PHOTON_COMMON_LIB        "${SDK_ROOT}/Common-cpp/lib/libCommon-cpp_${_TAG}.a"           CACHE FILEPATH "Common-cpp library")
    set(PHOTON_PHOTON_LIB        "${SDK_ROOT}/Photon-cpp/lib/libPhoton-cpp_${_TAG}.a"           CACHE FILEPATH "Photon-cpp library")
    set(PHOTON_LOADBALANCING_LIB "${SDK_ROOT}/LoadBalancing-cpp/lib/libLoadBalancing-cpp_${_TAG}.a" CACHE FILEPATH "LoadBalancing-cpp library")
    set(PHOTON_CHAT_LIB          "${SDK_ROOT}/Chat-cpp/lib/libChat-cpp_${_TAG}.a"               CACHE FILEPATH "Chat-cpp library")
    set(PHOTON_VOICE_LIB         "${SDK_ROOT}/PhotonVoice-cpp/lib/libPhotonVoice-cpp_${_TAG}.a" CACHE FILEPATH "PhotonVoice-cpp library")
    set(PHOTON_OPUS_LIB          "${SDK_ROOT}/PhotonVoice-cpp/opus/ps5/ps5/lib/libopus_egpv_${_TAG}.a" CACHE FILEPATH "Opus library")
    set(PHOTON_CRYPTO_LIB        "${SDK_ROOT}/3rdparty/lib/ps5/libcrypto_${_TAG}.a"             CACHE FILEPATH "Photon bundled OpenSSL crypto")

    foreach(_lib PHOTON_COMMON_LIB PHOTON_PHOTON_LIB PHOTON_LOADBALANCING_LIB
                 PHOTON_CHAT_LIB PHOTON_VOICE_LIB PHOTON_OPUS_LIB PHOTON_CRYPTO_LIB)
        if(NOT EXISTS "${${_lib}}")
            message(FATAL_ERROR "[photon] Missing library: ${${_lib}}\n"
                "  Set -D${_lib}=<path> or point -DSDK_ROOT= at the correct SDK folder.")
        endif()
    endforeach()

    target_link_libraries(ext_third_party INTERFACE
        "${PHOTON_COMMON_LIB}"
        "${PHOTON_PHOTON_LIB}"
        "${PHOTON_LOADBALANCING_LIB}"
        "${PHOTON_CHAT_LIB}"
        "${PHOTON_VOICE_LIB}"
        "${PHOTON_OPUS_LIB}"
        "${PHOTON_CRYPTO_LIB}"
    )

    # Same reasoning as PS4 above. This exact list is the PS5 demo's own
    # AdditionalDependencies (photon_sdk/Photon-PS5/Demos/demo_loadBalancing),
    # which already excludes graphics/UI libs — nothing to trim here.
    target_link_libraries(ext_third_party INTERFACE
        "-lSceCes"
        "-lSceCesCs_stub_weak"
        "-lSceNet_stub_weak"
        "-lSceNetCtl_stub_weak"
        "-lScePosix_stub_weak"
        "-lSceSysmodule_stub_weak"
        "-lSceUserService_stub_weak"
        "-lSceNpAuth_stub_weak"
        "-lSceHttp2_stub_weak"
        "-lSceSsl_stub_weak"
    )

# =============================================================================
# WINDOWS
# Layout: {Module}-cpp/lib/{Module}-cpp_vc17_{cfg}_windows_md_x64.lib
# =============================================================================
elseif(WIN32)

    set(_TAG "vc17_${_CFG}_windows_md_x64")

    set(PHOTON_COMMON_LIB        "${SDK_ROOT}/Common-cpp/lib/Common-cpp_${_TAG}.lib"                       CACHE FILEPATH "Common-cpp library")
    set(PHOTON_PHOTON_LIB        "${SDK_ROOT}/Photon-cpp/lib/Photon-cpp_${_TAG}.lib"                       CACHE FILEPATH "Photon-cpp library")
    set(PHOTON_LOADBALANCING_LIB "${SDK_ROOT}/LoadBalancing-cpp/lib/LoadBalancing-cpp_${_TAG}.lib"         CACHE FILEPATH "LoadBalancing-cpp library")
    set(PHOTON_CHAT_LIB          "${SDK_ROOT}/Chat-cpp/lib/Chat-cpp_${_TAG}.lib"                           CACHE FILEPATH "Chat-cpp library")
    set(PHOTON_VOICE_LIB         "${SDK_ROOT}/PhotonVoice-cpp/lib/PhotonVoice-cpp_${_TAG}.lib"             CACHE FILEPATH "PhotonVoice-cpp library")
    set(PHOTON_OPUS_LIB          "${SDK_ROOT}/PhotonVoice-cpp/opus/lib/opus_egpv_${_TAG}.lib"              CACHE FILEPATH "Opus library")

    foreach(_lib PHOTON_COMMON_LIB PHOTON_PHOTON_LIB PHOTON_LOADBALANCING_LIB
                 PHOTON_CHAT_LIB PHOTON_VOICE_LIB PHOTON_OPUS_LIB)
        if(NOT EXISTS "${${_lib}}")
            message(FATAL_ERROR "[photon] Missing library: ${${_lib}}\n"
                "  Set -D${_lib}=<path> or point -DSDK_ROOT= at the correct SDK folder.")
        endif()
    endforeach()

    target_link_libraries(ext_third_party INTERFACE
        "${PHOTON_COMMON_LIB}"
        "${PHOTON_PHOTON_LIB}"
        "${PHOTON_LOADBALANCING_LIB}"
        "${PHOTON_CHAT_LIB}"
        "${PHOTON_VOICE_LIB}"
        "${PHOTON_OPUS_LIB}"
    )

# =============================================================================
# ANDROID
# Layout: {Module}-cpp/lib/lib{module}-cpp-static_{cfg}_android_{ABI}.a
# =============================================================================
elseif(ANDROID)

    if(NOT DEFINED CMAKE_ANDROID_ARCH_ABI)
        message(FATAL_ERROR "[photon] CMAKE_ANDROID_ARCH_ABI is not set — use the Android NDK toolchain file.")
    endif()

    set(_TAG "${_CFG}_android_${CMAKE_ANDROID_ARCH_ABI}")

    set(PHOTON_COMMON_LIB        "${SDK_ROOT}/Common-cpp/lib/common-cpp-prebuilt/libcommon-cpp-static_${_TAG}.a"                 CACHE FILEPATH "Common-cpp library")
    set(PHOTON_PHOTON_LIB        "${SDK_ROOT}/Photon-cpp/lib/photon-cpp-prebuilt/libphoton-cpp-static_${_TAG}.a"                 CACHE FILEPATH "Photon-cpp library")
    set(PHOTON_LOADBALANCING_LIB "${SDK_ROOT}/LoadBalancing-cpp/lib/loadbalancing-cpp-prebuilt/libloadbalancing-cpp-static_${_TAG}.a" CACHE FILEPATH "LoadBalancing-cpp library")
    set(PHOTON_CHAT_LIB          "${SDK_ROOT}/Chat-cpp/lib/chat-cpp-prebuilt/libchat-cpp-static_${_TAG}.a"                      CACHE FILEPATH "Chat-cpp library")
    set(PHOTON_VOICE_LIB         "${SDK_ROOT}/PhotonVoice-cpp/lib/photonvoice-cpp-prebuilt/libphotonvoice-cpp-static_${_TAG}.a" CACHE FILEPATH "PhotonVoice-cpp library")
    set(PHOTON_OPUS_LIB          "${SDK_ROOT}/PhotonVoice-cpp/opus/lib/opus_egpv/libopus_egpv_${_TAG}.a"                        CACHE FILEPATH "Opus library")
    set(PHOTON_WEBSOCKETS_LIB    "${SDK_ROOT}/3rdparty/lib/android/libwebsockets_${_TAG}.a"                                     CACHE FILEPATH "Photon bundled libwebsockets")
    set(PHOTON_SSL_LIB           "${SDK_ROOT}/3rdparty/lib/android/libssl_${_TAG}.a"                                            CACHE FILEPATH "Photon bundled OpenSSL ssl")
    set(PHOTON_CRYPTO_LIB        "${SDK_ROOT}/3rdparty/lib/android/libcrypto_${_TAG}.a"                                         CACHE FILEPATH "Photon bundled OpenSSL crypto")

    foreach(_lib PHOTON_COMMON_LIB PHOTON_PHOTON_LIB PHOTON_LOADBALANCING_LIB
                 PHOTON_CHAT_LIB PHOTON_VOICE_LIB PHOTON_OPUS_LIB
                 PHOTON_WEBSOCKETS_LIB PHOTON_SSL_LIB PHOTON_CRYPTO_LIB)
        if(NOT EXISTS "${${_lib}}")
            message(FATAL_ERROR "[photon] Missing library: ${${_lib}}\n"
                "  Set -D${_lib}=<path> or point -DSDK_ROOT= at the correct SDK folder.")
        endif()
    endforeach()

    target_link_libraries(ext_third_party INTERFACE
        "${PHOTON_COMMON_LIB}"
        "${PHOTON_PHOTON_LIB}"
        "${PHOTON_LOADBALANCING_LIB}"
        "${PHOTON_CHAT_LIB}"
        "${PHOTON_VOICE_LIB}"
        "${PHOTON_OPUS_LIB}"
        # Dependency order matters: libssl depends on libcrypto.
        "${PHOTON_WEBSOCKETS_LIB}"
        "${PHOTON_SSL_LIB}"
        "${PHOTON_CRYPTO_LIB}"
        log
        android
    )

# =============================================================================
# iOS / tvOS
# Layout: {Module}-cpp/lib/lib{Module}-cpp_{cfg}_{variant}.a
# Variants: iphoneos | iphonesimulator
# =============================================================================
elseif(APPLE AND CMAKE_OSX_SYSROOT MATCHES "iphone|appletv")

    if(CMAKE_OSX_SYSROOT MATCHES "iphonesimulator")
        set(_IOS_VARIANT "iphonesimulator")
    else()
        set(_IOS_VARIANT "iphoneos")
    endif()

    set(_TAG "${_CFG}_${_IOS_VARIANT}")

    set(PHOTON_COMMON_LIB        "${SDK_ROOT}/Common-cpp/lib/libCommon-cpp_${_TAG}.a"           CACHE FILEPATH "Common-cpp library")
    set(PHOTON_PHOTON_LIB        "${SDK_ROOT}/Photon-cpp/lib/libPhoton-cpp_${_TAG}.a"           CACHE FILEPATH "Photon-cpp library")
    set(PHOTON_LOADBALANCING_LIB "${SDK_ROOT}/LoadBalancing-cpp/lib/libLoadBalancing-cpp_${_TAG}.a" CACHE FILEPATH "LoadBalancing-cpp library")
    set(PHOTON_CHAT_LIB          "${SDK_ROOT}/Chat-cpp/lib/libChat-cpp_${_TAG}.a"               CACHE FILEPATH "Chat-cpp library")
    set(PHOTON_VOICE_LIB         "${SDK_ROOT}/PhotonVoice-cpp/lib/libPhotonVoice-cpp_${_TAG}.a" CACHE FILEPATH "PhotonVoice-cpp library")
    set(PHOTON_OPUS_LIB          "${SDK_ROOT}/PhotonVoice-cpp/opus/lib/libopus_egpv_${_TAG}.a"  CACHE FILEPATH "Opus library")

    foreach(_lib PHOTON_COMMON_LIB PHOTON_PHOTON_LIB PHOTON_LOADBALANCING_LIB
                 PHOTON_CHAT_LIB PHOTON_VOICE_LIB PHOTON_OPUS_LIB)
        if(NOT EXISTS "${${_lib}}")
            message(FATAL_ERROR "[photon] Missing library: ${${_lib}}\n"
                "  Set -D${_lib}=<path> or point -DSDK_ROOT= at the correct SDK folder.")
        endif()
    endforeach()

    target_link_libraries(ext_third_party INTERFACE
        "${PHOTON_COMMON_LIB}"
        "${PHOTON_PHOTON_LIB}"
        "${PHOTON_LOADBALANCING_LIB}"
        "${PHOTON_CHAT_LIB}"
        "${PHOTON_VOICE_LIB}"
        "${PHOTON_OPUS_LIB}"
    )

# =============================================================================
# macOS
# Layout: {Module}-cpp/lib/lib{Module}-cpp_{cfg}_macosx.a
# =============================================================================
elseif(APPLE)

    set(_TAG "${_CFG}_macosx")

    set(PHOTON_COMMON_LIB        "${SDK_ROOT}/Common-cpp/lib/libCommon-cpp_${_TAG}.a"           CACHE FILEPATH "Common-cpp library")
    set(PHOTON_PHOTON_LIB        "${SDK_ROOT}/Photon-cpp/lib/libPhoton-cpp_${_TAG}.a"           CACHE FILEPATH "Photon-cpp library")
    set(PHOTON_LOADBALANCING_LIB "${SDK_ROOT}/LoadBalancing-cpp/lib/libLoadBalancing-cpp_${_TAG}.a" CACHE FILEPATH "LoadBalancing-cpp library")
    set(PHOTON_CHAT_LIB          "${SDK_ROOT}/Chat-cpp/lib/libChat-cpp_${_TAG}.a"               CACHE FILEPATH "Chat-cpp library")
    set(PHOTON_VOICE_LIB         "${SDK_ROOT}/PhotonVoice-cpp/lib/libPhotonVoice-cpp_${_TAG}.a" CACHE FILEPATH "PhotonVoice-cpp library")
    set(PHOTON_OPUS_LIB          "${SDK_ROOT}/PhotonVoice-cpp/opus/lib/libopus_egpv_${_TAG}.a"  CACHE FILEPATH "Opus library")
    set(PHOTON_CRYPTO_LIB        "${SDK_ROOT}/3rdparty/lib/apple/libcrypto_${_TAG}.a"           CACHE FILEPATH "Photon bundled OpenSSL crypto")

    foreach(_lib PHOTON_COMMON_LIB PHOTON_PHOTON_LIB PHOTON_LOADBALANCING_LIB
                 PHOTON_CHAT_LIB PHOTON_VOICE_LIB PHOTON_OPUS_LIB PHOTON_CRYPTO_LIB)
        if(NOT EXISTS "${${_lib}}")
            message(FATAL_ERROR "[photon] Missing library: ${${_lib}}\n"
                "  Set -D${_lib}=<path> or point -DSDK_ROOT= at the correct SDK folder.")
        endif()
    endforeach()

    target_link_libraries(ext_third_party INTERFACE
        "${PHOTON_COMMON_LIB}"
        "${PHOTON_PHOTON_LIB}"
        "${PHOTON_LOADBALANCING_LIB}"
        "${PHOTON_CHAT_LIB}"
        "${PHOTON_VOICE_LIB}"
        "${PHOTON_OPUS_LIB}"
        "${PHOTON_CRYPTO_LIB}"
        "-framework CoreFoundation"
        "-framework CFNetwork"
        "-framework Foundation"
        "-framework Security"
    )

# =============================================================================
# Linux
# Layout: {Module}-cpp/lib{ShortName}{Config}64.a  (no lib/ subdirectory)
# Example: Common-cpp/libCommonRelease64.a
# =============================================================================
elseif(UNIX)

    set(PHOTON_COMMON_LIB        "${SDK_ROOT}/Common-cpp/libCommon${_CFG_CAP}64.a"           CACHE FILEPATH "Common-cpp library")
    set(PHOTON_PHOTON_LIB        "${SDK_ROOT}/Photon-cpp/libPhoton${_CFG_CAP}64.a"           CACHE FILEPATH "Photon-cpp library")
    set(PHOTON_LOADBALANCING_LIB "${SDK_ROOT}/LoadBalancing-cpp/libLoadBalancing${_CFG_CAP}64.a" CACHE FILEPATH "LoadBalancing-cpp library")
    set(PHOTON_CHAT_LIB          "${SDK_ROOT}/Chat-cpp/libChat${_CFG_CAP}64.a"               CACHE FILEPATH "Chat-cpp library")
    set(PHOTON_VOICE_LIB         "${SDK_ROOT}/PhotonVoice-cpp/libPhotonVoice${_CFG_CAP}64.a" CACHE FILEPATH "PhotonVoice-cpp library")
    # The bundled Opus was not compiled with -fPIC and cannot link into a shared
    # library on Linux x86-64.  Left empty so we fall through to FetchContent below.
    set(PHOTON_OPUS_LIB "" CACHE FILEPATH "Opus library (empty = build from source)" FORCE)

    foreach(_lib PHOTON_COMMON_LIB PHOTON_PHOTON_LIB PHOTON_LOADBALANCING_LIB
                 PHOTON_CHAT_LIB PHOTON_VOICE_LIB)
        if(NOT EXISTS "${${_lib}}")
            message(FATAL_ERROR "[photon] Missing library: ${${_lib}}\n"
                "  Set -D${_lib}=<path> or point -DSDK_ROOT= at the correct SDK folder.")
        endif()
    endforeach()

    # --whole-archive pulls every .o from the Photon static archives into the
    # shared library so that RTTI typeinfo objects (e.g. _ZTI...) are present
    # at runtime — without it dlopen fails with "undefined symbol".
    target_link_libraries(ext_third_party INTERFACE
        -Wl,--whole-archive
        "${PHOTON_COMMON_LIB}"
        "${PHOTON_PHOTON_LIB}"
        "${PHOTON_LOADBALANCING_LIB}"
        "${PHOTON_CHAT_LIB}"
        "${PHOTON_VOICE_LIB}"
        -Wl,--no-whole-archive
    )

    # The bundled Opus .a is not -fPIC; build from source so we control the flag.
    include(FetchContent)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON CACHE BOOL "" FORCE)
    FetchContent_Declare(opus URL https://downloads.xiph.org/releases/opus/opus-1.4.tar.gz)
    set(OPUS_BUILD_SHARED_LIBRARY        OFF CACHE BOOL "" FORCE)
    set(OPUS_INSTALL_PKG_CONFIG_MODULE   OFF CACHE BOOL "" FORCE)
    set(OPUS_INSTALL_CMAKE_CONFIG_MODULE OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(opus)
    if(TARGET opus)
        set_target_properties(opus PROPERTIES POSITION_INDEPENDENT_CODE ON)
    endif()
    target_link_libraries(ext_third_party INTERFACE opus)
    message(STATUS "[photon] Building Opus from source (FetchContent 1.4) with -fPIC")

    target_link_libraries(ext_third_party INTERFACE pthread dl m)

    # Photon Linux prebuilts were compiled with -fno-rtti; consumers must match
    # or the linker sees undefined typeinfo symbols and dlopen fails at runtime.
    target_compile_options(ext_third_party INTERFACE $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>)

else()
    message(FATAL_ERROR "[photon] Unsupported platform.")
endif()

message(STATUS "[photon] PHOTON_COMMON_LIB        = ${PHOTON_COMMON_LIB}")
message(STATUS "[photon] PHOTON_PHOTON_LIB        = ${PHOTON_PHOTON_LIB}")
message(STATUS "[photon] PHOTON_LOADBALANCING_LIB = ${PHOTON_LOADBALANCING_LIB}")
message(STATUS "[photon] PHOTON_CHAT_LIB          = ${PHOTON_CHAT_LIB}")
message(STATUS "[photon] PHOTON_VOICE_LIB         = ${PHOTON_VOICE_LIB}")
message(STATUS "[photon] PHOTON_OPUS_LIB          = ${PHOTON_OPUS_LIB}")
message(STATUS "[photon] PHOTON_CRYPTO_LIB        = ${PHOTON_CRYPTO_LIB}")

set(EXT_TP_RUNTIME_DLLS "" PARENT_SCOPE)
