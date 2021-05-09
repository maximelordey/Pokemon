#ifndef BLEND_MOD_HPP
#define BLEND_MOD_HPP

#include <SDL.h>
#include "color.hpp"

typedef struct BlendMod {
	SDL_BlendMode blendMod;
	Color color;
} BlendMod;


#endif

