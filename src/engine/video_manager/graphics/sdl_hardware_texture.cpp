#include "sdl_hardware_texture.h"

SdlHardwareTexture::SdlHardwareTexture(SdlRenderer& renderer, SdlTexture& texture) {
	_texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), texture.getSurface());
}

SdlHardwareTexture::~SdlHardwareTexture() {
	SDL_DestroyTexture(_texture);
}

uint8_t SdlHardwareTexture::getAlphaMode() const {
	uint8_t alpha;
	SDL_GetTextureAlphaMod(_texture, &alpha);
	return alpha;
}

void SdlHardwareTexture::setAlphaMode(uint8_t alpha) {
	SDL_SetTextureAlphaMod(alpha);
}

SDL_Texture& SdlHardwareTexture::getTexture() const {
	return *_texture;
}
