#ifndef DEFAULT_POINT_H
#define DEFAULT_POINT_H

#include "ipoint.h"

class DefaultPoint : public IPoint {
	public:
        DefaultPoint(int32_t x, int32_t y);
        ~DefaultPoint();

		int32_t getX() const override;
		int32_t getY() const override;

		void move(int32_t x, int32_t y) override;
		void translate(int32_t dx, int32_t dy) override;

    public:
        uint32_t _x;
        uint32_t _y;
};

#endif