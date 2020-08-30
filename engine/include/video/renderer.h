#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H

#include "irenderer.h"
#include "color.h"
#include "dimension.h"
#include <SDL.h>

class Renderer: public IRenderer {
	public:
		Renderer(SDL_Window* window);
		~Renderer();

		Color getColor() const override;
		Dimension getOutputSize()const override;
		void clear() override;
		void drawTexture(const ITexture &texture, const Rectangle *src, const Rectangle *dest) override;
		void drawTexture(const ITexture &texture, const Rectangle *dest) override;
		void drawLine(const Line &line) override;
		void drawLines(const std::iterator_traits<Line> &begin, const std::iterator_traits<Line> &end) override;
		void drawPoint(const Point &p) override;
		void drawPoints(const std::iterator_traits<Point> &begin, const std::iterator_traits<Point> &end) override;
		void drawRect(const Rectangle &rectangle) override;
		void drawRects(const std::iterator_traits<Rectangle> &begin, const std::iterator_traits<Rectangle> &end) override;
		void fillRect(const Rectangle &rectangle) override;
		void fillRects(const std::iterator_traits<Rectangle> &begin, const std::iterator_traits<Rectangle> &end) override;
		Rectangle getViewport() const override;
		void show() override;
		void setViewport(const Rectangle &rectangle) override;
		void setColor(const Color &color) override;

	private:
		struct SDL_Renderer* _renderer;
};

#endif