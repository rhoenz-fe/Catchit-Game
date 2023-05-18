#include "pch.h"
#include "Image.h"
#include "OpenGLCode/OpenGLImage.h"

namespace Cloud {
	Image::Image(const std::string& imageFile)
	{
#ifdef CLOUD_OPENGL
		mImplementation = std::unique_ptr<ImplImage>{ new OpenGLImage { imageFile} };
#else
		#Only_OpenGL_is_implemented_at_the_moment
#endif
	}

	Image::Image(std::string&& imageFile)
	{
#ifdef CLOUD_OPENGL
		mImplementation = std::unique_ptr<ImplImage>{ new OpenGLImage { std::move(imageFile)} };
#else
		#Only_OpenGL_is_implemented_at_the_moment
#endif
	}

	void Image::Activate()
	{
		mImplementation->Activate();
	}

	int Image::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int Image::GetHeight() const
	{
		return mImplementation->GetHeight();
	}
}