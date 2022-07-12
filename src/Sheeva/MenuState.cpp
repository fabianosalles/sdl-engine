#include <iostream>
#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"

const std::string MenuState::menuID = "MENU";


void MenuState::update() {
	for (auto object : objects) {
		object->update();
	}
}

void MenuState::render() {
	for (auto object : objects) {
		object->draw();
	}
}

 bool MenuState::onEnter() {
	 std::cout << "entering MenuState\n";
	 std::cout << "\tloading assets...\n";
	 if (!TextureManager::instance().load("assets/button.png", "btn-play",
		 Game::instance().renderer())) {
		 return false;
	 }

	 if (!TextureManager::instance().load("assets/exit.png", "btn-exit",
		 Game::instance().renderer())) {
		 return false;
	 }

	 objects.push_back(new MenuButton(new LoaderParams(100, 100, 400, 100, "btn-play"), onPlayClicked));
	 objects.push_back(new MenuButton(new LoaderParams(100, 300, 400, 100, "btn-exit"), onExitClicked));
	 
	 return true;
}

 bool MenuState::onExit() {
	 std::cout << "exiting MenuState\n";
	 for (auto object : objects)
		 object->clean();
	 objects.clear();

	 TextureManager::instance().remove("btn-play");
	 TextureManager::instance().remove("btn-exit");
	 
	 return true;
}

 void MenuState::onPlayClicked() {
	 std::cout << "Play button clicked\n";
	 Game::instance().state()->change(new PlayState());
 }

 void MenuState::onExitClicked() {
	 std::cout << "Exit button clicked\n";
	 Game::instance().quit();
 }
