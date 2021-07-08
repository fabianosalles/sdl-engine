#pragma once

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

#include <SDL.h>
#include <vector>

class Game
{
public:
	Game() {};
	~Game() {};

	bool init(const char* title, int x, int y, int w, int h, bool fullscreen = false);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return _running; }
private:
	bool _running;
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::vector<GameObject*> objects;
	GameObject* go;
	GameObject* player;
	Enemy* enemy;

	int _currentFrame;
};

