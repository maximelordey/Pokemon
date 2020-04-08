// Pokemon.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Pokemon.h"
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>

#define WAV_PATH "C:\\Users\\quent\\Documents\\Polytech\\Annee3\\projetPerso\\Sons\\musique.mp3"
#define WAV2_PATH "C:\\Users\\quent\\Documents\\Polytech\\Annee3\\projetPerso\\Sons\\musique.mp3"

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[])
{

	std::cout << "COUCOU" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = SDL_CreateWindow("Hello SDL World for Pokemon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

	// Check that the window was successfully created
	if (NULL == window)
	{
		// In the case that the window could not be made...
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Event windowEvent;

	/*while (true)
	{
		if (SDL_PollEvent(&windowEvent))
		{
			if (SDL_QUIT == windowEvent.type)
			{
				break;
			}
		}
	}*/


	Mix_Music *wave = NULL;
	Mix_Music *wave2 = NULL;

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != 0) {
		std::cout << "Impossible d'ouvrir mixer " << SDL_GetError() << std::endl;
		return 1;
	}

	wave = Mix_LoadMUS(WAV_PATH);
	wave2 = Mix_LoadMUS(WAV2_PATH);

	std::cout << wave << std::endl;

	Mix_VolumeMusic(MIX_MAX_VOLUME / 6);

	if (wave == NULL || wave2 == NULL) {
		std::cout << "Impossible de chargé un fichier .ogg " << SDL_GetError() << std::endl;
		return 1;
	}

	if (Mix_PlayMusic(wave, 1) != 0) {
		std::cout << "Impossible de jouer le fichier " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Delay(5000);

	if (Mix_PlayMusic(wave2, 1) != 0) {
		std::cout << "Impossible de jouer le fichier " << SDL_GetError() << std::endl;
		return 1;
	}

	while (Mix_PlayingMusic());

	Mix_FreeMusic(wave);
	Mix_FreeMusic(wave2);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}