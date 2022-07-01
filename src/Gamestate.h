#pragma once
#include "State.h"

class Gamestate :
    public State
{
private:
    //Variables
    Player *player;

    //Functions
    void initKeybinds();
    void initTextures();
    void initPlayer();

public:
    Gamestate(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~Gamestate();
     
    //Functions

    void endStateUpdate();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

