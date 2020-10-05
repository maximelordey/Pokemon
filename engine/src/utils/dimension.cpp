#include "dimension.h"

Dimension::Dimension()
	: _width(0), _height(0)
{}

Dimension::Dimension(uint32_t width, uint32_t height)
	: _width(width), _height(height)
{}

Dimension::Dimension(const Dimension& dimension) {
	_width = dimension._width;
	_height = dimension._height;
}

Dimension::Dimension(Dimension&& dimension) {
	_width = dimension._width;
	_height = dimension._height;
}

Dimension::~Dimension(){}

Dimension& Dimension::operator=(const Dimension& dimension){
	if (this != &dimension){
		_width = dimension._width;
		_height = dimension._height;
	}
	return *this;
}

Dimension& Dimension::operator=(Dimension&& dimension){
	if (this != &dimension){
		_width = dimension._width;
		_height = dimension._height;
	}
	return *this;
}
