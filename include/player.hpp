#pragma once
#include <string>
#include "entity.hpp"

class Player : public Entity {
private:
	int health = 0, attack = 0, defense = 0;
	int mapPos = 0;
public:
	virtual std::string getType();

	//virtual void useItem(*vector<Item>){
        
    //};
	int getHealth();
	void setHealth(int health);

	int getAttack();
	void setAttack(int attack);

	int getDefense();
	void setDefense(int defense);

	int getMapPos();
	void setMapPos(int pos);

	int takeDamage(int enemyAttack);
	//não deveria ficar no battle para evitar que player tenha muitas responsabilidades?

	Player();
	Player(int health, int attack, int defense);
	~Player(){}
};
