#include "Goal.h"

void Goal::Draw()
{
	m_brd.DrawCell(m_loc, color);
}

void Goal::Respawn()
{
	m_loc = { xDist(rng), yDist(rng) };
}
