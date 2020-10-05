#include "line.h"

Line::Line() : 
	_x1(0), _y1(0), _x2(0), _y2(0)
{}

Line::Line(int32_t x1, int32_t y1, int32_t x2, int32_t y2) : 
	_x1(x1), _y1(y1), _x2(x2), _y2(y2) 
{}

Line::Line(const Line &line) {
	_x1 = line._x1;
	_x2 = line._x1;
	_y1 = line._y1;
	_y2 = line._y2;
}

Line::Line(Line &&line) {
	_x1 = line._x1;
	_x2 = line._x1;
	_y1 = line._y1;
	_y2 = line._y2;	
}

Line::~Line() {}

Line &Line::operator=(const Line &line) {
	if (this != &line) {
		_x1 = line._x1;
		_x2 = line._x1;
		_y1 = line._y1;
		_y2 = line._y2;
	}
	return *this;
}

Line &Line::operator=(Line &&line) {
	if (this != &line) {
		_x1 = line._x1;
		_x2 = line._x1;
		_y1 = line._y1;
		_y2 = line._y2;
	}
	return *this;
}