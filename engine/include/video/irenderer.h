#ifndef IRENDERER_H
#define IRENDERER_H

#include <iterator>

#include "color.h"
#include "dimension.h"
#include "rectangle.h"
#include "point.h"
#include "line.h"
#include "irenderer.h"
#include "itexture.h"

class IRenderer {
	public:
		virtual Color getColor() const = 0;
		virtual Dimension getOutputSize() const = 0;
		virtual void clear() = 0;
		virtual void drawTexture(const ITexture &texture, const Rectangle *src, const Rectangle *dest) = 0;
		virtual void drawTexture(const ITexture &texture, const Rectangle *dest) = 0;
		virtual void drawLine(const Line &line) = 0;
		virtual void drawLines(const std::iterator_traits<Line> &begin, const std::iterator_traits<Line> &end) = 0;
		virtual void drawPoint(const Point &p) = 0;
		virtual void drawPoints(const std::iterator_traits<Point> &begin, const std::iterator_traits<Point> &cend) = 0;
		virtual void drawRect(const Rectangle &rectangle) = 0;
		virtual void drawRects(const std::iterator_traits<Rectangle> &begin, const std::iterator_traits<Rectangle> &end) = 0;
		virtual void fillRect(const Rectangle &rectangle) = 0;
		virtual void fillRects(const std::iterator_traits<Rectangle> &begin, const std::iterator_traits<Rectangle> &end) = 0;
		virtual Rectangle getViewport() const = 0;
		virtual void show() = 0;
		virtual void setViewport(const Rectangle &rectangle) = 0;
		virtual void setColor(const Color &color) = 0;
};

#endif
