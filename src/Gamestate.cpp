#include "Gamestate.h"

Gamestate::Gamestate(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTextures();
	this->initPlayer();
}

Gamestate::~Gamestate()
{
	delete this->player;
}

void Gamestate::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

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

void Gamestate::initTextures()
{
	if (!this->textures["PLAYER"].loadFromFile("Graphics/Entities/player.png"))
	{
		std::cout << "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}
}

void Gamestate::initPlayer()
{
	this->player = new Player(0, 0, this->textures["PLAYER"]);
}

void Gamestate::endStateUpdate()
{

}

void Gamestate::updateInput(const float& dt)
{
	//Player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player->move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player->move(dt, 0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		this->player->move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player->move(dt, 1.f, 0.f);
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->quit = true;
	}
}

void Gamestate::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->player->update(dt);
}

void Gamestate::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player->render(window);

}
