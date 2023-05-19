cmake_minimum_required(VERSION 3.24)

project(GE_Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DCLOUD_WINDOWS)
elseif(APPLE)
	add_definitions(-DCLOUD_MACOS)
else()
	add_definitions(-DCLOUD_LINUX)
endif()

add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)
add_subdirectory(Cloud)
add_subdirectory(GE_Proj)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GE_Game)

