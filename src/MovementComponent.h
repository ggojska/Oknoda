#pragma once

#include "stdafx.h"

enum movementStates { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };
class MovementComponent
{
private:
	//Variables
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;

	//Initializers

public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
	~MovementComponent();

	//Accessors
	const sf::Vector2f& getVelocity() const;
	sf::Vector2f getDirection();

	//Functions
	void move(const float& dt, const float dir_x, const float dir_y);
	void update(const float& dt);
};

