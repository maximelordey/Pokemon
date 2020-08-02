#ifndef ICOLOR_H
#define ICOLOR_H

#include <cstdint>

class IColor {

	public:
		virtual uint8_t getRed() const = 0;
		virtual uint8_t getGreen() const = 0;
		virtual uint8_t getBlue() const = 0;
		virtual uint8_t getAlpha() const = 0;
};

#endif
