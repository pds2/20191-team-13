#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

class Enemy {
protected:
	int health, attack, defense;
	int fleeRate;
public:
	Enemy(int health, int attack, int defense);
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual int getFleeRate() = 0;
	virtual int takeDamage(int enemyAttack) = 0;
	virtual std::string getName() = 0;
	virtual std::string getBattleText() = 0;
	virtual std::string getQuote() = 0;
	virtual ~Enemy(){};
};

#endif
