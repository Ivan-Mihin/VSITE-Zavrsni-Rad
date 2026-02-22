#include "command_exit.h"

CommandExit::CommandExit(sf::RenderWindow& windowRef)
    : window(windowRef)
{
}

void CommandExit::execute()
{
    window.close();
}