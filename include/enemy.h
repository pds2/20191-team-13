#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
	int health, attack, defense;
public:
	Enemy(int health, int attack, int defense);
	virtual void makeAttack() = 0;
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual void takeDamage(int damage) = 0;
	virtual ~Enemy(){};
};

#endif
