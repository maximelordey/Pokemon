#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL.h>
#include "window.hpp"
#include "color.hpp"
#include "line.hpp"
#include "point.hpp"
#include "rectangle.hpp"

typedef uint32_t RendererFlags;
typedef int32_t RendererIndex;
typedef struct RendererCreateInfo RendererCreateInfo;

class Renderer {
	public:
		Renderer(const RendererCreateInfo& infos);
		~Renderer();
		Renderer(const Renderer& renderer) = delete;
		Renderer(Renderer&& renderer);

		SDL_Renderer* get() const;

		void setColor(const Color& color);
		void clear(const Color& color);
		void drawPoint(const Point& point);
		void drawPoints(Point* points, size_t count);
		void drawLine(const Line& line);
		void drawLines(Line* lines, size_t count);
		void drawRectangle(const Rectangle& rectangle);
		void fillRectangle(const Rectangle& rectangle);
		void drawRectangles(Rectangle* rectangles, size_t count);
		void fillRectangles(Rectangle* rectangles, size_t count);
		void drawString(const Point& origin, const std::string& string);
		void display();

		Renderer& operator=(const Renderer& renderer) = delete;
		Renderer& operator=(Renderer&& renderer);	
	private:
		SDL_Renderer* sdl_renderer;
};

struct RendererCreateInfo {
	Window* window;
	RendererIndex index;
	RendererFlags flags;
};

#endif
