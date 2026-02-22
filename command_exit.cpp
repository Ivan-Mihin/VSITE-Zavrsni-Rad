#include "command_exit.h"

CommandExit::CommandExit(sf::RenderWindow& windowRef)
    : window(windowRef)
{
}

void CommandExit::execute()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
    {
        window.close();
    }
}