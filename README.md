# Team 13 - RPG


### User stories

	1. Como jogador, quero que o jogo se inicialize com um menu, para iniciar um novo jogo, carregar o jogo já existente, e sair do jogo

		**Critérios de aceitação**
		- Necessárias três opções de seleção (Novo jogo, Continuar, sair do jogo)

	2. Como jogador quero me movimentar pelo cenário para interagir com os personagens do jogo e batalhar contra monstros.
	
		**Critérios de aceitação**
		- O jogador deve conseguir controlar os movimentos do personagem pela tela, e na tela reproduzir de maneira visual ao jogador, a posição de seu personagem
		- No cenário devem haver personagens não-jogáveis (NPCs) que se encontrem em posições pré-determinadas do cenário e que o jogador consiga interagir com eles
		- O jogador deve encontrar no cenário um NPC que permita salvar o estado do jogo, a fim de retornar ao jogo em um momento futuro

	3. Como jogador de RPGs, quero encontrar personagens não agressivos e com personalidade, para poder iniciar uma conversa com eles e apreciar uma pequena história no jogo.
	
		**Critérios de aceitação**

		- Quando estiver perto de um NPC, o jogador pode pressionar um botão para interagir com ele. Nesse momento, uma janela deve abrir com a fala do personagem.
		- O jogador pode continuar a conversa pressionando novamente o botão, até o texto terminar
		- O jogador poderá iniciar a conversa novamente, mesmo se já tiver conversado com o personagem antes

	4. Como jogador de RPGs, quero encontrar um monstro aleatoriamente pelo cenário que inicie uma batalha, para poder derrotá-lo e ganhar pontos pelos meus feitos no jogo

		**Critérios de aceitação**

		- Os monstros não ficarão visíveis no cenário; o jogador simplesmente receberá um aviso sonoro, indicando o começo de uma batalha
		- Quando a batalha terminar, o jogador retomará a sua posição original no cenário

	5. Como jogador de RPGs, quero a possibilidade de utilizar itens em uma batalha, para que eu possa alterar o andamento da batalha de forma inusitada
	
		**Critérios de aceitação**

		- O jogador deve ter a possibilidade de acessar um menu de itens durante a batalha
		- Os itens disponíveis devem causar diferentes efeitos no jogador (aumentar a vida, aumentar o ataque, etc)

	6. Com jogador quero que durante a batalha, no meu turno, eu tenha várias opções de ação, para que a luta seja mais dinâmica.

		**Critérios de aceitação**

		- Um botão para atacar e causar dano ao inimigo.
		- Um botão para verificar a vida e os atributos do inimigo
		- Um botão para utilizar itens
		- Um botão para fugir da batalha

	7.  Como jogador que conhece o jogo Undertale, quero que os monstros ataquem por meio de projéteis, para que eu possa desviar-me deles e não sofrer dano no turno do inimigo.

		**Critérios de aceitação**

		- No turno do monstro atacante, o jogador aparecerá representado por um ponto em uma caixa fechada.O jogador poderá movimentar-se somente nos limites da caixa
		- O inimigo lançará projéteis em direção ao jogador, que deverá desviar deles. O jogador só receberá dano se for atingido por um dos projéteis
