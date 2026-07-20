#include "assets.h"
#include "game.h"

#include <cstdlib>
#include <ctime>

int main() 
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    Assets::getInstance().load();
    Game::getInstance().run();

    return 0;
}