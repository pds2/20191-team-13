#pragma once

#include <queue>
#include <string>


#include "entity.hpp"
#include "position.hpp"
#include "game_state.hpp"

class Map : public GameState {
    private:        
        char* charMap; ///< guarda simbolos para imprimir no console */
        int xSize, ySize; ///< tamanho x,y do mapa */
        int numEnemies, numChests; ///< número aproximado de itens que serão gerados no construtor do mapa */
        int enemyCount; ///< conta quantos monstros restam no mapa. Quando chega a 0, o jogador ganha */

        std::queue<std::string> infoQueue; ///< fila de informações que aparecem embaixo do mapa */

    public:
        virtual void display();
        virtual void update();
        virtual void handleInput(std::string userInput);

        void movePlayer(int newPos); ///< verifica colisões e movimenta o jogador pelo mapa */

        Map(Game* game, int xSize, int ySize);
        ~Map(){};


};
