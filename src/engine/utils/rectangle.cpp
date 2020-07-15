#include "rectangle.h"

Rectangle::Rectangle(int32_t x, int32_t y, uint32_t width, uint32_t height){
	_point = new Point(x, y);
	_dimension = new Dimension(width, height);
}

Rectangle::Rectangle(const Rectangle& rectangle) {
	_point = new Point(*(rectangle._point));
	_dimension = new Dimension(*(rectangle._dimension));
}

Rectangle::Rectangle(Rectangle&& rectangle) {
	_point = rectangle._point;
	_dimension = rectangle._dimension;
	
	rectangle._point = nullptr;
	rectangle._dimension = nullptr;
}

Rectangle::~Rectangle(){
	delete _point;
	delete _dimension;
}

int32_t Rectangle::getX() const {
	return _point->getX();
}

int32_t Rectangle::getY() const{
	return _point->getY();
}

void Rectangle::setX(int32_t x){
	_point->move(x, getY());
}

void Rectangle::setY(int32_t y){
	_point->move(getX(), y);
}

uint32_t Rectangle::getWidth() const{
	return _dimension->getWidth();
}

uint32_t Rectangle::getHeight() const{
	return _dimension->getHeight();
}
void Rectangle::setWidth(uint32_t width){
	_dimension->setSize(width, getHeight());
}

void Rectangle::setHeight(uint32_t height){
	_dimension->setSize(getWidth(), height);
}

void Rectangle::move(int32_t x, int32_t y){
	_point->move(x, y);
}

void Rectangle::translate(int32_t dx, int32_t dy){
	_point->translate(dx, dy);
}

Rectangle& Rectangle::operator=(const Rectangle& rectangle) {
	if (this != &rectangle){
		_point->move(rectangle._point->getX(), rectangle._point->getY());
		_dimension->setSize(rectangle._dimension->getWidth(), rectangle._dimension->getHeight());
	}
	return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& rectangle) {
	if (this != &rectangle){
		delete _point;
		delete _dimension;

		_point = rectangle._point;
		_dimension = rectangle._dimension;
	
		rectangle._point = nullptr;
		rectangle._dimension = nullptr;
	}
	return *this;
}
