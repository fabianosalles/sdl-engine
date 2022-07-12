#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "InputHandler.h"
#include "PauseState.h"
#include <iostream>

const std::string PlayState::playID = "PLAY";

void PlayState::update() {
    if (InputHandler::instance().keyDown(SDL_SCANCODE_ESCAPE)) {
        Game::instance().state()->push(new PauseState());
    }

	for (auto obj : objects) 
		obj->update();
}

void PlayState::render() {
	for (auto obj : objects) 
		obj->draw();
}

bool PlayState::onEnter() {
	if (!TextureManager::instance().load("assets/helicopter.png", "helicopter", Game::instance().renderer())) {
		return false;
	}

	auto player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));
	objects.push_back(player);

    std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	for (auto obj : objects)
		obj->clean();

	objects.clear();
	TextureManager::instance().remove("helicopter");
    std::cout << "exiting PlayState\n";
    return true;
}
