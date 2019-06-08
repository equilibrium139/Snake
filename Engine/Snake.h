#pragma once

#include "Board.h"
#include "Location.h"
#include "MainWindow.h"

class Snake {
public:
	Snake(const Location& loc);
	void Move();
	void Grow();
	void Draw(Board& brd) const;
	void ProcessMovement(MainWindow& wnd);
	bool intersecting() const;
	bool pastEdge(const Board& brd) const
	{
		int x = segments[0].location().x;
		int y = segments[0].location().y;
		return x < 0 || x >= brd.GetGridWidth() || y < 0 || y >= brd.GetGridHeight();
	}
	Location location() const
	{
		return segments[0].location();
	}
private:
	class Segment {
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void Follow(const Segment& next);
		void Draw(Board& brd) const;
		void MoveBy(const Location& delta_loc);
		Location location() const
		{
			return m_loc;
		}
	private:
		Location m_loc;
		Color m_c;
	};
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nMaxSegments = 100;
	Location deltaLoc;
	Segment segments[nMaxSegments];
	int nSegments = 1;

};