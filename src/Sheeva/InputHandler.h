#pragma once
#include <SDL.h>
#include <vector>

class InputHandler {
public:
	static auto& instance() {
		static InputHandler _instance;
		return _instance;
	}

	InputHandler(const InputHandler&) = delete;
	InputHandler& operator=(const InputHandler&) = delete;
	InputHandler(InputHandler&&) = delete;
	InputHandler& operator=(InputHandler&&) = delete;

	void update();
	void clean();
	void initJoysticks();
	bool joysticksInitialized() { return _joysticksInitialized; }
private:
	InputHandler(){}

	bool _joysticksInitialized;
	std::vector<SDL_Joystick*> _joysticks;
};