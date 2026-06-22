#include "Entidade.h"

namespace Entidades {
	void Entidade::salvarDataBuffer() {
		buffer << " " << posicao.x << " " << posicao.y
			<< " " << velocidade.x << " " << velocidade.y
			<< " " << aceleracao.x << " " << aceleracao.y
			<< " " << direcao
			<< " " << escala;
	}
	void Entidades::Entidade::carregar(ifstream& arquivo) {
		arquivo >> posicao.x >> posicao.y
			>> velocidade.x >> velocidade.y
			>> aceleracao.x >> aceleracao.y
			>> direcao
			>> escala;
		mudarDirecao(direcao);
		setEscala(escala);
		sprite.setPosition(posicao);
	}
	Entidade::Entidade(): posicao(0.f, 0.f), velocidade(0.f, 0.f), aceleracao(0.f, 0.f), vivo(true), buffer(nullptr), escala(1.f) {
		mudarDirecao(DIRECAO_DIREITA);
	}
	Entidade::~Entidade() {
	}

	void Entidade::gravitar() {
		aceleracao.y = 2000.f;
	}
	void Entidade::destruir() {
		vivo = false;
	}
	const bool Entidade::getVivo() const {
		return vivo;
	}
	void Entidade::mudarDirecao(const bool dir) {
		if (dir == DIRECAO_DIREITA) {
			direcao = DIRECAO_DIREITA;
			sprite.setScale(escala, escala);
		}
		else {
			direcao = DIRECAO_ESQUERDA;
			sprite.setScale(-escala, escala);
		}
	}

	const bool Entidade::getDirecao() const{
		return direcao;
	}
	void Entidade::setEscala(const float esc) {
		escala = esc;
		if (direcao == DIRECAO_DIREITA) {
			sprite.setScale(escala, escala);
		}
		else {
			sprite.setScale(-escala, escala);
		}
	}
	ostream* Entidade::getBuffer() {
		return &buffer;
	}
	void Entidade::setVelocidadeX(const float vx) {
		velocidade.x = vx;
	}
	void Entidade::setVelocidadeY(const float vy) {
		velocidade.y = vy;
	}
	void Entidade::setAceleracaoX(const float ax) {
		aceleracao.x = ax;
	}
	void Entidade::setAceleracaoY(const float ay) {
		aceleracao.y = ay;
	}
	void Entidade::setPosicao(const sf::Vector2f pos) {
		posicao = pos;
		sprite.setPosition(posicao);
		desenhar();
	}
	const sf::Vector2f Entidade::getPosicao() const {
		return posicao;
	}
	const sf::FloatRect Entidade::getHitbox() const {
		return sprite.getGlobalBounds();
	}
}
