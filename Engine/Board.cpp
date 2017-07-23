#include "Board.h"
#include <assert.h>

int Board::GetGridWidth() {return width;}
int Board::GetGridHeight() {return height;}

Board::Board(Graphics & gfx) :
	gfx(gfx)
{

}

void Board::DrawCell(Location& loc, Color c) {
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x*dimension, loc.y * dimension, dimension, dimension, c);
}