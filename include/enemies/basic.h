#ifndef BASIC_ENEMY_H
#define BASIC_ENEMY_H

#include <iostream>
#include <vector>
#include "../enemy.h"

class Basic : public Enemy {
private:
	std::string battleText;
	std::vector<std::string> quotes;

public:
	Basic(int health, int attack, int defense);
	~Basic();
	virtual void makeAttack();
	virtual int getHealth();
	virtual int getAttack();
	virtual void takeDamage(int damage);
	virtual std::string getBattleText();

};

#endif
