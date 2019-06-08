#include <iostream>

#include "battle.h"
#include "enemy.h"
#include "helpers.h"

Battle::Battle(Game* game, Enemy* enemy){
	this->playerTurn = true;
	this->playerRan = false;
	this->battleEnded = false;
	this->enemy = enemy;
	this->game = game;
} //Game* game, Enemy* enemy


Battle::~Battle(){

}

void Battle::display(){
	if(this->playerTurn){
		std::cout << this->enemy->getBattleText() << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << "O que voce pretende fazer" << std::endl;
		std::cout << "\t(a)tacar" << std::endl;
		std::cout << "\t(i)nteragir" << std::endl;
		std::cout << "\t(f)ugir" << std::endl;
	} else {
		std::cout << this->enemy->getName() << " te ataca" << std::endl;
		int playerHealth = this->game->getPlayer()->takeDamage(this->enemy->getAttack());
		if(playerHealth <= 0){
			this->battleEnded = true;
			this->playerWon = false;
		} else {
			std::cout << "Seu HP agora e " << playerHealth << std::endl;
		}
	}

}

void Battle::update(){
	if(this->playerRan){
		this->game->popState();
		this->game->needsUserInput = true;
		return;
	}

	if(this->battleEnded){
		std::cout << (this->playerWon ? "Voce venceu a batalha!!!" : "Voce foi derrotado") << std::endl;
		this->game->popState();
		this->game->needsUserInput = true;
		return;
	}

	this->playerTurn = this->game->needsUserInput = !this->playerTurn;
}

void Battle::handleInput(std::string userInput){

	if(!this->playerTurn) return;

	userInput = Helpers::lowerString(userInput);

	if(userInput == "a"){
		int atk = this->game->getPlayer()->getAttack();
		int enemyRemainingHealth = this->enemy->takeDamage(atk);
		std::cout << "Voce atacou o " << this->enemy->getName() << "." << std::endl;
		if(enemyRemainingHealth <= 0){
			this->battleEnded = this->playerWon = true;
		}
		return;
	}
	if(userInput == "i"){
		std::cout << this->enemy->getQuote() << std::endl;
		return;
	}

	if(userInput == "f"){
		runFromBattle();
		if(this->playerRan){
			std::cout << "Voce fugiu da luta" << std::endl;
			return;
		} else {
			std::cout << "Voce nao conseguiu fugir" << std::endl;
		}
		return;
	}

	throw "Opcao invalida! Escolha uma da lista/verifique se digitou corretamente.";
}


void Battle::runFromBattle(){
	int userFlee = Helpers::randomPercentage();
	this->playerRan = userFlee <= this->enemy->getFleeRate();
}
