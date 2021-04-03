#include "game_engine.hpp"

#include <stdexcept>
#include <thread>
#include <vector>

void GameEngine::start() {
	this->setUp();
	this->run();
	this->tearDown();
}

void GameEngine::setColor(const Color& color) {
	SDL_SetRenderDrawColor(mRenderer, color.red, color.green, color.blue, color.alpha);
}

void GameEngine::clear(const Color& color) {
	//this->setColor();
	SDL_RenderClear(mRenderer);
}

void GameEngine::drawPoint(const Point& point) {
	SDL_RenderDrawPoint(mRenderer, point.x, point.y);
}

void GameEngine::drawLine(const Point& from, const Point& to) {
	SDL_RenderDrawLine(mRenderer, from.x, from.y, to.x, to.y);
}

void GameEngine::drawRectangle(const Point& origin, const Dimension& dimension) {
	SDL_Rect rect = SDL_Rect{origin.x, origin.y, dimension.width, dimension.height};
	SDL_RenderDrawRect(mRenderer, &rect);
}

void GameEngine::fillRectangle(const Point& origin, const Dimension& dimension) {
	SDL_Rect rect = SDL_Rect{origin.x, origin.y, dimension.width, dimension.height};
	SDL_RenderFillRect(mRenderer, &rect);
}

void GameEngine::drawString(const Point& origin, const std::string& string) {
	std::runtime_error("drawString is not implemented yet!");
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
<<<<<<< HEAD
	mWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 540, SDL_WINDOW_SHOWN );
    if( mWindow == NULL )
=======
	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 990, 540, SDL_WINDOW_SHOWN );
    if( window == NULL )
>>>>>>> empty.
    {
        throw std::runtime_error("Window could not be created!");
    }
}

void GameEngine::createRenderer() {
	mRenderer = SDL_CreateRenderer( mWindow, -1, SDL_RENDERER_ACCELERATED );
	if( mRenderer == NULL )
	{
		std::runtime_error("Renderer could not be created!");
	}
}

void GameEngine::gameLoop() {
	mExitGameLoop = false;

	Delta deltaThreshold = 17;
	Time lastUpdate = SDL_GetTicks();

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
	this->onPaint();
	SDL_RenderPresent(mRenderer);
}

void GameEngine::processEvent() {
	Event event;
	while(SDL_PollEvent(&event) != 0) {
		this->onEvent(event);
	}
}

void GameEngine::destoryRenderer() {
	SDL_DestroyRenderer(mRenderer);
}

void GameEngine::destroyWindow() {
	SDL_DestroyWindow( mWindow );
}

void GameEngine::quitSDL() {
	SDL_Quit();
}
