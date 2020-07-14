#ifndef IWINDOW_H
#define IWINDOW_H

#include <cstdint>

#include "irenderer.h"

class IWindow {
	public:
		virtual void getOrigin(IPoint& point) const = 0;
		virtual void getDimension(IDimension& dimension) const = 0;
};

#endif
