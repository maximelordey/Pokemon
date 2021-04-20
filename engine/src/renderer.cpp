#include "renderer.hpp"

#include <stdexcept>

Renderer::Renderer() 
	: sdl_renderer(nullptr)
{}

Renderer::Renderer(const RendererCreateInfo& infos)
{
	sdl_renderer = SDL_CreateRenderer(infos.window.get(), infos.index, infos.flags);
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(sdl_renderer);
}

Renderer::Renderer(const Renderer& renderer) {
	*this = renderer;
}

Renderer::Renderer(Renderer&& renderer) {
	*this = renderer;
}

const SDL_Renderer* Renderer::get() const {
	return sdl_renderer;
}

void Renderer::setColor(const Color& color) {
	SDL_SetRenderDrawColor(sdl_renderer, color.red, color.green, color.blue, color.alpha);
}

void Renderer::clear(const Color& color) {
	SDL_RenderClear(sdl_renderer);
}

void Renderer::drawPoint(const Point& point) {
	SDL_RenderDrawPoint(sdl_renderer, point.x, point.y);
}

void Renderer::drawLine(const Point& from, const Point& to) {
	SDL_RenderDrawLine(sdl_renderer, from.x, from.y, to.x, to.y);
}

void Renderer::drawRectangle(const Point& origin, const Dimension& dimension) {
	SDL_Rect rectangle{origin.x, origin.y, dimension.width, dimension.height};
	SDL_RenderDrawRect(sdl_renderer, &rectangle);
}

void Renderer::fillRectangle(const Point& origin, const Dimension& dimension) {
	SDL_Rect rectangle{origin.x, origin.y, dimension.width, dimension.height};
	SDL_RenderFillRect(sdl_renderer, &rectangle);
}

void Renderer::drawString(const Point& origin, const std::string& string) {
	throw std::runtime_error("drawString is not implemented yet !");
}

Renderer& operator=(const Renderer& renderer) {

}

Renderer& Renderer::operator=(Renderer&& renderer) {
	sdl_renderer = renderer.sdl_renderer;
	renderer.sdl_renderer = nullptr;
}
