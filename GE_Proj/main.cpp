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

	virtual void OnUpdate(bool& closeGame) override
	{
		startGame.GameRunnning(closeGame);
	}

	void MyKeyPressedFunc(const Cloud::KeyPressed& e)
	{
		startGame.OnKeyPressed(e);
	}

private:
	Cloud::Game startGame;


};

CLOUD_GAME_START(GE_Proj_App);