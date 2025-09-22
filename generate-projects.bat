del CMakeCache.txt 2>nul
cmake -S . -B . -G "Visual Studio 17 2022" -A x64
start "" "DinnEngine.sln"
PAUSE