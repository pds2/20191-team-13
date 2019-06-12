#include <cmath>
#include "map.hpp"
#include "player.hpp"
#include "helpers.hpp"
#include 

void Map::collisionCheck(int newPos){
    if (charMap[newPos] =='B'){
        //chamar funcao de interacao(?) this->player->items.push(new item("Bala"))
    }
    if (charMap[newPos] == 'M'){
        //this->game->pushState(new Battle(this->player, map[newPos]))
    }
    if (charMap[newPos] == '-'){

    }
    if (charMap[newPos] == '#'){

    }
}

Map::Map(int xSize, int ySize){
    this->xSize = xSize;
    this->ySize = ySize;
    this->charMap = new char[xSize*ySize];

    int gameObjs = xSize*ySize <= 100 ? 5 : floor(0.01 * (xSize*ySize));

    this->numChests = gameObjs;
    this->numEnemies = gameObjs;
    
    //criar jogador 
    this->player = new Player(20, 4, 2);

    //preencher as bordas com paredes
    for(int i = 0; i<xSize*ySize; i++){
        charMap[i] = '-';
    }

    for(int j=0; j<xSize; j++){
        charMap[j] = '#';
        charMap[((ySize-1)*xSize)+j] = '#';
    }

    for(int i=0; i<ySize; i++){
        charMap[i*xSize+0] = '#';
        charMap[i*xSize+(xSize-1)] = '#';
    }

    //inserir entidades para o jogador interagir
    for(int i=0; i < numChests; i++){
        int rand = Helpers::easyRandom(xSize*(ySize-1));
        if (charMap[rand] == '-'){
            charMap[rand] = 'B';
        }
    }
    for(int i=0; i < numEnemies; i++){
        int rand = Helpers::easyRandom(xSize*(ySize-1));
        if (charMap[rand] == '-'){
            charMap[rand] = 'M';
        }
    }

    //coloca o jogador
    bool playerNotSet = true;
    while(playerNotSet){
        int rand = Helpers::easyRandom(xSize*(ySize-1));
        if (charMap[rand] == '-'){
                charMap[rand] = '&';
                this->player->setMapPos(rand);
                playerNotSet = false;
            }
    }


}

void Map::display(){
    for(int i=0; i<ySize; i++){
        for(int j=0; j<xSize; j++){
            std::cout << charMap[i*xSize + j];
        }
        std::cout << std::endl;
    }
}
void Map::update(){
    return;
}

void Map::handleInput(std::string userInput){
    std::string ui = Helpers::lowerString(userInput);
    int pos = this->player->getMapPos();

    if(ui == "w" || ui == "i"){

    }
    if(ui == "s" || ui == "k"){

    }
    if(ui == "a" || ui == "j"){
        collisionCheck(pos-1);
    }
    if(ui == "d" || ui == "l"){
        colisionCheck(pos+1);
    }
}
