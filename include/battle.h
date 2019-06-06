#ifndef BATTLE_H
#define BATTLE_H

#include "game_state.hpp"
#include "game.hpp"

class Battle: public GameState {
private:
	bool playerTurn;
public:
	Battle();
	Battle(Game* game); //Game* game, Enemy* enemy
	~Battle();

	virtual void display();
	virtual void update(std::string userInput);
	virtual void handleInput(std::string userInput);
};

#endif
