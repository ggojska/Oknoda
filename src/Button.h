#pragma once
#include "stdafx.h"

enum button_state {BTN_IDLE = 0, BTN_PRESSED = 1, BTN_HOVER = 2};

class Button
{
private:
	//Variables
	button_state buttonState;
	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	const bool isPressed() const;

	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

