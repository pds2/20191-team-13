#ifndef BATTLE_H
#define BATTLE_H

#include "game_state.hpp"
#include "game.hpp"
#include "enemy.h"

class Battle: public GameState {
private:
	bool playerTurn, playerRan, battleEnded, playerWon;
	Enemy* enemy;
public:
	Battle();
	Battle(Game* game, Enemy* enemy); //Game* game, Enemy* enemy
	~Battle();

	virtual void display();
	virtual void update();
	virtual void handleInput(std::string userInput);

	void runFromBattle();
};

#endif
