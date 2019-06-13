#pragma once

#include <string>
#include <map>
#include "entity.hpp"

/** \brief um item que pode alterar atributos do jogador.O item pode ser usado pelo jogador para aumentar seus atributos permanentemente.
 * 
 */

class Item : public Entity{
    private: 
        std::string name;        ///< um nome que representa o item no jogo */
        std::string itemEffect;  ///< descrição do atributo que será alterado (ataque,defesa,vida) */
        std::string description; ///< descrição que aparece no inventário do jogador */
        int increment = 1;       ///< quantidade que será incrementada aos atributos do jogador */

    public:
        virtual std::string getType();

        std::string getDescription();
        std::string getEffect();
        std::string getName();
        int getIncrement();

    Item();
    ~Item(){};
};
