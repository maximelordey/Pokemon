#include "rectangle.h"

Rectangle::Rectangle() : 
	_x(0), _y(0), _width(0), _height(0)
{}

Rectangle::Rectangle(int32_t x, int32_t y, uint32_t width, uint32_t height) : 
	_x(x), _y(y), _width(width), _height(height)
{}

Rectangle::Rectangle(const Rectangle& rectangle) {
	_x = rectangle._x;
	_y = rectangle._y;
	_width = rectangle._width;
	_height = rectangle._height;
}

Rectangle::Rectangle(Rectangle&& rectangle) {
	_x = rectangle._x;
	_y = rectangle._y;
	_width = rectangle._width;
	_height = rectangle._height;
}

Rectangle::~Rectangle(){}

void Rectangle::move(int32_t x, int32_t y){
	_x = x;
	_y = y;
}

void Rectangle::translate(int32_t dx, int32_t dy){
	_x += dx;
	_y += dy;
}

Rectangle& Rectangle::operator=(const Rectangle& rectangle) {
	if (this != &rectangle){
		_x = rectangle._x;
		_y = rectangle._y;
		_width = rectangle._width;
		_height = rectangle._height;	
	}
	return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& rectangle) {
	if (this != &rectangle){
		_x = rectangle._x;
		_y = rectangle._y;
		_width = rectangle._width;
		_height = rectangle._height;
	}
	return *this;
}
