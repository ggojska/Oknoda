#pragma once
#include "stdafx.h"

enum button_state { BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED };

class Button
{
private:
	//Variables
	short unsigned buttonState;
	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, unsigned character_size, sf::Color textIlde, sf::Color textHover, sf::Color textActive, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	const bool isPressed() const;

	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

