#pragma once
#include <string>
#include "entity.hpp"

class Player : public Entity {
private:
	int health = 0, attack = 0, defense = 0;
public:
	virtual std::string getType();
	/*
	virtual void interact(){
        //Fazer em conjunto com Arthur//
    };
	virtual void useItem(*vector<Item>){
        //Fazer em conjunto com Arthur//
    };
	*/
	int getHealth();
	void setHealth(int health);

	int getAttack();
	void setAttack(int attack);

	int getDefense();
	void setDefense(int defense);

	int takeDamage(int enemyAttack);

	Player();
	Player(int health, int attack, int defense);
	~Player(){}
};
