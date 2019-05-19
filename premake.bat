@echo off
echo Generating solution files...
call "tools/premake5.exe" vs2017
set /p temp="Hit enter to continue"