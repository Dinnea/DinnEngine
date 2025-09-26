#ENGINE CMAKE
set (DEPENDENCIES ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)

#---------------------------------
# Define engine sources
#---------------------------------

file(GLOB_RECURSE DN_SRC CONFIGURE_DEPENDS
"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_library(${TARGET_ENGINE} SHARED ${DN_SRC})

#---------------------------------
# Libraries to include
#---------------------------------

target_include_directories(DinnEngine
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/spdlog/include"
)

target_precompile_headers(DinnEngine
    PRIVATE
        "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/src/dnpch.h>"
)
#---------------------------------
# Engine-specific defines
#---------------------------------
target_compile_definitions(DinnEngine
  PRIVATE
    $<$<PLATFORM_ID:Windows>:DN_PLATFORM_WINDOWS;DN_BUILD_DLL>
    $<$<CONFIG:Debug>:DN_DEBUG>
    $<$<CONFIG:Release>:DN_RELEASE>
  PUBLIC
    $<$<PLATFORM_ID:Windows>:DN_PLATFORM_WINDOWS>
)

#---------------------------------
# Set output folders
#---------------------------------
set_target_properties(${TARGET_ENGINE} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>${PLATFORM_SUFFIX}/${TARGET_ENGINE}"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>${PLATFORM_SUFFIX}/${TARGET_ENGINE}"
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin-int/$<CONFIG>${PLATFORM_SUFFIX}/${TARGET_ENGINE}"
)

#---------------------------------
# Copy the dll to the .exe file's location (unchanged)
#---------------------------------
add_custom_command(TARGET DinnEngine POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:DinnEngine>
          $<TARGET_FILE_DIR:${TARGET_GAME}>
)