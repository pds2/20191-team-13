#include <iostream>
#include <iterator>
#include "player.hpp"


Player::Player(){}

Player::Player(int health, int attack, int defense):
	health(health), attack(attack), defense(defense){
		this->maxHealth = health;
	}

std::string Player::getType(){
	return "jogador";
}

void Player::setHealth(int health){
	this->health = health;
}
void Player::setMaxHealth(int health){
	this->maxHealth = health;
}

int Player::getHealth(){
	return this->health;
}

void Player::setAttack(int attack){
	this->attack = attack;
}

int Player::getAttack(){
	return this->attack;
}

void Player::setDefense(int defense){
	this->defense = defense;
}

int Player::getDefense(){
	return this->defense;
}

int Player::getMapPos(){
	return this->mapPos;
}

void Player::setMapPos(int pos){
	this->mapPos = pos;
}

void Player::addItem(Item i){
	this->items.push_back(i);
}

Item Player::getLastItem(){
	return this->items.back();
}

Item* Player::getItem(int index){
	return &this->items.at(index);
}


int Player::getNumberItems(){
	return this->items.size();
}
void Player::printItems(){
	int i=0;
	std::cout << "|SEUS ITENS--------------" << std::endl;
	for(auto it : items){
		std:: cout << "\t[" << i << "] " << it.getDescription() << std::endl;
		i++;
	}
	std::cout << "-------------------------" << std::endl;
}

void Player::useItem(int index){
	Item i = this->items.at(index);
	
	if(i.getEffect()=="ATAQUE"){
		this->attack += i.getIncrement();
	}
	if(i.getEffect()=="DEFESA"){
		this->defense += i.getIncrement();
	}
	if(i.getEffect()=="HP"){
		int inc = i.getIncrement();
		this->health = (this->health + inc <= this->maxHealth) ? this->health + inc : this->maxHealth;	
	} 

	this->items.erase(items.begin()+index);
	return;
}

int Player::takeDamage(int enemyAttack){
	int damage = ((enemyAttack - this->defense) > 0) ? enemyAttack - this->defense : 1;
	this->health -= damage;
	return this->health;
}
