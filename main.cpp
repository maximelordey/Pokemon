#include <iostream>

#include "game_engine.hpp"
#include "surface.hpp"
#include "texture.hpp"
#include "animation.hpp"

class Game;

class Game : public GameEngine {
	Animation Load(const Renderer& renderer){
		AnimationCreateInfo info;
		Surface surface(std::string("/home/ubuntu/TvbKZr3.bmp"));

		Rectangle rectangle1{Point{35,38},Dimension{30,30}};
		Rectangle rectangle2{Point{68,38},Dimension{30,30}};

		Surface surface1(surface.blit(rectangle1));
		Surface surface2(surface.blit(rectangle2));

		info.refresh_rate = 150;
		info.textures.push_back(std::make_shared<Texture>(mRenderer, surface));
		info.textures.push_back(std::make_shared<Texture>(mRenderer, surface1));

		return Animation(info);
	}	

	void onCreate() {
		animationWalk = this->Load(mRenderer);
	}

	void onEvent(const Event& event) {
		if (event.type == SDL_QUIT) {
			mExitGameLoop = true;
		}
	}

	void onUpdate(Delta delta) {
		std::cout << "update" << '\n';
		animationWalk.update(delta);
	}

	void onPaint() {
		std::cout << "onPaint" << '\n';
		mRenderer.drawTexture(animationWalk.getCurrentTexture(), std::nullopt);
	}

	private:
		Animation animationWalk;
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
		return -1;
	}
	return 0;
}