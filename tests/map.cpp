#include "doctest.h"

#include "game.hpp"
#include "map.hpp"

TEST_CASE("01- construtor item "){
    Game game;
    CHECK_NOTHROW(new Map(&game, 10, 10));
}

TEST_CASE("02 - Display shouldn't throw anything") {
    Game game;
    Map map = Map(&game, 10,10);
    CHECK_NOTHROW(map.display());    
}

TEST_CASE("03 - Update shouldn't throw anything") {
    Game game;
    Map map = Map(&game, 10,10);
    CHECK_NOTHROW(map.update());    
}

TEST_CASE("04 - handleInput shouldn't throw with valid inputs") {
    Game game;
    Map map = Map(&game, 10,10);
    CHECK_NOTHROW(map.handleInput("w"));
    CHECK_NOTHROW(map.handleInput("s"));
    CHECK_NOTHROW(map.handleInput("a"));
    CHECK_NOTHROW(map.handleInput("d"));
    CHECK_NOTHROW(map.handleInput("i"));
    CHECK_NOTHROW(map.handleInput("j"));
    CHECK_NOTHROW(map.handleInput("k"));
    CHECK_NOTHROW(map.handleInput("l"));
}

TEST_CASE("05 - handleInput should throw with empty or invalid input") {
    Game game;
    Map map = Map(&game, 10,10);
    CHECK_THROWS(map.handleInput(""));
    CHECK_THROWS(map.handleInput("h"));
}
