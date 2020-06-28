#include "defaultdimension.h"

DefaultDimension::DefaultDimension(uint32_t width, uint32_t height)
    : _width(width), _height(height)
{}

DefaultDimension::~DefaultDimension(){}

uint32_t DefaultDimension::getWidth() const{
    return _width;
}

uint32_t DefaultDimension::getHeight() const{
    return _height;
}

void DefaultDimension::setSize(uint32_t width, uint32_t height){
    if ( width > 0 && height > 0 ){
        _width = width;
        _height = height;
    }
}
