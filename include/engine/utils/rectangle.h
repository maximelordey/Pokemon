#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "irectangle.h"
#include "point.h"
#include "dimension.h"

class Rectangle : public IRectangle{
	public:
		Rectangle(int32_t x, int32_t y, uint32_t width, uint32_t height);
		Rectangle(const Rectangle& rectangle);
		Rectangle(Rectangle&& rectangle);
		~Rectangle();

		int32_t getX() const;
		int32_t getY() const;
		void setX(int32_t x);
		void setY(int32_t y);

		uint32_t getWidth() const;
		uint32_t getHeight() const;
		void setWidth(uint32_t width);
		void setHeight(uint32_t height);

		void move(int32_t x, int32_t y);
		void translate(int32_t dx, int32_t dy);

		Rectangle& operator=(const Rectangle& rectangle);
		Rectangle& operator=(Rectangle&& rectangle);

	private:
		Point* _point;
		Dimension* _dimension;
};

#endif
