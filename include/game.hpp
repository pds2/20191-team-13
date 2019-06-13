#pragma once
#include <stack>
#include "player.hpp"

class GameState;

/** \brief classe principal do jogo.
 * O Game guarda alguns dados que são usados em todas as telas do jogo, como as informações sobre o jogador.
 * É responsável também por administrar os gameStates, que são as telas do jogo. * 
 */
class Game{
private:
    bool state_endgame = 0;
    bool state_win = 0;
    bool state_lose = 0;

    std::stack<std::string> errorStack;

    Player player;
public:
    std::stack<GameState*> states; ///<A pilha guarda os GameStates do jogo, A lógica é chamada sempre no GameState que está no topo */
    bool needsUserInput = true;
    Game();
    ~Game();

    void pushState(GameState* state); ///<insere um GameState na pilha. chamada em uma transição de telas */
    void changeState(GameState* state); ///<Deleta o GameState no topo da pilha e insere outro em seu lugar */
    void popState(); ///<remove o gameState no topo da pilha, essencialmente voltando para uma tela anterior do jogo */

    Player* getPlayer(); ///<referência do jogador atual do jogo */

    void quit(); ///<sai do jogo */
    void win(); ///<mostra uma mensagem de vitória e sai do jogo */
    void lose();///<mostra uma mensagem de derrota e sai do jogo */

    GameState* peekState(); ///<retorna uma referência ao GameState no topo da pilha, ou seja, a tela atual do jogo. */

    void gameLoop(); ///<Loop que roda a lógica do jogo */
};
