#include "surface.hpp"

#include <SDL2/SDL_image.h>
#include <stdexcept>

Surface::Surface() {
	const Dimension dimension{0, 0};
	const PixelDepth pixel_depth = 0;
	const SDL_PixelFormatEnum format = SDL_PIXELFORMAT_UNKNOWN;

	sdl_surface = SDL_CreateRGBSurfaceWithFormat(
		0,
		dimension.width,
		dimension.height,
		pixel_depth,
		format
	);

	SDL_assert(sdl_surface);
}

Surface::Surface(const SurfaceCreateInfo& infos) {
	if (infos.pixels) {
		sdl_surface = SDL_CreateRGBSurfaceWithFormat(
			0,
			infos.dimension.width,
			infos.dimension.height,
			infos.pixel_depth,
			infos.format
		);
	} else {
		sdl_surface = SDL_CreateRGBSurfaceWithFormatFrom(
			infos.pixels,
			infos.dimension.width,
			infos.dimension.height,
			infos.pixel_depth,
			infos.pitch,
			infos.format
		);
	}

	SDL_assert(sdl_surface);
}

Surface::~Surface() {
	SDL_FreeSurface(sdl_surface);
}

Surface::Surface(Surface&& surface) 
	: sdl_surface(surface.sdl_surface)
{
		surface.sdl_surface = nullptr;
}

SDL_Surface& Surface::get() const {
	return *sdl_surface;
}

Surface Surface::convertSurface(const SDL_PixelFormat& format) const {
	Surface surface;
	surface.sdl_surface = SDL_ConvertSurface(sdl_surface, &format, 0);
	return surface;
}

Surface Surface::blit(const Rectangle& rectangle) const {
	SurfaceCreateInfo create_info;
	create_info.pixels = nullptr;
	create_info.dimension = rectangle.dimension;
	create_info.format = sdl_surface->format->format;
	create_info.pitch = sdl_surface->pitch;
	create_info.pixel_depth = sdl_surface->format->BitsPerPixel;
	Surface surface(create_info);

	SDL_Rect sdl_rectangle;
	sdl_rectangle.x = rectangle.origin.x;
	sdl_rectangle.y = rectangle.origin.y;
	sdl_rectangle.w = rectangle.dimension.width;
	sdl_rectangle.h = rectangle.dimension.height;

	SDL_BlitSurface(sdl_surface, &sdl_rectangle, surface.sdl_surface, nullptr);
	return surface;
}

Rectangle Surface::getClipRect() const {
	SDL_Rect sdl_rect;
	SDL_GetClipRect(sdl_surface, &sdl_rect);
	return Rectangle{Point{sdl_rect.x, sdl_rect.y},Dimension{sdl_rect.w, sdl_rect.h}};
}

Color Surface::getColorKey() const {
	uint32_t sdl_pixel;
	SDL_GetColorKey(sdl_surface, &sdl_pixel);

	Color color;
	SDL_GetRGBA(sdl_pixel, sdl_surface->format, &color.red, &color.green, &color.blue, &color.alpha);
	return color;
}
BlendMod Surface::getSurfaceBlendMod() const {
	BlendMod blendMod;
	SDL_GetSurfaceAlphaMod(sdl_surface, &blendMod.color.alpha);
	SDL_GetSurfaceBlendMode(sdl_surface, &blendMod.blendMod);
	SDL_GetSurfaceColorMod(sdl_surface, &blendMod.color.red, &blendMod.color.green, &blendMod.color.blue);
	return blendMod;
}	

void Surface::setClipRect(const Rectangle& rectangle) {
	SDL_Rect sdl_rect{rectangle.origin.x, rectangle.origin.y, rectangle.dimension.width, rectangle.dimension.height};
	SDL_SetClipRect(sdl_surface, &sdl_rect);
}

void Surface::setColorKey(const Color& color) {
	uint32_t sdl_color_key = SDL_MapRGBA(sdl_surface->format,
                   color.red, color.green, color.blue, color.alpha);
	SDL_SetColorKey(sdl_surface, 1, sdl_color_key);
}

void Surface::setBlendMod(const BlendMod& blendMod) {
	SDL_SetSurfaceAlphaMod(sdl_surface, blendMod.color.alpha);
	SDL_SetSurfaceBlendMode(sdl_surface, blendMod.blendMod);
	SDL_SetSurfaceColorMod(sdl_surface, blendMod.color.red, blendMod.color.green, blendMod.color.blue);
}

void Surface::removeColorKey() {
	SDL_SetColorKey(sdl_surface,0,0);
}

void Surface::removeBlendMod() {
	SDL_SetSurfaceBlendMode(sdl_surface,SDL_BLENDMODE_NONE);
}

void Surface::removeClipRect() {
	SDL_SetClipRect(sdl_surface, nullptr);
}

void Surface::enableRLE() {
	SDL_SetSurfaceRLE(sdl_surface, 1);
}

void Surface::disableRLE() {
	SDL_SetSurfaceRLE(sdl_surface, 0);
}

void Surface::lockSurface() {
	SDL_LockSurface(sdl_surface);
}

void Surface::unlockSurface() {
	SDL_UnlockSurface(sdl_surface);
}


Surface& Surface::operator=(Surface&& surface) {
	if (this != &surface) {
		sdl_surface = surface.sdl_surface;
		surface.sdl_surface = nullptr;
	}
	return *this;
}
