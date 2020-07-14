#ifndef SDL_TEXTURE_H
#define SDL_TEXTURE_H

#include "sdl_surface.h"
#include "sdl_renderer.h"
#include <SDL.h>

class SdlTexture {
	public:
		SdlTexture(SdlRenderer& renderer, SdlSurface& surface);
		~SdlTexture();

		uint8_t getAlphaMode() const override;
		void setAlphaMode(uint8_t alpha) override;

		SDL_Texture& getTexture() const;
	
	private:
		SDL_Texture* _texture;
};

#endif
