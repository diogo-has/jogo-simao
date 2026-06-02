#pragma once

#include "Fase.h"

namespace Fases {
	class FasePrimeira:public Fase {
	protected:
		void criarInimigos();
		void criarObstaculos();
		void criarChao();
		sf::Sprite* pBackground;
		//Personagens::Jogador* pJogador;//nao sei se é assim que faz

	public:
		FasePrimeira(Entidades::Personagens::Jogador* pj1, Entidades::Personagens::Jogador* pj2 = nullptr);
		~FasePrimeira();
		void setpBackground(sf::Sprite* pb);
		void desenharbackground();
		void executar();
		//void setJog(Personagens::Jogador* p);
		
		//funcao criar pra cada tipo d einimimgo
	};
}

