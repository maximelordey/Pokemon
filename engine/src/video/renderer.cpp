#include "renderer.h"

Renderer::Renderer(SDL_Window* window) {
	 _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
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

void Renderer::drawTexture(const ITexture &texture, const Rectangle *src, const Rectangle *dest) {
	/**
	SDL_Rect srcRect;SDL_Rect* srcRectPtr = nullptr;
	SDL_Rect destRect;SDL_Rect* destRectPtr = nullptr;	
	SDL_Surface* surface;

	SdlTexture sdlTexture = dynamic_cast<SdlTexture>(texture);

	if (src != nullptr){
		srcRect.x = src->getX();
		srcRect.y = src->getY();
		srcRect.w = src->getWidth();
		srcRect.h = src->getHeight();
		srcRectPtr = &srcRect;
	}

	if (dest != nullptr){
		destRect.x = dest->getX();
		destRect.y = dest->getY();
		destRect.w = dest->getWidth();
		destRect.h = dest->getHeight();
		destRectPtr = &destRect;
	}

	SdlHardwareTexture hardwareTexture(*_renderer, *(sdlTexture.getSurface()));

	SDL_RenderCopy(_renderer,hardwareTexture.getTexture(),srcRectPtr,destRectPtr);
	**/
}

void Renderer::drawTexture(const ITexture &texture, const Rectangle *dest) {
	//drawTexture(texture,nullptr,dest);
}

void Renderer::drawLine(const Point &p1, const Point &p2) {
	SDL_RenderDrawLine(_renderer,p1.getX(),p1.getY(),p2.getX(),p2.getY());
}

void Renderer::drawPoint(const Point &p) {
	SDL_RenderDrawPoint(_renderer,p.getX(),p.getY());
}

void Renderer::drawRect(const Rectangle &rectangle) {
	SDL_Rect rect;
	rect.x = rectangle.getX();
	rect.y = rectangle.getY();
	rect.w = rectangle.getWidth();
	rect.h = rectangle.getHeight();

	SDL_RenderDrawRect(_renderer,&rect);
}

void Renderer::fillRect(const Rectangle &rectangle) {
	SDL_Rect rect;
	rect.x = rectangle.getX();
	rect.y = rectangle.getY();
	rect.w = rectangle.getWidth();
	rect.h = rectangle.getHeight();

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
	viewport.x = rectangle.getX();
	viewport.y = rectangle.getY();
	viewport.w = rectangle.getWidth();
	viewport.h = rectangle.getHeight();

    SDL_RenderSetViewport(_renderer, &viewport );
}

void Renderer::setColor(const Color &color) {
	SDL_SetRenderDrawColor(_renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}
