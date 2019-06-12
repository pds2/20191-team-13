#pragma once

#include <queue>
#include <string>

#include "game_state.hpp"
#include "game.hpp"
#include "enemy.hpp"

class Battle: public GameState {
private:
	bool playerTurn, playerRan, battleEnded, playerWon;
	Enemy* enemy;
	
	std::queue<std::string> infoQueue;

public:
	Battle();
	Battle(Game* game, Enemy* enemy); //Game* game, Enemy* enemy
	~Battle();

	virtual void display();
	virtual void update();
	virtual void handleInput(std::string userInput);

	void runFromBattle();
};

