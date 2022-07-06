#include "Player.h"

Player::Player(float x, float y, sf::Texture& textureSheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(textureSheet);

	this->animationComponent->addAnimation("PLAYER_IDLE", 100.f, 0, 0, 3, 0, 16, 16);
}

Player::~Player()
{

}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	this->animationComponent->play("PLAYER_IDLE", dt);
}

//Init fuctnions
void Player::initVariables()
{

}
