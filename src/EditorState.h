#pragma once

#include "State.h"
#include "Button.h"

class EditorState :
    public State
{
private:
    //Variables
    sf::Font font;

    std::map<std::string, Button*> buttons;

    //Functions
    void initKeybinds();
    void initFonts();
    void initButtons();
public:
    EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    ~EditorState();

    //Functions
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target);
    void renderButtons(sf::RenderTarget& target);
};

