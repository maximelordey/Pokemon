#ifndef INTERFACE_ANIMATION_HPP
#define INTERFACE_ANIMATION_HPP

#include "texture.hpp"

struct InterfaceAnimation {
	virtual const Texture& getTexture() const = 0;
};

#endif
