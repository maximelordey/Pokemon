#include "animation.hpp"

#include <SDL2/SDL.h>

Animation::Animation() :
textures(),
refresh_rate(0),
elapsed(0),
currentTexture(textures.cbegin())
{}

Animation::Animation(const AnimationCreateInfo& createInfo) :
textures(createInfo.textures),
refresh_rate(createInfo.refresh_rate),
elapsed(0),
currentTexture(textures.cbegin())
{}

void Animation::update(const Delta delta) {
	elapsed += delta;

	while (elapsed > refresh_rate) {
		currentTexture++;
		if (currentTexture == textures.cend()) {
			currentTexture = textures.cbegin();
		}
		elapsed -= refresh_rate;
	}
	SDL_assert(elapsed > 0);
}

const Texture& Animation::getCurrentTexture() const {
	return **currentTexture;
}
