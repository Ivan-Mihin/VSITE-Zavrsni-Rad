#include "assets.h"
#include "tetris.h"
#include "tetromino_factory.h"

Tetris::Tetris() :
    sprite_background(Assets::getInstance().getTexture("background_main_menu")),
    sprite_board(Assets::getInstance().getTexture("board")),
    sprite_tetromino(Assets::getInstance().getTexture("tetromino")),
    sprite_tetromino_ghost(Assets::getInstance().getTexture("tetromino_ghost"))

{
    sprite_board.setPosition({ 220, 25 });

    spawnTetromino();

    tetromino_fall_delay = 0.5f;

    key_bindings[sf::Keyboard::Scancode::Left] = std::make_unique<CommandMove>(*this, sf::Vector2i(-1, 0));
    key_bindings[sf::Keyboard::Scancode::A] = std::make_unique<CommandMove>(*this, sf::Vector2i(-1, 0));
    key_bindings[sf::Keyboard::Scancode::Right] = std::make_unique<CommandMove>(*this, sf::Vector2i(1, 0));
    key_bindings[sf::Keyboard::Scancode::D] = std::make_unique<CommandMove>(*this, sf::Vector2i(1, 0));
    key_bindings[sf::Keyboard::Scancode::Up] = std::make_unique<CommandRotate>(*this);
    key_bindings[sf::Keyboard::Scancode::W] = std::make_unique<CommandRotate>(*this);
    key_bindings[sf::Keyboard::Scancode::Space] = std::make_unique<CommandHardDrop>(*this);
}

void Tetris::spawnTetromino()
{
    int random = rand() % 7 + 1;
    tetromino = TetrominoFactory::createTetromino(static_cast<TetrominoShape>(random));
    tetromino->setPosition({ 4, 0 });
}

void Tetris::moveTetromino(const sf::Vector2i& offset)
{
    tetromino->move(offset);

    if (!board.isValidPosition(tetromino->getBlocks()))
    {
        // Reset to previous position
        tetromino->move({ -offset.x, -offset.y });
    }
}

void Tetris::rotateTetromino()
{
    tetromino->rotate();

    if (!board.isValidPosition(tetromino->getBlocks()))
    {
        // Reset to previous position
        tetromino->rotate();
        tetromino->rotate();
        tetromino->rotate();
    }
}

void Tetris::hardDropTetromino()
{
    while (board.isValidPosition(tetromino->getBlocks()))
    {
        tetromino->move({ 0, 1 });
    }

    // Reset to previous position
    tetromino->move({ 0, -1 });

    // Write the tetromino's position onto the board
    board.lockTetromino(tetromino->getBlocks(), static_cast<int>(tetromino->getColor()) + 1);

    tetromino_fall.restart();
    spawnTetromino();
}

void Tetris::setSoftDrop(bool active)
{
    is_soft_dropping = active;
}

void Tetris::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Down ||
            key->scancode == sf::Keyboard::Scancode::S)
        {
            setSoftDrop(true);
        }

        auto iterator = key_bindings.find(key->scancode);

        if (iterator != key_bindings.end())
        {
            iterator->second->execute();
        }
    }

    if (const auto* key = event.getIf<sf::Event::KeyReleased>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Down ||
            key->scancode == sf::Keyboard::Scancode::S)
        {
            setSoftDrop(false);
        }
    }
}


void Tetris::update(float delta_time)
{
    float current_speed = is_soft_dropping ? speed_soft_drop : speed_default;

    if (tetromino_fall.getElapsedTime().asSeconds() >= current_speed)
    {
        tetromino->move({ 0, 1 });

        if (!board.isValidPosition(tetromino->getBlocks()))
        {
            // Reset to previous position
            tetromino->move({ 0, -1 });

            // Write the tetromino's position onto the board
            board.lockTetromino(tetromino->getBlocks(), static_cast<int>(tetromino->getColor()) + 1);

            spawnTetromino();
        }

        tetromino_fall.restart();
    }
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

    // Draw Ghost Tetromino
    std::vector<sf::Vector2i> ghost_blocks = tetromino->getBlocks();

    while (board.isValidPosition(ghost_blocks))
    {
        for (int i = 0; i < ghost_blocks.size(); ++i)
        {
            ghost_blocks[i].y += 1;
        }
    }

    for (int i = 0; i < ghost_blocks.size(); ++i)
    {
        ghost_blocks[i].y -= 1;
    }

    sf::Vector2i texture_position = { (int)tetromino->getColor() * TEXTURE_SIZE, 0 };
    sf::Vector2i texture_size = { TEXTURE_SIZE, TEXTURE_SIZE };
    sprite_tetromino_ghost.setTextureRect(sf::IntRect(texture_position, texture_size));

    for (int i = 0; i < ghost_blocks.size(); ++i)
    {
        float pos_x = static_cast<float>(ghost_blocks[i].x * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_X);
        float pos_y = static_cast<float>(ghost_blocks[i].y * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_Y);

        sprite_tetromino_ghost.setPosition({ pos_x, pos_y });
        window.draw(sprite_tetromino_ghost);
    }
}