#pragma once
#include <stack>

class GameState;

class Game{
private:
    bool state_endgame = 0;

    std::stack<std::string> errorStack;

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
