file(GLOB_RECURSE EG_SRC CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

#---------------------------------
# Define the execulable
#---------------------------------
add_executable(ExampleGame ${EG_SRC})

#---------------------------------
# Link the engine (headers and libraries)
#---------------------------------
target_link_libraries(ExampleGame PRIVATE DinnEngine)

#---------------------------------
# Copy the dll to the .exe file's location
#---------------------------------
if(WIN32)
    add_custom_command(TARGET ExampleGame POST_BUILD
    COMMAND $(CMAKE_COMMAND) -E copy_if_different
        "$<TARGET_FILE:DinnEngine>"
        "$<TARGET_FILE_DIR:ExampleGame>/DinnEngine.dll"
        )
endif()
