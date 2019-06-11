#pragma once
#include <string>

class Entity{
    public:
        virtual std::string getType() = 0;

    Entity(){};
    virtual ~Entity (){};
};

