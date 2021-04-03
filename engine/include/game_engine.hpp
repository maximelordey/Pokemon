#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SDL.h>
#include <cstdint>

typedef uint32_t DeltaMilliseconds;
typedef SDL_Event Event;

class GameEngine {
	public:
		void run();

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
		virtual void onEvent(const Event& event) = 0;
		virtual void onUpdate(DeltaMilliseconds delta) = 0;
		virtual void onDisplay() = 0;

	private:
		SDL_Window* window;
};

#endif
