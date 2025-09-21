#---------------------------------
# Language + Compiler settings
#---------------------------------

cmake_minimum_required(VERSION 3.21)
project(DinnEngine LANGUAGES CXX) 

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    set (CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    add_compile_options("/utf-8")
endif()

#---------------------------------
# Output folders
#---------------------------------

foreach(cfg IN ITEMS Debug Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${cfg} "${CMAKE_SOURCE_DIR}/bin/${cfg}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${cfg} "${CMAKE_SOURCE_DIR}/bin/${cfg}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${cfg} "${CMAKE_SOURCE_DIR}/bin-int/${cfg}")
endforeach()

#---------------------------------
# Subproject folders
#---------------------------------

add_subdirectory(DinnEngine)
add_subdirectory(ExampleGame)
