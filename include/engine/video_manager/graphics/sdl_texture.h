#ifndef SDL_TEXTURE_H
#define SDL_TEXTURE_H

#include "itexture.h"
#include <SDL.h>

class SdlTexture: public ITexture {
	public:
		SdlTexture(std::string& path);
		~SdlTexture();

		uint8_t getAlphaMode() const override;
		void setAlphaMode(uint8_t alpha) override;

		SDL_Texture& getTexture() const;
	
	private:
		SDL_Texture* _texture;
};

#endif
