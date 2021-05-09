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
		Texture(const Renderer& renderer, const TextureMetaInfo& meta_info);
		Texture(const Renderer& renderer, const Surface& surface);
		~Texture();
		Texture(const Texture& texture) = delete;
		Texture(Texture&& texture);

		SDL_Texture* get() const;

		BlendMod getTextureBlendMod();
		void setTextureBlendMod(const BlendMod& blendMod);
		void removeTextureBlendMod();

		TextureContentInfo lockTexture() const;
		void unlockTexture() const;
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
