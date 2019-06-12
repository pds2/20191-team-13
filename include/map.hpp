#pragma once

#include <map>
#include <string>

#include "entity.hpp"
#include "position.hpp"
#include "game_state.hpp"

class Map : public GameState {
    private:
        char* charMap; /* guarda simbolos para imprimir no console */
        int xSize, ySize;
        int numEnemies, numChests;
        Player* player; /* informacoes sobre o jogador */

    public:
        virtual void display();
        virtual void update();
        virtual void handleInput(std::string userInput);

        Map(int xSize, int ySize);
        ~Map(){};


};
