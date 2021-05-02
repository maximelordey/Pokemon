#include "renderer.hpp"

#include <stdexcept>

Renderer::Renderer(const RendererCreateInfo& infos)
{
	SDL_assert(infos.window != nullptr);
	sdl_renderer = SDL_CreateRenderer(infos.window->get(), infos.index, infos.flags);
	if( sdl_renderer == nullptr )
	{
		std::runtime_error("Renderer could not be created!");
	}
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(sdl_renderer);
}

Renderer::Renderer(Renderer&& renderer) {
	sdl_renderer = renderer.sdl_renderer;
	renderer.sdl_renderer = nullptr;
}

SDL_Renderer* Renderer::get() const {
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

void Renderer::drawPoints(Point* points, size_t count) {
	SDL_Point* sdl_points = reinterpret_cast<SDL_Point*>(points);
	SDL_RenderDrawPoints(sdl_renderer, sdl_points, count);
}

void Renderer::drawLine(const Line& line) {
	SDL_RenderDrawLine(sdl_renderer, line.from.x, line.from.y, line.to.x, line.to.y);
}

void Renderer::drawLines(Line* lines, size_t count) {
	for(int i = 0; i < count; i++){
		const Line& line = lines[i];
		this->drawLine(line);
	}
}

void Renderer::drawRectangle(const Rectangle& rectangle) {
	SDL_Rect sdl_rectangle{rectangle.origin.x, rectangle.origin.y,
	 rectangle.dimension.width, rectangle.dimension.height};
	SDL_RenderDrawRect(sdl_renderer, &sdl_rectangle);
}

void Renderer::fillRectangle(const Rectangle& rectangle) {
	SDL_Rect sdl_rectangle{rectangle.origin.x, rectangle.origin.y,
	 rectangle.dimension.width, rectangle.dimension.height};
	SDL_RenderFillRect(sdl_renderer, &sdl_rectangle);
}

void Renderer::drawRectangles(Rectangle* rectangles, size_t count) {
	SDL_Rect* sdl_rectangles = reinterpret_cast<SDL_Rect*>(rectangles);
	SDL_RenderDrawRects(sdl_renderer, sdl_rectangles, count);
}

void Renderer::fillRectangles(Rectangle* rectangles, size_t count) {
	SDL_Rect* sdl_rectangles = reinterpret_cast<SDL_Rect*>(rectangles);
	SDL_RenderDrawRects(sdl_renderer, sdl_rectangles, count);
}

void Renderer::drawString(const Point& origin, const std::string& string) {
	throw std::runtime_error("drawString is not implemented yet !");
}

void Renderer::display() {
	SDL_RenderPresent(sdl_renderer);
}

Renderer& Renderer::operator=(Renderer&& renderer) {
	sdl_renderer = renderer.sdl_renderer;
	renderer.sdl_renderer = nullptr;
}
