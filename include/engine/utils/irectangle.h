#ifndef IRECTANGLE_H
#define IRECTANGLE_H

#include <cstdint>

class IRectangle {
	public:
		virtual int32_t getX() const = 0;
		virtual int32_t getY() const = 0;
		virtual void setX(int32_t x) = 0;
		virtual void setY(int32_t y) = 0;
		
		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;
		virtual void setWidth(uint32_t width) = 0;
		virtual void setHeight(uint32_t height) = 0;

		virtual void move(int32_t x, int32_t y) = 0;
		virtual void translate(int32_t dx, int32_t dy) = 0;
}

#endif
