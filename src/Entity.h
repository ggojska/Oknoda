#pragma once

#include "stdafx.h"

class Entity
{
private:
	void initVariables();

protected:
	sf::Sprite* sprite;
	sf::Texture* texture;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	//Component Fuctions
	void createSprite(sf::Texture* texture);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& dt, const float dir_x, const float dir_y);

	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

