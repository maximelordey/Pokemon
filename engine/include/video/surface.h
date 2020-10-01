#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include "SDL.h"

class Surface {
	public:
		Surface();
		Surface(std::string &path);
		Surface(const Surface &surface);
		Surface(Surface &&surface);
		~Surface();


		Surface &operator=(const Surface &surface);
		Surface &operator=(Surface &&surface);

	private:
		SDL_Surface *_surface;
};

#endif
