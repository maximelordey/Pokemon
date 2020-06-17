#ifndef IWINDOW_H
#define IWINDOW_H

#include <cstdint>

#include "irenderer.h"

class IWindow {
	public:
		virtual IRenderer& createRenderer(uint32_t index, uint32_t flags) const = 0;
		virtual bool isTargetSupported(IRenderer& renderer) const = 0;
}

#endif
