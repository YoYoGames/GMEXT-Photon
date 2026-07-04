#!/bin/bash

sed -i -e 's/\r$//' "$(dirname "$0")/scriptUtils.sh"
chmod +x "$(dirname "$0")/scriptUtils.sh"
source "$(dirname "$0")/scriptUtils.sh"

EXTENSION_DIR="$(cd "$(dirname "$0")" && pwd)"

# ######################################################################################
# Script Functions

# ----------------------------------------------------------------------------------------------------
setupmacOS() {
    # Nothing to do here (Photon SDK is linked statically into libGMPhoton.dylib)
    :
}

# ----------------------------------------------------------------------------------------------------
setupMac() {
    # GMRT macOS (platform name 'Mac'). Nothing to do here.
    :
}

# ----------------------------------------------------------------------------------------------------
setupLinux() {
    # Nothing to do here (Photon SDK is linked statically into GMPhoton.so)
    :
}

# ----------------------------------------------------------------------------------------------------
setupAndroid() {
    # Nothing to do here (native libraries are built from AndroidSource)
    :
}

# ----------------------------------------------------------------------------------------------------
setupiOS() {
    # iOS links the Photon SDK statically at the end user's Xcode build, so the
    # release static libraries must be staged into iOSSource before packaging.
    if [ -z "$SDK_IOS" ]; then
        logError "SDK path for iOS (sdkPathiOS) is not configured."
    fi

    # Resolve the iOS SDK path (must exist)
    pathResolveExisting "$YYprojectDir" "$SDK_IOS" SDK_PATH

    local DEST="$EXTENSION_DIR/iOSSource"

    echo "Copying Photon iOS (arm64) static libraries to iOSSource"
    itemCopyTo "$SDK_PATH/Chat-cpp/lib/libChat-cpp_release_iphoneos.a" "$DEST/libChat-cpp_release_iphoneos.a"
    itemCopyTo "$SDK_PATH/Common-cpp/lib/libCommon-cpp_release_iphoneos.a" "$DEST/libCommon-cpp_release_iphoneos.a"
    itemCopyTo "$SDK_PATH/LoadBalancing-cpp/lib/libLoadBalancing-cpp_release_iphoneos.a" "$DEST/libLoadBalancing-cpp_release_iphoneos.a"
    itemCopyTo "$SDK_PATH/Photon-cpp/lib/libPhoton-cpp_release_iphoneos.a" "$DEST/libPhoton-cpp_release_iphoneos.a"
    itemCopyTo "$SDK_PATH/PhotonVoice-cpp/lib/libPhotonVoice-cpp_release_iphoneos.a" "$DEST/libPhotonVoice-cpp_release_iphoneos.a"
    itemCopyTo "$SDK_PATH/PhotonVoice-cpp/opus/lib/libopus_egpv_release_iphoneos.a" "$DEST/libopus_egpv_release_iphoneos.a"
}

# ----------------------------------------------------------------------------------------------------
setupSwitch() {
    # Nothing to do here
    :
}

# ######################################################################################
# Script Logic

# Always init the script
scriptInit

# Version locks
optionGetValue "versionStable" RUNTIME_VERSION_STABLE
optionGetValue "versionBeta"   RUNTIME_VERSION_BETA
optionGetValue "versionDev"    RUNTIME_VERSION_DEV
optionGetValue "versionLTS"    RUNTIME_VERSION_LTS

# SDK Paths
optionGetValue "sdkPathiOS" SDK_IOS

# Checks IDE and Runtime versions (legacy runtime only; GMRT is version-agnostic here)
if [ "$YYTARGET_runtime" == "GMRT" ]; then
    logInformation "GMRT runtime detected, skipping legacy version lock check."
else
    versionLockCheck "$YYruntimeVersion" $RUNTIME_VERSION_STABLE $RUNTIME_VERSION_BETA $RUNTIME_VERSION_DEV $RUNTIME_VERSION_LTS
fi

# Call setup method depending on the platform
setup$YYPLATFORM_name

exit 0
