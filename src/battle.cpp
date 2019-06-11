#include <iostream>

#include "battle.hpp"
#include "enemy.hpp"
#include "helpers.hpp"

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
	
	while(!infoStack.empty()){
		std::cout << "[!]" << infoStack.top() << std::endl;
		infoStack.pop();
	}

	std::cout << this->enemy->getBattleText() << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << "O que voce pretende fazer" << std::endl;
		std::cout << "\t(a)tacar" << std::endl;
		std::cout << "\t(i)nteragir" << std::endl;
		std::cout << "\t(f)ugir" << std::endl;

}

void Battle::update(){
	if(this->playerRan){
		Helpers::waitForKey();
		this->game->popState();
		this->game->needsUserInput = true;
		return;
	}
	if(this->battleEnded){
		std::cout << (this->playerWon ? "Voce venceu a batalha!!!" : "Voce foi derrotado") << std::endl;
		Helpers::waitForKey();
		this->game->popState();
		this->game->needsUserInput = true;
		return;
	}

	if(!this->playerTurn){
		
		std::string info = "";
		info.append(this->enemy->getName()).append(" te ataca");
		infoStack.push(info);

		int playerHealth = this->game->getPlayer()->takeDamage(this->enemy->getAttack());
		if(playerHealth <= 0){
			this->battleEnded = true;
			this->playerWon = false;
		} else {
			info = "";
			info.append("Seu HP agora e ").append(std::to_string(playerHealth));
			infoStack.push(info);
		}
	}

	this->playerTurn = !this->playerTurn;

}

void Battle::handleInput(std::string userInput){

	if(!this->playerTurn) return;

	std::string info = "";

	userInput = Helpers::lowerString(userInput);

	if(userInput == "a"){
		int atk = this->game->getPlayer()->getAttack();
		int enemyRemainingHealth = this->enemy->takeDamage(atk);
		info.append("Voce atacou o ").append(this->enemy->getName()).append(".");
		if(enemyRemainingHealth <= 0){
			this->battleEnded = this->playerWon = true;
		}
		infoStack.push(info);
		return;
	}
	if(userInput == "i"){
		info.append(this->enemy->getQuote()).append(".");
		infoStack.push(info);
		return;
	}

	if(userInput == "f"){
		runFromBattle();
		if(this->playerRan){
			std::cout << "[!] Voce fugiu da luta!" << std::endl;
		} else {
			infoStack.push("Voce nao conseguiu fugir");
		}
		return;
	}

	throw "Opcao invalida! Escolha uma da lista/verifique se digitou corretamente.";
}


void Battle::runFromBattle(){
	int userFlee = Helpers::easyRandom(100);
	this->playerRan = userFlee <= this->enemy->getFleeRate();
}
