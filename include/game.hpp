#pragma once
#include <stack>

class GameState;

class Game{
    
        

    public:
        bool state_end = false;

        std::stack<GameState*> states;

        void pushState(GameState* state);
        void changeState(GameState* state);
        void popState();

        GameState* peekState();

        void gameLoop();

        Game();
        ~Game();

};