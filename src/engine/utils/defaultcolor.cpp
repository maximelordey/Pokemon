#include "defaultcolor.h"

DefaultColor::DefaultColor(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue)
    : _alpha(alpha), _red(red), _green(green), _blue(blue)
{}

DefaultColor::~DefaultColor(){}

uint8_t DefaultColor::getRed() const {
    return _red;
}

uint8_t DefaultColor::getGreen() const {
    return _green; 
}

uint8_t DefaultColor::getBlue() const {
    return _blue;
}

uint8_t DefaultColor::getAlpha() const {
    return _alpha;
}
