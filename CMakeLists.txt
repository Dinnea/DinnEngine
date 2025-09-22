#TOP LEVEL CMAKE

#---------------------------------
# Language + Compiler settings
#---------------------------------

cmake_minimum_required(VERSION 3.21)
project(DinnEngine LANGUAGES CXX) 

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set(PLATFORM_SUFFIX "-windows-x86_64")
set(TARGET_ENGINE "DinnEngine")
set(TARGET_GAME "ExampleGame")

if (MSVC)
    set (CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    add_compile_options("/utf-8")
endif()

#---------------------------------
# Subproject folders
#---------------------------------

add_subdirectory(${TARGET_ENGINE})
add_subdirectory(${TARGET_GAME})

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${TARGET_GAME})
