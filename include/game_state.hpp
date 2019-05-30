#pragma once
#include <string>
#include "game.hpp"

class GameState{
    public:
        Game* game;

        virtual void display() = 0;
        virtual void update(std::string userInput) = 0;
        virtual void handleInput(std::string userInput) = 0;

        virtual ~GameState(){};
};
