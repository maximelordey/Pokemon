#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <cstdint>
#include <vector>
#include "texture.hpp"
#include "time.hpp"

class Animation {
	public:
		Animation(const AnimationCreateInfo& createInfo);		
		void update(const Delta delta);
		const Texture& getCurrentTexture() const;
	
	private:
		std::vector<Texture> textures;
		Delta refresh_rate;
		Delta elapsed;
		std::vector<Texture>::const_iterator currentTexture;
};

struct AnimationCreateInfo {
	std::vector<Texture> textures;
	Delta refresh_rate;
};

#endif
