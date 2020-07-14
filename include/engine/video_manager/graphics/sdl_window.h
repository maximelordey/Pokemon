#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include <string>
#include <SDL.h>

#include "iwindow.h"
#include "ipoint.h"
#include "idimension.h"

class SdlWindow: public IWindow {
	public:
		SdlWindow(std::string& name, IPoint& origin, IDimension& dimension);
		~SdlWindow();
		
		void getOrigin(IPoint& point) const override;
		void getDimension(IDimension& dimension) const override;

		SDL_Window* getWindow() const ;

	private:
		SDL_Window* _window;

};

#endif
