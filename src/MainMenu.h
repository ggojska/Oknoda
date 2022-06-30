#pragma once
#include "Gamestate.h"
#include "Button.h"

class MainMenu :
    public State
{
private:
    //Variables
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Font font;
    std::map<std::string, Button*> buttons;

    //Functions
    void initKeybinds();
    void initFonts();
    void initButtons();
    void initVariables();
    void initBackground();

public:
    MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenu();

    //Functions
    void endStateUpdate();
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
    void renderButtons(sf::RenderTarget* target);
};

