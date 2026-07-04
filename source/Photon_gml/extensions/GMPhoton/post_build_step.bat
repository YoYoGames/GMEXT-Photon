@echo off
set Utils="%~dp0scriptUtils.bat"
set "EXTENSION_DIR=%~dp0"

:: ######################################################################################
:: Script Logic

:: Always init the script
call %Utils% scriptInit

:: Ensure we are on the output path
:: NOTE: version lock checks are performed in 'pre_build_step'
if "%YYTARGET_runtime%" == "GMRT" (
    pushd "%YYoutputFolder%\build\assets"
) else (
    pushd "%YYoutputFolder%"
)

:: Call setup method depending on the platform
:: NOTE: the setup method can be (:setupWindows, :setupMacOS, :setupLinux, :setupAndroid, :setupiOS, :setupSwitch)
call :setup%YYPLATFORM_name%

popd

exit %ERRORLEVEL%

:: ----------------------------------------------------------------------------------------------------
:setupWindows
    :: Nothing to do here
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupMacOS
    :: Nothing to do here
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupLinux
    :: Nothing to do here
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupAndroid
    :: Nothing to do here
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupiOS
    :: Remove the static libraries staged by pre_build_step (kept out of source control)
    call %Utils% itemDelete "%EXTENSION_DIR%iOSSource\libChat-cpp_release_iphoneos.a"
    call %Utils% itemDelete "%EXTENSION_DIR%iOSSource\libCommon-cpp_release_iphoneos.a"
    call %Utils% itemDelete "%EXTENSION_DIR%iOSSource\libLoadBalancing-cpp_release_iphoneos.a"
    call %Utils% itemDelete "%EXTENSION_DIR%iOSSource\libPhoton-cpp_release_iphoneos.a"
    call %Utils% itemDelete "%EXTENSION_DIR%iOSSource\libPhotonVoice-cpp_release_iphoneos.a"
    call %Utils% itemDelete "%EXTENSION_DIR%iOSSource\libopus_egpv_release_iphoneos.a"
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupSwitch
    :: Nothing to do here
exit /b 0
