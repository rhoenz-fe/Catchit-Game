set(HEADER_FILES
	src/CloudUtil.h
	src/CloudApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWCode/GLFWimplementation.h
)

set(SOURCE_FILES
	src/CloudApp.cpp
	src/GameWindow.cpp
	src/GLFWCode/GLFWimplementation.cpp

)

add_library(Cloud SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)

target_precompile_headers(Cloud PRIVATE src/pch.h)

target_link_libraries(Cloud glfw)

add_definitions(-DCLOUD_LIB)
add_definitions(-DCLOUD_GLFW)

