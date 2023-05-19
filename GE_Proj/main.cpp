#include "Cloud.h"
#include <iostream>

class GE_Proj_App : public Cloud::CloudApp
{
public:
	GE_Proj_App()
	{
		Cloud::GameWindow::Init();
		Cloud::GameWindow::CreateWindow(800,600, "Test Name");
	}

	virtual void OnUpdate() override
	{
		//std::cout << "Game is running" << std::endl;

		/*Cloud::GameWindow::SwapBuffers();
		Cloud::GameWindow::PollEvents();*/
	}
};

CLOUD_GAME_START(GE_Proj_App);