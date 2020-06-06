#ifndef IVIDEO_MANAGER_H
#define IVIDEO_MANAGER_H

#include <iostream>
#include <cstdint>

#include "iwindow.h"

class IVideoManager {
	public:
		virtual IWindow& createWindow(std::string& name, int32_t posX, int32_t posY, uint32_t width, uint32_t height, int32_t flags) = 0;
}

#endif
