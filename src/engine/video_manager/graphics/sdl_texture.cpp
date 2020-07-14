#include "sdl_texture.h"


SdlTexture::SdlTexture(std::string& path) {
	_surface = IMG_Load(path.c_str());	
}

SdlTexture::~SdlTexture() {
	SDL_FreeSurface(_surface);
}


SDL_Surface* SdlTexture::getSurface() const {
	return _surface;
}
