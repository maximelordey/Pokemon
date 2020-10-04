#include "surface.h"

Surface::Surface() {

}

Surface::Surface(SDL_Surface &surface) {
	_surface = &surface;
}

Surface::Surface(std::string &path) {
	_surface = IMG_Load(path.c_str());
}

Surface::Surface(const Surface &surface) {
	_surface = SDL_DuplicateSurface(surface._surface);
}

Surface::Surface(Surface &&surface) {
	_surface = surface._surface;
	surface._surface = nullptr;
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

Surface Surface::blitting(const Surface& surface,const Rectangle& area) const {
	SDL_Rect srcRect;
	srcRect.x = area.getX();
	srcRect.y = area.getY();
	srcRect.w = area.getWidth();
	srcRect.h = area.getHeight();

	SDL_Surface* srcSurface = surface._surface;
	SDL_Surface* destSurface = SDL_CreateRGBSurface(srcSurface->flags,
	 	srcRect.w,
	 	srcRect.h,
        srcSurface->format->BitsPerPixel,
        srcSurface->format->Rmask,
        srcSurface->format->Gmask,
        srcSurface->format->Bmask,
        srcSurface->format->Amask
    );
	SDL_BlitSurface(srcSurface, &srcRect, destSurface, nullptr);
	return Surface(*destSurface);
}

const SDL_Surface& Surface::getSurface() const {
	return *_surface;
}

Surface &Surface::operator=(const Surface &surface) {
	if (this != &surface) {
		_surface = SDL_DuplicateSurface(surface._surface);
	}
	return *this;
}

Surface &Surface::operator=(Surface &&surface) {
	if (this != &surface) {
		_surface = surface._surface;
		surface._surface = nullptr;		
	}
	return *this;
}
