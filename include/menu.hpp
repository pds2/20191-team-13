#pragma once
#include <string>
#include <map>

#include "game_state.hpp"
#include "game.hpp"


class GameStateMenu : public GameState {
    public:
        virtual void display();
        virtual void update();
        virtual void handleInput(std::string userInput);

        GameStateMenu(Game* game);
};
