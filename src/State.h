#pragma once
#include "stdafx.h"
#include "Entity.h"

class State
{
protected:
	std::stack<State*>* states; // pointer to itself! Very important

	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	std::vector<sf::Texture> textures;

	//Functions
	virtual void initKeybinds() = 0;

public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();

	void endState();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	void updateMousePositions();
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

