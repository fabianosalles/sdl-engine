#include <iostream>

#include "Game.h"


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

	std::cout << "SDL init success\n";

	std::cout << "Loading assets...\n";
	_textureManager.load("assets/animate-alpha.png", "animate", _renderer);


	_running = true;
	return true;
}

void Game::render() {
	SDL_RenderClear(_renderer);

	_textureManager.draw("animate", 0, 0, 128, 82, _renderer);
	_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, _currentFrame, _renderer);


	SDL_RenderPresent(_renderer);
}

void Game::clean() {
	std::cout << "cleaning game...\n";
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			_running = false;
			break;
		default:
			break;
		}
	}
}

void Game::update() {
	_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}