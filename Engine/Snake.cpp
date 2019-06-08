#include "Snake.h"


Snake::Snake(const Location & loc)
	:deltaLoc{ 0, 0 }
{
	segments[0].InitHead(loc);
}

void Snake::Move()
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(deltaLoc);
}

void Snake::Grow()
{
	if (nSegments < nMaxSegments)
	{
		nSegments++;
		segments[nSegments - 1].InitBody();
		segments[nSegments - 1].Follow(segments[nSegments - 2]);
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

void Snake::ProcessMovement(MainWindow& wnd)
{
	if (deltaLoc.x != 0 && deltaLoc.y == 0)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			deltaLoc = { 0, -1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			deltaLoc = { 0, 1 };
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			deltaLoc = { -1, 0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			deltaLoc = { 1, 0 };
		}
	}
}

bool Snake::intersecting() const
{
	for (int i = 1; i < nSegments; ++i)
	{
		if (segments[0].location() == segments[i].location())
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location & loc)
{
	m_loc = loc;
	m_c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	m_c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment & next)
{
	m_loc = next.m_loc;
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(m_loc, m_c);
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	m_loc.Add(delta_loc);
}
