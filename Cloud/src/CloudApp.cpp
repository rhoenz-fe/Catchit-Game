#include "pch.h"
#include "CloudApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

namespace Cloud 
{

	void CloudApp::Run()
	{
		while (true)
		{
			OnUpdate();
		}
	}

}