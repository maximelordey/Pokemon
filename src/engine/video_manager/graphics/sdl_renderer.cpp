#include "sdl_renderer.h"

SdlRenderer::SdlRenderer(SDL_Renderer& renderer)
 : _renderer(&renderer){}

SdlRenderer::~SdlRenderer(){
	SDL_DestroyRenderer(_renderer);
}

const IColor& SdlRenderer::getColor() const {
	return *_color;
}

const IDimension& SdlRenderer::getOutputSize() const {
	return *_dimension;
}

void SdlRenderer::clear() {
	SDL_RenderClear(_renderer);
}

void SdlRenderer::drawTexture(ITexture &texture, IRectangle &src, IRectangle &dest) {}

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

void SdlRenderer::getViewport(IRectangle &rectangle) const {}

void SdlRenderer::show() {
	SDL_RenderPresent(_renderer);
}

void SdlRenderer::setViewport(IRectangle &rectangle) {

}

void SdlRenderer::setColor(IColor &color) {
	
}