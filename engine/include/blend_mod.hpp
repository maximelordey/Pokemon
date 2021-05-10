#ifndef BLEND_MOD_HPP
#define BLEND_MOD_HPP

#include <SDL.h>
#include <optional>
#include <memory>

#include "color.hpp"

struct BlendMod;
typedef std::optional<BlendMod> OptBlendMod;
typedef std::shared_ptr<BlendMod> SharedBlendMod;
typedef std::unique_ptr<BlendMod> UniqueBlendMod;
typedef std::weak_ptr<BlendMod> WeakBlendMod;

struct BlendMod {
	SDL_BlendMode blendMod;
	Color color;
};


#endif
