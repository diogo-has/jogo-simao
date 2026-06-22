#include "Ente.h"

Ente::Ente() : id(-1), imagem(), sprite() {
	
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

void Ente::calculaOrigemSprite() {
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2.0f, bounds.height);
}

void Ente::setGG(Gerenciadores::GerenciadorGrafico* pG) {
	pGG = pG;
}
