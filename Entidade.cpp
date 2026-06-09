#include "Entidade.h"

namespace Entidades {
	Entidade::Entidade(): posicao(0.f, 0.f), velocidade(0.f, 0.f), aceleracao(0.f, 0.f), sofre_gravidade(false), ativo(true) {

	}
	Entidade::~Entidade() {
	}

	void Entidade::gravitar() {
		if (!sofre_gravidade) return;
		aceleracao.y = 2000.f;
	}
	void Entidade::destruir() {
		ativo = false;
	}
	bool Entidade::getAtivo() {
		return ativo;
	}
	void Entidade::setVelocidadeX(float vx) {
		velocidade.x = vx;
	}
	void Entidade::setVelocidadeY(float vy) {
		velocidade.y = vy;
	}
	void Entidade::setAceleracaoX(float ax) {
		aceleracao.x = ax;
	}
	void Entidade::setAceleracaoY(float ay) {
		aceleracao.y = ay;
	}
	void Entidade::setPosicao(sf::Vector2f pos) {
		posicao = pos;
		sprite.setPosition(posicao);
	}
	sf::Vector2f Entidade::getPosicao() {
		return posicao;
	}
	sf::FloatRect Entidade::getHitbox() {
		return sprite.getGlobalBounds();
	}
}
