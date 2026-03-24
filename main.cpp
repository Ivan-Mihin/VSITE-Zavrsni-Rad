#include "assets.h"
#include "game.h"

int main() 
{
    Assets::getInstance().load();
    Game::getInstance().run();

    return 0;
}