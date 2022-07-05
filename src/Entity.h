#pragma once

#include "stdafx.h"
#include "MovementComponent.h"

class Entity
{
private:
	void initVariables();

protected:
	sf::Sprite sprite;
	sf::Texture* texture;
	
	MovementComponent* movementComponent;

public:
	Entity();
	virtual ~Entity();

	//Component Fuctions
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& dt, const float dir_x, const float dir_y);

	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

