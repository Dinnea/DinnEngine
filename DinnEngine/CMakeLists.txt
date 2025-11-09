#ENGINE CMAKE
set (DEPENDENCIES ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)

set(GLFW_ROOT "${DEPENDENCIES}/glfw")
set(GLAD_ROOT "${DEPENDENCIES}/glad")

if (EXISTS "${GLAD_ROOT}/src/glad.c")
  set(GLAD_SRC "${GLAD_ROOT}/src/glad.c")
elseif (EXISTS "${GLAD_ROOT}/src/gl.c")
  set(GLAD_SRC "${GLAD_ROOT}/src/gl.c")
else()
  message(FATAL_ERROR "GLAD source not found under ${GLAD_ROOT}/src")
endif()
#---------------------------------
# Define engine sources
#---------------------------------

file(GLOB_RECURSE DN_SRC CONFIGURE_DEPENDS
"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

#---------------------------------
# Libraries to include
#---------------------------------
add_library(${TARGET_ENGINE} SHARED ${DN_SRC})

add_library(glfw3 STATIC IMPORTED GLOBAL)
set_target_properties(glfw3 PROPERTIES
  IMPORTED_LOCATION             "${GLFW_ROOT}/lib/glfw3_mt.lib"
  INTERFACE_INCLUDE_DIRECTORIES "${GLFW_ROOT}/include"
)

add_library(glad STATIC "${GLAD_SRC}")
target_include_directories(glad PUBLIC "${GLAD_ROOT}/include")

target_include_directories(DinnEngine
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${DEPENDENCIES}/glm"
    "${DEPENDENCIES}/spdlog/include"
	  "${DEPENDENCIES}/stb"
    "${GLFW_ROOT}/include"
    "${GLAD_ROOT}/include"
)

if (MSVC)
  set(PCH_HEADER dnpch.h)
  set(PCH_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/dnpch.cpp)
  set(PCH_NAME   ${TARGET_ENGINE}.pch)  # e.g. DinnEngine.pch

  target_sources(${TARGET_ENGINE} PRIVATE ${PCH_SOURCE})

  # Create the PCH from dnpch.cpp (NO quotes anywhere)
  set_source_files_properties(${PCH_SOURCE} PROPERTIES
    COMPILE_OPTIONS "/Yc${PCH_HEADER};/Fp$(IntDir)${PCH_NAME}"
  )

  # All other files: use the PCH (and force-include so you don't add the include manually)
  target_compile_options(${TARGET_ENGINE} PRIVATE
    "/Yu${PCH_HEADER}"
    "/Fp$(IntDir)${PCH_NAME}"
    "/FI${PCH_HEADER}"
  )
endif()

target_compile_options(DinnEngine PRIVATE /FI"dnpch.h")

target_link_libraries(glfw3 INTERFACE
  opengl32 user32 gdi32 shell32 ole32 uuid
)

target_link_libraries(${TARGET_ENGINE} PUBLIC glfw3 glad)

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
# Copy the dll to the .exe file's location
#---------------------------------
add_custom_command(TARGET ${TARGET_ENGINE} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${TARGET_GAME}>"
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          "$<TARGET_FILE:${TARGET_ENGINE}>"
          "$<TARGET_FILE_DIR:${TARGET_GAME}>"
  VERBATIM
)

#---------------------------------
# Copy the textures and shaders to the .exe file's location
#---------------------------------
add_custom_command(TARGET ${TARGET_ENGINE} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/src/Resources
            $<TARGET_FILE_DIR:${TARGET_GAME}>/Resources
)