#include "texture.h"
#include <SDL_image.h>

Texture::Texture() {

}

Texture::Texture(const std::string& path) {
	_surface = IMG_Load(path.c_str());	
}

Texture::Texture(const Texture &texture) {
	_surface = SDL_ConvertSurface(texture._surface,texture._surface->format,0);
}

Texture::Texture(Texture &&texture) {
	_surface = texture._surface;
	texture._surface = nullptr;
}

Texture::~Texture() {
	SDL_FreeSurface(_surface);
}


SDL_Surface* Texture::getSurface() const {
	return _surface;
}

Texture& Texture::operator=(const Texture &texture) {
	if (this != &texture) {
	SDL_FreeSurface(_surface);
	_surface = SDL_ConvertSurface(texture._surface,texture._surface->format,0);
	}
	return *this;
}

Texture& Texture::operator=(Texture &&texture) {
	if (this != &texture) {
		SDL_FreeSurface(_surface);
		_surface = texture._surface;
		texture._surface = nullptr;
	}
	return *this;
}