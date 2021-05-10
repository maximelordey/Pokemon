#include "texture.hpp"

#include <stdexcept>

Texture::Texture(const Renderer& renderer, const TextureMetaInfo& meta_info) {
	sdl_texture = SDL_CreateTexture(
		renderer.get(),
		meta_info.format,
		meta_info.acces,
		meta_info.dimension.width,
		meta_info.dimension.height
	);

	SDL_assert(sdl_texture);
}

Texture::Texture(const Renderer& renderer, const Surface& surface) {
	sdl_texture = SDL_CreateTextureFromSurface(
		renderer.get(),
		surface.get()
	);


	SDL_assert(sdl_texture);
}

Texture::~Texture() {
	SDL_DestroyTexture(sdl_texture);
}

Texture::Texture(Texture&& texture) 
	: sdl_texture(texture.sdl_texture)
{
	texture.sdl_texture = nullptr;
}

SDL_Texture& Texture::get() const{
	return *sdl_texture;
}

BlendMod Texture::getTextureBlendMod() {
	BlendMod blend_mod;
	SDL_GetTextureAlphaMod(sdl_texture, &blend_mod.color.alpha);
	SDL_GetTextureBlendMode(sdl_texture, &blend_mod.blendMod);
	SDL_GetTextureColorMod(sdl_texture, &blend_mod.color.red, &blend_mod.color.green, &blend_mod.color.blue);
	return blend_mod;
}

void Texture::setTextureBlendMod(const BlendMod& blend_mod) {
	SDL_SetTextureAlphaMod(sdl_texture, blend_mod.color.alpha);
	SDL_SetTextureBlendMode(sdl_texture, blend_mod.blendMod);
	SDL_SetTextureColorMod(sdl_texture, blend_mod.color.red, blend_mod.color.green, blend_mod.color.blue);
}

void Texture::removeTextureBlendMod() {
	SDL_SetTextureAlphaMod(sdl_texture, 0x00u);
	SDL_SetTextureBlendMode(sdl_texture, SDL_BLENDMODE_NONE);
	SDL_SetTextureColorMod(sdl_texture, 0x00u, 0x00u, 0x00u);
}

void Texture::unlockTexture() const{
	SDL_UnlockTexture(sdl_texture);
}

TextureContentInfo Texture::lockTexture() const{
	TextureContentInfo content_info;
	SDL_LockTexture(
		sdl_texture,
		nullptr,
		&content_info.pixels,
		&content_info.pitch
	);
	return content_info;
}

TextureMetaInfo Texture::queryTexture() {
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

void Texture::updateTexture(const TextureContentInfo& contentInfo) {
	SDL_UpdateTexture(
		sdl_texture,
        nullptr,
		contentInfo.pixels,
		contentInfo.pitch
	);
}

Texture& Texture::operator=(Texture&& texture) {
	if (this != &texture) {
		sdl_texture = texture.sdl_texture;
		texture.sdl_texture = nullptr;
	}
	return *this;
}
