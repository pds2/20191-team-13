#include "doctest.h"

#include "player.hpp"

#include <string.h>
#include <iostream>

TEST_CASE("01 - Construtor Player") {
    CHECK_NOTHROW(Player(10, 2, 2));
}

TEST_CASE("02 - Atributo Health - Setter e Getter") {
    Player player(10, 2, 2);
    CHECK(player.getHealth() == 10);
    player.setHealth(20);
    CHECK(player.getHealth() == 20);
}

TEST_CASE("03 - Atributo Attack - Setter e Getter") {
    Player player(10, 2, 2);
    CHECK(player.getAttack() == 2);
    player.setAttack(4);
    CHECK(player.getAttack() == 4);
}

TEST_CASE("04 - Atributo Defense - Setter e Getter") {
    Player player(10, 2, 2);
    CHECK(player.getDefense() == 2);
    player.setDefense(4);
    CHECK(player.getDefense() == 4);
}

TEST_CASE("05 - takeDamage deve colocar a vida do jogador como vida - (ataqueInimigo - defesa) quando o valor ataqueInimigo e maior que a defesa") {
    Player player(10, 2, 2);

    int newHealth = player.takeDamage(4);
    CHECK(newHealth == 8);
}

TEST_CASE("06 - takeDamage deve diminuir a vida do jogador em 1 quando o valor da defesa for maior que o valor do ataque inimigo") {
    Player player(10, 2, 6);

    int newHealth = player.takeDamage(4);
    CHECK(newHealth == 9);
}
