#include "Plataforma.h"

namespace Entidades {
	namespace Obstaculos {

		Plataforma::Plataforma(float x, float y) : Obstaculo(x, y), altura(1) {
			imagem.loadFromFile("sprites/plataforma.png"); //temporario
			sprite.setTexture(imagem);
			setEscala(1);
			calculaOrigemSprite();
			sprite.setPosition(x, y);
		}

		Plataforma::Plataforma() : Obstaculo(), altura(1) { }

		Plataforma::~Plataforma() { }

		void Plataforma::executar() { }

		void Plataforma::obstaculizar(Personagens::Jogador* p) {
			float topoPlataforma = sprite.getGlobalBounds().top;
			float fundoPlataforma = topoPlataforma + sprite.getGlobalBounds().height;

			if (p->getPosicao().y <= sprite.getGlobalBounds().top+10) {
				p->setNoChao(true);
				p->setVelocidadeY(0.f);
				p->setPosicao({ p->getPosicao().x, topoPlataforma });
			}
			else if (p->getSprite()->getGlobalBounds().top >= sprite.getGlobalBounds().height) {
				p->setVelocidadeY(0.f);
				p->setPosicao({ p->getPosicao().x, (fundoPlataforma + p->getSprite()->getLocalBounds().height) });
			}

		}

		void Plataforma::salvar() { }

	}
}
