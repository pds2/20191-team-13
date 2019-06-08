#ifndef PLAYER_H
#define PLAYER_H


class Player{
private:
	int health, attack, defense;
public:
	Player();
	Player(int health, int attack, int defense);

	~Player();

	int getHealth();
	void setHealth(int health);

	int getAttack();
	void setAttack(int attack);

	int getDefense();
	void setDefense(int defense);

	int takeDamage(int enemyAttack);
};


#endif
