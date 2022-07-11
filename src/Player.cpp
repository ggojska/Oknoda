#include "Player.h"

Player::Player(float x, float y, sf::Texture& textureSheet)
	: attacking(false)
{
	this->setPosition(x, y);

	//this->createHitboxComponent(this->sprite, 0.f, 0.f, this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height);
	this->createHitboxComponent(this->sprite, 0.f, 0.f, 128.f, 128.f);
	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(textureSheet);

	this->animationComponent->addAnimation("WALK_DOWN",  15.f, 0, 0, 3, 0, 128, 128);
	this->animationComponent->addAnimation("WALK_LEFT",  15.f, 0, 1, 3, 1, 128, 128);
	this->animationComponent->addAnimation("WALK_RIGHT", 15.f, 0, 2, 3, 2, 128, 128);
	this->animationComponent->addAnimation("WALK_UP",    15.f, 0, 3, 3, 3, 128, 128);
	this->animationComponent->addAnimation("IDLE",       15.f, 0, 4, 0, 4, 128, 128);
}

Player::~Player()
{

}

void Player::updateAnimation(const float& dt)
{
	if (this->attacking)
	{
		if (this->animationComponent->play("WALK_RIGHT", dt, true)) //TODO add attack animation
		{
			this->attacking = false;
		}
	}
	if (this->movementComponent->getDirection().x == 1)
	{
		this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getDirection().x == -1)
	{
		this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getDirection().y == 1)
	{
		this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getDirection().y == -1)
	{
		this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else
		this->animationComponent->play("IDLE", dt);
}

void Player::updateAttack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->attacking = true;
	}
}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	this->updateAttack();
	this->updateAnimation(dt);

	this->hitboxComponent->update();
}

//Init fuctnions
void Player::initVariables()
{

}
