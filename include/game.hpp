#pragma once
#include <stack>
#include "player.h"

class GameState;

class Game{
private:
    bool state_endgame = 0;

    std::stack<std::string> errorStack;

    Player player;
public:
    std::stack<GameState*> states;

    Game();
    ~Game();

    void pushState(GameState* state);
    void changeState(GameState* state);
    void popState();

    void quit();

    GameState* peekState();

    void gameLoop();


};
