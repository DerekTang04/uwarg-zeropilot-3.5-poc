@echo off
setlocal ENABLEDELAYEDEXPANSION

set "script_dir=%~dp0"
set "clean=false"

if not "%1" == "" (
    if "%1" == "-c" (
        set "clean=true"
    ) else (
        echo Usage: %0 [-c]
        exit /b 1
    )
)

if exist "%script_dir%\build" (
    if "%clean%" == "true" (
        rmdir /s /q "%script_dir%\build"
        mkdir "%script_dir%\build"
    )
) else (
    mkdir "%script_dir%\build"
)

cd /d "%script_dir%\build"

if not exist "CMakeCache.txt" (
    echo generating cmake...
    cmake -G "Ninja" ..
    if !errorlevel! neq 0 (
        cd ..
        exit /b 1
    )
)

echo; && echo building...
cmake --build .
cd ..
