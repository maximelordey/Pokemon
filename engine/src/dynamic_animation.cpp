#include "dynamic_animation.hpp"

DynamicAnimation::DynamicAnimation(const DynamicAnimationCreateInfo& createInfo) :
textures(createInfo.textures),
refresh_rate(createInfo.refresh_rate),
elapsed(0),
currentTexture(createInfo.textures.cbegin())
{}

void DynamicAnimation::update(const Delta delta) {
	elapsed += delta;

	while (elapsed > refresh_rate) {
		currentTexture = currentTexture++;
		if (currentTexture == textures.cend()) {
			currentTexture = textures.cbegin();
		}
		elapsed -= refresh_rate;
	}
	SDL_assert(elapsed > 0);
}

const Texture& DynamicAnimation::getTexture() const {
	return **currentTexture;
}
