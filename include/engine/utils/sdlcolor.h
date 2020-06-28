#ifndef SDL_COLOR_H
#define SDL_COLOR_H

#include "icolor.h"

class SdlColor : public IColor {
	public:
    SdlColor(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue);
    ~SdlColor();

	uint8_t getRed() const override;
	uint8_t getGreen() const override;
	uint8_t getBlue() const override;
	uint8_t getAlpha() const override;

  private:
	SDL_Color* _color;  
};

#endif
