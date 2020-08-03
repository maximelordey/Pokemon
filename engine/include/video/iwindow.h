#ifndef IWINDOW_H
#define IWINDOW_H

#include <cstdint>

#include "irenderer.h"

class IWindow {
	public:
		virtual Point getOrigin() const = 0;
		virtual Dimension getDimension() const = 0;
};

#endif
