#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "ListaEntidades.h" //temporario
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include <string>

class Jogo {
private:
	Gerenciadores::GerenciadorGrafico gg;
	Entidades::Personagens::Jogador pJog1;
	Entidades::Personagens::Jogador* pJog2;
	short int atual; // 0: Menu; 1: MenuSelecao; 2: GameOver ; 3: 1 player fase 1; 4: 2 players fase 1; 5: 1 player fase 2; 6: 2 players fase 2
	Fases::FasePrimeira* pFase1;
	Fases::FaseSegunda* pFase2;
	std::string nomeJogador;
	void inserirRanking(std::string nome, int pontos);
	void salvarJogada();
	bool pausado;
	sf::Text textoPausa;
	sf::Font fonte;

public:
	Jogo();
	~Jogo();
	void executar();
	void setAtual(short int a = 0);
	void carregarJogada();
};

