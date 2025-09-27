#GAME CMAKE

#---------------------------------
# Define game sources
#---------------------------------
file(GLOB_RECURSE EG_SRC CONFIGURE_DEPENDS
"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

#---------------------------------
# Set the exe
#---------------------------------
add_executable(${TARGET_GAME} ${EG_SRC}) 

#---------------------------------
# Link the engine (headers and libraries)
#---------------------------------
target_link_libraries(${TARGET_GAME} PRIVATE DinnEngine)

#---------------------------------
# Game-specific defines
#---------------------------------
target_compile_definitions(${TARGET_GAME}
  PRIVATE
    DN_PLATFORM_WINDOWS
    $<$<CONFIG:Debug>:DN_DEBUG>
    $<$<CONFIG:Release>:DN_RELEASE> 
)

#---------------------------------
# Set output folders
#---------------------------------
set_target_properties(${TARGET_GAME} PROPERTIES
  VS_DEBUGGER_COMMAND "$<TARGET_FILE:${TARGET_GAME}>"
  VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:${TARGET_GAME}>"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>${PLATFORM_SUFFIX}/${TARGET_GAME}"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>${PLATFORM_SUFFIX}/${TARGET_GAME}"
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin-int/$<CONFIG>${PLATFORM_SUFFIX}/${TARGET_GAME}"
)
