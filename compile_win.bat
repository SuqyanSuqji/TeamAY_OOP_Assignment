@echo off
cls
echo Please wait...

g++ main.cpp src\*.cpp -o program_kasir.exe -mconsole

if %ERRORLEVEL% EQU 0 (
    echo Success!
) else (
    echo Error!
)

pause