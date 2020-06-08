#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"
class Game
{
private:

	//Variables
	GraphicsSettings gfxSettings;
	StateData stateData;
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;

	float gridSize;

	//Initialization
	void initVariables();
	void initGraphicsSettings();
	void initWindow();
	void initKeys();
	void initStateData();
	void initStates();
	


public:
	//Constructor-Destructor
	Game();
	virtual ~Game();

	//functions

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateSMFLEvents();
	void update();

	//render
	void render();
	//core
	void run();
};

#endif // !GAME_H
