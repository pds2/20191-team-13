#include <iostream>
#include "game.hpp"
#include "menu.hpp"

int main(){
    Game game;
    game.pushState(new GameStateMenu(&game));
    game.gameLoop();

    return 0;
}
