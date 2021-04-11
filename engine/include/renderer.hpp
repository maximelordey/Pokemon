#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include "window.hpp"

typedef uint32_t RendererFlags;
typedef int32_t RenderIndex;

class Renderer {
	public:
		Renderer();
		Renderer(const RendererCreateInfo& flags);
		~Renderer();
		Renderer(const Renderer& renderer);
		Renderer(Renderer&& renderer);

		Renderer& operator=(const Renderer& renderer);
		Renderer& operator=(Renderer&& renderer);	
	private:
		SDL_Renderer* renderer;
};

typedef struct RendererCreateInfo {
	Window& window;
	RendererIndex index;
	RendererFlags flags
};

#endif
