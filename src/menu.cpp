#include <iostream>

#include "helpers.hpp"
#include "menu.hpp"
#include "battle.hpp"
#include "map.hpp"
#include "enemy.hpp"
#include "enemies/clek.hpp"
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
        this->game->pushState(new Map(this->game, 30, 7));
        return;
    }

    if (ui == "c") return;//this->game->loadGame();


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


