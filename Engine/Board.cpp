#include "Board.h"

Board::Board(Graphics & gfx)
	:m_gfx(gfx)
{
}

void Board::DrawCell(const Location & loc, Color c)
{
	m_gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}
