#pragma once
#include <string>

/** \brief uma entidade é um objeto no mapa do jogo, como baús ou monstros
 * 
 */
class Entity{
    public:
        virtual std::string getType() = 0;
        
    Entity(){};
    virtual ~Entity (){};
};

