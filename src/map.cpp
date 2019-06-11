#include <cmath>
#include "map.hpp"
#include "helpers.hpp"

Map::Map(int xSize, int ySize){
    this->xSize = xSize;
    this->ySize = ySize;
    this->charMap = new char[xSize*ySize];

    int gameObjs = xSize*ySize <= 100 ? 5 : floor(0.01 * (xSize*ySize));

    this->numChests = gameObjs;
    this->numEnemies = gameObjs;
}

void Map::display(){
    //preencher as bordas com parede
    for(int i = 0; i<xSize*ySize; i++){
        charMap[i] = ' ';
    }

    for(int j=0; j<xSize; j++){
        charMap[0*ySize+j] = '#';
        charMap[(ySize-1)*ySize+j] = '#';
    }

    for(int i = 0; i<ySize; i++){
        for(int j = 0; j<xSize; j++){
            std::cout << charMap[i*ySize + j];
        }
        std::cout << std::endl;
    }
}

void Map::update(){
    return;
}

void Map::handleInput(std::string userInput){
    std::string ui = Helpers::lowerString(userInput);

    if(ui == "w" || ui == "i"){

    }
    if(ui == "s" || ui == "k"){

    }
    if(ui == "a" || ui == "j"){

    }
    if(ui == "d" || ui == "l"){

    }
}
