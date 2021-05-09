#include <iostream>

#include "game_engine.hpp"
#include "surface.hpp"
#include "texture.hpp"

class Game;
class Animation;

class Animation {
	public:
		void update(const Delta& elapsed) {
			refresh += elapsed;
			if (refresh > refresh_rate) {
				indice++;
				if (indice >= textures.size()) {
					indice = 0;
				}
				refresh = 0;
			}
		}

		Texture& getTexture() {
			return *textures.at(indice);
		}

	public:
		std::vector<SharedTexture> textures;
		Delta refresh_rate;
		Delta refresh;
		uint32_t indice;
};

class Game : public GameEngine {

	Animation Load(const Renderer& renderer){
		Surface surface(std::string("/home/ubuntu/TvbKZr3.bmp"));
		
		Animation animation;
		animation.refresh_rate = 150;
		animation.refresh = 0;
		animation.indice = 0;

		Rectangle rectangle1{Point{35,38},Dimension{30,30}};
		Rectangle rectangle2{Point{68,38},Dimension{30,30}};

		Surface surface1 = surface.blit(rectangle1);
		Surface surface2 = surface.blit(rectangle2);

		animation.textures.push_back(std::make_shared<Texture>(surface1, mRenderer));
		animation.textures.push_back(std::make_shared<Texture>(surface2, mRenderer));

		return animation;
	}	

	void onCreate() {
		animationWalk = this->Load(mRenderer);
	}

	void onEvent(const Event& event) {
		//std::cout << "catch event" << '\n';
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
		mRenderer.drawTexture(animationWalk.getTexture(), Rectangle{Point{0,0},Dimension{300,300}});
	}

	private:
		Animation animationWalk;
		Texture t;
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