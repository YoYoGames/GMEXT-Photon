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
:: NOTE: the setup method can be (:setupWindows, :setupMacOS, :setupLinux, :setupAndroid, :setupiOS,
::       :setupPlaystation, :setupSwitch). PlayStation covers both PS4 and PS5: "call :setup%YYPLATFORM_name%"
:: with YYPLATFORM_name="PlayStation 4"/"PlayStation 5" is parsed by cmd as "call :setupPlaystation 4"/"5"
:: (batch splits on the first space, passing the rest as an argument) — same trick GMEXT-FMOD uses.
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
:setupPlaystation
    :: Unlike Windows/macOS/Linux/Android (which ship a precompiled GMPhoton binary), PS4/PS5 binaries
    :: are never committed (see GMPhoton/.gitignore) — they must be built from source via the CMake
    :: project in source/ before the IDE's packaging step can pick up GMPhoton_ps4.prx/_ps5.prx.
    :: Always builds the "release" preset regardless of the game's own Debug/Release config, matching
    :: how FMOD's console AutoBuild configs are decoupled from the game build config.
    :: Requires a one-time CMakeUserPresets.json set up per templates/CMakeUserPresets.json.template.
    set "CMAKE_PRESET=ps4-release"
    if "%YYPLATFORM_name%"=="PlayStation 5" set "CMAKE_PRESET=ps5-release"

    call "%YYPREF_visual_studio_path%"

    where cmake >nul 2>nul
    if errorlevel 1 call %Utils% logError "cmake was not found on PATH. Install CMake to build %YYPLATFORM_name%."

    pushd "%EXTENSION_DIR%source"
    cmake --preset %CMAKE_PRESET%
    if errorlevel 1 call %Utils% logError "CMake configure failed for %CMAKE_PRESET%. Check CMakeUserPresets.json is set up (see templates/CMakeUserPresets.json.template)."
    cmake --build --preset %CMAKE_PRESET% --target GMPhoton
    if errorlevel 1 call %Utils% logError "CMake build failed for %CMAKE_PRESET%."
    popd
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupSwitch
    :: See :setupPlaystation above for why a build trigger is needed here at all — same reasoning,
    :: GMPhoton.nro/.nrr/.nrs are never committed and must be built from source before packaging.
    call "%YYPREF_visual_studio_path%"

    where cmake >nul 2>nul
    if errorlevel 1 call %Utils% logError "cmake was not found on PATH. Install CMake to build Nintendo Switch."

    pushd "%EXTENSION_DIR%source"
    cmake --preset switch-release
    if errorlevel 1 call %Utils% logError "CMake configure failed for switch-release. Check CMakeUserPresets.json is set up (see templates/CMakeUserPresets.json.template)."
    cmake --build --preset switch-release --target GMPhoton
    if errorlevel 1 call %Utils% logError "CMake build failed for switch-release."
    popd
exit /b 0
