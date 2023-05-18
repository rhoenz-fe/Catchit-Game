#pragma once

#include "pch.h"
#include "CloudUtil.h"
#include "Image.h"
#include "Shader.h"
#include "RendererTypes.h"
#include "ImplRenderer.h"

namespace Cloud
{
	class CLOUD_API Renderer
	{

	public:
		Renderer();

		void Draw(Image& image, Shader& shader, ScreeCoord coords);
		void Draw(Image& image, ScreeCoord coords);

		void Draw(Image& image,TextureBox texCoords, Shader& shader, ScreeCoord coords);
		void Draw(Image& image, TextureBox texCoords, ScreeCoord coords);

	private:
		std::unique_ptr<ImplRenderer> mImplementation {nullptr};

		Shader mDefaultShader;

	};

}