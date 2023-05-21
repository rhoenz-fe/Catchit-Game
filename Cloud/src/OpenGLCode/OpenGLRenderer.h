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
			ScreenCoord coords) override;

		virtual void Clear() override;

	private:
		unsigned int mVBO, mVAO, mEBO;
	};
}