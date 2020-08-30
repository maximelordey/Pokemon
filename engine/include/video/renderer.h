#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H
#include "SDL.h"
#include <vector>

#include "irenderer.h"
#include "color.h"
#include "dimension.h"

class Renderer: public IRenderer {
	public:
		Renderer(SDL_Window* window);
		~Renderer();

		Color getColor() const override;
		Dimension getOutputSize()const override;
		void clear() override;
		void drawTexture(const ITexture &texture, const Rectangle *src, const Rectangle *dest) override;
		void drawTexture(const ITexture &texture, const Rectangle *dest) override;
		void drawLine(const Point &p1, const Point &p2) override;
		void drawPoint(const Point &p) override;
		void drawRect(const Rectangle &rectangle) override;
		void fillRects(const std::vector<Rectangle> &rectangles);
		void fillRect(const Rectangle &rectangle) override;
		Rectangle getViewport() const override;
		void show() override;
		void setViewport(const Rectangle &rectangle) override;
		void setColor(const Color &color) override;

	private:
		struct SDL_Renderer* _renderer;
};

#endif