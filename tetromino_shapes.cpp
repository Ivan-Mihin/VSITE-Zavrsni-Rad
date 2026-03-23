#include "tetromino_shapes.h"

ShapeI::ShapeI() 
{
    color = sf::Color::Blue;
    shape_matrix = { {0,1},{1,1},{2,1},{3,1} };
    rotation = 0;
}

ShapeJ::ShapeJ()
{
    color = sf::Color::Blue;
    shape_matrix = { {0,0}, {0,1}, {1,1}, {2,1} };
    rotation = 0;
}

ShapeL::ShapeL()
{
    color = sf::Color::Blue;
    shape_matrix = { {2,0}, {0,1}, {1,1}, {2,1} };
    rotation = 0;
}

ShapeO::ShapeO()
{
    color = sf::Color::Blue;
    shape_matrix = { {0,0}, {1,0}, {0,1}, {1,1} };
    rotation = 0;
}

ShapeS::ShapeS()
{
    color = sf::Color::Blue;
    shape_matrix = { {1,0}, {2,0}, {0,1}, {1,1}};
    rotation = 0;
}

ShapeT::ShapeT()
{
    color = sf::Color::Blue;
    shape_matrix = { {1,0}, {0,1}, {1,1}, {2,1} };
    rotation = 0;
}

ShapeZ::ShapeZ()
{
    color = sf::Color::Blue;
    shape_matrix = { {0,0}, {1,0}, {1,1}, {2,1} };
    rotation = 0;
}