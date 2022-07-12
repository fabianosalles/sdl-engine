#include <iostream>

#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"
#include "MenuState.h"

bool Game::init(const char* title, int x, int y, int w, int h, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL init failed\n";
		return false;
	}
	
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	_window = SDL_CreateWindow(title, x, y, w, h, flags);
	if (_window == NULL) {
		std::cout << "SDL create window failed\n";
		return false;
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, 0);
	if (_renderer == NULL) {
		std::cout << "SDL create renderer failed\n";
		return false;
	}
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

	InputHandler::instance().initJoysticks();

	std::cout << "SDL init success\n";

	_state = new GameStateMachine();
	_state->push(new MenuState());
	_running = true;

	return true;
}

void Game::render() {
	SDL_RenderClear(_renderer);

	_state->render();

	SDL_RenderPresent(_renderer);
}

void Game::clean() {
	std::cout << "cleaning game...\n";
	InputHandler::instance().clean();
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

void Game::handleEvents() {
	InputHandler::instance().update();
	
}

void Game::update() {
	_state->update();
}