#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H

#include "irenderer.h"
#include "color.h"
#include "dimension.h"
#include "window.h"
#include <SDL.h>

class Renderer: public IRenderer {
	public:
		Renderer(Window& window);
		~Renderer();

		Color getColor() const override;
		Dimension getOutputSize()const override;
		void clear() override;
		void drawTexture(const Surface &surface, const Rectangle *src, const Rectangle *dest) override;
		void drawTexture(const Surface &surface, const Rectangle *dest) override;
		void drawLine(const Line &line) override;
		void drawPoint(const Point &p) override;
		void drawRect(const Rectangle &rectangle) override;
		void fillRect(const Rectangle &rectangle) override;
		Rectangle getViewport() const override;
		void show() override;
		void setViewport(const Rectangle &rectangle) override;
		void setColor(const Color &color) override;

	private:
		struct SDL_Renderer* _renderer;
};

#endif