#pragma once

#include "ImplRenderer.h"

namespace Cloud 
{
	class OpenGLRenderer : public ImplRenderer
	{
	public:
		OpenGLRenderer();

		virtual void Draw(Image& image,
			TextureBox texCoords,
			Shader& shader,
			ScreeCoord coords) override;
	private:
		unsigned int mVBO, mVAO, mEBO;
	};
}