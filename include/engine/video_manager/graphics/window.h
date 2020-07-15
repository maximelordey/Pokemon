#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL.h>

#include "iwindow.h"
#include "ipoint.h"
#include "idimension.h"

class Window: public IWindow {
	public:
		Window(std::string& name, IPoint& origin, IDimension& dimension);
		~Window();
		
		void getOrigin(IPoint& point) const override;
		void getDimension(IDimension& dimension) const override;

		SDL_Window* getWindow() const ;

	private:
		SDL_Window* _window;
};

#endif
