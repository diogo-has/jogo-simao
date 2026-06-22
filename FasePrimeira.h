#pragma once

#include "Fase.h"

namespace Fases {
	class FasePrimeira:public Fase {
	private:
		const int maxCacadores;
		const int maxTroncos;
		
	protected:
		void criarInimigos();
		void criarCacadores(); //imimigo medio
		void criarObstaculos();
		void criarTroncos();
		//void criarFormigueiros();

	public:
		FasePrimeira(Entidades::Personagens::Jogador* pj1, Entidades::Personagens::Jogador* pj2 = nullptr, bool carregada = false);
		~FasePrimeira();
		void executar();
		void carregar(ifstream& arquivo);
	};
}

