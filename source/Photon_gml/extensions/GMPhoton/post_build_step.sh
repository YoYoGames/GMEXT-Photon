#!/bin/bash

sed -i -e 's/\r$//' "$(dirname "$0")/scriptUtils.sh"
chmod +x "$(dirname "$0")/scriptUtils.sh"
source "$(dirname "$0")/scriptUtils.sh"

EXTENSION_DIR="$(cd "$(dirname "$0")" && pwd)"

# ######################################################################################
# Script Functions

# Removes the macOS Gatekeeper quarantine attribute from the extension dylib if present
removeQuarantine() {
    for f in "./libGMPhoton.dylib" "./GMPhoton.dylib"; do
        [ -f "$f" ] || continue
        if xattr -p com.apple.quarantine "$f" >/dev/null 2>&1; then
            logWarning "'$(basename "$f")' is quarantined. Removing com.apple.quarantine..."
            if xattr -d com.apple.quarantine "$f" >/dev/null 2>&1; then
                logInformation "Removed quarantine from '$f'."
            else
                logError "Failed to remove quarantine from '$f' (check permissions)."
            fi
        fi
    done
}

# ----------------------------------------------------------------------------------------------------
setupmacOS() {
    # Legacy macOS runtime (cwd is the output folder)
    removeQuarantine
}

# ----------------------------------------------------------------------------------------------------
setupMac() {
    # GMRT macOS (platform name 'Mac'); dependencies live under build/assets
    pushd "./build/assets" >/dev/null
    removeQuarantine
    popd >/dev/null
}

# ----------------------------------------------------------------------------------------------------
setupLinux() {
    # Nothing to do here
    :
}

# ----------------------------------------------------------------------------------------------------
setupAndroid() {
    # Nothing to do here
    :
}

# ----------------------------------------------------------------------------------------------------
setupiOS() {
    # Remove the static libraries staged by pre_build_step (kept out of source control)
    for LIB in \
        "libChat-cpp_release_iphoneos.a" \
        "libCommon-cpp_release_iphoneos.a" \
        "libLoadBalancing-cpp_release_iphoneos.a" \
        "libPhoton-cpp_release_iphoneos.a" \
        "libPhotonVoice-cpp_release_iphoneos.a" \
        "libopus_egpv_release_iphoneos.a"
    do
        itemDelete "$EXTENSION_DIR/iOSSource/$LIB"
    done
}

# ----------------------------------------------------------------------------------------------------
setupSwitch() {
    # Nothing to do here
    :
}

# ######################################################################################
# Script Logic

# Always init the script
# NOTE: version lock checks are performed in 'pre_build_step'
scriptInit

# Ensure we are on the output path
pushd "$YYoutputFolder" >/dev/null

# Call setup method depending on the platform
setup$YYPLATFORM_name

popd >/dev/null

exit 0
