#include "enemies/basic.h"

Basic::Basic(int health, int attack, int defense): Enemy(health, attack, defense){}
Basic::~Basic(){}
void Basic::makeAttack(){}
int Basic::getHealth(){return 0;}
int Basic::getAttack(){return 0;}
void Basic::takeDamage(int damage){}
