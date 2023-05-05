#pragma once

#include "pch.h"
#include "CloudUtil.h"
#include "Image.h"
#include "Shader.h"
//#include "ImplRenderer.h"

namespace Cloud
{
	class CLOUD_API Renderer
	{

	public:
		Renderer();

		struct TextureBox {
			int xTexCoord{ 0 };
			int yTexCoord{ 0 };
			int texWidth{ 0 };
			int texHeight{ 0 };
		};

		struct ScreeCoord{
			int xCoord{ 0 };
			int yCoord{ 0 };
		};

		void Draw(Image& image, Shader& shader, ScreeCoord coords);
		void Draw(Image& image, ScreeCoord coords);

		void Draw(Image& image,TextureBox texCoords, Shader& shader, ScreeCoord coords);
		void Draw(Image& image, TextureBox texCoords, ScreeCoord coords);

	private:
		//std::unique_ptr<ImplRenderer> mImplementation {nullptr};

	};

}