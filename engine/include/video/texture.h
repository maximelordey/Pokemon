#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <SDL.h>
#include "itexture.h"

class Texture: public ITexture {
	public:
		Texture(const std::string &path);
		~Texture();

		SDL_Surface* getSurface() const;

	private: 
		SDL_Surface* _surface;
};

#endif
