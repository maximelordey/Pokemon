#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL.h>
#include "renderer.hpp"
#include "surface.hpp"
#include "blend_mod.hpp"

class Texture;
typedef struct TextureMetaInfo TextureMetaInfo;
typedef struct TextureContentInfo TextureContentInfo;

class Texture {
	public:
		Texture(const Renderer& renderer, SDL_PixelFormatEnum format, SDL_TextureAccess acces, const Dimension& dimension);
		Texture(const Surface& surface, const Renderer& renderer);
		~Texture();
		Texture(const Texture& texture);
		Texture(Texture&& texture);

		SDL_Texture* get();

		BlendMod getTextureBlendMod();
		void setTextureBlendMod(const BlendMod& blendMod);
		void removeTextureBlendMod();

		void unlockTexture();
		TextureContentInfo lockTexture();
		TextureMetaInfo queryTexture();
		void updateTexture(const TextureContentInfo& contentInfo);

		Texture& operator=(const Texture& texture);
		Texture& operator=(Texture&& texture);
	private:
		SDL_Texture* sdl_texture;
};

struct TextureMetaInfo {
	SDL_PixelFormatEnum format;
	SDL_TextureAccess access;
    Dimension dimension;
};

struct TextureContentInfo {
	void* pixels;
	int pitch;
};

#endif
