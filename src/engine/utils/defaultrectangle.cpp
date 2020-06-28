#include "defaultrectangle.h"
#include "defaultpoint.h"
#include "defaultdimension.h"


DefaultRectangle::DefaultRectangle(int32_t x, int32_t y, uint32_t width, uint32_t height){
    _origin = new DefaultPoint(x, y);
    _dimension = new DefaultDimension(width ,height);
}

DefaultRectangle::~DefaultRectangle(){
    delete _origin;
    delete _dimension;
}

int32_t DefaultRectangle::getX() const {
    return _origin->getX();
}

int32_t DefaultRectangle::getY() const{
    return _origin->getY();
}

void DefaultRectangle::setX(int32_t x){
    _origin->move(x, _origin->getY());
}

void DefaultRectangle::setY(int32_t y){
    _origin->move(_origin->getX(), y);
}

uint32_t DefaultRectangle::getWidth() const{
    return _dimension->getWidth();
}

uint32_t DefaultRectangle::getHeight() const{
    return _dimension->getHeight();
}
void DefaultRectangle::setWidth(uint32_t width){
    _dimension->setSize(width, _dimension->getHeight());
}

void DefaultRectangle::setHeight(uint32_t height){
    _dimension->setSize(_dimension->getWidth(), height);
}

void DefaultRectangle::move(int32_t x, int32_t y){
    _origin->move(x, y);
}

void DefaultRectangle::translate(int32_t dx, int32_t dy){
    _origin->translate(dx, dy);
}