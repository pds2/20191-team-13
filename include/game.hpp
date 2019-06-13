#pragma once
#include <stack>
#include "player.hpp"

class GameState;

class Game{
private:
    bool state_endgame = 0;
    bool state_win = 0;
    bool state_lose = 0;

    std::stack<std::string> errorStack;

    Player player;
public:
    std::stack<GameState*> states;
    bool needsUserInput = true;
    Game();
    ~Game();

    void pushState(GameState* state);
    void changeState(GameState* state);
    void popState();

    Player* getPlayer();

    void quit();
    void win();
    void lose();

    GameState* peekState();

    void gameLoop();
};
