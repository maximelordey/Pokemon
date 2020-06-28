#include "sdlrectangle.h"

SdlRectangle::SdlRectangle(int32_t x, int32_t y, uint32_t width, uint32_t height){
    _rect = new SDL_Rect;
    _rect->x = x;
    _rect->y = y;
    _rect->w = width;
    _rect->h = height;

}

SdlRectangle::~SdlRectangle(){
    delete _rect;
}

int32_t SdlRectangle::getX() const {
    return _rect->x;
}

int32_t SdlRectangle::getY() const{
    return _rect->y;
}

void SdlRectangle::setX(int32_t x){
    _rect->x = x;
}

void SdlRectangle::setY(int32_t y){
    _rect->y = y;
}

uint32_t SdlRectangle::getWidth() const{
    return _rect->w;
}

uint32_t SdlRectangle::getHeight() const{
    return _rect->h;
}
void SdlRectangle::setWidth(uint32_t width){
    _rect->w = width;
}

void SdlRectangle::setHeight(uint32_t height){
    _rect->h = height;
}

void SdlRectangle::move(int32_t x, int32_t y){
    _rect->x = x;
    _rect->y = y;
}

void SdlRectangle::translate(int32_t dx, int32_t dy){
    _rect->x += dx;
    _rect->y += dy;
}
