#include "window.hpp"

#include <stdexcept>

Window::Window() 
	: window(nullptr)
{}

Window::Window(const WindowCreateInfo& infos) {
	window = SDL_CreateWindow(
		infos.name.data(),
		infos.origin.x,
		infos.origin.y,
		infos.dimension.width,
		infos.dimension.height,
		infos.flags
	);

	if (window == NULL) {
		throw std::runtime_error("Couldn't create window!");
	}
}

Window::~Window() {
	SDL_DestroyWindow(window);
}

Window::Window(const Window& window) {
	this->window = SDL_CreateWindowFrom(window.window);
}

Window::Window(Window&& window) {
	this->window = window.window;
	window.window = nullptr;
}

const SDL_Window* Window::get() const {
	return window;
}

Window& Window::operator=(const Window& window) {
	this->window = SDL_CreateWindowFrom(window.window);
}

Window& Window::operator=(Window&& window) {
	this->window = window.window;
	window.window = nullptr;
}
