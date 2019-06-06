#ifndef PLAYER_H
#define PLAYER_H


class Player{
private:
	int health, attack, defense;
public:
	Player();
	~Player();

	int getHealth();
	void setHealth(int health);

	int getAttack();
	void setAttack(int attack);

	int getDefense();
	void setDefense(int defense);
};


#endif
