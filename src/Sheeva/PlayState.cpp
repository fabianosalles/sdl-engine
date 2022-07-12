#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

const map<string, string> PlayState::_textures = {
        {"helicopter", "assets/helicopter.png"},
        {"helicopter2", "assets/helicopter2.png"}
};

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
    for(auto entry : _textures) {
        if (!TextureManager::instance().load(entry.second, entry.first, Game::instance().renderer())) {
            cerr << "Could not load " << entry.second << endl;
            return false;
        }
    }

    objects.push_back(new Player(new LoaderParams(100, 100, 128, 55, "helicopter")));
    objects.push_back(new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2")));

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
