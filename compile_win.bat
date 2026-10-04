@echo off
cls
echo Please wait...

g++ main.cpp src\*.cpp -o teamAY.exe -mconsole

if %ERRORLEVEL% EQU 0 (
    echo Success!
) else (
    echo Error!
)

pause