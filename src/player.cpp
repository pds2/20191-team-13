#include "player.h"

Player::Player(){}

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
