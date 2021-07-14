#include <iostream>
#include <SDL.h>

#include "InputHandler.h"
#include "Game.h"

	
bool InputHandler::keyDown(SDL_Scancode key)
{
	if (_keyboardState != 0) {
		return _keyboardState[key] == 1;
	}
	return false;
}

InputHandler::InputHandler() {
	_keyboardState = SDL_GetKeyboardState(0);
	for (int i = 0; i < 3; i++) 
		_mouseButtons.push_back(false);
}

void InputHandler::update() {
	_keyboardState = SDL_GetKeyboardState(0);

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			Game::instance().quit();

		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT)
				_mouseButtons[MouseButton::LEFT] = true;

			if (event.button.button == SDL_BUTTON_MIDDLE)
				_mouseButtons[MouseButton::MIDDLE] = true;

			if (event.button.button == SDL_BUTTON_RIGHT)
				_mouseButtons[MouseButton::RIGHT] = true;
		}

		if (event.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT)
				_mouseButtons[MouseButton::LEFT] = false;

			if (event.button.button == SDL_BUTTON_MIDDLE)
				_mouseButtons[MouseButton::MIDDLE] = false;

			if (event.button.button == SDL_BUTTON_RIGHT)
				_mouseButtons[MouseButton::RIGHT] = false;
		}

		if (event.type == SDL_MOUSEMOTION) {
			_mousePosition->setX(event.motion.x);
			_mousePosition->setY(event.motion.y);
		}

		if (event.type == SDL_JOYBUTTONDOWN) {
			_joyButtons[event.jaxis.which][event.jbutton.button] = true;
		}

		if (event.type == SDL_JOYBUTTONUP) {
			_joyButtons[event.jaxis.which][event.jbutton.button] = false;
		}

		if (event.type == SDL_JOYAXISMOTION) {
			int wichOne = event.jaxis.which;

			switch (event.jaxis.axis) {
			case 0: /* left stick move left or right */
				if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
					_joyValues[wichOne].first->setX(1);
				else if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
					_joyValues[wichOne].first->setX(-1);
				else
					_joyValues[wichOne].first->setX(0);
				break;

			case 1: /* left stick move up or down */
				if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
					_joyValues[wichOne].first->setY(1);
				else if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
					_joyValues[wichOne].first->setY(-1);
				else
					_joyValues[wichOne].first->setY(0);
				break;

			case 3: /* right stick move left or right */
				if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
					_joyValues[wichOne].second->setX(1);
				else if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
					_joyValues[wichOne].second->setX(-1);
				else
					_joyValues[wichOne].second->setX(0);
				break;

			case 4: /* right stick move up or down */
				if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
					_joyValues[wichOne].second->setY(1);
				else if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
					_joyValues[wichOne].second->setY(-1);
				else
					_joyValues[wichOne].second->setY(0);
				break;
			}
		}
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
		if (joy) {
			_joysticks.push_back(joy);
			_joyValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

			std::vector<bool> temp;
			for (int i = 0; i < SDL_JoystickNumButtons(joy); i++) {
				temp.push_back(false);
			}
			_joyButtons.push_back(temp);
		}
		else
			std::cerr << SDL_GetError();
	}

	if (_joysticks.size() > 0) {
		_joysticksInitialized = true;
		std::cout << "Initialized " << _joysticks.size() << " joystick(s)\n";
	}

}

int InputHandler::joyX(int joy, int stick) {
	if (_joyValues.size() > 0) {
		if (stick == 1) 
			return _joyValues[joy].first->getX();

		if (stick == 2)
			return _joyValues[joy].second->getX();
	}
	return 0;
}

int InputHandler::joyY(int joy, int stick) {
	if (_joyValues.size() > 0) {
		if (stick == 1)
			return _joyValues[joy].first->getY();

		if (stick == 2)
			return _joyValues[joy].second->getY();
	}
	return 0;
}