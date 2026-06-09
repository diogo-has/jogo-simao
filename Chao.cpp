#include "Chao.h"

namespace Entidades {
	Chao::Chao(): Entidade() {
		imagem.loadFromFile("sprites/chao.png");
		imagem.setRepeated(true);
		sprite.setTexture(imagem);
		//sprite.setTextureRect(sf::IntRect(0, 0, LARGURA_TELA*2, imagem.getSize().y));
		setEscala(2);

		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(0, bounds.height);

		sprite.setPosition(0, ALTURA_TELA+5);
	}

	Chao::~Chao() {
	}

	void Chao::executar() {}

	void Chao::colidir(Personagens::Personagem* pP) {
		pP->setNoChao(true);
		pP->setVelocidadeY(0.f);
		pP->setPosicao({ pP->getPosicao().x, sprite.getGlobalBounds().top });
	}
	void Chao::setTamanho(int tam) {
		sprite.setTextureRect(sf::IntRect(0, 0, int(LARGURA_TELA * tam / escala), imagem.getSize().y));
	}
	void Chao::salvar() {
	}
}



