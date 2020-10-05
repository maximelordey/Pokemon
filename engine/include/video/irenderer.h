#ifndef IRENDERER_H
#define IRENDERER_H

#include <iterator>

#include "color.h"
#include "dimension.h"
#include "rectangle.h"
#include "point.h"
#include "line.h"
#include "surface.h"
#include "irenderer.h"

class IRenderer {
	public:
		virtual Color getColor() const = 0;
		virtual Dimension getOutputSize() const = 0;
		virtual void clear() = 0;
		virtual void drawTexture(const Surface &surface, const Rectangle *src, const Rectangle *dest) = 0;
		virtual void drawTexture(const Surface &surface, const Rectangle *dest) = 0;
		virtual void drawLine(const Line &line) = 0;
		virtual void drawPoint(const Point &p) = 0;
		virtual void drawRect(const Rectangle &rectangle) = 0;
		virtual void fillRect(const Rectangle &rectangle) = 0;
		virtual Rectangle getViewport() const = 0;
		virtual void show() = 0;
		virtual void setViewport(const Rectangle &rectangle) = 0;
		virtual void setColor(const Color &color) = 0;
};

#endif
