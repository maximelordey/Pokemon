#include "renderer.h"

Renderer::Renderer(Window& window) {
	 _renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_SOFTWARE);
 }

Renderer::~Renderer(){
	SDL_DestroyRenderer(_renderer);
}

Color Renderer::getColor() const {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;

	SDL_GetRenderDrawColor(_renderer, &red, &green, &blue, &alpha);
	
	return Color(red, green, blue, alpha);
}

Dimension Renderer::getOutputSize()const {
	int32_t width;
	int32_t height;

	SDL_GetRendererOutputSize(_renderer, &width, &height);

	return Dimension(width, height);
}

void Renderer::clear() {
	SDL_RenderClear(_renderer);
}

void Renderer::drawTexture(const Surface &surface, const Rectangle *src, const Rectangle *dest) {
	SDL_Rect* src_ptrRect = nullptr;
	SDL_Rect* dest_ptrRect = nullptr;

	if (src) {
		SDL_Rect srcRect;
		srcRect.x = src->getX();
		srcRect.y = src->getY();
		srcRect.w = src->getWidth();
		srcRect.h = src->getHeight();
		src_ptrRect = &srcRect;
	}

	if (dest) {
		SDL_Rect destRect;
		destRect.x = dest->getX();
		destRect.y = dest->getY();
		destRect.w = dest->getWidth();
		destRect.h = dest->getHeight();
		dest_ptrRect = &destRect;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface.getSurface());
	SDL_RenderCopy(_renderer, texture, src_ptrRect, dest_ptrRect);
	SDL_DestroyTexture(texture);
}

void Renderer::drawTexture(const Surface &surface, const Rectangle *dest) {
	drawTexture(surface,nullptr,dest);
}

void Renderer::drawLine(const Line &line) {
	SDL_RenderDrawLine(_renderer,line._x1, line._y1, line._x2, line._y2);
}

void Renderer::drawPoint(const Point &p) {
	SDL_RenderDrawPoint(_renderer,p._x,p._y);
}

void Renderer::drawRect(const Rectangle &rectangle) {
	SDL_Rect rect;
	rect.x = rectangle._x;
	rect.y = rectangle._y;
	rect.w = rectangle._width;
	rect.h = rectangle._height;

	SDL_RenderDrawRect(_renderer,&rect);
}

void Renderer::fillRect(const Rectangle &rectangle) {
	SDL_Rect rect;
	rect.x = rectangle._x;
	rect.y = rectangle._y;
	rect.w = rectangle._width;
	rect.h = rectangle._height;

	SDL_RenderFillRect(_renderer,&rect);
}

Rectangle Renderer::getViewport() const {
	SDL_Rect viewport;
	SDL_RenderGetViewport(_renderer, &viewport);

	return Rectangle(viewport.x, viewport.y, viewport.w, viewport.h);
}

void Renderer::show() {
	SDL_RenderPresent(_renderer);
}

void Renderer::setViewport(const Rectangle &rectangle) {
	SDL_Rect viewport;
	viewport.x = rectangle._x;
	viewport.y = rectangle._y;
	viewport.w = rectangle._width;
	viewport.h = rectangle._height;

    SDL_RenderSetViewport(_renderer, &viewport );
}

void Renderer::setColor(const Color &color) {
	SDL_SetRenderDrawColor(_renderer, color._red, color._green, color._blue, color._alpha);
}
