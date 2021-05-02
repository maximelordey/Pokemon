#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <SDL2/SDL.h>
#include <filesystem>
#include <optional>
#include <vector>

#include "dimension.hpp"
#include "rectangle.hpp"
#include "color.hpp"

class Surface;
typedef struct SurfaceCreateInfo SurfaceCreateInfo;
typedef struct BlendMod BlendMod;

class Surface {
	private:
		static const Dimension DEFAULT_DIMENSION;
		static const uint32_t DEFAULT_DEPTH;
		static const SDL_PixelFormatEnum DEFAULT_FORMAT;

	public:
		Surface();
		Surface(const SurfaceCreateInfo& infos);
		~Surface();
		Surface(const Surface& surface);
		Surface(Surface&& surface);

		SDL_Surface* get();

		Surface convertSurface(const PixelFormat& format) const;		
		
		Surface blit(const std::optionnal<Rectangle>& extract_zone) const;
		Surface	blitScaled(const std::optionnal<Rectangle>& extract_zone) const;

		void fillRect(const std::optionnal<Rectangle>& rectangle, const Color& color);
		void fillRects(const Rectangle* rectangle, size_t count, const Color& color);

		Rectangle getClipRect() const;
		Color getColorKey() const;
		BlendMod getSurfaceBlendMod() const;
		void setClipRect(const Rectangle& rectangle);
		void setColorKey(const Color& color);
		void setBlendMode(const BlendMod& blendMod);
		void removeColorKey();
		void removeBlendMod();
		void removeClipRect();

		void enableRLE();
		void disableRLE();

		void lockSurface();
		void unlockSurface();

		Surface& operator=(const Surface& surface);
		Surface& operator=(Surface&& surface);	
	private:
		SDL_Surface* sdl_surface;
};

struct BlendMod {
	SDL_BlendMode blendMod;
	Color color;
};

struct SurfaceCreateInfo {
	void* pixels;
	Dimension dimension;
	int pixel_depth;
	SDL_PixelFormatEnum format;
};

#endif
