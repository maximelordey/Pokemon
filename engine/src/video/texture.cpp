#include "texture.h"
#include <SDL_image.h>


Texture::Texture(const std::string& path) {
	_surface = IMG_Load(path.c_str());	
}

Texture::~Texture() {
	SDL_FreeSurface(_surface);
}


SDL_Surface* Texture::getSurface() const {
	return _surface;
}
