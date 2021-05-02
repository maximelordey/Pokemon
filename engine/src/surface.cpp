#include "surface.hpp"

#include <SDL2/SDL_image.h>
#include <stdexcept>

const Dimension Surface::DEFAULT_DIMENSION = Dimension{0, 0};
const uint32_t Surface::DEFAULT_DEPTH = 0;
const SDL_PixelFormatEnum Surface::DEFAULT_FORMAT = SDL_PIXELFORMAT_UNKNOWN;

Surface::Surface() {
	sdl_surface = SDL_CreateRGBSurfaceWithFormat(
		0,
		DEFAULT_DIMENSION.width,
		DEFAULT_DIMENSION.height,
		DEFAULT_DEPTH,
		DEFAULT_FORMAT
	);

	if (sdl_surface == nullptr) {
		throw std::runtime_error("Couldn't create the surface !");
	}

}

Surface::Surface(const SurfaceCreateInfo& infos) {
	if (infos.pixels == nullptr) {
		sdl_surface = SDL_CreateRGBSurfaceWithFormat(
			0,
			infos.dimension.width,
			infos.dimension.height,
			infos.pixel_depth,
			infos.format
		);
	} else {
		int pitch = (infos.dimension.width * infos.pixel_depth) / 8;
		sdl_surface = SDL_CreateRGBSurfaceWithFormatFrom(
			infos.pixels,
			infos.dimension.width,
			infos.dimension.height,
			infos.pixel_depth,
			pitch,
			infos.format
		);
	}

	if (sdl_surface == nullptr) {
		throw std::runtime_error("Couldn't create the surface !");
	}
}

Surface::~Surface() {
	SDL_FreeSurface(sdl_surface);
}

Surface::Surface(const Surface& surface) {
	*this = surface;
}

Surface::Surface(Surface&& surface) {
	*this = surface;
}

Surface Surface::convertSurface(const SDL_PixelFormat& format) const {
	Surface surface;
	surface.sdl_surface = SDL_ConvertSurface(sdl_surface, &format, 0);
	return surface;
}

void Surface::fillRect(const std::optional<Rectangle>& rectangle, const Color& color) {
	uint32_t sdl_color = SDL_MapRGBA(sdl_surface->format, color.red, color.green, color.blue, color.alpha);
	if (rectangle.has_value()) {
		SDL_Rect sdl_rectangle{rectangle.value().origin.x, rectangle.value().origin.y,
			rectangle.value().dimension.width, rectangle.value().dimension.height};
		SDL_FillRect(sdl_surface, &sdl_rectangle, sdl_color);
	} else {
		SDL_FillRect(sdl_surface, nullptr, sdl_color);
	}
}

void Surface::fillRects(Rectangle* rectangle, size_t count, const Color& color) {
	uint32_t sdl_color = SDL_MapRGBA(sdl_surface->format, color.red, color.green, color.blue, color.alpha);
	const SDL_Rect* ptr_sdl_rect = reinterpret_cast<SDL_Rect*>(rectangle);
	SDL_FillRects(sdl_surface, ptr_sdl_rect, count, sdl_color);
}

Surface Surface::blit(const std::optional<Rectangle>& rectangle) const {
	Surface surface;
	SDL_Rect sdl_rectangle;
	if (rectangle.has_value()) {
		sdl_rectangle.x = rectangle.value().origin.x;
		sdl_rectangle.y = rectangle.value().origin.y;
		sdl_rectangle.w = rectangle.value().dimension.width;
		sdl_rectangle.h = rectangle.value().dimension.height;
	}
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


Surface& Surface::operator=(const Surface& surface) {
	sdl_surface = SDL_CreateRGBSurfaceFrom(
		surface.sdl_surface->pixels,
		surface.sdl_surface->w,
		surface.sdl_surface->h,
		surface.sdl_surface->format->BytesPerPixel,
		surface.sdl_surface->pitch,
		surface.sdl_surface->format->Rmask,
		surface.sdl_surface->format->Gmask,
		surface.sdl_surface->format->Bmask,
		surface.sdl_surface->format->Amask
	);
}

Surface& Surface::operator=(Surface&& surface) {
	sdl_surface = surface.sdl_surface;
	surface.sdl_surface = nullptr;
}
