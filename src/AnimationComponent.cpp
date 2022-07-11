#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
	:sprite(sprite), textureSheet(textureSheet), lastAnimation(NULL), priorityAnimation(NULL)
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

//Accesors
const bool& AnimationComponent::isDone(const std::string key)
{
	return this->animations[key]->isDone();
}

//Functions
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

const bool& AnimationComponent::play(const std::string key, const float& dt, const bool priority)
{
	if (this->priorityAnimation) // if there is priority animation
	{
		if (this->priorityAnimation == this->animations[key])
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

			// if priority animation is done, remove it
			if (this->animations[key]->play(dt))
			{
				this->priorityAnimation = NULL;
			}
		}
	}
	else // play normal if no priority animation is set
	{
		if (priority)
		{
			this->priorityAnimation = this->animations[key];
		}
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

		// if priority animation is done, remove it
		if (this->animations[key]->play(dt))
		{
			this->priorityAnimation = NULL;
		}
	}
	return this->animations[key]->isDone();
}

const bool& AnimationComponent::play(const std::string key, const float& dt, const float& modifier, const float& modifier_max, const bool priority)
{
	if (this->priorityAnimation) // if there is priority animation
	{
		if (this->priorityAnimation == this->animations[key])
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

			// if priority animation is done, remove it
			if (this->animations[key]->play(dt, abs(modifier / modifier_max)))
			{
				this->priorityAnimation = NULL;
			}
		}
	}
	else // play normal if no priority animation is set
	{
		if (priority)
		{
			this->priorityAnimation = this->animations[key];
		}
		if (this->lastAnimation != this->animations[key])
		{
			if (this->lastAnimation == NULL)
				this->lastAnimation = this->animations[key];
			else
			{
				this->lastAnimation->reset();
				this->lastAnimation = this->animations[key];
			}
		}

		// if priority animation is done, remove it
		if (this->animations[key]->play(dt, abs(modifier / modifier_max)))
		{
			this->priorityAnimation = NULL;
		}
	}
	return this->animations[key]->isDone();
}

