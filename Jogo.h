#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "ListaEntidades.h" //temporario

class Jogo {
private:
	Gerenciadores::GerenciadorGrafico gg;
	Entidades::Personagens::Jogador pJog1;
	Listas::ListaEntidades listaEnt; //temporario

public:
	Jogo();
	~Jogo();
	void executar();
};

