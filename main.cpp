#include "assets.h"
#include "game.h"

int main() 
{
    srand(time(nullptr));
    
    Assets::getInstance().load();
    Game::getInstance().run();

    return 0;
}