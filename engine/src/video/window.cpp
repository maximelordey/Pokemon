#include "window.h"

Window::Window(const std::string& name,int32_t x, int32_t y,uint32_t width, uint32_t height) {
	_window = SDL_CreateWindow(name.c_str(), x, y, width, height, SDL_WINDOW_RESIZABLE);
}

Window::Window(const std::string &name, const Point &origin, const Dimension &dimension) {
	_window = SDL_CreateWindow(name.c_str(), origin.getX(), origin.getY(), dimension.getWidth(), dimension.getHeight(), 0);
}

Window::~Window() {
	SDL_DestroyWindow(_window);
}

void Window::show() {
	SDL_ShowWindow(_window);
}

void Window::hidde() {
	SDL_HideWindow(_window);
}

bool Window::isVisible() const {
	return ((SDL_GetWindowFlags(_window) & SDL_WINDOW_SHOWN) != 0);
}

bool Window::isHidden() const {
	return ((SDL_GetWindowFlags(_window) & SDL_WINDOW_HIDDEN) != 0);
}

void Window::setFullScreen() {
	SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
}

void Window::setWindowed() {
	SDL_SetWindowFullscreen(_window, 0);
}

bool Window::isFullScreen() const {
	return ((SDL_GetWindowFlags(_window) & SDL_WINDOW_FULLSCREEN) != 0);
}

void Window::setBorderless() {
	SDL_SetWindowBordered(_window, SDL_FALSE);
}

void Window::setBordered() {
	SDL_SetWindowBordered(_window, SDL_TRUE);
}

bool Window::isBorderless() const {
	return ((SDL_GetWindowFlags(_window) & SDL_WINDOW_BORDERLESS) != 0);
}

void Window::setResizable() {
	SDL_SetWindowResizable(_window, SDL_TRUE);
}

void Window::unsetResizable() {
	SDL_SetWindowResizable(_window, SDL_FALSE);
}

bool Window::isResizable() const {
	return ((SDL_GetWindowFlags(_window) & SDL_WINDOW_RESIZABLE) != 0);
}


std::string Window::getName() const {
	const char *name = SDL_GetWindowTitle(_window);
	return std::string(name);
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

void Window::setName(const std::string &name){
	SDL_SetWindowTitle(_window, name.c_str());
}

void Window::setOrigin(const Point &origin){
	SDL_SetWindowPosition(_window, origin.getX(), origin.getY());
}

void Window::setDimension(const Dimension &dimension){
	SDL_SetWindowSize(_window, dimension.getWidth(), dimension.getHeight());
}

