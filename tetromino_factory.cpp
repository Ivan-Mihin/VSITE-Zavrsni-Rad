#include "tetromino.h"
#include "tetromino_factory.h"
#include "tetromino_shapes.h"

#include <memory>

std::unique_ptr<Tetromino> TetrominoFactory::createTetromino(TetrominoShape shape)
{
    switch (shape)
    {
    case TetrominoShape::ShapeI:
        return std::make_unique<ShapeI>();

    case TetrominoShape::ShapeJ:
        return std::make_unique<ShapeJ>();

    case TetrominoShape::ShapeL:
        return std::make_unique<ShapeL>();

    case TetrominoShape::ShapeO:
        return std::make_unique<ShapeO>();

    case TetrominoShape::ShapeS:
        return std::make_unique<ShapeS>();

    case TetrominoShape::ShapeT:
        return std::make_unique<ShapeT>();

    case TetrominoShape::ShapeZ:
        return std::make_unique<ShapeZ>();
    }

    return nullptr;
}