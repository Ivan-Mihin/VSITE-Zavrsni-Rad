#include "assets.h"
#include "audio.h"
#include "tetris.h"
#include "tetromino_factory.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cmath>
#include <memory>
#include <vector>

Tetris::Tetris() :
    sprite_background(Assets::getInstance().getTexture("background")),
    sprite_board(Assets::getInstance().getTexture("board")),
    sprite_tetromino(Assets::getInstance().getTexture("tetromino")),
    sprite_tetromino_ghost(Assets::getInstance().getTexture("tetromino_ghost")),
    sprite_game_over_line(Assets::getInstance().getTexture("game_over_line")),
    label_score(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    label_combo(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text_score(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text_combo(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{
    initializeUserInterface();
    initializeKeyBindings();

    lock_delay_bar_left.setFillColor(sf::Color(255, 255, 255, 255));
    lock_delay_bar_right.setFillColor(sf::Color(255, 255, 255, 255));

    board.addObserver(&manager_score);

    spawnTetromino();
}

void Tetris::initializeUserInterface()
{
    sprite_background.setPosition({ 0, 0 });
    sprite_board.setPosition({ SPRITE_BOARD_OFFSET_X, SPRITE_BOARD_OFFSET_Y });
    sprite_game_over_line.setPosition({ SPRITE_BOARD_OFFSET_X, SPRITE_BOARD_OFFSET_Y + (3 * TEXTURE_SIZE) });

    label_score.setString("Score");
    label_score.setCharacterSize(37);
    label_score.setFillColor(sf::Color::White);
    float label_score_position_x = (SPRITE_BOARD_OFFSET_X - label_score.getLocalBounds().size.x) / 2.f;
    label_score.setPosition({ label_score_position_x, 100.f });

    label_combo.setString("Combo");
    label_combo.setCharacterSize(37);
    label_combo.setFillColor(sf::Color::White);
    float label_combo_position_x = (SPRITE_BOARD_OFFSET_X - label_combo.getLocalBounds().size.x) / 2.f;
    label_combo.setPosition({ label_combo_position_x, 230.f });

    text_score.setCharacterSize(37);
    text_score.setFillColor(sf::Color::White);

    text_combo.setCharacterSize(37);
    text_combo.setFillColor(sf::Color::White);
}

void Tetris::initializeKeyBindings()
{
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
    int random = rand() % 7;
    tetromino = TetrominoFactory::createTetromino(static_cast<TetrominoShape>(random));
    tetromino->setPosition({ 4, 0 });
}

void Tetris::setSoftDrop(bool active)
{
    is_soft_dropping = active;
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
        clock_lock_delay.restart();
    }
}

void Tetris::drawActiveTetromino(sf::RenderWindow& window)
{
    std::vector<sf::Vector2i> blocks = tetromino->getBlocks();

    // Calculates which part of the texture is taken for drawing
    sf::Vector2i position = { (int)tetromino->getColor() * TEXTURE_SIZE, 0 };
    sf::Vector2i size = { TEXTURE_SIZE, TEXTURE_SIZE };
    sprite_tetromino.setTextureRect(sf::IntRect(position, size));

    for (int index = 0; index < blocks.size(); ++index)
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

    // Drops ghost tetromino as far as it can
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

    // Calculates which part of the texture is taken for drawing
    sf::Vector2i position = { (int)tetromino->getColor() * TEXTURE_SIZE, 0 };
    sf::Vector2i size = { TEXTURE_SIZE, TEXTURE_SIZE };
    sprite_tetromino_ghost.setTextureRect(sf::IntRect(position, size));

    for (int i = 0; i < ghost_blocks.size(); ++i)
    {
        float position_x = static_cast<float>(ghost_blocks[i].x * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_X);
        float position_y = static_cast<float>(ghost_blocks[i].y * TEXTURE_SIZE + SPRITE_BOARD_OFFSET_Y);
        sprite_tetromino_ghost.setPosition({ position_x, position_y });

        window.draw(sprite_tetromino_ghost);
    }
}

void Tetris::drawLockDelayBars(sf::RenderWindow& window)
{
    if (!is_tetromino_grounded) return;

    float elapsed = clock_lock_delay.getElapsedTime().asSeconds();
    float progress = std::clamp(elapsed / LOCK_DELAY_TIME, 0.0f, 1.0f);
    float max_height = board.getRows() * static_cast<float>(TEXTURE_SIZE);
    float current_height = max_height * (1.0f - progress);

    lock_delay_bar_left.setSize({ 15.f, current_height });
    lock_delay_bar_left.setOrigin({ 0.f, current_height });
    lock_delay_bar_right.setSize({ 15.f, current_height });
    lock_delay_bar_right.setOrigin({ 0.f, current_height });

    float left_bar_x = SPRITE_BOARD_OFFSET_X - TEXTURE_SIZE;
    float left_bar_y = SPRITE_BOARD_OFFSET_Y + max_height;
    float right_bar_x = SPRITE_BOARD_OFFSET_X + (TEXTURE_SIZE * board.getColumns()) + (TEXTURE_SIZE / 2);
    float right_bar_y = SPRITE_BOARD_OFFSET_Y + max_height;

    lock_delay_bar_left.setPosition({ left_bar_x, left_bar_y });
    lock_delay_bar_right.setPosition({ right_bar_x, right_bar_y });

    window.draw(lock_delay_bar_left);
    window.draw(lock_delay_bar_right);
}

void Tetris::drawUserInterface(sf::RenderWindow& window)
{
    window.draw(label_score);

    text_score.setString(std::to_string(manager_score.getScore()));
    float text_score_position_x = (SPRITE_BOARD_OFFSET_X - text_score.getLocalBounds().size.x) / 2.f;
    text_score.setPosition({ text_score_position_x, 145.f });
    window.draw(text_score);

    if (manager_score.isComboActive())
    {
        text_combo.setString("x" + std::to_string(manager_score.getCombo()));

        float time = clock_combo_flash.getElapsedTime().asSeconds();
        const float PI = 3.14159265f;
        float factor = (std::sin(time * 2.f * PI) + 1.f) * 0.5f;
        std::uint8_t color = static_cast<std::uint8_t>(127.f + factor * (255.f - 127.f));
        label_combo.setFillColor(sf::Color(color, color, color));
        text_combo.setFillColor(sf::Color(color, color, color));

        window.draw(label_combo);

        float text_combo_position_x = (SPRITE_BOARD_OFFSET_X - text_combo.getLocalBounds().size.x) / 2.f;
        text_combo.setPosition({ text_combo_position_x, 275.f });
        window.draw(text_combo);
    }
    else
    {
        clock_combo_flash.restart();
    }
}

bool Tetris::isGameOver()
{
    return board.isGameOver();
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
        Audio::getInstance().playSound("move");
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
        Audio::getInstance().playSound("rotate");
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

    Audio::getInstance().playSound("hard_drop");

    board.lockTetromino(tetromino->getBlocks(), static_cast<int>(tetromino->getColor()) + 1);
    isGameOver();
    board.clearFullLines();

    clock_tetromino_drop.restart();
    spawnTetromino();
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

bool Tetris::updateLockDelay()
{
    if (checkTetrominoGrounded())
    {
        if (!is_tetromino_grounded)
        {
            is_tetromino_grounded = true;
            clock_lock_delay.restart();
        }

        if (clock_lock_delay.getElapsedTime().asSeconds() >= LOCK_DELAY_TIME)
        {
            is_tetromino_grounded = false;

            board.lockTetromino(tetromino->getBlocks(), static_cast<int>(tetromino->getColor()) + 1);
            isGameOver();
            board.clearFullLines();
            clock_tetromino_drop.restart();
            spawnTetromino();

            return true;
        }
    }
    else
    {
        is_tetromino_grounded = false;
    }

    return false;
}

void Tetris::updateTetrominoDrop()
{
    float current_speed = is_soft_dropping ? SPEED_SOFT_DROP : SPEED_DEFAULT;

    if (clock_tetromino_drop.getElapsedTime().asSeconds() >= current_speed)
    {
        tetromino->move({ 0, 1 });

        if (!board.isValidPosition(tetromino->getBlocks()))
        {
            // Reset to previous position
            tetromino->move({ 0, -1 });

            if (!is_tetromino_grounded)
            {
                is_tetromino_grounded = true;
                clock_lock_delay.restart();
            }
        }

        clock_tetromino_drop.restart();
    }
}

void Tetris::update(float delta_time)
{
    // If a tetromino gets locked after lock delay, skip the tetromino drop
    if (updateLockDelay())
    {
        return;
    }

    updateTetrominoDrop();
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
    drawUserInterface(window);
}