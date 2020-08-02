#include "dimension.h"

Dimension::Dimension(uint32_t width, uint32_t height)
	: _width(width), _height(height)
{}

Dimension::Dimension(const Dimension& dimension) {
	setSize(dimension._width, dimension._height);
}

Dimension::Dimension(Dimension&& dimension) {
	setSize(dimension._width, dimension._height);
}

Dimension::~Dimension(){}

uint32_t Dimension::getWidth() const{
	return _width;
}

uint32_t Dimension::getHeight() const{
	return _height;
}

void Dimension::setSize(uint32_t width, uint32_t height){
	_width = width;
	_height = height;
}

Dimension& Dimension::operator=(const Dimension& dimension){
	if (this != &dimension){
		setSize(dimension._width, dimension._height);
	}
	return *this;
}

Dimension& Dimension::operator=(Dimension&& dimension){
	if (this != &dimension){
		setSize(dimension._width, dimension._height);
	}
	return *this;
}
