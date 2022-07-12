#include "GameStateMachine.h"

void GameStateMachine::push(GameState* state)
{
	states.push_back(state);
	states.back()->onEnter();
}

void GameStateMachine::pop()
{
	if (!states.empty()) {
		if (states.back()->onExit()) {
			delete states.back();
			states.pop_back();
		}
	}
}

void GameStateMachine::change(GameState* state)
{
	if (!states.empty()) {
		if (states.back()->stateID() == state->stateID())
			return;

		if (states.back()->onExit()) {
			delete states.back();
			states.pop_back();
		}
	}
	states.push_back(state);
	states.back()->onEnter();
}

void GameStateMachine::update() {
	if (!states.empty())
		states.back()->update();
}

void GameStateMachine::render() {
	if (!states.empty())
		states.back()->render();
}

