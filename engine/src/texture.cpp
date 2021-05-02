#include "texture.hpp"

#include <stdexcept>

Texture::Texture(const Renderer& renderer, SDL_PixelFormatEnum format, SDL_TextureAccess acces, const Dimension& dimension) {
	sdl_texture = SDL_CreateTexture(
		renderer.get(),
		format,
		acces,
		dimension.width,
		dimension.height
	);

	if (sdl_texture == nullptr) {
		std::runtime_error("Couldn't create Texture !");
	}
}

Texture::Texture(const Surface& surface, const Renderer& renderer) {
	sdl_texture = SDL_CreateTextureFromSurface(
		renderer.get(),
		surface.get()
	);

	if (sdl_texture == nullptr) {
		std::runtime_error("Couldn't create Texture !");
	}
}

Texture::~Texture() {
	SDL_DestroyTexture(sdl_texture);
}

Texture::Texture(const Texture& texture) {
	*this = texture;
}

Texture::Texture(Texture&& texture) {
	*this = texture;
}

SDL_Texture* Texture::get() {
	return sdl_texture;
}

BlendMod Texture::getTextureBlendMod() {
	BlendMod blend_mod;
	SDL_GetTextureAlphaMod(sdl_texture, &blend_mod.color.alpha);
	SDL_GetTextureBlendMode(sdl_texture, &blend_mod.blendMod);
	SDL_GetTextureColorMod(sdl_texture, &blend_mod.color.red, &blend_mod.color.green, &blend_mod.color.blue);
	return blend_mod;
}

void Texture::setTextureBlendMod(const BlendMod& blendMod) {
	SDL_GetTextureAlphaMod(sdl_texture, blend_mod.color.alpha);
	SDL_GetTextureBlendMode(sdl_texture, blend_mod.blendMod);
	SDL_GetTextureColorMod(sdl_texture, blend_mod.color.red, blend_mod.color.green, blend_mod.color.blue);
}

void Texture::removeTextureBlendMod() {
	SDL_GetTextureAlphaMod(sdl_texture, 0xFF);
	SDL_GetTextureBlendMode(sdl_texture, SDL_BLENDMODE_NONE);
	SDL_GetTextureColorMod(sdl_texture, 0x00, 0x00, 0x00);
}

void Texture::unlockTexture() {
	SDL_UnlockTexture(sdl_texture);
}

TextureContentInfo Texture::lockTexture() {
	TextureContentInfo content_info;
	SDL_LockTexture(
		sdl_texture,
		nullptr,
		&content_info.pixels,
		&content_info.pitch
	);
	return content_info;
}

void Texture::queryTexture() {
	TextureMetaInfo texture_info;
	SDL_QueryTexture(
		sdl_texture,
        &texture_info.format,
		&texture_info.access,
        &texture_info.dimension.width,
		&texture_info.dimension.height
	);
	return texture_info;
}

void updateTexture(const TextureContentInfo& contentInfo) {
	SDL_UpdateTexture(
		sdl_texture,
        nullptr,
		contentInfo.pixels,
		contentInfo.pitch
	);
}

Texture& Texture::operator=(const Texture& texture) {
	TextureContentInfo content_info= texture.lockTexture();
	
	SDL_UpdateTexture(
		sdl_texture,
		nullptr,
		content_info.pixels,
		content_info.pitch
	);
	texture.unlockTexture();
}

Texture& Texture::operator=(Texture&& texture) {
	sdl_texture = texture.sdl_texture;
	texture.sdl_texture = nullptr;
}
