#include "sdlcolor.h"

SdlColor::SdlColor(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue)
{
    _color = new SDL_Color;

    _color->a = alpha;
    _color->r = red;
    _color->g = green;
    _color->b = blue;
}

SdlColor::~SdlColor(){
    delete _color;
}

uint8_t SdlColor::getRed() const {
    return _color->r;
}

uint8_t SdlColor::getGreen() const {
    return _color->g; 
}

uint8_t SdlColor::getBlue() const {
    return _color->b;
}

uint8_t SdlColor::getAlpha() const {
    return _color->a;
}
