#include "player.h"

Player::Player(){}

Player::Player(int health, int attack, int defense):
	health(health), attack(attack), defense(defense){}

Player::~Player(){}

void Player::setHealth(int health){
	this->health = health;
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

int Player::takeDamage(int enemyAttack){
	int damage = ((enemyAttack - this->defense) > 0) ? enemyAttack - this->defense : 1;
	this->health -= damage;
	return this->health;
}
