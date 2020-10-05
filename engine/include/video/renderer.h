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