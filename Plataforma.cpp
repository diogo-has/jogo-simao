#include "Plataforma.h"

namespace Entidades {
	namespace Obstaculos {

		Plataforma::Plataforma(float x, float y) : Obstaculo(x, y), altura(1) {
			imagem.loadFromFile("sprites/plataforma.png");
			sprite.setTexture(imagem);
			setEscala(1);
			calculaOrigemSprite();
			sprite.setPosition(x, y);
		}

		Plataforma::Plataforma() : Obstaculo(), altura(1) {
			imagem.loadFromFile("sprites/plataforma.png");
			sprite.setTexture(imagem);
			setEscala(1);
			calculaOrigemSprite();
		}

		Plataforma::~Plataforma() { }

		void Plataforma::executar() { }

		void Plataforma::obstaculizar(Personagens::Jogador* p) {
			float topoPlataforma = sprite.getGlobalBounds().top;
			float fundoPlataforma = topoPlataforma + sprite.getGlobalBounds().height;
			float esquerdaPlataforma = sprite.getGlobalBounds().left;
			float direitaPlataforma = esquerdaPlataforma + sprite.getGlobalBounds().width;

			if (p->getPosicao().y <= sprite.getGlobalBounds().top+10) {
				p->setNoChao(true);
				p->setVelocidadeY(0.f);
				p->setPosicao({ p->getPosicao().x, topoPlataforma });
			}
			else if (p->getSprite()->getGlobalBounds().top >= fundoPlataforma-10) {
				p->setPulando(false);
				p->setVelocidadeY(0.f);
				p->setPosicao({ p->getPosicao().x, (fundoPlataforma + p->getHitbox().height)});
			}
			else if (p->getPosicao().x < sprite.getPosition().x) {
				p->setPosicao({ (esquerdaPlataforma - p->getHitbox().width / 2), p->getPosicao().y });
			}
			else if (p->getPosicao().x > sprite.getPosition().x) {
				p->setPosicao({ (direitaPlataforma + p->getHitbox().width / 2), p->getPosicao().y });
			}
		}

		void Plataforma::salvar() { }

	}
}
