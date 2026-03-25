#include "assets.h"
#include "state_playing.h"

StatePlaying::StatePlaying() :
    background(Assets::getInstance().getTexture("background_main_menu"))
{
    background.setPosition({ 0, 0 });
}

void StatePlaying::handleInput(const sf::Event& event)
{
    // add later
}

void StatePlaying::update(float delta_time)
{
    // add later
}

void StatePlaying::render(sf::RenderWindow& window)
{
    // add later
}