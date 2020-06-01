#ifndef IVIDEO_MANAGER_H
#define IVIDEO_MANAGER_H

include <iostream>

include "iwindow.h"

class IVideoManager {
	public:
		virtual IWindow createWindow(std::string name, int posX, int posY, int width, int height, int flags) = 0;
}

#endif
