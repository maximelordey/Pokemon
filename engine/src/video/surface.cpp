#include "surface.h"
#include "SDL_image.h"

Surface::Surface() {

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

Surface &Surface::operator=(const Surface &surface) {
	return *this;
}

Surface &Surface::operator=(Surface &&surface) {
	return *this;
}
