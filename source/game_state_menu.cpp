#include <iostream>
#include "game_state_menu.hpp"

using std::cout;
using std::endl;

void GameStateMenu::display(){
    cout << "PDS2 Adventure" << endl;
    cout << "MENU" << endl;
    //TODO: SelectionList
    /*
        for(auto it : options){
            cout << it->first << "=> " << it->second << endl
        }
    */
}

void GameStateMenu::update(std::string userInput){

}

void GameStateMenu::handleInput(std:: string userInput){
    if (userInput == "sair")
        this->game->state_end = true;
}

GameStateMenu::GameStateMenu (Game* game){
    this-> game = game;
}
