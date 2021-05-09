#include "game_engine.hpp"

#include <stdexcept>
#include <thread>
#include <vector>

void GameEngine::start() {
	this->setUp();
	this->run();
	this->tearDown();
}

void GameEngine::run() {
	this->gameLoop();
}

void GameEngine::setUp() {
	this->initSDL();
	this->createWindow();
	this->createRenderer();
}

void GameEngine::tearDown() {
	this->destoryRenderer();
	this->destroyWindow();
	this->quitSDL();
}

void GameEngine::initSDL() {
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        throw std::runtime_error("SDL intialization failed!");
    }
}

void GameEngine::createWindow() {
	WindowCreateInfo createInfo;
	createInfo.dimension = Dimension{960, 540};
	createInfo.name = std::string("SDL Tutorial");
	createInfo.origin = Point{SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED};
	createInfo.flags = SDL_WINDOW_SHOWN;

	mWindow = Window(createInfo);
}

void GameEngine::createRenderer() {
	RendererCreateInfo createInfo;
	createInfo.window = &mWindow;
	createInfo.index = -1;
	createInfo.flags = SDL_RENDERER_SOFTWARE;

	mRenderer = Renderer(createInfo);
}

void GameEngine::gameLoop() {
	mExitGameLoop = false;

	Delta deltaThreshold = 17;
	Time lastUpdate = SDL_GetTicks();

	this->onCreate();
	while(!mExitGameLoop) {
		Time now = SDL_GetTicks();
		Delta delta = now - lastUpdate;

		if (delta > deltaThreshold) {
			this->processEvent();
			this->onUpdate(delta);
			this->display();
			lastUpdate = now;
		}		
	}
}

void GameEngine::display() {
	mRenderer.clear(Color{0,0,0,255});
	this->onPaint();
	mRenderer.display();
}

void GameEngine::processEvent() {
	Event event;
	while(SDL_PollEvent(&event) != 0) {
		this->onEvent(event);
	}
}

void GameEngine::destoryRenderer() {
}

void GameEngine::destroyWindow() {
}

void GameEngine::quitSDL() {
	SDL_Quit();
}
