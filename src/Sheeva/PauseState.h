//
// Created by fabiano on 12/07/22.
//

#ifndef SHEEVA_PAUSESTATE_H
#define SHEEVA_PAUSESTATE_H


#include <map>
#include "GameState.h"
#include "GameObject.h"

using namespace std;

class PauseState: public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string stateID() const { return _pauseID; }
private:
    static void onExitToMain();
    static void onResumePlay();

    static const std::string _pauseID;
    vector<GameObject*> _objects;
    static const map<string, string> _textures;
};


#endif //SHEEVA_PAUSESTATE_H
