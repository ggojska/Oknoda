#pragma once

#include"stdafx.h"
#include"Gamestate.h"
#include"MainMenu.h"

/*
	Class that works as game engine. Wrapper class
*/
class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Game objects
	std::vector<sf::RectangleShape> enemies;

	//Initialization
	void initWindow();
	void initKeys();
	void initStates();

public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	void endApplication();

	//Update
	void updateSFMLEvents();
	void update();
	void updateDT();

	//Render
	void render();

	//Core
	void run();
};