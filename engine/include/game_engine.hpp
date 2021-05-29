#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SDL2/SDL.h>
#include <cstdint>
#include <string>

#include "color.hpp"
#include "point.hpp"
#include "dimension.hpp"
#include "texture.hpp"
#include "renderer.hpp"
#include "window.hpp"

typedef uint32_t Milliseconds;
typedef Milliseconds Delta;
typedef Milliseconds Time;
typedef SDL_Event Event;

class GameEngine {
	public:
		void start();

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
		virtual void onCreate() = 0;
		virtual void onEvent(const Event& event) = 0;
		virtual void onUpdate(Delta delta) = 0;
		virtual void onPaint() = 0;

	public:
		Window mWindow;
		Renderer mRenderer;

	public:
		bool mExitGameLoop;
};

#endif
