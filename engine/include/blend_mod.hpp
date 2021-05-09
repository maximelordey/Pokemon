#ifndef BLEND_MOD_HPP
#define BLEND_MOD_HPP

#include <SDL2/SDL.h>
#include "color.hpp"

struct BlendMod {
	SDL_BlendMode blendMod;
	Color color;
};


#endif

