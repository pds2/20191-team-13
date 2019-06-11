#pragma once

#include <map>
#include <string>

#include "entity.hpp"
#include "position.hpp"
#include "game_state.hpp"

class Map : public GameState {
    private:
        //std::map<Position, Entity*> grid; /* guarda a posicao das entidades em uma 'grade' */
        char* charMap; /* guarda simbolos para imprimir no console */
        int xSize, ySize;
        int numEnemies, numChests;

    public:
        virtual void display();
        virtual void update();
        virtual void handleInput(std::string userInput);

        Map(int xSize, int ySize);
        ~Map(){};


};
