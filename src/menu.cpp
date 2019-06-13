#include <iostream>

#include "helpers.hpp"
#include "menu.hpp"
#include "battle.hpp"
#include "map.hpp"
#include "item.hpp"
#include "enemy.hpp"
#include "enemies/clek.hpp"
#include "enemies/sans.hpp"
//#include "game_state_map.hpp"

using std::cout;
using std::endl;

GameStateMenu::GameStateMenu (Game* game){
    this->game = game;
}

void GameStateMenu::display(){
    cout << "PDS2 Adventure" << endl;
    cout << "|MENU -------------------" << endl;
    cout << "Selecione uma opcao:" << endl;
    cout << "\t(n)ovo jogo" << endl;
    cout << "\t(c)arregar jogo salvo" << endl;
    cout << "\t(s)air" << endl;
    cout << "-------------------------" << endl;
}

void GameStateMenu::update(){
    return;
}

void GameStateMenu::handleInput(std::string userInput){
    std::string ui = Helpers::lowerString(userInput);

    if (ui == "s"){
        this->game->quit();
        return;
    }

    if (ui == "n"){
        this->game->pushState(new Map(this->game, 43, 11));
        return;
    }

    if (ui == "c") return;//this->game->loadGame();

    if (ui == "sans") {
        Enemy* enemy = new Sans(1, 1, 1);
        this->game->getPlayer()->setHealth(92);
        this->game->getPlayer()->setMaxHealth(92);
        this->game->getPlayer()->addItem(Item("Pie", 3, 91));
        this->game->getPlayer()->addItem(Item("Instant Noodles", 3, 90));
        this->game->getPlayer()->addItem(Item("Steak in the Shape of Mettaton's Face", 3, 60));
        this->game->getPlayer()->addItem(Item("Snowman Piece", 3, 45));
        this->game->getPlayer()->addItem(Item("Legendary Hero", 3, 40));
        this->game->pushState(new Battle(this->game, enemy));
        return;
    }
    //Test purpose only
    if(ui == "b"){
        Enemy* enemy = new Clek(10, 1, 1);
        this->game->pushState(new Battle(this->game, enemy));
        return;
    }

    if(ui == "m"){
        this->game->pushState(new Map(this->game, 30, 7));
        return;
    }

    //tratamento de entrada invalida
    throw "Opcao invalida! Escolha uma da lista/verifique se digitou corretamente.";
}


