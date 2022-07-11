#pragma once

#include "Entity.h"

class Player :
    public Entity
{
private:
    //Variables
    bool attacking;
    
    //Initializer fuctions
    void initVariables();
    //void initComponents();

public:
    Player(float x, float y, sf::Texture& textureSheet);
    virtual ~Player();

    //Fuction
    void updateAnimation(const float& dt);
    void updateAttack();
    virtual void update(const float& dt);
};

