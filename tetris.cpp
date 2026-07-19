#include "assets.h"
#include "tetris.h"
#include "tetromino_factory.h"

Tetris::Tetris() :
    sprite_background(Assets::getInstance().getTexture("background_main_menu")),
    sprite_board(Assets::getInstance().getTexture("board")),
    sprite_tetromino(Assets::getInstance().getTexture("tetromino"))
{
    sprite_board.setPosition({ 220, 25 });

    spawnTetromino();

    tetromino_fall_delay = 0.5f;
}

void Tetris::spawnTetromino()
{
    int random = rand() % 7 + 1;
    tetromino = TetrominoFactory::createTetromino(static_cast<TetrominoShape>(random));
    tetromino->setPosition({ 4, 0 });
}

void Tetris::tetrominoFall()
{
    if (tetromino_fall.getElapsedTime().asSeconds() >= tetromino_fall_delay)
    {
        sf::Vector2i previous_position = tetromino->getPosition();
        tetromino->move({ 0, 1 });

        if (board.isValidPosition(tetromino->getBlocks()))
        {
            tetromino_fall.restart();
        }
        else
        {
            // Reset to previous position
            tetromino->move({ 0,-1 });

            // Write the tetromino's position onto the board
            board.lockTetromino(tetromino->getBlocks(), static_cast<int>(tetromino->getColor()) + 1);

            // Spawn a new tetromino
            spawnTetromino();
        }
    }
}

void Tetris::handleInput(const sf::Event& event)
{
    // add user input later
}

void Tetris::update(float delta_time)
{
    tetrominoFall();
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

        float pos_x = static_cast<float>(blocks[index].x * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_X);
        float pos_y = static_cast<float>(blocks[index].y * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_Y);
        sprite_tetromino.setPosition({ pos_x, pos_y });

        window.draw(sprite_tetromino);
    }

    // Draw Locked Tetrominoes
    for (int row = 0; row < board.getRows(); ++row)
    {
        for (int column = 0; column < board.getColumns(); ++column)
        {
            int color = board.getCell(row, column);

            // Skip if color is 0, needs fixing later
            if (color == 0) continue;

            sf::Vector2i position = { (color - 1) * TEXTURE_SIZE, 0 };
            sf::Vector2i size = { TEXTURE_SIZE, TEXTURE_SIZE };
            sprite_tetromino.setTextureRect(sf::IntRect(position, size));

            float pos_x = static_cast<float>(column * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_X);
            float pos_y = static_cast<float>(row * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_Y);
            sprite_tetromino.setPosition({ pos_x, pos_y });

            window.draw(sprite_tetromino);
        }
    }
}