#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cstdint>

#include "point.h"
#include "dimension.h"

class Rectangle {
	public:
		Rectangle();
		Rectangle(int32_t x, int32_t y, uint32_t width, uint32_t height);
		Rectangle(const Rectangle& rectangle);
		Rectangle(Rectangle&& rectangle);
		~Rectangle();

		void move(int32_t x, int32_t y);
		void translate(int32_t dx, int32_t dy);

		Rectangle& operator=(const Rectangle& rectangle);
		Rectangle& operator=(Rectangle&& rectangle);

	public:
		int32_t _x;
		int32_t _y;
		uint32_t _width;
		uint32_t _height;
};

#endif
