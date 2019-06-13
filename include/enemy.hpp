#pragma once
#include "entity.hpp"

class Enemy : public Entity {
protected:
	int health, attack, defense;
	int fleeRate;
public:	
	
	virtual std::string getType();
	
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual int getBaseAttack() = 0;
	virtual int getFleeRate() = 0;
	virtual int takeDamage(int enemyAttack) = 0;
	virtual std::string getName() = 0;
	virtual std::string getBattleText() = 0;
	virtual std::string getQuote() = 0;

	Enemy(int health, int attack, int defense);
	virtual ~Enemy(){};
};

