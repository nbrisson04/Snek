#pragma once
struct Location {
	Location& operator+=(const Location& rhs) {
		x += rhs.x;
		y += rhs.y;
	};
	int x;
	int y;
};