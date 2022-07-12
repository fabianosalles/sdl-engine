#pragma once

#include "GameObject.h"
#include "GameStateMachine.h"
#include <SDL2/SDL.h>
#include <vector>

class Game
{
public:
	static auto& instance() {
		static Game _instance;
		return _instance;
	}

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;


	bool init(const char* title, int x, int y, int w, int h, bool fullscreen = false);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() { _running = false;  }
	bool running() const { return _running; }
	SDL_Renderer* renderer() const { return _renderer; }
	GameStateMachine* state() { return _state; }
private:
	Game(){}
	bool _running;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	GameStateMachine* _state;
};

