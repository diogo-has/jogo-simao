#pragma once

#include "Fase.h"

namespace Fases {
	class FasePrimeira:public Fase {
	private:
		const int maxCacadores = 4;
		
	protected:
		void criarInimigos();
		void criarCacadores(); //imimigo medio
		void criarObstaculos();
		void criarFormigueiros();
		void criarChao();
		sf::Sprite background;
		sf::Texture thud;
		sf::Sprite HUD;
		//Personagens::Jogador* pJogador;//nao sei se é assim que faz

	public:
		FasePrimeira(Entidades::Personagens::Jogador* pj1, Entidades::Personagens::Jogador* pj2 = nullptr);
		~FasePrimeira();
		void desenharbackground();
		void executar();
		void atualizaHUD(int v);
		//void setJog(Personagens::Jogador* p);
		
		//funcao criar pra cada tipo d einimimgo
	};
}

