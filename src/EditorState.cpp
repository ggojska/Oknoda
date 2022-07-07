#include "EditorState.h"

EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initFonts();
	this->initButtons();
}

EditorState::~EditorState()
{
	for (auto const& x : buttons)
	{
		delete x.second;
	}
}

void EditorState::initKeybinds()
{
	std::ifstream ifs("Config/editorstate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void EditorState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Viking.TTF"))
	{
		throw("ERROR::EDITORSTATE:: Could not load font (Fonts/Viking.TTF)");
	}
}

void EditorState::initButtons()
{
	this->buttons["BUTTON"] = new Button(this->window->getSize().x / 2, this->window->getSize().y / 2 - 75, 250, 75,
		&this->font, "BUTTON", 25,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(175, 175, 175, 200), sf::Color(175, 175, 175, 255), sf::Color(255, 175, 175, 255)
	);
}

void EditorState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->quit = true;
	}
}

void EditorState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

void EditorState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void EditorState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void EditorState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->renderButtons(*target);
}
