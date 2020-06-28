#include "sdlpoint.h"


SdlPoint::SdlPoint(int32_t x, int32_t y)
{
    _point = new SDL_Point;

    _point->x = x;
    _point->y = y;
}

SdlPoint::~SdlPoint(){
    delete _point;
}

int32_t SdlPoint::getX() const{
    return _point->x;
}

int32_t SdlPoint::getY() const {
    return _point->y;
}

void SdlPoint::move(int32_t x, int32_t y){
    _point->x = x;
    _point->y = y;
}


void SdlPoint::translate(int32_t dx, int32_t dy){
    point->x += dx;
    point->y += dy;
}
