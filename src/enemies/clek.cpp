#include <iostream>
#include "enemies/clek.hpp"

Clek::Clek(int health, int attack, int defense): Enemy(health, attack, defense){
	this->fleeRate = 100;
	this->battleText = "Clek te encara com um olhar confuso";
	this->name = "Clek";
	this->quotes.push_back("A confusao fica ainda mais visivel");
	this->quotesIndex = 0;
}
Clek::~Clek(){}


int Clek::getHealth(){
	return this->health;
}
int Clek::getAttack(){
	return this->attack;
}

int Clek::getBaseAttack(){
	return this->attack;
}

int Clek::takeDamage(int enemyAttack){
	int damage = ((enemyAttack - this->defense) > 0) ? enemyAttack - this->defense : 1;
	this->health -= damage;
	return this->health;
}

std::string Clek::getBattleText(){
	return this->battleText;
}

int Clek::getFleeRate(){
	return this->fleeRate;
}

std::string Clek::getName(){
	return this->name;
}

std::string Clek::getQuote(){
	std::string quote = this->quotes[this->quotesIndex];
	if(this->quotesIndex + 1 < (int)this->quotes.size()){
		this->quotesIndex++;
	}
	return quote;
}
