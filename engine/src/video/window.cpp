#include "window.h"

Window::Window(const std::string &name, const Point &origin, const Dimension &dimension) {
	_window = SDL_CreateWindow(name.c_str(), origin.getX(), origin.getY(), dimension.getWidth(), dimension.getHeight(), SDL_WINDOW_SHOWN);
}

Window::~Window() {
	SDL_DestroyWindow(_window);
}

Point Window::getOrigin() const{
	int32_t x;
	int32_t y;

	SDL_GetWindowPosition(_window, &x, &y);

	return Point(x, y);
}

Dimension Window::getDimension() const  {
	int32_t width;
	int32_t height;

	SDL_GetWindowSize(_window, &width, &height);

	return Dimension(width, height);
}

SDL_Window* Window::getWindow() const {
	return _window;
}
