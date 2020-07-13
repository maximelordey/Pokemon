#ifndef SDL_SURFACE_H
#define SDL_SURFACE_H

#include <string>
#include <SDL.h>

class SdlSurface {
	public:
		SdlSurface(std::string& path);
		~SdlSurface();

	private: 
		SDL_Surface* _surface;
};

#endif