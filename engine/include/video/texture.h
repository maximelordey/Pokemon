#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <SDL.h>

#include "itexture.h"
#include "rectangle.h"

class Texture: public ITexture {
	public:
		Texture();
		Texture(const std::string &path);
		Texture(const Texture &texture);
		Texture(Texture &&texture);
		~Texture();

		SDL_Surface* getSurface() const;

		Texture& operator=(const Texture &texture);
		Texture& operator=(Texture &&texture);

	private: 
		SDL_Surface* _surface;
};

#endif
