#pragma once
#include <vector>
#include <string>
#include "entity.hpp"
#include "item.hpp"

/** \brief entidade controlável no jogo, usando as teclas WASD ou IJKL
 * 
 */

class Player : public Entity {
private:
	int health = 0, attack = 0, defense = 0, maxHealth;
	int mapPos = 0; ///< posição no mapa */
	std::vector<Item> items; ///< inventário */

public:
	virtual std::string getType();
	
	int getHealth();
	void setHealth(int health);

	int getAttack();
	void setAttack(int attack);

	int getDefense();
	void setDefense(int defense);

	int getMapPos();
	void setMapPos(int pos);	

	/// funções que manipulam o inventário */
	void addItem(Item i);
	Item getLastItem();
	Item* getItem(int index);
	int getNumberItems();
	void printItems();
	void useItem(int index);

	int takeDamage(int enemyAttack);

	Player();
	Player(int health, int attack, int defense);
	~Player(){}
};
