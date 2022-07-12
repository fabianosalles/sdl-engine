#pragma once
#include "GameObject.h"
#include "GameState.h"
#include <vector>
#include <map>

using namespace std;

class PlayState : public GameState {
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string stateID() { return playID; }
private:
	static const std::string playID;
	vector<GameObject*> objects;
    static const map<string, string> _textures;
};

