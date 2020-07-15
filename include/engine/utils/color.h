#ifndef COLOR_H
#define COLOR_H

#include "icolor.h"

class Color : public IColor {
	public:
		Color(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue);
		Color(Color& color);
		Color(Color&& color);	
		~Color();

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
