#include "FasePrimeira.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "Formigueiro.h"
#include "Tronco.h"
#include "Macaco.h"
#include "Cacador.h"
#include "Chao.h"
#include "Boitata.h"
#include <iostream>


namespace Fases {
	
	FasePrimeira::FasePrimeira(Entidades::Personagens::Jogador* pj1, Entidades::Personagens::Jogador* pj2): pBackground(NULL)
	{
		GC.setJogadores(pj1, pj2);
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pj1));
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pj2));
		criarCenario();
		criarChao();
		criarObstaculos();
		criarInimigos();
	}

	FasePrimeira::~FasePrimeira() {
		//deletar entidades da fase
	}
	
	void FasePrimeira::criarInimigos()
	{
		/*
		Entidades::Personagens::Macaco* m1 = new Entidades::Personagens::Macaco;
		Entidades::Personagens::Cacador* c1 = new Entidades::Personagens::Cacador;
		lista_ents.incluir(static_cast<Entidades::Entidade*>(m1));
		lista_ents.incluir(static_cast<Entidades::Entidade*>(c1));
		GC.incluirInimigo(m1);
		GC.incluirInimigo(c1);
		*/

		Entidades::Personagens::Boitata* b1 = new Entidades::Personagens::Boitata();
		b1->setPosicao({ 1200.f, 500.f });
		lista_ents.incluir(b1);
		GC.incluirInimigo(b1);

	}
	void FasePrimeira::criarObstaculos()
	{
		//Entidades::Obstaculos::Plataforma* plat1 = new Entidades::Obstaculos::Plataforma;
		//Entidades::Obstaculos::Formigueiro* f1 = new Entidades::Obstaculos::Formigueiro;
		//Entidades::Obstaculos::Tronco* t1 = new Entidades::Obstaculos::Tronco;
		//lista_ents.incluir(plat1);
		//lista_ents.incluir(f1);
		//lista_ents.incluir(t1);
		//GC.incluirObstaculo(plat1);
		//GC.incluirObstaculo(f1);
		//GC.incluirObstaculo(t1);

		//Entidades::Obstaculos::Plataforma* plat1 = nullptr;
		//for (int i = 0; i <= 1000; i += 200) {
		//	plat1 = new Entidades::Obstaculos::Plataforma((float)i, 624.f );
		//	lista_ents.incluir(plat1);
		//	GC.incluirObstaculo(plat1);
		//	plat1 = nullptr;
		//}
		//plat1 = new Entidades::Obstaculos::Plataforma(400.f, 524.f);
		//lista_ents.incluir(plat1);
		//GC.incluirObstaculo(plat1);

	}
	void FasePrimeira::criarChao() {
		Entidades::Chao* chao = new Entidades::Chao();
		lista_ents.incluir(chao);
		GC.setChao(chao);
	}
	void FasePrimeira::setpBackground(sf::Sprite* pb)
	{
		pBackground = pb;
	}
	void FasePrimeira::desenharbackground()
	{
		pGG->desenhaBackground(pBackground);
	}

	void FasePrimeira::executar()
	{
		lista_ents.percorrer();
		GC.executar();
		lista_ents.desenhar();
		//std::cout << "executando gc" << std::endl;
		
	}

	//void FasePrimeira::setJog(Personagens::Jogador* p)
	//{
	//	pJogador = p;
	//	GC.setJogador(pJogador);
	//}

}
