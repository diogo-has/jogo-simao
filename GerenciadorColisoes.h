#pragma once
#include <vector>
#include <list>
#include <set>
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Fireball.h"
#include "Chao.h"
#include "GerenciadorGrafico.h"


using std::vector;
using std::list;
using std::set;

using namespace Entidades;

namespace Gerenciadores {
	class GerenciadorColisoes {
	private:
		vector<Personagens::Inimigo*> LIs;
		list<Obstaculos::Obstaculo*> LOs;
		set<Fireball*> LPs;
		Chao* chao;
		Personagens::Jogador* pJog1;
		Personagens::Jogador* pJog2;


		const bool verificarColisao(Entidade* pe1, Entidade* pe2) const;
		void tratarColisoesJogsInimigs();
		void tratarColisoesJogsObstacs();
		void tratarColisoesInimigsObstacs();
		void tratarColisoesJogsProjeteis();
		void tratarColisoesChao();

	public:
		GerenciadorColisoes();
		~GerenciadorColisoes();
		void incluirInimigo(Personagens::Inimigo* pi);
		void removerInimigo(Personagens::Inimigo* pi);
		void incluirObstaculo(Obstaculos::Obstaculo* po);
		void incluirProjetil(Fireball* pp);
		void setChao(Chao* pc);
		void executar();
		void setJogador(int nJog, Personagens::Jogador* pJog);

	};
}

