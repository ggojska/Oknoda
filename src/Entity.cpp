#include "Entity.h"

Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->movementComponent;
}

void Entity::initVariables()
{
	this->texture = NULL;

	this->movementComponent = NULL;
}

//Component Fuctions
void Entity::setTexture(sf::Texture& texture)
{
	this->texture = &texture;
	this->sprite.setTexture(*this->texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

//Functoins
void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(dt, dir_x, dir_y); //Sets Velocity
	}
}

void Entity::update(const float& dt)
{
	this->movementComponent->update(dt);
}

void Entity::render(sf::RenderTarget* target)
{
		target->draw(this->sprite);
}

