#include <iostream>
#include "enemies/basic.h"

Basic::Basic(int health, int attack, int defense): Enemy(health, attack, defense){
	this->battleText = "O inimigo te encara fixamente";
	this->quotes.push_back("Nao esta disposto a te deixar correr");
}
Basic::~Basic(){}

void Basic::makeAttack(){}

int Basic::getHealth(){return 0;}
int Basic::getAttack(){return 0;}
void Basic::takeDamage(int damage){}

std::string Basic::getBattleText(){
	return this->battleText;
}
