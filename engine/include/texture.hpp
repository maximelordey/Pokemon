#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL.h>
#include "renderer.hpp"
#include "surface.hpp"
#include "blend_mod.hpp"

class Texture;
struct TextureMetaInfo;
struct TextureContentInfo;
typedef	uint32_t PixelFormatEnum;
typedef	int TextureAccess;

class Texture {
	public:
		Texture();
		Texture(const Renderer& renderer, SDL_PixelFormatEnum format, SDL_TextureAccess acces, const Dimension& dimension);
		Texture(const Surface& surface, const Renderer& renderer);
		~Texture();
		Texture(const Texture& texture) = delete;
		Texture(Texture&& texture);

		SDL_Texture* get() const;

		BlendMod getTextureBlendMod();
		void setTextureBlendMod(const BlendMod& blendMod);
		void removeTextureBlendMod();

		void unlockTexture() const;
		TextureContentInfo lockTexture() const;
		TextureMetaInfo queryTexture();
		void updateTexture(const TextureContentInfo& contentInfo);

		Texture& operator=(const Texture& texture) = delete;
		Texture& operator=(Texture&& texture);
	private:
		SDL_Texture* sdl_texture;
};

struct TextureMetaInfo {
	PixelFormatEnum format;
	TextureAccess access;
    Dimension dimension;
};

struct TextureContentInfo {
	void* pixels;
	int pitch;
};

#endif
