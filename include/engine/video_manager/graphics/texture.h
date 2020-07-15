#ifndef TEXTURE_H
#define TEXTURE_H

#include "itexture.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Texture: public ITexture {
	public:
		Texture(std::string& path);
		~Texture();

		SDL_Surface* getSurface() const;

	private: 
		SDL_Surface* _surface;
};

#endif
