#include "FaseSegunda.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "Tronco.h"
#include "Formigueiro.h"
#include "Tronco.h"
#include "Macaco.h"
#include "Cacador.h"
#include "Chao.h"
#include "Fireball.h"
#include <iostream>
#include <string>

using std::string;


namespace Fases {

	FaseSegunda::FaseSegunda(Entidades::Personagens::Jogador* pj1, Entidades::Personagens::Jogador* pj2, bool carregada) : maxBoitatas(4), maxFormigueiros(6), tempo_fireball(2.f), timer_fireball(0.f) {
		tamanho = 7;
		GC.setJogador(1, pj1);
		if (pj2) {
			GC.setJogador(2, pj2);
			singleplayer = false;
		}
		else
			singleplayer = true;
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pj1));
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pj2));
		imagem.loadFromFile("sprites/background_fase2.png");
		tipoChao = 2;
		if (!carregada) {
			criarObstaculos();
			criarInimigos();
			criarCenario();
		}
	}

	FaseSegunda::~FaseSegunda() {

	}

	void FaseSegunda::criarInimigos() {

		criarBoitatas();
		criarMacacos();


	}
	void FaseSegunda::criarBoitatas() {
		int qntBoitatas = MIN_RAND_ENTIDADES + (std::rand() % (maxBoitatas - MIN_RAND_ENTIDADES + 1));

		int qnt_lugares = tamanho;
		set<int> lugares;
		while (lugares.size() < qntBoitatas) {
			int lugarBoitata = std::rand() % qnt_lugares;
			lugares.insert(lugarBoitata);
		}
		set<int>::iterator it;
		for (it = lugares.begin(); it != lugares.end(); it++) {
			Entidades::Personagens::Boitata* b = new Entidades::Personagens::Boitata;
			lista_ents.incluir(static_cast<Entidades::Entidade*>(b));
			GC.incluirInimigo(b);
			LBs.insert(b);
			b->setPosicao({ 700.f, 200.f });
			b->setRaiva((std::rand() % 4) + 1);
			b->setPosicao({ 700.f + ((*it) * LARGURA_TELA), 200.f });
		}
	}
	void FaseSegunda::criarObstaculos() {
		criarFormigueiros();
		criarPlataformas();

	}
	void FaseSegunda::criarFormigueiros()
	{
		int qntFormigueiros = MIN_RAND_ENTIDADES + (std::rand() % (maxFormigueiros - MIN_RAND_ENTIDADES + 1));

		int qnt_lugares = tamanho;
		set<int> lugares;
		while (lugares.size() < qntFormigueiros) {
			int lugarFormigueiro = std::rand() % qnt_lugares;
			lugares.insert(lugarFormigueiro);
		}
		set<int>::iterator it;
		for (it = lugares.begin(); it != lugares.end(); it++) {
			Entidades::Obstaculos::Formigueiro* f = new Entidades::Obstaculos::Formigueiro;
			lista_ents.incluir(static_cast<Entidades::Entidade*>(f));
			GC.incluirObstaculo(f);
			f->setPosicao({ (200.f + (std::rand() % 401)) + ((*it) * LARGURA_TELA), 447.f });
		}
	}
	

	void FaseSegunda::criarFireballs()
	{
		set<Entidades::Personagens::Boitata*>::iterator it;
		for (it = LBs.begin(); it != LBs.end(); it++) {
			bool direcaoB = (*it)->getDirecao();
			sf::Vector2f posicaoB = (*it)->getPosicao();

			Entidades::Fireball* f = new Entidades::Fireball;
			f->setPosicao({posicaoB.x + 100.f * (direcaoB == DIRECAO_DIREITA ? 1 : -1), posicaoB.y - 50.f});
			f->mudarDirecao(direcaoB);
			f->setVelocidadeX(500.f * (direcaoB == DIRECAO_DIREITA ? 1 : -1));
			f->setTamanho((float) (*it)->getInflamabilidade());

			(*it)->setFireball(f);
			f->setBoitata(*it);
			lista_ents.incluir(static_cast<Entidades::Fireball*>(f));
			GC.incluirProjetil(f);
		}
	}

	void FaseSegunda::executar() {
		float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
		timer_fireball += dt;
		if (timer_fireball >= tempo_fireball) {
			criarFireballs();
			timer_fireball = 0.f;
		}
		set<Entidades::Personagens::Boitata*>::iterator it;
		for (it = LBs.begin(); it != LBs.end();) {
			if (!(*it)->getVivo())
				it = LBs.erase(it);
			else
				it++;
		}

		pGG->desenhaAlheio(&background);
		lista_ents.percorrer();
		GC.executar();
		//lista_ents.desenhar();
		pGG->desenhaHUD(&HUDp1);
		if (!singleplayer)
			pGG->desenhaHUD(&HUDp2);

	}

	void Fases::FaseSegunda::carregar(ifstream& arquivo) {
		imagem.setRepeated(true);
		background.setTexture(imagem);
		background.setTextureRect(sf::IntRect(0, 0, int(LARGURA_TELA * tamanho), imagem.getSize().y));
		background.setPosition(0.f, 0.f);
		pGG->desenhaAlheio(&background);

		string tipoEntidade;

		while (arquivo >> tipoEntidade) {
			cout << tipoEntidade << endl;
			if (tipoEntidade == "chao") {
				Entidades::Chao* chao = new Entidades::Chao();
				chao->carregar(arquivo);
				chao->setTamanho(tamanho);
				chao->setTipo(tipoChao);
				lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));
				GC.setChao(chao);
			}
			else if (tipoEntidade == "macaco") {
				Entidades::Personagens::Macaco* m = new Entidades::Personagens::Macaco();
				m->carregar(arquivo);
				lista_ents.incluir(static_cast<Entidades::Entidade*>(m));
				GC.incluirInimigo(m);
			}
			else if (tipoEntidade == "plataforma") {
				Entidades::Obstaculos::Plataforma* p = new Entidades::Obstaculos::Plataforma();
				p->carregar(arquivo);
				lista_ents.incluir(static_cast<Entidades::Entidade*>(p));
				GC.incluirObstaculo(p);
			}
			else if (tipoEntidade == "boitata") {
				Entidades::Personagens::Boitata* b = new Entidades::Personagens::Boitata();
				b->carregar(arquivo);
				lista_ents.incluir(static_cast<Entidades::Entidade*>(b));
				GC.incluirInimigo(b);
				LBs.insert(b);
			}
			else if (tipoEntidade == "formigueiro") {
				Entidades::Obstaculos::Formigueiro* f = new Entidades::Obstaculos::Formigueiro();
				f->carregar(arquivo);
				lista_ents.incluir(static_cast<Entidades::Entidade*>(f));
				GC.incluirObstaculo(f);
			}
			else if (tipoEntidade == "fireball") {
				Entidades::Fireball* f = new Entidades::Fireball();
				f->carregar(arquivo);
				lista_ents.incluir(static_cast<Entidades::Entidade*>(f));
				GC.incluirProjetil(f);
			}
		}
	}

}
