#ifndef IMAGE_TYPEDEF_HPP
#define IMAGE_TYPEDEF_HPP

#include <SDL2/SDL.h>
#include <optional>
#include <memory>

#include "color.hpp"

struct BlendMod;
typedef std::optional<BlendMod> OptBlendMod;
typedef std::shared_ptr<BlendMod> SharedBlendMod;
typedef std::unique_ptr<BlendMod> UniqueBlendMod;
typedef std::weak_ptr<BlendMod> WeakBlendMod;

typedef uint32_t PixelFormatEnum;
typedef int Pitch;
typedef int PixelDepth;
typedef	int TextureAccess;

struct BlendMod {
	SDL_BlendMode blendMod;
	Color color;
};


#endif
