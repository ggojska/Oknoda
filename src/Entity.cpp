#include "Entity.h"

void Entity::initVariables()
{
	this->sprite = NULL;
	this->texture = NULL;
	this->movementSpeed = 0.f;
}

Entity::Entity()
{
	this->initVariables();
	this->movementSpeed = 180.f;
}

Entity::~Entity()
{
	delete this->sprite;
}

//Component Fuctions
void Entity::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

void Entity::setPosition(const float x, const float y)
{
	if (this->sprite)
	{
		this->sprite->setPosition(x, y);
	}
}

//Functoins
void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	if(this->sprite)
		this->sprite->move(dir_x * this->movementSpeed * dt , dir_y * this->movementSpeed * dt);
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
	if(this->sprite)
		target->draw(*this->sprite);
}

