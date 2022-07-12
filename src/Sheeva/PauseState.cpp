//
// Created by fabiano on 12/07/22.
//

#include <map>
#include <string>
#include "Game.h"
#include "PauseState.h"
#include "MenuState.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "MenuButton.h"

using namespace std;


const string PauseState::_pauseID = "PAUSE";
const map<string, string> PauseState::_textures = {
        { "btn-resume", "assets/resume.png", } ,
        { "btn-main", "assets/main.png" }
    };

void PauseState::onExitToMain() {
    Game::instance().state()->change(new MenuState());
}

void PauseState::onResumePlay() {
    Game::instance().state()->pop();
}

void PauseState::update() {
    for (auto o: _objects) o->update();
}

void PauseState::render() {
    for (auto o: _objects) o->draw();
}

bool PauseState::onEnter() {
    for (auto entry : _textures) {
        if (!TextureManager::instance().load(entry.second, entry.first, Game::instance().renderer())) {
            std::cerr << "Could not load " << entry.second << std::endl;
            return false;
        }
    }

    _objects.push_back(new MenuButton(new LoaderParams(200, 100, 200, 80, "btn-main"), onExitToMain));
    _objects.push_back(new MenuButton(new LoaderParams(200, 300, 200, 80, "btn-resume"), onResumePlay));

    std::cout << "entering PauseState" << endl;
    return true;
}

bool PauseState::onExit() {
    for (auto o : _objects)
        o->clean();
    _objects.clear();

    for (auto entry: _textures)
        TextureManager::instance().remove(entry.first);


    //reset the mouse button states to false
    InputHandler::instance().reset();

    cout << "exiting PauseState" << endl;
    return true;
}

