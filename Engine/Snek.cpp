#include "Snek.h"
#include <assert.h>

Snek::Snek(const Location & loc) {
	segments[0].InitHead(loc);
}

void Snek::MoveBy(const Location & delta_loc) {
	for (int i = nSegments - 1; i > 0; --i)
		segments[i].Follow(segments[i - 1]);
	segments[0].MoveBy(delta_loc);
}

void Snek::Grow() {
	if (nSegments < nSegmentsMax)
		++nSegments;
}

void Snek::Draw(Board & brd) const {
	for (int i; i < nSegments; ++i)
		segments[i].Draw(brd);
}

void Snek::Segment::InitHead(const Location& _loc) {
	loc = _loc;
	c = Snek::headColor;
}

void Snek::Segment::InitBody() {
	c = Snek::bodyColor;
}

void Snek::Segment::Follow(const Segment& next) {
	loc = next.loc;
}

void Snek::Segment::MoveBy(const Location & delta_loc) {
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc += delta_loc;
}

void Snek::Segment::Draw(Board& brd) const {
	brd.DrawCell(loc, c);
}
