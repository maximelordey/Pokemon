#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <cstdint>
#include <vector>
#include "texture.hpp"
#include "time.hpp"

class Animation {
	public:
		void update(const Delta delta);
		const Texture& getCurrentTexture() const;

	public:
		std::vector<Texture> textures;
		Delta refresh_threshold;
	
	private:
		Delta current;
};

#endif
