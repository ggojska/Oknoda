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
		unsigned int width;
		unsigned int height;
		float timer;
		float animationTimer;

		Animation(sf::Sprite& sprite, sf::Texture& textureSheet, 
			float animationTimer, int startFrame_x, int startFrame_y, int frames_x, int frames_y, int width, int height)
			: sprite(sprite), textureSheet(textureSheet), animationTimer(animationTimer), width(width), height(height)
		{
			this->timer = 0.f;
			this->startRect = sf::IntRect(startFrame_x * width, startFrame_y * height, width, height);
			this->endRect = sf::IntRect(frames_x * width, frames_y * height, width, height);
			this->currentRect = this->startRect;

			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
		}

		//Functions
		void play(const float& dt)
		{
			//Update timer
			this->timer += 100.f * dt;
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
				}

				this->sprite.setTextureRect(this->currentRect);
			}
		}

		void reset()
		{
 			this->timer = 0.f;
			this->currentRect.left = this->startRect.left;
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;
	Animation* lastAnimation;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
	virtual ~AnimationComponent();

	//Functions
	void addAnimation(const std::string key, float animationTimer, int startFrame_x, int startFrame_y, int frames_x, int frames_y, int width, int height);

	void play(const std::string key, const float& dt);
};

