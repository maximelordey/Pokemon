#ifndef SDL_RECTANGLE_H
#define SDL_RECTANGLE_H

#include "irectangle.h"
#include <SDL.h>

class SdlRectangle : public IRectangle{
    public:
        SdlRectangle(int32_t x, int32_t y, uint32_t width, uint32_t height);
        ~SdlRectangle();

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
		SDL_Rect* _rect;
};

#endif
