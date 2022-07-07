#include "Entity.h"

Entity::Entity()
	: texture(NULL), movementComponent(NULL), animationComponent(NULL), hitboxComponent(NULL)
{

}

Entity::~Entity()
{
	delete this->movementComponent;
	delete this->animationComponent;
	delete this->hitboxComponent;
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

void Entity::createAnimationComponent(sf::Texture& textureSheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, textureSheet);
}

void Entity::createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width, height);
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

}

void Entity::render(sf::RenderTarget& target)
{
		target.draw(this->sprite);
		if (this->hitboxComponent)
			this->hitboxComponent->render(target);
}

