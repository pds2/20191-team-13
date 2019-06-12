#ifdef __unix__
#include <stdlib.h>
#define CLEAR_SCREEN() system("clear")
#endif

#ifdef _WIN32
#include <stdlib.h>
#define CLEAR_SCREEN() system("cls")
#endif

#include <string>
#include <iostream>
#include "game.hpp"
#include "game_state.hpp"
#include "player.hpp"

Game::Game(){
	player = Player(20, 2, 2);
}

Game::~Game(){
	while(!this->states.empty()) this->popState();
}

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
	std::string userInput = "";
	while(true){
		if (this->state_endgame) break;
		CLEAR_SCREEN();
		this->peekState()->display();

		while(!this->errorStack.empty()){
			std::cout << "[ERRO] " << this->errorStack.top() << std::endl;
			this->errorStack.pop();
		}

		if(this->needsUserInput){
			std::cout << "==> ";
			std::cin >> userInput;
			std::cout << std::endl;
		}

		//tratamento de entrada invalida
		try{
			GameState* currentState = this->peekState();
			currentState->handleInput(userInput);
			userInput = "";
			currentState->update();
		}catch (const char* &e){
			// std::string tmp = e;
			this->errorStack.push(e);
		}
	}
}

Player* Game::getPlayer(){
	return &this->player;
}

void Game::quit(){
	this->state_endgame = true;
}
