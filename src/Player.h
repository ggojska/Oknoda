#pragma once

#include "Entity.h"

class Player :
    public Entity
{
private:
    //Variables
    
    //Initializer fuctions
    void initVariables();
    //void initComponents();

public:
    Player(float x, float y, sf::Texture& textureSheet);
    virtual ~Player();

    //Fuction
    virtual void update(const float& dt);
};

