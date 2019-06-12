#include "item.hpp"
#include "entity.hpp"
#include <string>
#include "helpers.hpp"

std::string Item::getType(){
    return "item";
}

Item::Item (){
    int rand = Helpers::easyRandom (3);

    if (rand == 1){
        this-> itemEffect = "ATAQUE";
        this->name = "Vassoura";
    }else if (rand == 2){
        this-> itemEffect = "DEFESA";
        this->name = "Gelo";
    }else if (rand == 3){
        this-> itemEffect = "HP";
        this->name = "Laranja";
    }

    int rand2 = Helpers::easyRandom(10);
    this->increment = rand2;

    this->description = this->name + ": " + this->itemEffect + " + " + std::to_string(this->increment);
}

std::string Item::getName(){
    return this->name;
}

std::string Item::getEffect(){
    return this->itemEffect;
}

std::string Item::getDescription(){
    return this->description;
}

int Item::getIncrement(){
    return this->increment;
}