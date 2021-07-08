#include <iostream>
#include <SDL.h>
#include "Game.h"


Game* game = NULL;

int main(int argc, char** argv) {
	std::cout << "Game init attempt...\n";
	if (!Game::instance().init("Chapter 1 : Setting Up SDL", 100, 100, 800, 600, false)) {
		std::cerr << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "game init success!\n";
	while (Game::instance().running())
	{
		Game::instance().handleEvents();
		Game::instance().update();
		Game::instance().render();

		SDL_Delay(10);
	}
	std::cout << "game closing...\n";
	Game::instance().clean();
	
	return EXIT_SUCCESS;

}