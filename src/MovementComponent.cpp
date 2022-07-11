#include "MovementComponent.h"

//Costructors
MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration,  float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{

}

//Accesors
const float& MovementComponent::getMaxVelocity() const
{
	return this->maxVelocity;
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

sf::Vector2f MovementComponent::getDirection()
{
	sf::Vector2f ret = sf::Vector2f(0, 0);
	if (this->velocity.x == 0 && this->velocity.y == 0) // not moving
	{
		return sf::Vector2f(0, 0);
	}
	else if (abs(this->velocity.x) > abs(this->velocity.y)) // going faster along oX axis than oY axis
	{
		if (this->velocity.x > 0.f) return sf::Vector2f(1, 0);
		else return sf::Vector2f(-1, 0);
	}
	else // going faster along oY axis than oX axis
	{
		if (this->velocity.y > 0.f) return sf::Vector2f(0, 1);
		else return sf::Vector2f(0, -1);
	}
}

//Functions
void MovementComponent::move(const float& dt, const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{
	//Acceleration till we reach maxVelocity
	if (abs(this->velocity.x) > maxVelocity) // check if velocity.x above maxSpeed
	{
		if (this->velocity.x > 0.f) // check if moving along positive oX
		{
			this->velocity.x = this->maxVelocity;
		}
		else // moving along negative oX
		{
			this->velocity.x = -this->maxVelocity;
		}
	}
	if (abs(this->velocity.y) > maxVelocity) // check if velocity.y above maxSpeed
	{
		if (this->velocity.y > 0.f) // check if moving along positive oY
		{
			this->velocity.y = this->maxVelocity;
		}
		else // moving along negative oY
		{
			this->velocity.y = -this->maxVelocity;
		}
	}

	//Deceleration till object stops
	if (this->velocity.x > 0.f) // check if moving along positive oX
	{
		this->velocity.x -= this->deceleration; // decrease velocity.x
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else // moving along negative oX
	{
		this->velocity.x += this->deceleration; // increase velocity.x
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}
	if (this->velocity.y > 0.f)// check if moving along positive oY
	{
		this->velocity.y -= this->deceleration; // decrease velocity.y
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else // moving along negative oY
	{
		this->velocity.y += this->deceleration; // increase velocity.y
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}

	//Final move
	this->sprite.move(this->velocity * dt);
}
