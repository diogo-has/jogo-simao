#include "Plataforma.h"

namespace Entidades {
	namespace Obstaculos {

		/*
		Plataforma::Plataforma(float x, float y) : Obstaculo(x, y), altura(1) {
			imagem.loadFromFile("sprites/plataforma.png");
			sprite.setTexture(imagem);
			setEscala(1);
			calculaOrigemSprite();
			sprite.setPosition(x, y);
		}
		*/

		Plataforma::Plataforma() : Obstaculo(), forcaFlutuacao(2000.f) {
			imagem.loadFromFile("sprites/plataforma.png");
			sprite.setTexture(imagem);
			setEscala(1);
			calculaOrigemSprite();
			velocidade.y = 30.f;
		}

		Plataforma::~Plataforma() { }

		void Plataforma::executar() {
			aceleracao.y -= forcaFlutuacao;

			// Oscila ao redor da altura
			if (std::abs(posicao.y - altura) > 50)
				velocidade.y *= -1;
			


			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
			velocidade += aceleracao * dt;
			posicao += velocidade * dt;
			sprite.setPosition(posicao);
		}

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

		void Plataforma::obstaculizar(Personagens::Inimigo* i) {
			float topoPlataforma = sprite.getGlobalBounds().top;

			if (i->getPosicao().y <= sprite.getGlobalBounds().top + 20) {
				i->setNoChao(true);
				i->setVelocidadeY(0.f);
				i->setAceleracaoY(0.f);
				i->setPosicao({ i->getPosicao().x, topoPlataforma });
			}
		}

		void Plataforma::salvar() {
			salvarDataBuffer();
		}
		void Plataforma::salvarDataBuffer() {
			buffer << "plataforma";

			Obstaculo::salvarDataBuffer();

			buffer << " " << altura << endl;;

		}

		void Plataforma::carregar(ifstream& arquivo) {
			Obstaculo::carregar(arquivo);

			arquivo >> altura;
		}

		void Plataforma::setAltura(float a)
		{
			altura = a;
		}

	}
}
