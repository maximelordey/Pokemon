#ifndef IWINDOW_H
#define IWINDOW_H

#include <cstdint>

#include "irenderer.h"

class IWindow {
	public:
		virtual void show() = 0;
		virtual void hidde() = 0;
		virtual bool isVisible() const = 0;
		virtual bool isHidden() const = 0;

		virtual void setFullScreen() = 0;
		virtual void setWindowed() = 0;
		virtual bool isFullScreen() const = 0;

		virtual void setBorderless() = 0;
		virtual void setBordered() = 0;
		virtual bool isBorderless() const = 0;

		virtual void setResizable() = 0;
		virtual void unsetResizable() = 0;
		virtual bool isResizable() const = 0;

		virtual std::string getName() const = 0;
		virtual Point getOrigin() const = 0;
		virtual Dimension getDimension() const = 0;

		virtual void setName(const std::string &name) = 0;
		virtual void setOrigin(const Point &origin) = 0;
		virtual void setDimension(const Dimension &dimension) = 0;
};

#endif
