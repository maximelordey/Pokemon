#include "sdl_hardware_texture.h"

SdlHardwareTexture::SdlHardwareTexture(SDL_Renderer& renderer, SDL_Surface& surface) {
	_texture = SDL_CreateTextureFromSurface(&renderer, &surface);
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

SDL_Texture* SdlHardwareTexture::getTexture() const {
	return _texture;
}
