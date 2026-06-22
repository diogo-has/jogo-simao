#include "Chao.h"

namespace Entidades {
	Chao::Chao(): Entidade() {
		cout << "criou chao" << endl;
		imagem.loadFromFile("sprites/chao.png");
		imagem.setRepeated(true);
		sprite.setTexture(imagem);
		//sprite.setTextureRect(sf::IntRect(0, 0, LARGURA_TELA*2, imagem.getSize().y));
		setEscala(2);

		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(0, bounds.height);

		posicao = { 0.f, ALTURA_TELA + 5 };
		sprite.setPosition(posicao);

	}

	Chao::~Chao() {
	}

	void Chao::executar() {}

	void Chao::colidir(Personagens::Personagem* pP) {
		pP->setNoChao(true);
		pP->setVelocidadeY(0.f);
		pP->setPosicao({ pP->getPosicao().x, sprite.getGlobalBounds().top });
	}
	void Chao::setTamanho(const int tam) {
		sprite.setTextureRect(sf::IntRect(0, 0, int(LARGURA_TELA * tam / escala), imagem.getSize().y));
	}
	void Chao::salvar() {
		salvarDataBuffer();
	}
	void Chao::salvarDataBuffer() {
		buffer << "chao";

		Entidade::salvarDataBuffer();

		buffer << " " << tipo << endl;
	}
	void Chao::carregar(ifstream& arquivo) {
		Entidade::carregar(arquivo);

		arquivo >> tipo;
		setTipo(tipo);
	}
	void Chao::setTipo(const int tip) {
		if (tip == 1) {
			tipo = 1;
			imagem.loadFromFile("sprites/chao.png");
			sprite.setTexture(imagem);
		}
		else if (tip == 2) {
			tipo = 2;
			imagem.loadFromFile("sprites/chao_fase2.png");
			sprite.setTexture(imagem);
		}
	}
}



