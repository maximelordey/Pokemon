#ifndef IRENDERER_H
#define IRENDERER_H

class IRenderer {
	public:
		virtual const IColor getColor() const = 0;
		virtual const IDimension getOutputSize() const = 0;
		virtual int clear() = 0;
		virtual int drawTexture(ITexture &texture, IRectangle &src, IRectangle &dest) = 0;
		virtual void drawLine(IPoint &p1, IPoint &p2) = 0;
		virtual void drawPoint(Ipoint &p) = 0;
		virtual void drawRect(IRectangle &rectangle) = 0;
		virtual void fillRect(IRectangle &rectangle) = 0;
		virtual void getViewport(IRectangle &rectangle) const = 0;
		virtual void show() = 0;
		virtual void setViewport(IRectangle &rectangle) = 0;
		virtual void setColor(IColor &color) = 0;
}

#endif
