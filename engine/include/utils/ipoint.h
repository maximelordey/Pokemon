#ifndef IPOINT_H
#define IPOINT_H

#include <cstdint>

class IPoint {
	public:
		virtual int32_t getX() const = 0;
		virtual int32_t getY() const = 0;

		virtual void move(int32_t x, int32_t y) = 0;
		virtual void translate(int32_t dx, int32_t dy) = 0;
};

#endif
