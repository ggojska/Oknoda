#pragma once

#include "stdafx.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "HitboxComponent.h"

class Entity
{
private:

protected:
	sf::Sprite sprite;
	sf::Texture* texture;
	
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	HitboxComponent* hitboxComponent;

public:
	Entity();
	virtual ~Entity();

	//Component Fuctions
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& textureSheet);
	void createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& dt, const float dir_x, const float dir_y);

	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

