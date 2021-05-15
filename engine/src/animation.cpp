#include "animation.hpp"

Animation::Animation(const AnimationCreateInfo& createInfo) :
textures(createInfo.textures),
refresh_rate(createInfo.refresh_rate),
elapsed(0),
currentTexture(createInfo.textures.cbegin())
{}

void Animation::update(const Delta delta) {
	elapsed += delta;

	while (elapsed > refresh_rate) {
		currentTexture = currentTexture++;
		if (currentTexture == textures.cend()) {
			currentTexture = textures.cbegin();
		}
		elapsed -= refresh_rate;
	}
}

const Texture& Animation::getCurrentTexture() const {
	return *currentTexture;
}
