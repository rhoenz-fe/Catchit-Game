#include "pch.h"
#include "Renderer.h"
#include "GameWindow.h"
#include "OpenGLCode/OpenGLRenderer.h"

namespace Cloud 
{

#ifdef CLOUD_OPENGL
	Renderer::Renderer() :
		mImplementation(std::unique_ptr<ImplRenderer>{ new OpenGLRenderer }),
		mDefaultShader{ "../Assets/Shaders/DefaultVertexShader.glsl",
			"../Assets/Shaders/DefaultFragmentShader.glsl" }
	{}
#else
		#Only_OpenGL_is_implemented_at_the_moment
#endif
	

	void Renderer::Draw(Image& image, Shader& shader, ScreeCoord coords)
	{
		mImplementation->Draw(image, 
			{0, 0, image.GetWidth(), image.GetHeight()}, 
			shader, 
			coords);
	}

	void Renderer::Draw(Image& image, ScreeCoord coords)
	{
		mDefaultShader.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		mImplementation->Draw(image,
			{ 0, 0, image.GetWidth(), image.GetHeight() },
			mDefaultShader,
			coords);
	}

	void Renderer::Draw(Image& image, TextureBox texCoords, Shader& shader, ScreeCoord coords)
	{
		mImplementation->Draw(image, texCoords, shader, coords);
	}

	void Renderer::Draw(Image& image, TextureBox texCoords, ScreeCoord coords)
	{
		mDefaultShader.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		mImplementation->Draw(image,
			texCoords,
			mDefaultShader,
			coords);
	}


}