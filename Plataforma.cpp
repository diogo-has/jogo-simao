#include "Plataforma.h"

namespace Entidades {
	namespace Obstaculos {

		Plataforma::Plataforma(float x, float y) : Obstaculo(x, y), altura(1) {
			imagem.loadFromFile("sprites/plataforma.png"); //temporario
			sprite.setTexture(imagem);
			sprite.setScale(2, 2);
			sprite.setPosition(x, y);
		}

		Plataforma::Plataforma() : Obstaculo(), altura(1) { }

		Plataforma::~Plataforma() { }

		void Plataforma::executar() { }

		void Plataforma::obstaculizar(Personagens::Jogador* p) {
			p->setNoChao(true);
			p->setVelocidadeY(0.f);
			//p->setPosicaoY(sprite.getGlobalBounds().top);

			//p->setNoChao(true);

			//float topo =
			//	sprite.getPosition().y -
			//	sprite.getGlobalBounds().height / 2.f;

			//float metadeJogador =
			//	(p->getSprite()->getGlobalBounds().height / 2.f) - 15.f; // para o player ficar "dentro" da plataforma 15px

			//float y = topo - metadeJogador;
			//p->setAceleracaoY(0.f);
			//p->setpulo(0.f);
			////p->setPosicaoY(y);
			//p->setVelocidadeY(0.f);
		}

		void Plataforma::salvar() { }

	}
}
