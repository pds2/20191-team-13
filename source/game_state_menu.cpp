#include <iostream>

#include "game_state_menu.hpp"
//#include "game_state_map.hpp"

using std::cout;
using std::endl;

void GameStateMenu::display(){
    cout << "PDS2 Adventure" << endl;
    cout << "|MENU--------------------" << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "\t (n)ovo jogo" << endl;
    cout << "\t (c)arregar jogo salvo" << endl;
    cout << "-------------------------" << endl;
}

void GameStateMenu::update(std::string userInput){
    return;
}

void GameStateMenu::handleInput(std::string userInput){
    std::string ui = userInput;
    for(int i=0; i<ui.length(); i++){
        ui[i] = tolower(ui[i]);
    }

    if (ui == "sair"){
        this->game->quit();
        return;
    }

    if (ui == "n") return;//this->game->pushState(new GamestateMap(this->game));

    if (ui == "c") return;//this->game->loadGame();

    //tratamento de entrada inválida
    throw "opcao invalida! escolha uma da lista/verifique se digitou corretamente.";
}

GameStateMenu::GameStateMenu (Game* game){
    this-> game = game;
}
