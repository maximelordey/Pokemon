#ifndef SDL_TEXTURE_H
#define SDL_TEXTURE_H

#include "itexture.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class SdlTexture: public ITexture {
	public:
		SdlTexture(std::string& path);
		~SdlTexture();

		SDL_Surface* getSurface() const;

	private: 
		SDL_Surface* _surface;
};

#endif
