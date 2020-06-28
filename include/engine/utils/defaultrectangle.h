#ifndef DEFAULT_RECTANGLE_H
#define DEFAULT_RECTANGLE_H

#include "irectangle.h"
#include "ipoint.h"
#include "idimension.h"

class DefaultRectangle : public IRectangle{
    public:
        DefaultRectangle(int32_t x, int32_t y, uint32_t width, uint32_t height);
        ~DefaultRectangle();

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

    private:
        IPoint* _origin;
        IDimension* _dimension;
};

#endif