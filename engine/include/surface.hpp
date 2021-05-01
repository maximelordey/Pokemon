#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <SDL2/SDL.h>
#include <filesystem>
#include <optional>
#include <vector>

#include "dimension.hpp"

class Surface;
typedef struct Palette Palette;
typedef struct SurfaceCreateInfo SurfaceCreateInfo;
typedef struct PixelFormat PixelFormat;


class Surface {
	private:
		static const uint32_t DEFAULT_WIDTH;
		static const Dimension DEFAULT_DIMENSION;
		static const uint32_t DEFAULT_RED_MASK;
		static const uint32_t DEFAULT_GREEN_MASK;
		static const uint32_t DEFAULT_BLUE_MASK;
		static const uint32_t DEFAULT_ALPHA_MASK;

	public:
		Surface();
		Surface(const SurfaceCreateInfo& infos);
		Surface(const std::path& path);
		~Surface();
		Surface(const Surface& surface);
		Surface(Surface&& surface);
		SDL_Surface* get();

		Surface convertSurface(const PixelFormat& format) const;
		void fillRect(const std::optionnal<Rectangle>& rectangle, const Color& color);
		void fillRects(const Rectangle* rectangle, size_t count, const Color& color);
		
		Surface blit(const std::optionnal<Rectangle>& extract_zone) const;
		Surface	blitScaled(const std::optionnal<Rectangle>& extract_zone) const;

		Rectangle getClipRect() const;
		Color getColorKey() const;
		AlphaMod getSurfaceAlphaMod() const;
		BlendMod getSurfaceBlendMod() const;
		ColorMod getSurfaceColorMod() const;
		void setClipRect(const Rectangle& rectangle);
		void setColorKey(const Color& color);
		void setAlphaMod(const AlpaMod& alphaMod);
		void setBlendMode(const BlendMod& blendMod);
		void setColorMod(const ColorMod& ColorMod);
		void setPalette(const Palette& palette);

		void enableRLE();
		void disableRLE();

		void lockSurface();
		void unlockSurface();

		Surface& operator=(const Surface& surface);
		Surface& operator=(Surface&& surface);	
	private:
		SDL_Surface* sdl_surface;
};

struct PixelFormat {

};

struct Palette {
	std::vector<Color> colors;
};

struct SurfaceCreateInfo {
	Dimension dimension
	int depth;
	uint32_t red_mask;
	uint32_t green_mask;
	uint32_t blue_mask;
	uint32_t alpha_mask;
};

#endif
