#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL.h>
#include "renderer.hpp"
#include "surface.hpp"

class Texture {
	public:
		Texture(const Surface& surface, const Renderer& renderer);


	private:
		SDL_Texture* sdl_texture;
};

#endif
