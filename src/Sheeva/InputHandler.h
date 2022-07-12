#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"

const int JOYSTICK_DEAD_ZONE = 10000;

enum MouseButton {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

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

	int joyX(int joy, int stick);
	int joyY(int joy, int stick);
	bool mouseButton(MouseButton button) { return _mouseButtons[button]; }
	Vector2D& mousePosition() { return *_mousePosition;  }

	bool keyDown(SDL_Scancode key);
private:
	InputHandler();

	bool _joysticksInitialized;
	std::vector<SDL_Joystick*> _joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*>> _joyValues;
	std::vector<std::vector<bool>> _joyButtons;
	std::vector<bool> _mouseButtons;
	Vector2D* _mousePosition = new Vector2D(0,0);
	const Uint8* _keyboardState;

	//keyboard events
	void onKeyUp();
	void onKeyDown();

	// mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseDown(SDL_Event& event);
	void onMouseUp(SDL_Event& event);
};