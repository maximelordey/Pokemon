#ifndef ITEXTURE_H
#define ITEXTURE_H

class ITexture {
	public:
		virtual int getAlphaMode(uint8_t &alpha) = 0;
		virtual int setAlphaMode(uint8_t alpha) = 0;
}

#endif
