#pragma once
#include "entity.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Item : public Entity{

    std::string name;
    std::string type;
    int quantity = 1;

    public:
        virtual std::string getType();
        void set_quantity(int quantity);
        int get_quantity();

    Item(std::string name, std::string type);
    ~Item(){};
};
