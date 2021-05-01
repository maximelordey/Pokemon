#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <SDL2/SDL.h>
#include <filesystem>
#include <optional>

class Surface {
	public:
		Surface(const std::path& path);
		~Surface();
		Surface(const Surface& surface);
		Surface(Surface&& surface);

		SDL_Surface* get();

		Surface blit(const std::optionnal<Rectangle>& extract_zone) const;


		Surface& operator=(const Surface& surface);
		Surface& operator=(Surface&& surface);	
	private:
		SDL_Surface* sdl_surface;
};

#endif
