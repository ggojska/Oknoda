#pragma once

#include "stdafx.h"

class Entity
{
private:

protected:
	sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	virtual void move(const float& dt, const float dir_x, const float dir_y);

	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

