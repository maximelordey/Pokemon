#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H

#include "irenderer.h"

class SdlRenderer: public IRenderer {
	public:
		const IColor& getColor() const override;
		const IDimension& getOutputSize() const override;
		void clear() override;
		void drawTexture(ITexture &texture, IRectangle &src, IRectangle &dest) override;
		void drawLine(IPoint &p1, IPoint &p2) override;
		void drawPoint(IPoint &p) override;
		void drawRect(IRectangle &rectangle) override;
		void fillRect(IRectangle &rectangle) override;
		void getViewport(IRectangle &rectangle) const override;
		void show() override;
		void setViewport(IRectangle &rectangle) override;
		void setColor(IColor &color) override;

};

#endif