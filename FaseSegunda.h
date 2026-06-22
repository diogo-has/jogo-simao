#pragma once
#include "Fase.h"
#include "Boitata.h"
namespace Fases {
	class FaseSegunda : public Fase {
	private:
		const int maxBoitatas;
		const int maxFormigueiros;
		set<Entidades::Personagens::Boitata*> LBs;
		float tempo_fireball;
		float timer_fireball;

	protected:
		void criarInimigos();
		void criarBoitatas(); //imimigo difícil
		void criarObstaculos();
		void criarFormigueiros();
		//void criarTroncos();
		void criarFireballs();

	public:
		FaseSegunda(Entidades::Personagens::Jogador* pj1, Entidades::Personagens::Jogador* pj2 = nullptr, bool carregada = false);
		~FaseSegunda();
		void executar();
		void carregar(ifstream& arquivo);
	};
}

