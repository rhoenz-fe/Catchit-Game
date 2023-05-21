set(HEADER_FILES
	src/CloudUtil.h
	src/CloudApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWCode/GLFWimplementation.h
	src/Renderer.h
	src/ImplRenderer.h
	src/OpenGLCode/OpenGLRenderer.h
	src/RendererTypes.h
	src/Shader.h
	src/ImplShader.h
	src/OpenGLCode/OpenGLShader.h
	src/Image.h
	src/ImplImage.h
	src/OpenGLCode/OpenGLImage.h
	src/Unit.h
	src/RendererTypes.h
	src/CloudEvents.h
	src/CloudKeys.h
	src/Game.h
)

set(SOURCE_FILES
	src/CloudApp.cpp
	src/GameWindow.cpp
	src/GLFWCode/GLFWimplementation.cpp
	src/Renderer.cpp
	src/OpenGLCode/OpenGLRenderer.cpp
	src/Shader.cpp
	src/OpenGLCode/OpenGLShader.cpp
	src/Image.cpp
	src/OpenGLCode/OpenGLImage.cpp
	src/Unit.cpp
	src/CloudEvents.cpp
	src/Game.cpp

)

add_library(Cloud SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../glfw/include)

target_precompile_headers(Cloud PRIVATE src/pch.h)

target_link_libraries(Cloud glfw glad stbi)

add_definitions(-DCLOUD_LIB)
add_definitions(-DCLOUD_GLFW)
add_definitions(-DCLOUD_OPENGL)
add_definitions(-DCLOUD_WINDOWS)
add_definitions(-DCLOUD_DEBUG=2)
