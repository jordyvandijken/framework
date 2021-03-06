# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (RT2D)

find_package(OpenGL REQUIRED)

OPTION(USE_OPENAL "Use OpenAL" OFF)
OPTION(MAKE_AUDIOSTART "Make OpenAL/RT2D audiostart" OFF)
OPTION(MAKE_OPENAL_TONEGEN "Make OpenAL Tone Generator" OFF)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

set (CMAKE_CXX_FLAGS "-Wall")


# Compile external dependencies
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)

include_directories(
	external/glfw-3.0.3/include/GLFW/
	external/glm-0.9.7.0/
	external/glew-1.9.0/include/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	GLFW_303
	GLEW_190
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Demo
add_executable(demo
   demo/demo.cpp
   demo/scene1.cpp
   demo/scene1.h
   demo/scene2.cpp
   demo/scene2.h
   demo/scene3.cpp
   demo/scene3.h
   demo/scene4.cpp
   demo/scene4.h
   demo/scene5.cpp
   demo/scene5.h
   demo/player.cpp
   demo/player.h
   demo/circle.cpp
   demo/circle.h
   demo/circlepoint.cpp
   demo/circlepoint.h
   common/audio.cpp
   common/audio.h
   common/sound.cpp
   common/sound.h
   common/wav.cpp
   common/wav.h
   common/config.h
   common/shader.cpp
   common/shader.h
   common/camera.cpp
   common/camera.h
   common/renderer.cpp
   common/renderer.h
   common/sprite.cpp
   common/sprite.h
   common/scene.cpp
   common/scene.h
   common/entity.cpp
   common/entity.h
   common/core.cpp
   common/core.h
   common/input.cpp
   common/input.h
   common/vector2.cpp
   common/vector2.h
   common/resourcemanager.cpp
   common/resourcemanager.h
)


####################################################################
# OpenAL                                                           #
####################################################################
	add_subdirectory (external/openal)
	include_directories(
		${CMAKE_SOURCE_DIR}/external/openal/include/
	)

	link_directories(
		${CMAKE_SOURCE_DIR}/external/openal/
	)

	IF(WIN32)
		SET(OPENAL OpenAL32)
	ELSE()
		SET(OPENAL openal)
	ENDIF()

####################################################################
# OpenAL tone generator                                            #
####################################################################
IF(MAKE_OPENAL_TONEGEN AND USE_OPENAL)
	add_executable(altonegenrt
		external/openal/examples/altonegen.c
		external/openal/examples/common/alhelpers.c
	)
	target_link_libraries(altonegenrt
		${OPENAL}
	)
ENDIF()
####################################################################

target_link_libraries(demo
	${ALL_LIBS}
  ${OPENAL}
)
# Xcode and Visual working directories
set_target_properties(demo PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/demo/")
create_target_launcher(demo WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/demo/")


SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )


if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
#add_custom_command(
#   TARGET demo POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/demo${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/demo/"
#)
elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )


# Copy assets to the build directory
file(
	COPY demo/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY common/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)
