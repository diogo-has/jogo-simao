#include "FasePrimeira.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "Tronco.h"
#include "Formigueiro.h"
#include "Tronco.h"
#include "Macaco.h"
#include "Cacador.h"
#include "Chao.h"
#include "Boitata.h"
#include <iostream>


namespace Fases {
	
	FasePrimeira::FasePrimeira(Entidades::Personagens::Jogador* pj1, Entidades::Personagens::Jogador* pj2) : maxCacadores(4), maxTroncos(6)
	{
		tamanho = 7;
		GC.setJogador(1, pj1);
		if (pj2) {
			GC.setJogador(2, pj2);
			singleplayer = false;
		} else
			singleplayer = true;
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pj1));
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pj2));
		criarObstaculos();
		criarInimigos();
		imagem.loadFromFile("sprites/background.png");
		tipoChao = 1;
		criarCenario();
		//imagem.setRepeated(true);
		//background.setTexture(imagem);
		//background.setTextureRect(sf::IntRect(0, 0, int(LARGURA_TELA * tamanho), imagem.getSize().y));
		//background.setPosition(0.f, 0.f);
		//thud.loadFromFile("sprites/3hearts.png");
		//HUD.setTexture(thud);
		//HUD.setPosition(20.f, 20.f);
		//HUD.setScale(3, 3);
	}

	FasePrimeira::~FasePrimeira() {

	}
	
	void FasePrimeira::criarInimigos()
	{
		/*
		
		Entidades::Personagens::Cacador* c1 = new Entidades::Personagens::Cacador;
		
		lista_ents.incluir(static_cast<Entidades::Entidade*>(c1));
		
		GC.incluirInimigo(c1);

		Entidades::Personagens::Boitata* b1 = new Entidades::Personagens::Boitata();
		b1->setPosicao({ 1200.f, 500.f });
		lista_ents.incluir(b1);
		GC.incluirInimigo(b1);
		*/
		criarCacadores();
		criarMacacos();
		

	}
	void FasePrimeira::criarCacadores()
	{
		int qntCacadores = MIN_RAND_ENTIDADES + (std::rand() % (maxCacadores - MIN_RAND_ENTIDADES + 1));

		int qnt_lugares = tamanho;
		set<int> lugares;
		while (lugares.size() < qntCacadores) {
			int lugarCacador = std::rand() % qnt_lugares;
			lugares.insert(lugarCacador);
		}
		set<int>::iterator it;
		for (it = lugares.begin(); it != lugares.end(); it++) {
			Entidades::Personagens::Cacador* c = new Entidades::Personagens::Cacador;
			lista_ents.incluir(static_cast<Entidades::Entidade*>(c));
			GC.incluirInimigo(c);
			c->setPosicao({ 700.f + ((*it) * LARGURA_TELA), 200.f });
		}

		//Entidades::Personagens::Cacador* c1 = new Entidades::Personagens::Cacador;
		//c1->setPosicao({ 400.f, 200.f });
		//lista_ents.incluir(static_cast<Entidades::Entidade*>(c1));
		//GC.incluirInimigo(c1);
	}
	void FasePrimeira::criarObstaculos()
	{
		criarTroncos();
		criarPlataformas();

		//Entidades::Obstaculos::Tronco* t1 = new Entidades::Obstaculos::Tronco();
		//t1->setPosicao({ 500.f, 440.f });
		//t1->setTipo(0);
		//lista_ents.incluir(static_cast<Entidades::Entidade*>(t1));
		//GC.incluirObstaculo(t1);

		//Entidades::Obstaculos::Plataforma* plat1 = new Entidades::Obstaculos::Plataforma;
		
		//Entidades::Obstaculos::Tronco* t1 = new Entidades::Obstaculos::Tronco;
		//lista_ents.incluir(plat1);
		
		//lista_ents.incluir(t1);
		//GC.incluirObstaculo(plat1);
		
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

		//Entidades::Obstaculos::Plataforma* plat1 = new Entidades::Obstaculos::Plataforma(500.f, 320.f);
		//lista_ents.incluir(static_cast<Entidades::Entidade*>(plat1));
		//GC.incluirObstaculo(plat1);

	}
	void FasePrimeira::criarTroncos()
	{
		int qntTroncos = MIN_RAND_ENTIDADES + (std::rand() % (maxTroncos - MIN_RAND_ENTIDADES + 1));

		int qnt_lugares = tamanho;
		set<int> lugares;
		while (lugares.size() < qntTroncos) {
			int lugarTronco = std::rand() % qnt_lugares;
			lugares.insert(lugarTronco);
		}
		set<int>::iterator it;
		for (it = lugares.begin(); it != lugares.end(); it++) {
			Entidades::Obstaculos::Tronco* t = new Entidades::Obstaculos::Tronco();
			lista_ents.incluir(static_cast<Entidades::Entidade*>(t));
			GC.incluirObstaculo(t);
			t->setTipo(std::rand() % 2);
			t->setPosicao({ (200.f + (std::rand() % 401)) + ((*it) * LARGURA_TELA), 520.f });
		}
	}

	void FasePrimeira::executar()
	{
		pGG->desenhaBackground(&background);
		lista_ents.percorrer();
		GC.executar();
		//lista_ents.desenhar();
		pGG->desenhaHUD(&HUDp1);
		if (!singleplayer)
			pGG->desenhaHUD(&HUDp2);
		
		//std::cout << "executando gc" << std::endl;
		
	}

	//void FasePrimeira::setJog(Personagens::Jogador* p)
	//{
	//	pJogador = p;
	//	GC.setJogador(pJogador);
	//}

}
