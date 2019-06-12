#include <cmath>
#include "map.hpp"
#include "battle.hpp"
#include "player.hpp"
#include "item.hpp"
#include "enemies/clek.hpp"
#include "helpers.hpp"

void Map::movePlayer(int newPos){
    std::string info = "";

    if (charMap[newPos] =='B'){
        this->game->getPlayer()->addItem(Item()); /* no momento em que o jogador abre um baú, um item aleatório é gerado e adicionado ao inventário*/
        info = "voce pegou um item! |--> " +  this->game->getPlayer()->getLastItem().getDescription();
        this->infoQueue.push(info);

        charMap[game->getPlayer()->getMapPos()] = '-';
        charMap[newPos] = '@';

    }else if (charMap[newPos] == 'M'){

        std::cout << "[!]voce encontrou um monstro!" << std::endl;
        Helpers::waitForKey();
        this->game->pushState(new Battle(this->game, new Clek(10,1,1)));

        charMap[game->getPlayer()->getMapPos()] = '-';
        charMap[newPos] = '@';

    } else if(charMap[newPos] == '-'){
        charMap[game->getPlayer()->getMapPos()] = '-';
        charMap[newPos] = '@';
    }

    if(charMap[newPos] != '#'){
        game->getPlayer()->setMapPos(newPos);
    }    
    return;
}

Map::Map(Game* game, int xSize, int ySize){
    this->game = game;
    this->xSize = xSize;
    this->ySize = ySize;
    this->charMap = new char[xSize*ySize];

    int gameObjs = xSize*ySize <= 100 ? 5 : (3 + floor(0.05 * (xSize*ySize)));

    this->numChests = gameObjs;
    this->numEnemies = gameObjs;

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

    srand(time(0));

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
                this->game->getPlayer()->setMapPos(rand);
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
        std::cout << "[!]" << this->infoQueue.front() << std::endl;
        this->infoQueue.pop();
    }
}

void Map::update(){
    return;
}

void Map::handleInput(std::string userInput){
    std::string ui = Helpers::lowerString(userInput);
    int pos = this->game->getPlayer()->getMapPos();

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
