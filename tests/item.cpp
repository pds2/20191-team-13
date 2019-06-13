#include "doctest.h"

#include "item.hpp"

TEST_CASE("01- construtor item "){
    CHECK_NOTHROW(new Item());
}

TEST_CASE("02- Getters"){
    Item i;
    CHECK(i.getIncrement() > 0);

    CHECK_NOTHROW(i.getName);
    CHECK_NOTHROW(i.getType);
    CHECK_NOTHROW(i.getEffect);
    CHECK_NOTHROW(i.getDescription);    
}