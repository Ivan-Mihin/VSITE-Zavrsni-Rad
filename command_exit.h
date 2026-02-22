#pragma once
#include <SFML/Graphics.hpp>
#include "ICommand.h"

class CommandExit : public ICommand
{
private:
    sf::RenderWindow& window;

public:
    explicit CommandExit(sf::RenderWindow& window);
    void execute() override;
};