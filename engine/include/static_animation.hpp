#ifndef STATIC_ANIMATION_HPP
#define STATIC_ANIMATION_HPP

#include "interface_animation.hpp"
#include "texture.hpp"

class StaticAnimation : public InterfaceAnimation {
	public:
		StaticAnimation(const SharedTexture& texture);
		const Texture& getTexture() const override;

	private:
		SharedTexture sharedTexture;
};

#endif
