#include "Fase.h"
#include "Boitata.h"
#include "Macaco.h"
#include "Plataforma.h"

namespace Fases {
	void Fase::criarMacacos()
	{
		int qntMacacos = MIN_RAND_ENTIDADES + (std::rand() % (maxMacacos - MIN_RAND_ENTIDADES + 1));
		
		int qnt_lugares = tamanho * 2;
		set<int> lugares;
		while (lugares.size() < qntMacacos) {
			int lugarMacaco = 1 + (std::rand() % qnt_lugares);
			lugares.insert(lugarMacaco);
		}
		set<int>::iterator it;
		for (it = lugares.begin(); it != lugares.end(); it++) {
			Entidades::Personagens::Macaco* m = new Entidades::Personagens::Macaco;
			lista_ents.incluir(static_cast<Entidades::Entidade*>(m));
			GC.incluirInimigo(m);
			if ((*it) % 2 == 0) {
				m->setPosicao({ 100.f + ( (int)((*it)/2) * LARGURA_TELA), 200.f});
			}
			else {
				m->setPosicao({ 700.f + ((int)((*it) / 2) * LARGURA_TELA), 200.f });
				m->mudarDirecao(DIRECAO_ESQUERDA);
				m->setVelocidadeX(-100.f);
			}
		}

		//Entidades::Personagens::Macaco* m1 = new Entidades::Personagens::Macaco;
		//m1->setPosicao({ 700.f, 200.f });
		//m1->mudarDirecao(DIRECAO_ESQUERDA);
		//m1->setVelocidadeX(-100.f);
		//lista_ents.incluir(static_cast<Entidades::Entidade*>(m1));
		//GC.incluirInimigo(m1);
	}
	void Fase::criarPlataformas() {
		int qntPlataformas = MIN_RAND_ENTIDADES + (std::rand() % (maxPlataformas - MIN_RAND_ENTIDADES + 1));

		int qnt_lugares = tamanho;
		set<int> lugares;

		while (lugares.size() < qntPlataformas) {
			int lugarPlataforma = std::rand() % (qnt_lugares + 1);
			lugares.insert(lugarPlataforma);
		}

		set<int>::iterator it;
		for (it = lugares.begin(); it != lugares.end(); it++) {
			Entidades::Obstaculos::Plataforma* p = new Entidades::Obstaculos::Plataforma;
			lista_ents.incluir(static_cast<Entidades::Entidade*>(p));
			GC.incluirObstaculo(p);
			p->setPosicao({
				(100.f + (std::rand() % 601)) + ((*it) * LARGURA_TELA),
				230.f + (std::rand() % 91)
			});
		}
	}
	void Fase::criarCenario()
	{
		
	}
	Fase::Fase() : maxMacacos(10), maxPlataformas(7)
	{

	}
	Fase::~Fase()
	{
	}
}