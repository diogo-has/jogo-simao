#include "GerenciadorGrafico.h"
#include "Ente.h"

namespace Gerenciadores {
	GerenciadorGrafico::GerenciadorGrafico() : 
		janela(sf::VideoMode(LARGURA_TELA, ALTURA_TELA), "Jogo Simão", sf::Style::Titlebar | sf::Style::Close) {
		janela.setFramerateLimit(60);
	}
	float GerenciadorGrafico::dt(0.f);

	GerenciadorGrafico::~GerenciadorGrafico() {}


	void GerenciadorGrafico::limpar() {
		janela.clear();
	}

	void GerenciadorGrafico::mostrar() {
		janela.display();
	}

	bool GerenciadorGrafico::janelaAberta() {
		return janela.isOpen();
	}

	sf::RenderWindow* GerenciadorGrafico::getJanela() {
		return &janela;
	}

	void GerenciadorGrafico::desenharEnte(Ente* pE) {
		janela.draw(*(pE->getSprite()));
	}

	void GerenciadorGrafico::atualizarDeltaTime() {
		dt = clock.restart().asSeconds();
	}

	float GerenciadorGrafico::getDeltaTime() {
		return dt;
	}

	void GerenciadorGrafico::desenhaBackground(sf::Drawable* pObjeto)
	{
		if (pObjeto) {
			janela.draw(*pObjeto);
		}
	}
   
}