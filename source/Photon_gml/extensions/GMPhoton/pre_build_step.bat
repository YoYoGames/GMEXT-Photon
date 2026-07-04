@echo off
set Utils="%~dp0scriptUtils.bat"
set "EXTENSION_DIR=%~dp0"

:: ######################################################################################
:: Script Logic

:: Always init the script
call %Utils% scriptInit

:: Version locks
call %Utils% optionGetValue "versionStable" RUNTIME_VERSION_STABLE
call %Utils% optionGetValue "versionBeta"   RUNTIME_VERSION_BETA
call %Utils% optionGetValue "versionDev"    RUNTIME_VERSION_DEV
call %Utils% optionGetValue "versionLTS"    RUNTIME_VERSION_LTS

:: SDK Paths
call %Utils% optionGetValue "sdkPathiOS" SDK_IOS

:: Checks IDE and Runtime versions (legacy runtime only; GMRT is version-agnostic here)
if "%YYTARGET_runtime%" == "GMRT" (
    call %Utils% logInformation "GMRT runtime detected, skipping legacy version lock check."
) else (
    call %Utils% versionLockCheck "%YYruntimeVersion%" %RUNTIME_VERSION_STABLE% %RUNTIME_VERSION_BETA% %RUNTIME_VERSION_DEV% %RUNTIME_VERSION_LTS%
)

:: Call setup method depending on the platform
:: NOTE: the setup method can be (:setupWindows, :setupMacOS, :setupLinux, :setupAndroid, :setupiOS, :setupSwitch)
call :setup%YYPLATFORM_name%

exit %ERRORLEVEL%

:: ----------------------------------------------------------------------------------------------------
:setupWindows
    :: Nothing to do here (Photon SDK is linked statically into GMPhoton.dll)
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupMacOS
    :: Nothing to do here (Photon SDK is linked statically into libGMPhoton.dylib)
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupLinux
    :: Nothing to do here (Photon SDK is linked statically into GMPhoton.so)
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupAndroid
    :: Nothing to do here (native libraries are built from AndroidSource)
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupiOS
    :: iOS links the Photon SDK statically at the end user's Xcode build, so the
    :: release static libraries must be staged into iOSSource before packaging.
    if "%SDK_IOS%"=="" call %Utils% logError "SDK path for iOS (sdkPathiOS) is not configured."

    :: Resolve the iOS SDK path (must exist)
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_IOS%" SDK_PATH

    echo "Copying Photon iOS (arm64) static libraries to iOSSource"
    pushd "%EXTENSION_DIR%iOSSource"
    call %Utils% itemCopyTo "%SDK_PATH%\Chat-cpp\lib\libChat-cpp_release_iphoneos.a" "libChat-cpp_release_iphoneos.a"
    call %Utils% itemCopyTo "%SDK_PATH%\Common-cpp\lib\libCommon-cpp_release_iphoneos.a" "libCommon-cpp_release_iphoneos.a"
    call %Utils% itemCopyTo "%SDK_PATH%\LoadBalancing-cpp\lib\libLoadBalancing-cpp_release_iphoneos.a" "libLoadBalancing-cpp_release_iphoneos.a"
    call %Utils% itemCopyTo "%SDK_PATH%\Photon-cpp\lib\libPhoton-cpp_release_iphoneos.a" "libPhoton-cpp_release_iphoneos.a"
    call %Utils% itemCopyTo "%SDK_PATH%\PhotonVoice-cpp\lib\libPhotonVoice-cpp_release_iphoneos.a" "libPhotonVoice-cpp_release_iphoneos.a"
    call %Utils% itemCopyTo "%SDK_PATH%\PhotonVoice-cpp\opus\lib\libopus_egpv_release_iphoneos.a" "libopus_egpv_release_iphoneos.a"
    popd
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupSwitch
    :: Nothing to do here
exit /b 0
