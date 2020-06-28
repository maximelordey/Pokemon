#ifndef DEFAULT_COLOR_H
#define DEFAULT_COLOR_H

#include "icolor.h"

class DefaultColor : public IColor {
	public:
    DefaultColor(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue);
    ~DefaultColor();

		uint8_t getRed() const override;
		uint8_t getGreen() const override;
		uint8_t getBlue() const override;
		uint8_t getAlpha() const override;

    private:
        uint8_t _red;
        uint8_t _green;
        uint8_t _blue;
        uint8_t _alpha;
};

#endif
