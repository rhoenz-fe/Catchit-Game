#include "Cloud.h"
#include <iostream>
#include <functional>

class GE_Proj_App : public Cloud::CloudApp
{
public:
	GE_Proj_App()
	{
		SetKeyPressedCallback([this](const Cloud::KeyPressed& e) {MyKeyPressedFunc(e); });

	}

	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(back, { 0, 0 });
		renderer.Draw(unit);
	}

	void MyKeyPressedFunc(const Cloud::KeyPressed& e)
	{
		if (e.GetKeyCode() == CLOUD_KEY_RIGHT)
			unit.UpdateXCoord(20);
		else if (e.GetKeyCode() == CLOUD_KEY_LEFT)
			unit.UpdateXCoord(-20);
	}

private:
	Cloud::Renderer renderer;
	Cloud::Image back{ "../Assets/Images/Desert.png" };
	Cloud::Unit unit{ "../Assets/Images/test4.png", {100,100} };

};

CLOUD_GAME_START(GE_Proj_App);