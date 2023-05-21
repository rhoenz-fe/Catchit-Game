#include "pch.h"
#include "Game.h"


namespace Cloud
{
	Game::Game()
	{
	}

	void Game::GameRunnning(bool& closeGame)
	{
		shoe = rand() % 5;
		renderer.Clear();
		renderer.Draw(background, { 0, 0 });
		renderer.Draw(bucketUnit);

		Scoreboard(closeGame);
		TearDrop();
		CheckCollision(closeGame);

	}

	void Game::OnKeyPressed(const KeyPressed& e)
	{
		if (e.GetKeyCode() == CLOUD_KEY_RIGHT && bucketUnit.GetCoords().xCoord <= 600)
			bucketUnit.UpdateXCoord(70);
		else if (e.GetKeyCode() == CLOUD_KEY_LEFT && bucketUnit.GetCoords().xCoord >= 50)
			bucketUnit.UpdateXCoord(-70);
	}

	void Game::SpawnDropUnit()
	{
		int x = std::rand() % 700;
		int y = 800;
		if (shoe == 2) {
			tearDrops.push_back(Unit("../Assets/Images/brick.png", ScreenCoord{ x, y }));
			tearDrops[0].SetBrick();
		}
		else {
			tearDrops.push_back(Unit("../Assets/Images/rain.png", ScreenCoord{ x, y }));
		}
	}

	void Game::UpdateDropUnit(Unit& tear)
	{
		
		if (score < 3) {
			tear.UpdateYCoord(-10);
		}
		else if (score < 6) {
			tear.UpdateYCoord(-15);
		}
		else if (score < 9) {
			tear.UpdateYCoord(-20);
		}
		else if (score < 12) {
			tear.UpdateYCoord(-30);
		}
		else
		{
			tear.UpdateYCoord(-45);
		}
		
		
	}

	void Game::CheckCollision(bool& closeGame)
	{
		if (!tearDrops.empty() && UnitsOverlap(bucketUnit, tearDrops[0]) && tearDrops[0].GetBrick()) {
			closeGame = true;
		}
		else if(!tearDrops.empty() && UnitsOverlap(bucketUnit, tearDrops[0])) {
			score++;
			renderer.Draw(splash, { bucketUnit.GetCoords().xCoord, bucketUnit.GetCoords().yCoord+75});
			tearDrops.pop_back();
		}
		

	}
	void Game::Scoreboard(bool& closeGame)
	{
		if (score == 0) {
			renderer.Draw(Score, { 600,650 });
		}
		else if (score == 1) {
			Image pic{ "../Assets/Images/one.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 2) {
			Image pic{ "../Assets/Images/two.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 3) {
			Image pic{ "../Assets/Images/three.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 4) {
			Image pic{ "../Assets/Images/four.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 5) {
			Image pic{ "../Assets/Images/five.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 6) {
			Image pic{ "../Assets/Images/six.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 7) {
			Image pic{ "../Assets/Images/seven.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 8) {
			Image pic{ "../Assets/Images/eight.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 9) {
			Image pic{ "../Assets/Images/nine.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 10) {
			Image pic{ "../Assets/Images/ten.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 11) {
			Image pic{ "../Assets/Images/ele.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 12) {
			Image pic{ "../Assets/Images/twe.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 13) {
			Image pic{ "../Assets/Images/thi.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score == 14) {
			Image pic{ "../Assets/Images/fou.png" };
			renderer.Draw(pic, { 600,650 });
		}
		else if (score >= 15) {
			closeGame = true;
		}

	}
	void Game::TearDrop()
	{
		if (tearDrops.empty())
		{
			SpawnDropUnit();
		}
		else {
			renderer.Draw(cloud, {tearDrops[0].GetCoords().xCoord-100, 720});
			UpdateDropUnit(tearDrops[0]);
			renderer.Draw(tearDrops[0]);
			if (tearDrops[0].GetCoords().yCoord <= 0) {
				tearDrops.pop_back();
			}
		}
	}
}
