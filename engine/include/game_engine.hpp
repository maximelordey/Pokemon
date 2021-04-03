#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "SDL.h"

class GameEngine {
	public:
		run();

	private:
		void setUp();
		void tearDown();

		void initSDL();
		void createWindow();
		void createRenderer();

		void gameLoop();

		void destoryRenderer();
		void destroyWindow();
		void closeSDL();
	
	protected:
		virtual void onEvent() = 0;
		virtual void onUpdate() = 0;
		virtual void onDisplay() = 0;


	private:
		SDL_Window* window;
};

#endif
