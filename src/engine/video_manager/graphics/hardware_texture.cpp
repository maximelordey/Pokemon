#include "hardware_texture.h"

HardwareTexture::HardwareTexture(SDL_Renderer& renderer, SDL_Surface& surface) {
	_texture = SDL_CreateTextureFromSurface(&renderer, &surface);
}

HardwareTexture::~HardwareTexture() {
	SDL_DestroyTexture(_texture);
}

uint8_t HardwareTexture::getAlphaMode() const {
	uint8_t alpha;
	SDL_GetTextureAlphaMod(_texture, &alpha);
	return alpha;
}

void HardwareTexture::setAlphaMode(uint8_t alpha) {
	SDL_SetTextureAlphaMod(alpha);
}

SDL_Texture* HardwareTexture::getTexture() const {
	return _texture;
}
