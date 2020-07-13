#include "sdl_surface.h"


SdlSurface::SdlSurface(std::string& path) {
	_surface = IMG_Load(path.c_str());	
}

SdlSurface::~SdlSurface(
	SDL_FreeSurface(_surface);
);