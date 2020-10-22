#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include "SDL.h"
#include "rectangle.h"
#include "SDL_image.h"

class Surface {
	public:
		Surface();
		Surface(const std::string& path);
		Surface(SDL_Surface* surface);
		Surface(const Surface& surface);
		Surface(Surface&& surface);
		~Surface();

		void setFormat(const SDL_PixelFormat& pixelFormat);
		SDL_PixelFormat& getFormat() const;

		Surface blitting(const Rectangle& area) const;
		SDL_Surface* getSurface() const;

		Surface& operator=(const Surface &surface);
		Surface& operator=(Surface &&surface);

	private:
		SDL_Surface *_surface;
};

#endif
