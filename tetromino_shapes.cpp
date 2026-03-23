#include "tetromino_enums.h"
#include "tetromino_shapes.h"

ShapeI::ShapeI() 
{
    shape = TetrominoShape::ShapeI;
    color = TetrominoColor::Red;
    rotation_states = {
        {{0,1},{1,1},{2,1},{3,1}}, // rotation 0, default
        {{2,0},{2,1},{2,2},{2,3}}, // rotation 1
        {{0,2},{1,2},{2,2},{3,2}}, // rotation 2
        {{1,0},{1,1},{1,2},{1,3}}  // rotation 3
    };
    current_rotation = 0;
}

ShapeJ::ShapeJ()
{
    shape = TetrominoShape::ShapeJ;
    color = TetrominoColor::Orange;
    rotation_states = {
        {{0,0},{0,1},{1,1},{2,1}}, // rotation 0, default
        {{1,0},{2,0},{1,1},{1,2}}, // rotation 1
        {{0,1},{1,1},{2,1},{2,2}}, // rotation 2
        {{1,0},{1,1},{0,2},{1,2}}  // rotation 3
    };
    current_rotation = 0;
}

ShapeL::ShapeL()
{
    shape = TetrominoShape::ShapeL;
    color = TetrominoColor::Yellow;
    rotation_states = {
        {{2,0},{0,1},{1,1},{2,1}}, // rotation 0, default
        {{1,0},{1,1},{1,2},{2,2}}, // rotation 1
        {{0,1},{1,1},{2,1},{0,2}}, // rotation 2
        {{0,0},{1,0},{1,1},{1,2}}  // rotation 3
    };
    current_rotation = 0;
}

ShapeO::ShapeO()
{
    shape = TetrominoShape::ShapeO;
    color = TetrominoColor::Green;
    rotation_states = {
        {{0,0},{1,0},{0,1},{1,1}}, // rotation 0, default
        {{0,0},{1,0},{0,1},{1,1}}, // rotation 1
        {{0,0},{1,0},{0,1},{1,1}}, // rotation 2
        {{0,0},{1,0},{0,1},{1,1}}  // rotation 3
    };
    current_rotation = 0;
}

ShapeS::ShapeS()
{
    shape = TetrominoShape::ShapeS;
    color = TetrominoColor::Cyan;
    rotation_states = {
        {{1,0},{2,0},{0,1},{1,1}}, // rotation 0, default
        {{1,0},{1,1},{2,1},{2,2}}, // rotation 1
        {{1,1},{2,1},{0,2},{1,2}}, // rotation 2
        {{0,0},{0,1},{1,1},{1,2}}  // rotation 3
    };
    current_rotation = 0;
}

ShapeT::ShapeT()
{
    shape = TetrominoShape::ShapeT;
    color = TetrominoColor::Blue;
    rotation_states = {
        {{1,0},{0,1},{1,1},{2,1}}, // rotation 0, default
        {{1,0},{1,1},{2,1},{1,2}}, // rotation 1
        {{0,1},{1,1},{2,1},{1,2}}, // rotation 2
        {{1,0},{0,1},{1,1},{1,2}}  // rotation 3
    };
    current_rotation = 0;
}

ShapeZ::ShapeZ()
{
    shape = TetrominoShape::ShapeZ;
    color = TetrominoColor::Purple;
    rotation_states = {
        {{0,0},{1,0},{1,1},{2,1}}, // rotation 0, default
        {{2,0},{1,1},{2,1},{1,2}}, // rotation 1
        {{0,1},{1,1},{1,2},{2,2}}, // rotation 2
        {{1,0},{0,1},{1,1},{0,2}}  // rotation 3
    };
    current_rotation = 0;
}