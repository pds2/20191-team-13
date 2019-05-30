#include <string>
#include <iostream>
#include <stdlib.h>

#include "../include/game.hpp"
#include "../include/game_state.hpp"


void Game::pushState(GameState* state){
    this->states.push(state);
}

void Game::popState(){
    delete this->states.top();
    this->states.pop();
}

void Game::changeState(GameState* state){
    if(!this->states.empty()){
        this->popState();
        this->pushState(state);
    }
}

GameState* Game::peekState(){
    if (this->states.empty()) return nullptr;
    return this->states.top();
}

void Game::gameLoop(){
    std::string userInput;    
    while(true){
        if (this->state_end) break;
        system("cls");
        this->peekState()->display();
        std::cout << "==> ";      
        std::cin >> userInput;
        this->peekState()->handleInput(userInput);
        this->peekState()->update(userInput);        
    }
}

Game::Game(){

}

Game::~Game(){
    while(!this->states.empty()) this->popState();
}