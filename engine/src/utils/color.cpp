#include "color.h"

Color::Color()
: _red(0), _green(0), _blue(0), _alpha(0)
{}

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
