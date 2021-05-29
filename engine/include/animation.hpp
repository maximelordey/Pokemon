#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <cstdint>
#include <vector>
#include "texture.hpp"
#include "time.hpp"

class Animation;
struct AnimationCreateInfo;

class Animation {
	public:
		Animation();
		Animation(const AnimationCreateInfo& createInfo);		
		void update(const Delta delta);
		const Texture& getCurrentTexture() const;
	
	private:
		std::vector<SharedTexture> textures;
		Delta refresh_rate;
		Delta elapsed;
		std::vector<SharedTexture>::const_iterator currentTexture;
};

struct AnimationCreateInfo {
	std::vector<SharedTexture> textures;
	Delta refresh_rate;
};

#endif
