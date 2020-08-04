#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "itexture.h"

class Texture: public ITexture {
	public:
		Texture(const std::string &path);
		~Texture();

		uint8_t getAlphaMode() const override;
		void setAlphaMode(uint8_t alpha) override;

		SDL_Surface* getSurface() const;

	private: 
		SDL_Surface* _surface;
};

#endif
