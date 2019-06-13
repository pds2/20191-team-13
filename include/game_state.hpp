#pragma once
#include <string>
#include "game.hpp"

/** \brief  representa uma tela do jogo.
 * contém funções que desenham essa tela no console, faz tratamento do input do usuário e avança no jogo
 * baseado no input do jogador.
 * 
 */

class GameState{
    public:
        Game* game; ///<todo gameState contém a referencia ao Game, para utilizar as informações gerais sobre o jogo */

        virtual void display() = 0;
        virtual void update() = 0;
        virtual void handleInput(std::string userInput) = 0;

        virtual ~GameState(){};
};
