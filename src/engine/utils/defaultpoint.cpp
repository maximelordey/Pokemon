#include "defaultpoint.h"


DefaultPoint::DefaultPoint(int32_t x, int32_t y)
    : _x(x), _y(y)
{}

DefaultPoint::~DefaultPoint(){}

int32_t DefaultPoint::getX() const{
    return _x;
}

int32_t DefaultPoint::getY() const {
    return _y;
}

void DefaultPoint::move(int32_t x, int32_t y){
    _x = x;
    _y = y;
}


void DefaultPoint::translate(int32_t dx, int32_t dy){
    _x += dx;
    _y += dy;
}