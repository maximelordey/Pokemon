#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL.h>

#include "iwindow.h"
#include "point.h"
#include "dimension.h"

class Window: public IWindow {
	public:
		Window(const std::string& name,const Point& origin,const Dimension& dimension);
		~Window();
		
		void getOrigin(Point& point) const override;
		void getDimension(Dimension& dimension) const override;

		SDL_Window* getWindow() const ;

	private:
		SDL_Window* _window;
};

#endif
