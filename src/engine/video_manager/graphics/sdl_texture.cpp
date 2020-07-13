#include "sdl_texture.h"


SdlTexture::SdlTexture(std::string& path) {
	
	_texture = SDL_CreateTextureFromSurface(&renderer, &surface);
}

SdlTexture::~SdlTexture() {
	SDL_DestroyTexture(_texture);
}

uint8_t SdlTexture::getAlphaMode() const {
	uint8_t alpha;
	SDL_GetTextureAlphaMod(_texture, &alpha);
	return alpha;
}

void SdlTexture::setAlphaMode(uint8_t alpha) {
	SDL_SetTextureAlphaMod(alpha);
}

SDL_Texture& SdlTexture::getTexture() const {
	return *_texture;
}
