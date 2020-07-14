#ifndef SDL_HARDWARE_TEXTURE_H
#define SDL_HARDWARE_TEXTURE_H

#include "sdl_texture.h"
#include "sdl_renderer.h"
#include <SDL.h>

class SdlHardwareTexture {
	public:
		SdlHardwareTexture(SdlRenderer& renderer, SdlTexture& texture);
		~SdlHardwareTexture();

		uint8_t getAlphaMode() const override;
		void setAlphaMode(uint8_t alpha) override;

		SDL_Texture& getTexture() const;
	
	private:
		SDL_Texture* _texture;
};

#endif
