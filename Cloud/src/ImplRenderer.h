#pragma once

#include "RendererTypes.h"
#include "Image.h"
#include "Shader.h"

namespace Cloud 
{
	class ImplRenderer 
	{
	public:
		virtual void Draw(Image& image, 
			TextureBox texCoords, 
			Shader& shader, 
			ScreenCoord coords) = 0;

		virtual void Clear() = 0;
	};
}