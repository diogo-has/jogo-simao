#include "Ente.h"

Ente::Ente() : id(-1), imagem(), sprite(), escala(1.f) {
	mudarDirecao(DIRECAO_DIREITA);
}
Gerenciadores::GerenciadorGrafico* Ente::pGG = nullptr;

Ente::~Ente() {
	id = -1;
}


void Ente::desenhar() {
	pGG->desenharEnte(this);
}

const sf::Sprite* Ente::getSprite() {
	return &sprite;
}

void Ente::mudarDirecao(bool dir) {
	if (dir == DIRECAO_DIREITA) {
		direcao = DIRECAO_DIREITA;
		sprite.setScale(escala, escala);
	} else {
		direcao = DIRECAO_ESQUERDA;
		sprite.setScale(-escala, escala);
	}
}

bool Ente::getDirecao() {
	return direcao;
}

void Ente::setEscala(float esc) {
	escala = esc;
	if (direcao == DIRECAO_DIREITA) {
		sprite.setScale(escala, escala);
	}
	else {
		sprite.setScale(-escala, escala);
	}
}

void Ente::calculaOrigemSprite() {
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2.0f, bounds.height);
}

void Ente::setGG(Gerenciadores::GerenciadorGrafico* pG) {
	pGG = pG;
}
