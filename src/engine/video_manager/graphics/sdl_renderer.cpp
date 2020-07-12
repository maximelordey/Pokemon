#include "sdl_renderer.h"

SdlRenderer::SdlRenderer(SDL_Window* window) {
	 _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
 }

SdlRenderer::~SdlRenderer(){
	SDL_DestroyRenderer(_renderer);
}

void SdlRenderer::getColor(IColor& color) const {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;

	SDL_GetRenderDrawColor(_renderer, &red, &green, &blue, &alpha);
	
	color.setRed(red);
	color.setGreen(green);
	color.setBlue(blue);
	color.setAlpha(alpha);
}

void SdlRenderer::getOutputSize(IDimension& dimension)const {
	uint32_t width;
	uint32_t height;

	SDL_GetRendererOutputSize(_renderer, &width, &height);

	dimension.setSize(width, height);
}

void SdlRenderer::clear() {
	SDL_RenderClear(_renderer);
}

void SdlRenderer::drawTexture(ITexture &texture, IRectangle *src, IRectangle *dest) {
	SDL_Rect srcRect;
	SDL_Rect* srcRectPtr = nullptr;
	SDL_Rect destRect;
	SDL_Rect* destRectPtr = nullptr;	
	ITexture texture;

	SdlTexture& texture = dynamic_cast<SdlTexture&>(texture);
	texture = sdlTexture.getTexture();

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

	SDL_RenderCopy(_renderer,texture,srcRectPtr,destRectPtr);
}

void SdlRenderer::drawTexture(ITexture &texture, IRectangle *dest) {
	drawTexture(texture,nullptr,dest);
}

void SdlRenderer::drawLine(IPoint &p1, IPoint &p2) {
	SDL_RenderDrawLine(_renderer,p1.getX(),p1.getY(),p2.getX(),p2.getY());
}

void SdlRenderer::drawPoint(IPoint &p) {
	SDL_RenderDrawPoint(_renderer,p.getX(),p.getY());
}

void SdlRenderer::drawRect(IRectangle &rectangle) {
	SDL_Rect rect;
	rect.x = rectangle.getX();
	rect.y = rectangle.getY();
	rect.w = rectangle.getWidth();
	rect.h = rectangle.getHeight();

	SDL_RenderDrawRect(_renderer,&rect);
}

void SdlRenderer::fillRect(IRectangle &rectangle) {
	SDL_Rect rect;
	rect.x = rectangle.getX();
	rect.y = rectangle.getY();
	rect.w = rectangle.getWidth();
	rect.h = rectangle.getHeight();

	SDL_RenderFillRect(_renderer,&rect);
}

void SdlRenderer::getViewport(IRectangle &rectangle) const {
	SDL_Rect viewport;
	SDL_RenderGetViewport(_renderer, &viewport);

	rectangle.setX(viewport.x);
	rectangle.setY(viewport.y);
	rectangle.setWidth(viewport.w);
	rectangle.setHeight(viewport.h);
}

void SdlRenderer::show() {
	SDL_RenderPresent(_renderer);
}

void SdlRenderer::setViewport(const IRectangle &rectangle) {
	SDL_Rect viewport;
	viewport.x = rectangle.getX();
	viewport.y = rectangle.getY();
	viewport.w = rectangle.getWidth();
	viewport.h = rectangle.getHeight();

    SDL_RenderSetViewport(_renderer, &viewport );
}

void SdlRenderer::setColor(const IColor &color) {
	SDL_SetRenderDrawColor(_renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}
