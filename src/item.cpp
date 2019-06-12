#include "item.hpp"
#include "entity.hpp"
#include <string>
#include "helpers.hpp"
std::string Item::getType(){
    return "item";
}
void Item::set_quantity(int quantity){
    this->quantity = quantity;
}
int Item::get_quantity(){
    return this->quantity;
}

Item::Item (){
    int rand = Helpers::easyRandom (3);
    if (rand == 1){
        this -> itemEffect = "Ataque";
        this->name = "Vassoura";
    }else if (rand == 2){
        this -> itemEffect = "Defesa";
        this->name = "Gelo";
    }else if (rand == 3){
        this -> itemEffect = "HP";
        this->name = "Laranja";
    }
}
