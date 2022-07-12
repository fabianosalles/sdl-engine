#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

const int FPS = 60;
const int FRAME_DELAY = 1000.0f / FPS;

int main(int argc, char** argv) {
	std::cout << "Game init attempt...\n";
	if (!Game::instance().init("Chapter 1 : Setting Up SDL", 100, 100, 640, 480, false)) {
		std::cerr << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "game init success!\n";
	
	Uint32 frameStart, frameTime;
	while (Game::instance().running())
	{
		frameStart = SDL_GetTicks();

		Game::instance().handleEvents();
		Game::instance().update();
		Game::instance().render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < FRAME_DELAY) {
			SDL_Delay((int)(FRAME_DELAY - frameTime));
		}
	}
	std::cout << "game closing...\n";
	Game::instance().clean();
	
	return EXIT_SUCCESS;

}