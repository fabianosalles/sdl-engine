#include "PlayState.h"
#include <iostream>

const std::string PlayState::playID = "PLAY";

void PlayState::update() {

}

void PlayState::render() {

}

bool PlayState::onEnter() {
	std::cout << "entering PLayState\n";
	return true;
}
bool PlayState::onExit() {
	std::cout << "exiting PlayState\n";
	return true;
}
