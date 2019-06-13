#include "doctest.h"

#include "game.hpp"
#include "menu.hpp"

TEST_CASE("01- construtor item "){
    Game game;
    CHECK_NOTHROW(new GameStateMenu(&game));
}

TEST_CASE("02 - Display shouldn't throw anything") {
    Game game;
    GameStateMenu menu = GameStateMenu(&game);
    CHECK_NOTHROW(menu.display());    
}

TEST_CASE("03 - Update shouldn't throw anything") {
    Game game;
    GameStateMenu menu = GameStateMenu(&game);
    CHECK_NOTHROW(menu.update());    
}

TEST_CASE("04 - handleInput shouldn't throw with valid inputs") {
    Game game;
    GameStateMenu menu = GameStateMenu(&game);
    CHECK_NOTHROW(menu.handleInput("n"));
    CHECK_NOTHROW(menu.handleInput("c"));
    CHECK_NOTHROW(menu.handleInput("s"));    
}

TEST_CASE("05 - handleInput should throw with empty or invalid input") {
    Game game;
    GameStateMenu menu = GameStateMenu(&game);
    CHECK_THROWS(menu.handleInput(""));
    CHECK_THROWS(menu.handleInput("h"));
}
