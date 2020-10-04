#include "surface.h"
#include "SDL_image.h"

Surface::Surface() {

}

Surface::Surface(SDL_Surface &surface) {
	_surface = &surface;
}

Surface::Surface(std::string &path) {
	_surface = IMG_Load(path.c_str());
}

Surface::Surface(const Surface &surface) {

}

Surface::Surface(Surface &&surface) {

}

Surface::~Surface() {
	SDL_FreeSurface(_surface);
}

void Surface::setFormat(const SDL_PixelFormat &pixelFormat) {
	SDL_Surface* newSurface = SDL_ConvertSurface(_surface, &pixelFormat, 0 );
	SDL_FreeSurface(_surface);
	_surface = newSurface;
}

SDL_PixelFormat &Surface::getFormat() const {
	return *(_surface->format);
}

Surface& blitting(const Surface& surface,const Rectangle& area) const {

}

const SDL_Surface& getSurface() const {
	
}

Surface &Surface::operator=(const Surface &surface) {
	return *this;
}

Surface &Surface::operator=(Surface &&surface) {
	return *this;
}
