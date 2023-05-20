#pragma once

#include "pch.h"
#include "../ImplImage.h"

namespace Cloud
{
	class OpenGLImage : public ImplImage
	{
	public:
		OpenGLImage(const std::string& imageFile);
		OpenGLImage(std::string&& imageFile);

		//virtual void Activate() override;

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

	private:
		unsigned int mtexture;
		int width, height, nrChannels;
		unsigned char* data;
	};
}