#pragma once
#include "State.h"

class Gamestate :
    public State
{
private:
    //Variables
    Entity player;

    //Functions
    void initKeybinds();

public:
    Gamestate(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~Gamestate();
     
    //Functions

    void endStateUpdate();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

