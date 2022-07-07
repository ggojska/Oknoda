#include "Button.h"

Button::Button(float x, float y, float width, float height, 
				sf::Font* font, std::string text, unsigned characterSize,
				sf::Color textIlde, sf::Color textHover, sf::Color textActive,
				sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(textIlde);
	this->text.setCharacterSize(characterSize);

	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2.f, this->shape.getGlobalBounds().height / 2.f);
	this->text.setOrigin(this->text.getGlobalBounds().width / 2.f, this->text.getGlobalBounds().height / 2.f);

	this->text.setPosition(
		sf::Vector2f(this->shape.getPosition().x, 
		this->shape.getPosition().y - static_cast<float>(this->text.getCharacterSize()) / 4.f)
	);

	this->textIdleColor = textIlde;
	this->textHoverColor = textHover;
	this->textActiveColor = textActive;

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
}

Button::~Button()
{

}

//Accessors
const bool Button::isPressed() const{
	return false ? true : (this->buttonState == BTN_PRESSED);
}

//Functions
void Button::update(sf::Vector2f mousePos)
{
	//Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_PRESSED;
		}
	}

	switch (this->buttonState) {
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		this->text.setFillColor(this->textIdleColor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		this->text.setFillColor(this->textHoverColor);
		break;
	case BTN_PRESSED:
		this->shape.setFillColor(this->activeColor);
		this->text.setFillColor(this->textActiveColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Blue);
		break;
	}
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}
