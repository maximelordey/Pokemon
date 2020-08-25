#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL.h>

#include "iwindow.h"
#include "point.h"
#include "dimension.h"

class Window: public IWindow {
	public:
		Window(const std::string& name,int32_t x, int32_t y, uint32_t width, uint32_t height);
		Window(const std::string& name,const Point& origin,const Dimension& dimension);
		~Window();

		void show() override;
		void hidde() override;
		void setFullScreen() override;
		void setBorderless() override;
		void setWindowed() override;

		std::string getName() const override;
		Point getOrigin() const override;
		Dimension getDimension() const override;

		void setName(const std::string &name) override;
		void setOrigin(const Point &origin) override;
		void setDimension(const Dimension &dimension) override;

		SDL_Window* getWindow() const ;

	private:
		SDL_Window* _window;
};

#endif
