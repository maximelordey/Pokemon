#ifndef ITEXTURE_H
#define ITEXTURE_H

#include <cstdint>

class ITexture {
	public:
		virtual uint8_t getAlphaMode() const = 0;
		virtual void setAlphaMode(uint8_t alpha) = 0;
}

#endif
