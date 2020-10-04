#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include "SDL.h"
#include "rectangle.h"
#include "SDL_image.h"

class Surface {
	public:
		Surface();
		Surface(SDL_Surface& surface);
		Surface(std::string& path);
		Surface(const Surface& surface);
		Surface(Surface&& surface);
		~Surface();

		void setFormat(const SDL_PixelFormat& pixelFormat);
		SDL_PixelFormat& getFormat() const;

		Surface blitting(const Surface& surface,const Rectangle& area) const;
		const SDL_Surface& getSurface() const;

		Surface& operator=(const Surface &surface);
		Surface& operator=(Surface &&surface);

	private:
		SDL_Surface *_surface;
};

#endif
