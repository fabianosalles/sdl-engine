#pragma once

#include <vector>
#include "GameState.h"

class GameStateMachine {
public:
	void push(GameState* state);
	void change(GameState* state);
    void pop();

	void update();
	void render();
private:
	std::vector<GameState*> states;
};
