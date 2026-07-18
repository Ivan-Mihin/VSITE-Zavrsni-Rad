#include "assets.h"
#include "tetris.h"
#include "tetromino_factory.h"

Tetris::Tetris() :
    sprite_background(Assets::getInstance().getTexture("background_main_menu")),
    sprite_board(Assets::getInstance().getTexture("board")),
    sprite_tetromino(Assets::getInstance().getTexture("tetromino"))
{
    sprite_board.setPosition({ 220, 25 });
    board.assign(BOARD_ROWS, std::vector<int>(BOARD_COLUMNS, 0));

    spawnTetromino();
}

void Tetris::spawnTetromino()
{
    int random = rand() % 7 + 1;
    tetromino = TetrominoFactory::createTetromino(static_cast<TetrominoShape>(random));
    tetromino->setPosition({ 4, 0 });
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

    // Draw Tetromino
    std::vector<sf::Vector2i> blocks = tetromino->getBlocks();

    for (int index = 0; index < 4; ++index)
    {
        sf::Vector2i position = { (int)tetromino->getColor() * TEXTURE_SIZE, 0 };
        sf::Vector2i size = { TEXTURE_SIZE, TEXTURE_SIZE };
        sprite_tetromino.setTextureRect(sf::IntRect(position, size));

        float pos_x = static_cast<float>(blocks[index].x * TEXTURE_SIZE + BOARD_OFFSET_X);
        float pos_y = static_cast<float>(blocks[index].y * TEXTURE_SIZE + BOARD_OFFSET_Y);
        sprite_tetromino.setPosition({ pos_x, pos_y });

        window.draw(sprite_tetromino);
    }
}