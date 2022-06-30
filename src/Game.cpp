#include "Game.h"
#include "stdafx.h"

//Constructor
Game::Game()
{
	this->initWindow();
	this->initKeys();
	this->initStates();
}

//Destructor
Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Game::initWindow()
{
	/*Creates a SFML window.*/
	sf::VideoMode videoMode(800,600);
	std::string title = "None";
	unsigned fps = 60;
	bool verticalSyncEnabled = false;

	std::ifstream ifs("Config/window.ini");

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> videoMode.width >> videoMode.height;
		ifs >> fps;
		ifs >> verticalSyncEnabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(videoMode, title, sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(fps);
	this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::initKeys()
{
	std::ifstream ifs("Config/supportedKeys.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;

		while (ifs >> key >> key_value)
		{
			this->supportedKeys[key] = key_value;
		}
	}

	ifs.close();
}

void Game::initStates()
{
	this->states.push(new MainMenu(this->window, &this->supportedKeys, &this->states));
}

void Game::endApplication()
{
	std::cout << "Ending Application!\n";
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		switch (this->sfEvent.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (sfEvent.mouseButton.button == sf::Mouse::Left)
			{
				
			}
			else if (sfEvent.mouseButton.button == sf::Mouse::Right)
			{

			}
			break;
		}
	}
}

//Updates the dt variable with time it takes to update and render one frame
void Game::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}

//Updates current gamestate
void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Aplication end
	else
	{
		this->endApplication();
		this->window->close();
	}
}

//Renders current gamestate
void Game::render()
{
	this->window->clear();
	if (!this->states.empty())
		this->states.top()->render(this->window);

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDT();
		this->update();
		this->render();
	}
}
