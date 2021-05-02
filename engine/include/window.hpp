#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL.h>
#include "point.hpp"
#include "dimension.hpp"

typedef uint32_t WindowFlags;
typedef struct WindowCreateInfo WindowCreateInfo;

class Window {
	public:
		Window(const WindowCreateInfo& infos);
		~Window();
		Window(const Window& window) = delete;
		Window(Window&& window);

		SDL_Window* get() const;

		void setTitle(std::string& title);
		std::string getTitle() const;

		void setDimension(const Dimension& dimension);
		Dimension getDimension() const;

		void setOrigin(const Point& origin);
		Point getOrigin() const;

		void show();
		void hide();

		void setFlags(WindowFlags flags);
		WindowFlags getFlags() const;

		Window& operator=(const Window& window) = delete;
		Window& operator=(Window&& window);
		
	private:
		SDL_Window* sdl_window;
};

struct WindowCreateInfo {
	std::string name;
	WindowFlags flags;
	Point origin;
	Dimension dimension;
};

#endif
