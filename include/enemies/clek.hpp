#pragma once

#include <iostream>
#include <vector>
#include "../enemy.hpp"

class Clek : public Enemy {
private:
	std::string battleText, name;
	std::vector<std::string> quotes;
	int quotesIndex;
public:
	Clek(int health, int attack, int defense);
	~Clek();
	virtual int getHealth();
	virtual int getAttack();
	virtual int getFleeRate();
	virtual int takeDamage(int enemyAttack);
	virtual std::string getName();
	virtual std::string getBattleText();
	virtual std::string getQuote();
};
