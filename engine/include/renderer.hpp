#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include "window.hpp"
#include "color.hpp"

typedef uint32_t RendererFlags;
typedef int32_t RendererIndex;

class Renderer {
	public:
		Renderer();
		Renderer(const RendererCreateInfo& infos);
		~Renderer();
		Renderer(const Renderer& renderer);
		Renderer(Renderer&& renderer);

		const SDL_Renderer* get() const;

		void setColor(const Color& color);
		void clear(const Color& color);
		void drawPoint(const Point& point);
		void drawLine(const Point& from, const Point& to);
		void drawRectangle(const Point& origin, const Dimension& dimension);
		void fillRectangle(const Point& origin, const Dimension& dimension);
		void drawString(const Point& origin, const std::string& string);

		Renderer& operator=(const Renderer& renderer);
		Renderer& operator=(Renderer&& renderer);	
	private:
		SDL_Renderer* sdl_renderer;
};

typedef struct RendererCreateInfo {
	Window& window;
	RendererIndex index;
	RendererFlags flags;
};

#endif
