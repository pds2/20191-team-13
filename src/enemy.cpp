#include <string>
#include "enemy.hpp"

Enemy::Enemy(int health, int attack, int defense):
	health(health), attack(attack), defense(defense){}

std::string Enemy::getType(){
	return "monstro";
}
