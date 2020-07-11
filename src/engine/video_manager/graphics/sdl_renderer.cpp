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

}

void SdlRenderer::fillRect(IRectangle &rectangle) {

}

void SdlRenderer::getViewport(IRectangle &rectangle) const {}

void SdlRenderer::show() {}

void SdlRenderer::setViewport(IRectangle &rectangle) {}

void SdlRenderer::setColor(IColor &color) {}