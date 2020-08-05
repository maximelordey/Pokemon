#include "color.h"

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
: _red(red), _green(green), _blue(blue), _alpha(alpha)
{}

Color::Color(const Color& color) {
	_alpha = color._alpha;
	_red = color._red;
	_green = color._green;
	_blue = color._blue;
}

Color::Color(Color&& color) {
	_alpha = color._alpha;
	_red = color._red;
	_green = color._green;
	_blue = color._blue;
}

Color::~Color(){}

uint8_t Color::getRed() const {
	return _red;
}

uint8_t Color::getGreen() const {
	return _green; 
}

uint8_t Color::getBlue() const {
	return _blue;
}

uint8_t Color::getAlpha() const {
	return _alpha;
}

Color& Color::operator=(const Color& color) {
	if (this != &color) {
		_alpha = color._alpha;
		_red = color._red;
		_green = color._green;
		_blue = color._blue;
	}	
	return *this;
}

Color& Color::operator=(Color&& color) {
	if (this != &color) {
		_alpha = color._alpha;
		_red = color._red;
		_green = color._green;
		_blue = color._blue;
	}	
	return *this;
}
