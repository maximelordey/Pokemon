#ifndef IRENDERER_H
#define IRENDERER_H

#include "color.h"
#include "dimension.h"
#include "rectangle.h"
#include "point.h"
#include "irenderer.h"
#include "itexture.h"

class IRenderer {
	public:
		virtual const Color getColor() const = 0;
		virtual const Dimension getOutputSize() const = 0;
		virtual void clear() = 0;
		virtual void drawTexture(ITexture &texture, Rectangle &src, Rectangle &dest) = 0;
		virtual void drawLine(Point &p1, Point &p2) = 0;
		virtual void drawPoint(Point &p) = 0;
		virtual void drawRect(Rectangle &rectangle) = 0;
		virtual void fillRect(Rectangle &rectangle) = 0;
		virtual void getViewport(Rectangle &rectangle) const = 0;
		virtual void show() = 0;
		virtual void setViewport(Rectangle &rectangle) = 0;
		virtual void setColor(Color &color) = 0;
};

#endif
