#pragma once

#include "Board.h"
#include "Colors.h"
#include "Location.h"
#include <random>

class Goal {	
	Board& m_brd;
	Location m_loc;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	static constexpr Color color = Colors::Red;
public:
	Goal(Board& brd)
		:m_brd{ brd }, 
		rng(std::random_device()()),
		xDist(0, brd.GetGridWidth() - 1),
		yDist(0, brd.GetGridHeight() - 1)
	{
		Respawn();
	}
	void Draw();
	void Respawn();
	Location location() const
	{
		return m_loc;
	}
};