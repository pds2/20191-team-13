#ifndef BATTLE_H
#define BATTLE_H

#include "game_state.hpp"
#include "game.hpp"
#include "enemy.h"

class Battle: public GameState {
private:
	bool playerTurn;
	Enemy* enemy;
public:
	Battle();
	Battle(Game* game, Enemy* enemy); //Game* game, Enemy* enemy
	~Battle();

	virtual void display();
	virtual void update();
	virtual void handleInput(std::string userInput);
};

#endif
