#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SDL.h>
#include <cstdint>

#include "color.hpp"
#include "point.hpp"
#include "dimension.hpp"

typedef uint32_t Milliseconds;
typedef Milliseconds Delta;
typedef Milliseconds Time;
typedef SDL_Event Event;

class GameEngine {
	public:
		void start();

		void setColor(const Color& color);
		void drawPoint(const Point& point);
		void drawLine(const Point& from, const Point& to);
		void drawRectangle(const Point& origin, const Dimension& dimension);
		void fillRectangle(const Point& origin, const Dimension& dimension);

	private:
		void setUp();
		void tearDown();
		void run();

		void initSDL();
		void createWindow();
		void createRenderer();

		void gameLoop();
		void processEvent();
		void display();

		void destoryRenderer();
		void destroyWindow();
		void quitSDL();
	
	protected:
		virtual void onEvent(const Event& event) = 0;
		virtual void onUpdate(Delta delta) = 0;
		virtual void onPaint() = 0;

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
};

#endif
