del CMakeCache.txt 2>nul
cmake -S . -B . -G "Visual Studio 17 2022" -A x64

echo Killing all Visual Studio instances...
taskkill /F /IM devenv.exe /T >nul 2>&1
echo Done.

echo Starting solution...
start "" "DinnEngine.sln"
PAUSE