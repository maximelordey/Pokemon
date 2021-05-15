#include "window.hpp"

#include <stdexcept>

Window::Window(const WindowCreateInfo& infos) {
	sdl_window = SDL_CreateWindow(
		infos.name.data(),
		infos.origin.x,
		infos.origin.y,
		infos.dimension.width,
		infos.dimension.height,
		infos.flags
	);

	if (sdl_window == nullptr) {
		throw std::runtime_error("Couldn't create window!");
	}
}

Window::~Window() {
	SDL_DestroyWindow(sdl_window);
}

Window::Window(Window&& window) {
	this->sdl_window = window.sdl_window;
	window.sdl_window = nullptr;
}

SDL_Window* Window::get() const {
	return sdl_window;
}

void Window::setTitle(const std::string& title) {
	SDL_SetWindowTitle(sdl_window, title.data());
}

std::string Window::getTitle() const {
	return std::string(SDL_GetWindowTitle(sdl_window));
}

void Window::setDimension(const Dimension& dimension) {
	SDL_SetWindowSize(sdl_window, dimension.width, dimension.height);
}

Dimension Window::getDimension() const {
	Dimension dimension;
	SDL_GetWindowSize(sdl_window, &dimension.width, &dimension.height);
	return dimension;
}

void Window::setOrigin(const Point& origin) {
	SDL_SetWindowPosition(sdl_window, origin.x, origin.y);
}

Point Window::getOrigin() const {
	Point origin;
	SDL_GetWindowPosition(sdl_window, &origin.x, &origin.y);
	return origin;
}

void Window::show() {
	SDL_ShowWindow(sdl_window);
}

void Window::hide() {
	SDL_HideWindow(sdl_window);
}

void Window::setFlags(WindowFlags flags) {
	std::runtime_error("setFlags is not implemented yet!");
}

WindowFlags Window::getFlags() const {
	return SDL_GetWindowFlags(sdl_window);
}

Window& Window::operator=(Window&& window) {
	this->sdl_window = window.sdl_window;
	window.sdl_window = nullptr;
}
