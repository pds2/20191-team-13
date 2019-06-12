#include <cmath>
#include "map.hpp"
#include "player.hpp"
#include "helpers.hpp"

void Map::movePlayer(int newPos){
    std::string info = "";
    
    if (charMap[newPos] =='B'){        
        //this->player->items.push(new item()); /* no momento em que o jogador abre um baú, um item aleatório é gerado e adicionado ao inventário*/
        //info = "voce pegou um item! |--> " +  this->player->items.back()->name + "+ " + this->player->items.back()->name + this->player->items.back()->itemEffect;
        //this->infoQueue.push(info);

        charMap[player->getMapPos()] = '-';
        charMap[newPos] = '@';        

    }else if (charMap[newPos] == 'M'){

        std::cout << "\t[!]voce encontrou um monstro!" << std::endl;
        Helpers::waitForKey();
        //this->game->pushState(new Battle(this->player, map[newPos]));

        charMap[player->getMapPos()] = '-';
        charMap[newPos] = '@';

    } else if(charMap[newPos] == '-'){
        charMap[player->getMapPos()] = '-';
        charMap[newPos] = '@';
    }
    
    player->setMapPos(newPos);
    return;
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
                charMap[rand] = '@';
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

    while(!this->infoQueue.empty()){
        std::cout << "/t[!]" << this->infoQueue.front() << std::endl;
        this->infoQueue.pop();
    }
}

void Map::update(){
    return;
}

void Map::handleInput(std::string userInput){
    std::string ui = Helpers::lowerString(userInput);
    int pos = this->player->getMapPos();

    if(ui == "w" || ui == "i"){
        movePlayer(pos-xSize);
    }
    if(ui == "s" || ui == "k"){
        movePlayer(pos+xSize);
    }
    if(ui == "a" || ui == "j"){
        movePlayer(pos-1);
    }
    if(ui == "d" || ui == "l"){
        movePlayer(pos+1);
    }
}
