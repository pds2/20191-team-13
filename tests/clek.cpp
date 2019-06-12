#include "doctest.h"

#include "enemies/clek.hpp"

#include <string.h>
#include <iostream>

TEST_CASE("01 - Construtor Clek") {
    CHECK_NOTHROW(Clek(10, 2, 2));
}

TEST_CASE("02 - Atributo Health - Getter") {
    Clek clek(10, 2, 2);
    CHECK(clek.getHealth() == 10);
}

TEST_CASE("03 - Atributo Attack - Getter") {
    Clek clek(10, 2, 2);
    CHECK(clek.getAttack() == 2);
}

TEST_CASE("04 - Atributo FleeRate - Getter") {
    Clek clek(10, 2, 2);
    CHECK(clek.getFleeRate() == 100);
}

TEST_CASE("05 - Atributo Nome - Getter"){
    Clek clek(10, 2, 2);
    CHECK(clek.getName() == "Clek");
}

TEST_CASE("06 - Atributo battleText - Getter"){
    Clek clek(10, 2, 2);
    CHECK(clek.getBattleText() == "Clek te encara com um olhar confuso");
}

TEST_CASE("07 - Atributo quotes - Getter"){
    Clek clek(10, 2, 2);
    CHECK(clek.getQuote() == "A confusao fica ainda mais visivel");
}

TEST_CASE("07 - Atributo quotes - Chamar o metodo mais vezes do que o tamanho do vector deve retornar a ultima frase"){
    Clek clek(10, 2, 2);
    CHECK(clek.getQuote() == "A confusao fica ainda mais visivel");
    CHECK(clek.getQuote() == "A confusao fica ainda mais visivel");
}

TEST_CASE("08 - takeDamage deve colocar a vida do monstro como vida - (ataqueInimigo - defesa) quando o valor ataqueInimigo e maior que a defesa") {
    Clek clek(10, 2, 2);

    int newHealth = clek.takeDamage(4);
    CHECK(newHealth == 8);
}

TEST_CASE("09 - takeDamage deve diminuir a vida do monstro em 1 quando o valor da defesa for maior que o valor do ataque inimigo") {
    Clek clek(10, 2, 6);

    int newHealth = clek.takeDamage(4);
    CHECK(newHealth == 9);
}

