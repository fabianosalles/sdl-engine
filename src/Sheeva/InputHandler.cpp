#include <iostream>
#include <SDL.h>

#include "InputHandler.h"
#include "Game.h"

void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			Game::instance().quit();
	}

}

void InputHandler::clean() {
	for (auto joy : _joysticks) {
		SDL_JoystickClose(joy);
	}
}

void InputHandler::initJoysticks() {
	
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if (SDL_NumJoysticks() == 0) {
		_joysticksInitialized = false;
		return;
	}

	for (int i = 0; i < SDL_NumJoysticks(); i++) {
		SDL_Joystick* joy = SDL_JoystickOpen(i);
		if (joy) 
			_joysticks.push_back(joy);
		else
			std::cerr << SDL_GetError();
	}

	if (_joysticks.size() > 0) {
		_joysticksInitialized = true;
		std::cout << "Initialized " << _joysticks.size() << " joystick(s)\n";
	}

}