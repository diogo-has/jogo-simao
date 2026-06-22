#pragma once
#include "GerenciadorGrafico.h"
#define DIRECAO_DIREITA true
#define DIRECAO_ESQUERDA false

class Ente {
protected:
	int id;
	static Gerenciadores::GerenciadorGrafico* pGG;
	sf::Texture imagem;
	sf::Sprite sprite;

public:
	Ente();
	virtual ~Ente();

	virtual void executar() = 0;
	void desenhar();

	const sf::Sprite* getSprite();
	virtual void calculaOrigemSprite();

	static void setGG(Gerenciadores::GerenciadorGrafico* pG);

};

