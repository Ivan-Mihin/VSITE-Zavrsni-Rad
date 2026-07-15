#include "assets.h"
#include "tetris.h"

Tetris::Tetris() :
    sprite_background(Assets::getInstance().getTexture("background_main_menu")),
    sprite_board(Assets::getInstance().getTexture("board"))
{
    sprite_board.setPosition({ 220, 25 });

    board.assign(BOARD_ROWS, std::vector<int>(BOARD_COLUMNS, 0));
}

void Tetris::handleInput(const sf::Event& event)
{
    // add user input later
}

void Tetris::update(float delta_time)
{
    // add game logic updates later
}

void Tetris::render(sf::RenderWindow& window)
{
    window.draw(sprite_background);
    window.draw(sprite_board);
}