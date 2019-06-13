#include <iostream>
#include <limits>
#include <cstdint> 
#include <thread>
#include <chrono>

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

Battle::~Battle(){}

void Battle::display(){
	if(!this->playerTurn) return;

	while(!infoQueue.empty()){
		std::cout << "\t[!]" << infoQueue.front() << std::endl;
		infoQueue.pop();
		std::cout << "|-------------------------" << std::endl;
	}

	std::cout << "|[SEU STATUS]------------" << std::endl;
	std::cout << "|\t\t|vida: " << this->game->getPlayer()->getHealth() << std::endl;
	std::cout << "|\t\t|AT: " << this->game->getPlayer()->getAttack() << std::endl;
	std::cout << "|\t\t|DEF: " << this->game->getPlayer()->getDefense() << std::endl;
	std::cout << "|\t\t|Quantidade de itens: " << this->game->getPlayer()->getNumberItems() << std::endl;

	std::cout << "|["<< Helpers::upperString(this->enemy->getName())<<"]---------------" << std::endl;
	std::cout << "|\t\t|vida: " << this->enemy->getHealth() << std::endl;
	std::cout << "|\t\t|AT: " << this->enemy->getBaseAttack() << std::endl;
	std::cout << "|------------------------" << std::endl;

	std::cout << "|\t" << this->enemy->getBattleText() << std::endl;
    std::cout << "|-------------------------" << std::endl;
    std::cout << "|O que voce pretende fazer?" << std::endl;
    std::cout << "|\t(a)tacar" << std::endl;
    std::cout << "|\t(i)nteragir" << std::endl;
    std::cout << "|\t(u)sar um item" << std::endl;
    std::cout << "|\t(f)ugir" << std::endl;
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

		std::string info = this->enemy->getName() + " te ataca";
		infoQueue.push(info);

		int playerHealth = this->game->getPlayer()->takeDamage(this->enemy->getAttack());
		if(playerHealth <= 0){
			this->battleEnded = true;
			this->playerWon = false;
		} else {
			info = "Seu HP agora e " + std::to_string(playerHealth);
			infoQueue.push(info);
		}

	}

	this->playerTurn =  this->game->needsUserInput = !this->playerTurn;

}

void Battle::handleInput(std::string userInput){

	if(!this->playerTurn) return;

    std::cout << userInput << std::endl;
	std::string info = "";

	userInput = Helpers::lowerString(userInput);

	if(userInput == "a"){
		int atk = this->game->getPlayer()->getAttack();
		int enemyRemainingHealth = this->enemy->takeDamage(atk);
		info = "Voce atacou o " + this->enemy->getName() + ".";
		if(enemyRemainingHealth == INT8_MAX){
			std::this_thread::sleep_for(std::chrono::minutes(1));
		} else if(enemyRemainingHealth <= 0){
			this->battleEnded = this->playerWon = true;
		}
		infoQueue.push(info);
		return;
	}else if(userInput == "i"){
		info = this->enemy->getQuote() + ".";
		infoQueue.push(info);
		return;
	}else if(userInput == "u"){
		if(this->game->getPlayer()->getNumberItems() > 0){
			int option;
			this->game->getPlayer()->printItems();
			std::cout << "==> ";
			std:: cin >> option;
			Item* item = this->game->getPlayer()->getItem(option);
			infoQueue.push("Voce usou " + item->getName()+". " + item->getEffect() + " +" + std::to_string(item->getIncrement()));
			this->game->getPlayer()->useItem(option);
		}
		return;
	} else if(userInput == "f"){
		runFromBattle();
		if(this->playerRan){
			std::cout << "[!] Voce fugiu da luta!" << std::endl;
		} else {
			infoQueue.push("Voce nao conseguiu fugir");
		}
		return;
	} else{
		throw "Opcao invalida! Escolha uma da lista/verifique se digitou corretamente.";
	}
	return;
}


void Battle::runFromBattle(){
	int userFlee = Helpers::easyRandom(100);
	this->playerRan = userFlee <= this->enemy->getFleeRate();
}
