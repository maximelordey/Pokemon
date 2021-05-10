#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <SDL2/SDL.h>
#include <optional>
#include <vector>
#include <memory>

#include "dimension.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "blend_mod.hpp"

class Surface;
struct SurfaceCreateInfo;
typedef uint32_t PixelFormatEnum;
typedef int Pitch;
typedef int PixelDepth;

typedef std::shared_ptr<Surface> SharedSurface;
typedef std::unique_ptr<Surface> UniqueSurface;
typedef std::weak_ptr<Surface> WeakSurface;

class Surface {
	public:
		Surface();
		Surface(const SurfaceCreateInfo& infos);
		~Surface();
		Surface(const Surface& surface) = delete;
		Surface(Surface&& surface);

		SDL_Surface& get() const;

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
	PixelDepth pixel_depth;
	Pitch pitch;
	PixelFormatEnum format;
};

#endif
