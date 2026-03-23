#pragma once
#include <memory>
#include "tetromino.h"
#include "tetromino_enums.h"

class TetrominoFactory 
{
public:
    static std::unique_ptr<Tetromino> createTetromino(TetrominoShape shape);
};