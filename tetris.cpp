#include "assets.h"
#include "tetris.h"
#include "tetromino_factory.h"
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

Tetris::Tetris() :
    sprite_background(Assets::getInstance().getTexture("background")),
    sprite_board(Assets::getInstance().getTexture("board")),
    sprite_tetromino(Assets::getInstance().getTexture("tetromino")),
    sprite_tetromino_ghost(Assets::getInstance().getTexture("tetromino_ghost")),
    sprite_game_over_line(Assets::getInstance().getTexture("game_over_line"))
{
    sprite_background.setPosition({ 0, 0 });
    sprite_board.setPosition({ SPRITE_BOARD_OFFSET_X, SPRITE_BOARD_OFFSET_Y });
    sprite_game_over_line.setPosition({ SPRITE_BOARD_OFFSET_X, SPRITE_BOARD_OFFSET_Y + (2 * TEXTURE_SIZE)});

    spawnTetromino();

    key_bindings[sf::Keyboard::Scancode::Left] = std::make_unique<CommandMove>(*this, sf::Vector2i(-1, 0));
    key_bindings[sf::Keyboard::Scancode::A] = std::make_unique<CommandMove>(*this, sf::Vector2i(-1, 0));
    key_bindings[sf::Keyboard::Scancode::Right] = std::make_unique<CommandMove>(*this, sf::Vector2i(1, 0));
    key_bindings[sf::Keyboard::Scancode::D] = std::make_unique<CommandMove>(*this, sf::Vector2i(1, 0));
    key_bindings[sf::Keyboard::Scancode::Up] = std::make_unique<CommandRotate>(*this);
    key_bindings[sf::Keyboard::Scancode::W] = std::make_unique<CommandRotate>(*this);
    key_bindings[sf::Keyboard::Scancode::Space] = std::make_unique<CommandHardDrop>(*this);

    lock_delay_bar_left.setFillColor(sf::Color(255, 255, 255, 255));
    lock_delay_bar_right.setFillColor(sf::Color(255, 255, 255, 255));
}

void Tetris::spawnTetromino()
{
    int random = rand() % 7;
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
    else
    {
        resetLockDelay();
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
    else
    {
        resetLockDelay();
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

    board.lockTetromino(tetromino->getBlocks(), static_cast<int>(tetromino->getColor()) + 1);
    isGameOver();
    board.clearFullLines();

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

bool Tetris::checkTetrominoGrounded() const
{
    std::vector<sf::Vector2i> blocks = tetromino->getBlocks();

    for (int i = 0; i < blocks.size(); ++i)
    {
        blocks[i].y += 1;
    }

    return !board.isValidPosition(blocks);
}

void Tetris::resetLockDelay()
{
    is_tetromino_grounded = checkTetrominoGrounded();

    if (is_tetromino_grounded)
    {
        lock_delay_clock.restart();
    }
}

bool Tetris::isGameOver() const
{
    return board.isGameOver();
}

void Tetris::update(float delta_time)
{
    if (checkTetrominoGrounded())
    {
        if (!is_tetromino_grounded)
        {
            is_tetromino_grounded = true;
            lock_delay_clock.restart();
        }

        if (lock_delay_clock.getElapsedTime().asSeconds() >= lock_delay_time)
        {
            board.lockTetromino(tetromino->getBlocks(), static_cast<int>(tetromino->getColor()) + 1);
            isGameOver();
            board.clearFullLines();

            is_tetromino_grounded = false;
            tetromino_fall.restart();
            spawnTetromino();
            return;
        }
    }
    else
    {
        is_tetromino_grounded = false;
    }

    float current_speed = is_soft_dropping ? speed_soft_drop : speed_default;

    if (tetromino_fall.getElapsedTime().asSeconds() >= current_speed)
    {
        tetromino->move({ 0, 1 });

        if (!board.isValidPosition(tetromino->getBlocks()))
        {
            // Reset to previous position
            tetromino->move({ 0, -1 });

            if (!is_tetromino_grounded)
            {
                is_tetromino_grounded = true;
                lock_delay_clock.restart();
            }
        }

        tetromino_fall.restart();
    }
}

void Tetris::drawActiveTetromino(sf::RenderWindow& window)
{
    std::vector<sf::Vector2i> blocks = tetromino->getBlocks();

    sf::Vector2i position = { (int)tetromino->getColor() * TEXTURE_SIZE, 0 };
    sf::Vector2i size = { TEXTURE_SIZE, TEXTURE_SIZE };
    sprite_tetromino.setTextureRect(sf::IntRect(position, size));

    for (int index = 0; index < 4; ++index)
    {
        float position_x = static_cast<float>(blocks[index].x * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_X);
        float position_y = static_cast<float>(blocks[index].y * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_Y);
        sprite_tetromino.setPosition({ position_x, position_y });

        window.draw(sprite_tetromino);
    }
}

void Tetris::drawGhostTetromino(sf::RenderWindow& window)
{
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

    sf::Vector2i position = { (int)tetromino->getColor() * TEXTURE_SIZE, 0 };
    sf::Vector2i size = { TEXTURE_SIZE, TEXTURE_SIZE };
    sprite_tetromino_ghost.setTextureRect(sf::IntRect(position, size));

    for (int i = 0; i < ghost_blocks.size(); ++i)
    {
        float pos_x = static_cast<float>(ghost_blocks[i].x * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_X);
        float pos_y = static_cast<float>(ghost_blocks[i].y * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_Y);
        sprite_tetromino_ghost.setPosition({ pos_x, pos_y });

        window.draw(sprite_tetromino_ghost);
    }
}

void Tetris::drawLockDelayBars(sf::RenderWindow& window)
{
    if (!is_tetromino_grounded) return;

    float elapsed = lock_delay_clock.getElapsedTime().asSeconds();
    float progress = std::clamp(elapsed / lock_delay_time, 0.0f, 1.0f);
    float max_height = 25 * TEXTURE_SIZE;
    float current_height = max_height * (1.0f - progress);

    lock_delay_bar_left.setSize({ 15.f, current_height });
    lock_delay_bar_left.setOrigin({ 0.f, current_height });
    lock_delay_bar_right.setSize({ 15.f, current_height });
    lock_delay_bar_right.setOrigin({ 0.f, current_height });

    float left_bar_x = SPRITE_BOARD_OFFSET_X - TEXTURE_SIZE;
    float left_bar_y = SPRITE_BOARD_OFFSET_Y + max_height;
    float right_bar_x = SPRITE_BOARD_OFFSET_X + (TEXTURE_SIZE * 12) + (TEXTURE_SIZE / 2);
    float right_bar_y = SPRITE_BOARD_OFFSET_Y + max_height;

    lock_delay_bar_left.setPosition({ left_bar_x, left_bar_y });
    lock_delay_bar_right.setPosition({ right_bar_x, right_bar_y });

    window.draw(lock_delay_bar_left);
    window.draw(lock_delay_bar_right);
}

void Tetris::render(sf::RenderWindow& window)
{
    window.draw(sprite_background);
    window.draw(sprite_board);
    window.draw(sprite_game_over_line);
    board.draw(window, sprite_tetromino, TEXTURE_SIZE, SPRITE_BOARD_OFFSET_X, SPRITE_BOARD_OFFSET_Y);
    drawActiveTetromino(window);
    drawGhostTetromino(window);
    drawLockDelayBars(window);
}