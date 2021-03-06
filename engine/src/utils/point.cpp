#include "point.h"

Point::Point()
: _x(0), _y(0)
{}

Point::Point(int32_t x, int32_t y)
: _x(x), _y(y)
{}

Point::Point(const Point& point) {
	move(point._x, point._y);
}

Point::Point(Point&& point) {
	move(point._x, point._y);
}

Point::~Point(){}

void Point::move(int32_t x, int32_t y){
	_x = x;
	_y = y;
}

void Point::translate(int32_t dx, int32_t dy){
	_x += dx;
	_y += dy;
}

Point& Point::operator=(const Point& point) {
	if (this != &point) {
		move(point._x, point._y);
	}
	return *this;
}

Point& Point::operator=(Point&& point) {
	if (this != &point) {
		move(point._x, point._y);
	}
	return *this;
}
