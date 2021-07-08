#include <iostream>
#include <SDL.h>
#include "Game.h"


Game* game = NULL;

int main(int argc, char** argv) {
	game = new Game();
	game->init("Chapter 1 : Setting Up SDL",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600);
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();

		SDL_Delay(10);
	}
	game->clean();
	delete game;
	return EXIT_SUCCESS;

}