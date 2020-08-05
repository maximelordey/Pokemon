#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

class Color {
	public:
		Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		Color(const Color &color);
		Color(Color &&color);	
		~Color();

		uint8_t getRed() const;
		uint8_t getGreen() const;
		uint8_t getBlue() const;
		uint8_t getAlpha() const;

		Color& operator=(const Color &color);
		Color& operator=(Color &&color);

	private:
		uint8_t _red;
		uint8_t _green;
		uint8_t _blue;
		uint8_t _alpha;  
};

#endif
