#ifndef SDL_SURFACE_H
#define SDL_SURFACE_H

#include "itexture.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class SdlSurface: public ITexture {
	public:
		SdlSurface(std::string& path);
		~SdlSurface();

		SDL_Surface* getSurface();

	private: 
		SDL_Surface* _surface;
};

#endif