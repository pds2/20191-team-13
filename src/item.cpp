#include "item.hpp"
#include "entity.hpp"
#include <string>

std::string Item::getType(){
    return "item";
}
void Item::set_quantity(int quantity){
    quantity = this->quantity;
}
int Item::get_quantity(){
    return this->quantity;
}
Item::Item (std::string name, std::string type){
    name = this->name;
    type = this->type;
}
