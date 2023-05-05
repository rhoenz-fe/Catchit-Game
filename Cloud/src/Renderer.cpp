#include "pch.h"
#include "Renderer.h"
//#include "OpenGLRenderer.h"

namespace Cloud 
{
	Renderer::Renderer()
	{
#ifdef CLOUD_OPENGL
		//mImplementation = std::unique_ptr<ImplShader>{ new OpenGLRenderer };
#else
		#Only_OpenGL_is_implemented_at_the_moment
#endif
	}

	void Renderer::Draw(Image& image, Shader& shader, ScreeCoord coords)
	{
		//mImplementation->Draw(image, shader, coords);
	}

	void Renderer::Draw(Image& image, ScreeCoord coords)
	{
		//mImplementation->Draw(image, coords);
	}

	void Renderer::Draw(Image& image, TextureBox texCoords, Shader& shader, ScreeCoord coords)
	{
	}


}