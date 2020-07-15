#ifndef HARDWARE_TEXTURE_H
#define HARDWARE_TEXTURE_H

#include "texture.h"
#include "renderer.h"
#include <SDL.h>

class HardwareTexture {
	public:
		HardwareTexture(SDL_Renderer& renderer, SDL_Surface& surface);
		~HardwareTexture();

		uint8_t getAlphaMode() const override;
		void setAlphaMode(uint8_t alpha) override;

		SDL_Texture* getTexture() const;
	
	private:
		SDL_Texture* _texture;
};

#endif
