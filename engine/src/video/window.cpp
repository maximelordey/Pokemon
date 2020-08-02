#include "window.h"

Window::Window(const std::string &name, const IPoint &origin, const IDimension &dimension) {
	_window = SDL_CreateWindow(name.c_str(), origin.getX(), origin.getY(), dimension.getWidth(), dimension.getHeight(), 0);
}

Window::~Window() {
	SDL_DestroyWindow(_window);
}

void Window::getOrigin(Point& point) const{
	int32_t x;
	int32_t y;

	SDL_GetWindowPosition(_window, &x, &y);

	point.move(x, y);
}

void Window::getDimension(Dimension& dimension) const  {
	uint32_t width;
	uint32_t height;

	SDL_GetWindowSize(_window, &width, &height);

	dimension.setSize(width, height);
}

SDL_Window* Window::getWindow() const {
	return _window;
}
