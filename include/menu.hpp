#pragma once
#include <string>
#include <map>

#include "game_state.hpp"
#include "game.hpp"

/** \brief tela do menu. mostra uma mensagem de boas vindas e permite ao usuário escolher opções diversas
 * 
 */

class GameStateMenu : public GameState {
    public:
        virtual void display();
        virtual void update();
        virtual void handleInput(std::string userInput);

        GameStateMenu(Game* game);
};
