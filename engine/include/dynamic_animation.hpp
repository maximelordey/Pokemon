#ifndef DYNAMIC_ANIMATION_HPP
#define DYNAMIC_ANIMATION_HPP

#include <cstdint>
#include <vector>
#include "texture.hpp"
#include "time.hpp"
#include "interface_animation.hpp"
#include "interface_mutable.hpp"

class DynamicAnimation;
struct DynamicAnimationCreateInfo;

class DynamicAnimation : public InterfaceAnimation,	public InterfaceMutable	{	
	public:
		DynamicAnimation(const DynamicAnimationCreateInfo& createInfo);		
		void update(const Delta delta) override;
		const Texture& getTexture() const override;

	private:
		std::vector<SharedTexture> textures;
		Delta refresh_rate;
		Delta elapsed;
		std::vector<SharedTexture>::const_iterator currentTexture;
};

struct DynamicAnimationCreateInfo {
	std::vector<SharedTexture> textures;
	Delta refresh_rate;
};

#endif
