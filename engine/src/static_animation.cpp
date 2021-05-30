#include "static_animation.hpp"

StaticAnimation::StaticAnimation(const SharedTexture& texture)
	: sharedTexture(sharedTexture)
{}

const Texture& StaticAnimation::getTexture() const {
	return *sharedTexture;
}
