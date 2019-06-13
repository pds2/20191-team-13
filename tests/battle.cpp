#include "doctest.h"

#include "enemies/clek.hpp"
#include "game.hpp"
#include "battle.hpp"
#include "enemy.hpp"

#include <string.h>
#include <iostream>

TEST_CASE("01 - Construtor Battle") {
    Game game;
    Enemy* enemy = new Clek(10, 1, 1);
    CHECK_NOTHROW(Battle(&game, enemy));
}

TEST_CASE("02 - Display shouldn't throw anything") {
    Game game;
    Enemy* enemy = new Clek(10, 1, 1);
    Battle battle = Battle(&game, enemy);
    CHECK_NOTHROW(battle.display());    
}

TEST_CASE("03 - Update shouldn't throw anything") {
    Game game;
    Enemy* enemy = new Clek(10, 1, 1);
    Battle battle = Battle(&game, enemy);
    CHECK_NOTHROW(battle.update());    
}

TEST_CASE("04 - handleInput shouldn't throw with valid inputs") {
    Game game;
    Enemy* enemy = new Clek(10, 1, 1);
    Battle battle = Battle(&game, enemy);
    CHECK_NOTHROW(battle.handleInput("a"));
    CHECK_NOTHROW(battle.handleInput("i"));
    CHECK_NOTHROW(battle.handleInput("f"));
    CHECK_NOTHROW(battle.handleInput("u"));
}

TEST_CASE("05 - handleInput should throw with empty input") {
    Game game;
    Enemy* enemy = new Clek(10, 1, 1);
    Battle battle = Battle(&game, enemy);
    CHECK_THROWS(battle.handleInput(""));    
}
