#pragma once

#include "Fase.h"

namespace Fases {
	class FasePrimeira:public Fase {
	protected:
		void criarInimigos();
		void criarObstaculos();
		sf::Sprite* pBackground;
		Personagens::Jogador* pJogador;//nao sei se é assim que faz

	public:
		FasePrimeira();
		~FasePrimeira();
		void setpBackground(sf::Sprite* pb);
		void desenharbackground();
		void executar();
		void setJog(Personagens::Jogador* p);
		
	};
}

