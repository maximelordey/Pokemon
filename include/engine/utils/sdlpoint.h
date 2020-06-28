#ifndef DEFAULT_POINT_H
#define DEFAULT_POINT_H

#include "ipoint.h"
#include <SDL.h>

class SdlPoint : public IPoint {
	public:
    SdlPoint(int32_t x, int32_t y);
    ~SdlPoint();

		int32_t getX() const override;
		int32_t getY() const override;

		void move(int32_t x, int32_t y) override;
		void translate(int32_t dx, int32_t dy) override;

  public:
    SDL_Point* _point;  

};

#endif
