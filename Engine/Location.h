#pragma once

struct Location {
	void Add(const Location& loc)
	{
		x += loc.x;
		y += loc.y;
	}
	
	bool operator==(const Location& other)
	{
		return x == other.x && y == other.y;
	}
	int x;
	int y;
};