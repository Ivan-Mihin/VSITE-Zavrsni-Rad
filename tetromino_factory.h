#pragma once
#include "tetromino.h"
#include "tetromino_enums.h"
#include <memory>

class TetrominoFactory 
{
public:
    static std::unique_ptr<Tetromino> createTetromino(TetrominoShape shape);
};