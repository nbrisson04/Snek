#include "Board.h"
#include <assert.h>

int Board::GetGridWidth() const { return width; }
int Board::GetGridHeight() const { return height; }

Board::Board(Graphics& gfx)
	: gfx(gfx) {

}

void Board::DrawCell(const Location& loc, const Color c) const {
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x*dimension, loc.y * dimension, dimension, dimension, c);
}