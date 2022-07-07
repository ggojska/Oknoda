#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
	:sprite(sprite), textureSheet(textureSheet), lastAnimation(NULL)
{

}

AnimationComponent::~AnimationComponent()
{
	// TODO: Fix this. This if uncommented provides compiler error

	//for (auto& i : this->animations)
	//{
	//	delete i.second;
	//}
}

void AnimationComponent::addAnimation(const std::string key, 
	float animationTimer, int startFrame_x, int startFrame_y, int frames_x, int frames_y, 
	int width, int height)
{
	this->animations[key] = new Animation (
		sprite, textureSheet, 
		animationTimer, 
		startFrame_x, startFrame_y, frames_x, frames_y, 
		width, height
	);
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	if (this->lastAnimation != this->animations[key])
	{
		if (this->lastAnimation == NULL)
			this->lastAnimation = animations[key];
		else
		{
			this->lastAnimation->reset();
			this->lastAnimation = this->animations[key];
		}
	}

	animations[key]->play(dt);
}
