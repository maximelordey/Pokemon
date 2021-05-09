#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <SDL2/SDL.h>
#include <optional>
#include <vector>

#include "dimension.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "blend_mod.hpp"

class Surface;
typedef struct SurfaceCreateInfo SurfaceCreateInfo;
typedef uint32_t PixelFormatEnum;

class Surface {
	private:
		static const Dimension DEFAULT_DIMENSION;
		static const uint32_t DEFAULT_DEPTH;
		static const SDL_PixelFormatEnum DEFAULT_FORMAT;

	public:
		Surface();
		Surface(const SurfaceCreateInfo& infos);
		~Surface();
		Surface(const Surface& surface) = delete;
		Surface(Surface&& surface);

		SDL_Surface* get() const;

		Surface convertSurface(const SDL_PixelFormat& format) const;		
		
		Surface blit(const Rectangle& rectangle) const;

		Rectangle getClipRect() const;
		Color getColorKey() const;
		BlendMod getSurfaceBlendMod() const;
		void setClipRect(const Rectangle& rectangle);
		void setColorKey(const Color& color);
		void setBlendMod(const BlendMod& blendMod);
		void removeColorKey();
		void removeBlendMod();
		void removeClipRect();

		void enableRLE();
		void disableRLE();

		void lockSurface();
		void unlockSurface();

		Surface& operator=(const Surface& surface) = delete;
		Surface& operator=(Surface&& surface);	
	private:
		SDL_Surface* sdl_surface;
};

struct SurfaceCreateInfo {
	void* pixels;
	Dimension dimension;
	int pixel_depth;
	int pitch;
	PixelFormatEnum format;
};

#endif
