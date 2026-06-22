#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "ListaEntidades.h" //temporario
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include <string>

using std::string;

class Jogo {
private:
	Gerenciadores::GerenciadorGrafico gg;
	Entidades::Personagens::Jogador pJog1;
	Entidades::Personagens::Jogador* pJog2;
	short int atual; // 0: Menu; 1: MenuSelecao; 2: GameOver ; 3: 1 player fase 1; 4: 2 players fase 1; 5: 1 player fase 2; 6: 2 players fase 2
	Fases::FasePrimeira* pFase1;
	Fases::FaseSegunda* pFase2;
	std::string nomeJogador;
	bool pausado;
	sf::Text textoPausa;
	sf::Font fonte;
	void inserirRanking(const string nome, const int pontos);
	void salvarJogada();

public:
	Jogo();
	~Jogo();
	void executar();
	void setAtual(const short int a = 0);
	void carregarJogada();
};

