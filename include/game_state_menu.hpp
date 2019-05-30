#pragma once
#include <string>
#include <map>

#include "game_state.hpp"
#include "game.hpp"

class GameStateMenu : public GameState {
    private:
        //TODO: SelectionList

    public:
        virtual void display();
        virtual void update(std::string userInput);
        virtual void handleInput(std::string userInput);

        GameStateMenu(Game* game);
};
