#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
	:sprite(sprite), textureSheet(textureSheet)
{

}

AnimationComponent::~AnimationComponent()
{
	// TODO: Fix this. This uncommented provides compiler error:
	// 1>AnimationComponent.obj : error LNK2019: unresolved external symbol "public: 
	// __thiscall AnimationComponent::Animation::~Animation(void)" 
	// (??1Animation@AnimationComponent@@QAE@XZ) referenced in function "public: 
	// void * __thiscall AnimationComponent::Animation::`scalar deleting destructor'(unsigned int)" 
	// (??_GAnimation@AnimationComponent@@QAEPAXI@Z)

	//for (auto& i : this->animations)
	//{
	//	delete i.second;
	//}
}

void AnimationComponent::addAnimation(const std::string key, 
	float animationTimer, int startFrame_x, int startFrame_y, int frames_x, int frames_y, 
	int width, int height)
{
	this->animations[key] = new Animation(
		sprite, textureSheet, 
		animationTimer, 
		startFrame_x, startFrame_y, frames_x, frames_y, 
		width, height
	);
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	animations[key]->play(dt);
}
