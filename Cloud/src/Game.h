#pragma once
#include "pch.h"
#include "CloudUtil.h"
#include "Image.h"
#include "RendererTypes.h"
#include "Unit.h"
#include "Renderer.h"
#include "Unit.h"
#include "CloudKeys.h"
#include "CloudEvents.h"

namespace Cloud {
	class CLOUD_API Game
	{
	public:
		Game();
		void GameRunnning(bool& closeGame);
		void OnKeyPressed(const KeyPressed& e);

	private:
		Renderer renderer;
		Image Score{ "../Assets/Images/zero.png" };
		Image background{ "../Assets/Images/Rainback.png" };
		Image splash{ "../Assets/Images/Splash.png" };
		Image cloud{ "../Assets/Images/cloud.png" };
		Unit bucketUnit{ "../Assets/Images/bucket.png", {350, 10} };
		std::vector<Unit> tearDrops{};
		int score = 0;
		int shoe = 0;
		void SpawnDropUnit();
		void UpdateDropUnit(Unit& drop);
		void CheckCollision(bool& closeGame);
		void Scoreboard(bool& closeGame);
		void TearDrop();
	};
}
