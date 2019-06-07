#include <iostream>

#include "battle.h"
#include "enemy.h"
#include "helpers.h"

Battle::Battle(){
	this->playerTurn = true;
}

Battle::Battle(Game* game, Enemy* enemy){
	this->playerTurn = true;
	this->enemy = enemy;
} //Game* game, Enemy* enemy


Battle::~Battle(){

}

void Battle::display(){
	if(this->playerTurn){
		std::cout << this->enemy->getBattleText() << std::endl;
		std::cout << "O que voce pretende fazer" << std::endl;
		std::cout << "\t(a)tacar" << std::endl;
		std::cout << "\t(i)nteragir" << std::endl;
		std::cout << "\t(f)ugir" << std::endl;
	} else {
		std::cout << "O inimigo te ataca";
	}

}
void Battle::update(){
	this->playerTurn = !this->playerTurn;
}
void Battle::handleInput(std::string userInput){
	userInput = Helpers::lowerString(userInput);

	if(userInput == "a") return;
	if(userInput == "i") return;
	if(userInput == "f") return;
	throw "Opcao invalida! Escolha uma da lista/verifique se digitou corretamente.";
}
