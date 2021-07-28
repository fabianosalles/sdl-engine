#include "GameState.h"
#include "GameObject.h"
#include <vector>

class MenuState : public GameState {
public:
	virtual void update(); 
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string stateID() { return menuID; }

private:
	const static std::string menuID;
	std::vector<GameObject*> objects;

	static void onPlayClicked();
	static void onExitClicked();
};