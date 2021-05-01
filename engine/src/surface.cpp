#include "surface.hpp"

#include <SDL2/SDL_image.h>
#include <stdexcept>

Surface::Surface(const std::path& path) {
	sdl_surface = SDL_LoadBMP(path.c_str());

	if (sdl_surface == nullptr) {
		throw std::runtime_error("Couldn't load the surface !");
	}
}

Surface::Surface(const Surface& surface) {
	*this = surface
}

Surface::Surface(Surface&& surface) {
	*this = surface
}

Surface::operator=(const Surface& surface) {
	sdl_surface = SDL_CreateRGBSurfaceFrom(
		surface.sdl_surface->pixels,
		surface.sdl_surface->w,
		surface.sdl_surface->h,
		surface.sdl_surface->format->BytesPerPixel,
		surface.sdl_surface->pitch,
		surface.sdl_surface->format->Rmask,
		surface.sdl_surface->format->Gmask,
		surface.sdl_surface->format->Bmask
		surface.sdl_surface->format->Amask,
	)
}

Surface::operator=(Surface&& surface) {
	sdl_surface = surface.sdl_surface;
	surface.sdl_surface = nullptr;
}
