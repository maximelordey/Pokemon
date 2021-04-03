#include <iostream>

#include "game_engine.hpp"

class Game : public GameEngine {
	void onEvent(const Event& event) {
		std::cout << "catch event" << '\n';
	}

	void onUpdate(Delta delta) {
		std::cout << "update" << '\n';
	}

	void onPaint() {
		std::cout << "onPaint" << '\n';
		for(int x = 0; x < 954; x++) {
			for (int y = 0; y < 540; y++)
			{
				uint32_t random = rand();
				uint8_t red = (random & 0xFF000000) > 24;
				uint8_t green = (random & 0x00FF0000) > 16;
				uint8_t blue = (random & 0x0000FF00) > 8;
				this->setColor(Color{0, 0, 0, 0xFF});
				this->drawPoint(Point{x, y});
			}			
		}
	}

};

int main() {
	Game game;

	try
	{
		game.start();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}