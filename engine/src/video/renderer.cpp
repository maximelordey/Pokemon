#include "renderer.h"

#include "texture.h"
#include "hardware_texture.h"

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
	SDL_Rect srcRect;
	SDL_Rect* srcRectPtr = nullptr;
	SDL_Rect destRect;
	SDL_Rect* destRectPtr = nullptr;

	Texture *t = (Texture*)(&texture);
	SDL_Surface *surface = t->getSurface();

	if (src != nullptr){
		srcRect.x = src->_x;
		srcRect.y = src->_y;
		srcRect.w = src->_width;
		srcRect.h = src->_height;
		srcRectPtr = &srcRect;
	}
	if (dest != nullptr){
		destRect.x = dest->_x;
		destRect.y = dest->_y;
		destRect.w = dest->_width;
		destRect.h = dest->_height;
		destRectPtr = &destRect;
	}

	HardwareTexture hardwareTexture(*_renderer, *surface);

	SDL_RenderCopy(_renderer,hardwareTexture.getTexture(),srcRectPtr,destRectPtr);
}

void Renderer::drawTexture(const ITexture &texture, const Rectangle *dest) {
	drawTexture(texture,nullptr,dest);
}

void Renderer::drawLine(const Point &p1, const Point &p2) {
	SDL_RenderDrawLine(_renderer,p1.getX(),p1.getY(),p2.getX(),p2.getY());
}

void Renderer::drawPoint(const Point &p) {
	SDL_RenderDrawPoint(_renderer,p.getX(),p.getY());
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
	SDL_Rect r1;
	r1.x = rectangle._x;
	r1.y = rectangle._y;
	r1.w = rectangle._width;
	r1.h = rectangle._height;

	SDL_RenderFillRect(_renderer,&r1);
}

void Renderer::fillRects(const std::vector<Rectangle> &rectangles) {
	const int size = rectangles.size();

	SDL_Rect rects[size];

	for (int i = 0 ; i < size ; i++) {
		rects[i].h = rectangles[i]._height; 
		rects[i].w = rectangles[i]._width; 
		rects[i].x = rectangles[i]._x; 
		rects[i].y = rectangles[i]._y; 
	}

	SDL_RenderFillRects(_renderer, rects, size);
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
	SDL_SetRenderDrawColor(_renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}
