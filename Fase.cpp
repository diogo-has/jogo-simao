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
				m->setRaiva(4);
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
			int lugarPlataforma = std::rand() % (qnt_lugares);
			lugares.insert(lugarPlataforma);
		}

		set<int>::iterator it;
		for (it = lugares.begin(); it != lugares.end(); it++) {
			Entidades::Obstaculos::Plataforma* p = new Entidades::Obstaculos::Plataforma;
			lista_ents.incluir(static_cast<Entidades::Entidade*>(p));
			GC.incluirObstaculo(p);
			p->setPosicao({
				(100.f + (std::rand() % 601)) + ((*it) * LARGURA_TELA),
				0
			});
			p->setAltura(250 + (std::rand() % 91));
		}
	}
	void Fase::criarCenario()
	{
		Entidades::Chao* chao = new Entidades::Chao();
		chao->setTamanho(tamanho);
		chao->setTipo(tipoChao);
		lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));
		GC.setChao(chao);

		imagem.setRepeated(true);
		background.setTexture(imagem);
		background.setTextureRect(sf::IntRect(0, 0, int(LARGURA_TELA * tamanho), imagem.getSize().y));
		background.setPosition(0.f, 0.f);
		pGG->desenhaBackground(&background);
	}
	Fase::Fase() : maxMacacos(10), maxPlataformas(7)
	{

	}
	Fase::~Fase()
	{	

	}

	void Fase::encerrar(Personagens::Jogador* pJog1, Personagens::Jogador* pJog2) {
		if (pJog1)
			lista_ents.remover(static_cast<Entidades::Entidade*>(pJog1));
		if (pJog2) {
			lista_ents.remover(static_cast<Entidades::Entidade*>(pJog2));
			GC.setJogador(2, nullptr);
		}
	}
	void Fase::removerJogadorDois(Personagens::Jogador* pJog) {
		if (pJog) {
			pJog->destruir();
			GC.setJogador(2, nullptr);
		}
	}
	void Fase::atualizaHUDP1(int vidas) {
		switch (vidas) {
		case 1:
			tHUDp1.loadFromFile("sprites/1heart.png");
			HUDp1.setTexture(tHUDp1);
			HUDp1.setPosition(20.f, 20.f);
			HUDp1.setScale(3, 3);
			break;
		case 2:
			tHUDp1.loadFromFile("sprites/2hearts.png");
			HUDp1.setTexture(tHUDp1);
			HUDp1.setPosition(20.f, 20.f);
			HUDp1.setScale(3, 3);
			break;
		case 3:
			tHUDp1.loadFromFile("sprites/3hearts.png");
			HUDp1.setTexture(tHUDp1);
			HUDp1.setPosition(20.f, 20.f);
			HUDp1.setScale(3, 3);
			break;
			
		}
	}
	void Fase::atualizaHUDP2(int vidas) {
		switch (vidas) {
		case 0:
			tHUDp2.loadFromFile("sprites/0heartP2.png");
			HUDp2.setTexture(tHUDp2);
			HUDp2.setPosition(650.f, 20.f);
			HUDp2.setScale(3, 3);
			break;
		case 1:
			tHUDp2.loadFromFile("sprites/1heartP2.png");
			HUDp2.setTexture(tHUDp2);
			HUDp2.setPosition(650.f, 20.f);
			HUDp2.setScale(3, 3);
			break;
		case 2:
			tHUDp2.loadFromFile("sprites/2heartsP2.png");
			HUDp2.setTexture(tHUDp2);
			HUDp2.setPosition(650.f, 20.f);
			HUDp2.setScale(3, 3);
			break;
		case 3:
			tHUDp2.loadFromFile("sprites/3heartsP2.png");
			HUDp2.setTexture(tHUDp2);
			HUDp2.setPosition(650.f, 20.f);
			HUDp2.setScale(3, 3);
			break;

		}
	}
}