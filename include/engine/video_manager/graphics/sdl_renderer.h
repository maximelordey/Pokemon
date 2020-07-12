#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H

#include "irenderer.h"
#include "icolor.h"
#include "idimension.h"
#include <SDL.h>

class SdlRenderer: public IRenderer {
	public:
		SdlRenderer(SDL_Window* window);
		~SdlRenderer();

		void getColor(IColor& color) const override;
		void getOutputSize(IDimension& dimension)const override;
		void clear() override;
		void drawTexture(ITexture &texture, IRectangle *src, IRectangle *dest) override;
		void drawTexture(ITexture &texture, IRectangle *dest) override;
		void drawLine(IPoint &p1, IPoint &p2) override;
		void drawPoint(IPoint &p) override;
		void drawRect(IRectangle &rectangle) override;
		void fillRect(IRectangle &rectangle) override;
		void getViewport(IRectangle &rectangle) const override;
		void show() override;
		void setViewport(const IRectangle &rectangle) override;
		void setColor(const IColor &color) override;

	private:
		struct SDL_Renderer* _renderer;
};

#endif