#pragma once

#include <iostream>
#include <vector>
#include "../enemy.hpp"

class Sans : public Enemy {
private:
	std::string name;
	std::vector<std::string> quotes, battleTexts;
	int quotesIndex, battleTextIndex;
public:
	Sans(int health, int attack, int defense);
	~Sans();
	virtual int getHealth();
	virtual int getAttack();
	virtual int getBaseAttack();
	virtual int getFleeRate();
	virtual int takeDamage(int enemyAttack);
	virtual std::string getName();
	virtual std::string getBattleText();
	virtual std::string getQuote();
	void setBattleTexts();
};
