#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL2/SDL.h>
#include "point.hpp"
#include "dimension.hpp"

typedef uint32_t WindowFlags;

class Window {
	public:
		Window();
		Window(const WindowCreateInfo& infos);
		~Window();
		Window(const Window& window);
		Window(Window&& window);

		const SDL_Window* get() const;

		Window& operator=(const Window& window);
		Window& operator=(Window&& window);
		
	private:
		SDL_Window* window;
};

typedef struct WindowCreateInfo {
	std::string name;
	WindowFlags flags;
	Point origin;
	Dimension dimension;
};

#endif
