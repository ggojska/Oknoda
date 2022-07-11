#pragma once

#include "stdafx.h"

class AnimationComponent
{
private:
	class Animation
	{
	public:
		//Variables
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;
		bool done;
		float timer;
		float animationTimer;
		unsigned int width;
		unsigned int height;

		Animation(sf::Sprite& sprite, sf::Texture& textureSheet, 
			float animationTimer, int startFrame_x, int startFrame_y, int frames_x, int frames_y, int width, int height)
			: sprite(sprite), textureSheet(textureSheet), 
			startRect(sf::IntRect(startFrame_x* width, startFrame_y* height, width, height)), 
			currentRect(startRect),
			endRect(sf::IntRect(frames_x* width, frames_y* height, width, height)), done(false), timer(0.f),
			animationTimer(animationTimer), width(width), height(height)
		{
			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
		}
		//Accessors
		const bool& isDone() const
		{
			return this->done;
		}

		//Functions
		const bool& play(const float& dt)
		{
			//Update timer
			this->timer += 100.f * dt;
			this->done = false;

			if (this->timer >= this->animationTimer)
			{
				//reset timer
				this->timer = 0.f;

				//Animate
				if (this->currentRect != this->endRect)
				{
					this->currentRect.left += this->width;
				}
				else //Reset
				{
					this->currentRect.left = this->startRect.left;
					this->done = true;
				}

				this->sprite.setTextureRect(this->currentRect);
			}
			return this->done;
		}

		bool play(const float& dt, float mod_percent)
		{
			//Update timer
			if (mod_percent < 0.5f) mod_percent = 0.5f;
			this->done = false;

			this->timer += mod_percent * 100.f * dt;
			if (this->timer >= this->animationTimer)
			{
				//reset timer
				this->timer = 0.f;

				//Animate
				if (this->currentRect != this->endRect)
				{
					this->currentRect.left += this->width;
				}
				else //Reset
				{
					this->currentRect.left = this->startRect.left;
					this->done = true;
				}

				this->sprite.setTextureRect(this->currentRect);
			}
			return this->done;
		}

		void reset()
		{
			this->timer = this->animationTimer;
			this->currentRect.left = this->startRect.left;
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;
	Animation* lastAnimation;
	Animation* priorityAnimation;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
	virtual ~AnimationComponent();
	//Accessors
	const bool& isDone(const std::string key);

	//Functions
	void addAnimation(const std::string key, float animationTimer, int startFrame_x, int startFrame_y, int frames_x, int frames_y, int width, int height);

	const bool& play(const std::string key, const float& dt, const bool priority = false);
	const bool& play(const std::string key, const float& dt, const float& modifier, const float& modifier_max, const bool priority = false);
};

