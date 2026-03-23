#include "tetromino_shapes.h"

ShapeI::ShapeI() 
{
    color = sf::Color::Blue;
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
    color = sf::Color::Blue;
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
    color = sf::Color::Blue;
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
    color = sf::Color::Blue;
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
    color = sf::Color::Blue;
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
    color = sf::Color::Blue;
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
    color = sf::Color::Blue;
    rotation_states = {
        {{0,0},{1,0},{1,1},{2,1}}, // rotation 0, default
        {{2,0},{1,1},{2,1},{1,2}}, // rotation 1
        {{0,1},{1,1},{1,2},{2,2}}, // rotation 2
        {{1,0},{0,1},{1,1},{0,2}}  // rotation 3
    };
    current_rotation = 0;
}