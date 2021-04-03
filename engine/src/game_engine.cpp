#include "game_engine.hpp"

#include <stdexcept>
#include <thread>
#include <vector>

void GameEngine::start() {
	this->setUp();
	this->gameLoop();
	this->tearDown();
}

void GameEngine::setColor(const Color& color) {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
}

void GameEngine::drawPoint(const Point& point) {
	SDL_RenderDrawPoint(renderer, point.x, point.y);
}

void GameEngine::drawLine(const Point& from, const Point& to) {
	SDL_RenderDrawLine(renderer, from.x, from.y, to.x, to.y);
}

void GameEngine::drawRectangle(const Point& origin, const Dimension& dimension) {
	SDL_Rect rect = SDL_Rect{origin.x, origin.y, dimension.width, dimension.height};
	SDL_RenderDrawRect(renderer, &rect);
}

void GameEngine::fillRectangle(const Point& origin, const Dimension& dimension) {
	SDL_Rect rect = SDL_Rect{origin.x, origin.y, dimension.width, dimension.height};
	SDL_RenderFillRect(renderer, &rect);
}

void GameEngine::drawString(const Point& origin, const std::string& string) {
	std::runtime_error("drawString is not implemented yet!");
}

void GameEngine::run() {
	std::thread gameThread = std::thread(&GameEngine::gameLoop, this);
	gameThread.join();
}

void GameEngine::setUp() {
	this->initSDL();
	this->createWindow();
}

void GameEngine::tearDown() {
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
	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 540, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        throw std::runtime_error("Window could not be created!");
    }
}

void GameEngine::createRenderer() {
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if( renderer == NULL )
	{
		std::runtime_error("Renderer could not be created!");
	}
}

void GameEngine::gameLoop() {
	bool quit = false;

	Delta deltaThreshold = 17;
	Time lastUpdate;

	while(!quit) {
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
	SDL_RenderClear(renderer);
	this->onPaint();
	SDL_RenderPresent(renderer);
}

void GameEngine::processEvent() {
	Event event;
	while(SDL_PollEvent(&event) != 0) {
		this->onEvent(event);
	}
}

void GameEngine::destoryRenderer() {
	SDL_DestroyRenderer(renderer);
}

void GameEngine::destroyWindow() {
	SDL_DestroyWindow( window );
}

void GameEngine::quitSDL() {
	SDL_Quit();
}
