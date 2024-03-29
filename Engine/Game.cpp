/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	rng(std::random_device()()),
	snake(Location{ 39, 29 }),
	goal(brd)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameOver)
	{
		snake.ProcessMovement(wnd);

		++snakeMoveCounter;
		if (snakeMoveCounter >= snakeMovePeriod)
		{
			snakeMoveCounter = 0;
			snake.Move();
		}

		if (snake.location() == goal.location())
		{
			snake.Grow();
			snake.Move();
			goal.Respawn();
		}

		if (snake.intersecting() || snake.pastEdge(brd))
		{
			gameOver = true;
		}
	}
}

void Game::ComposeFrame()
{
	if (!gameOver)
	{
		snake.Draw(brd);
		goal.Draw();
	}
	else
	{
		SpriteCodex::DrawGameOver(400, 300, gfx);
	}
	/*std::uniform_int_distribution<int> colorDist(0, 255);
	for (int y = 0; y < brd.GetGridHeight(); ++y)
	{
		for (int x = 0; x < brd.GetGridWidth(); ++x)
		{
			Location loc = { x, y };
			Color c( colorDist(rng), colorDist(rng), colorDist(rng) );
			brd.DrawCell(loc, c);
		}
	}*/
}
