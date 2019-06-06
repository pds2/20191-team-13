#ifndef BASIC_ENEMY_H
#define BASIC_ENEMY_H

#include "../enemy.h"

class Basic : public Enemy {
public:
	Basic(int health, int attack, int defense);
	~Basic();
	virtual void makeAttack();
	virtual int getHealth();
	virtual int getAttack();
	virtual void takeDamage(int damage);
};

#endif
