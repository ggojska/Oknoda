#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariables();
	this->initKeybinds();
	this->initFonts();
	this->initButtons();
	this->initBackground();
}

MainMenu::~MainMenu()
{
	for (auto const& x : buttons)
	{
		delete x.second;
	}
}

void MainMenu::initVariables()
{

}

void MainMenu::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Graphics/mainmenu_background.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->backgroundTexture);
}

void MainMenu::initKeybinds()
{
	std::ifstream ifs("Config/mainmenu_keybinds.ini");

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

void MainMenu::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Viking.TTF"))
	{
		throw("ERROR::MAINMENUSTATEE Could not load font (Fonts/Viking.TTF)");
	}
}

void MainMenu::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(this->window->getSize().x/2, this->window->getSize().y / 2 - 75, 250, 75,
		&this->font, "Start Game", 25,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(175, 175, 175, 200), sf::Color(175, 175, 175, 255), sf::Color(255, 175, 175, 255)
	);
	this->buttons["EDITOR_STATE"] = new Button(this->window->getSize().x / 2, this->window->getSize().y / 2 + 25, 250, 75,
		&this->font, "Editor", 25,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(175, 175, 175, 200), sf::Color(175, 175, 175, 255), sf::Color(255, 175, 175, 255)
	);
	this->buttons["EXIT_STATE"] = new Button(this->window->getSize().x / 2, this->window->getSize().y / 2 + 250, 250, 75,
		&this->font, "Exit Game", 25,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(175, 175, 175, 200), sf::Color(175, 175, 175, 255), sf::Color(255, 175, 175, 255)
	);
}

void MainMenu::updateInput(const float& dt)
{

}

void MainMenu::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// new game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new Gamestate(this->window, this->supportedKeys, this->states));
	}

	// editor state
	if (this->buttons["EDITOR_STATE"]->isPressed())
	{
		this->states->push(new EditorState(this->window, this->supportedKeys, this->states));
	}

	// quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}
}

void MainMenu::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void MainMenu::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenu::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(*target);
}
