#pragma once

#include "CloudUtil.h"
#include "Image.h"
#include "Shader.h"
#include "ImplRenderer.h"

namespace Cloud
{
	class CLOUD_API Renderer
	{

	public:
		void Draw(Image& imgage, Shader& shader, int xCoord, int yCoord);
		void Draw(Image& imgage,int xCoord, int yCoord);

	private:
		ImplRenderer* mImplementation {nullptr};

	};

}