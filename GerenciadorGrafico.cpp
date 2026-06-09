#include "GerenciadorGrafico.h"
#include "Ente.h"


namespace Gerenciadores {
	void GerenciadorGrafico::moverCamera() {
		if (!camera_movendo) return;

		camera_alpha += camera_velocidade * dt;

		if (camera_alpha >= 1.0f) {
			camera_alpha = 1.0f;
			camera.setCenter(camera_destino);
			camera_movendo = false;
			return;
		}

		//float alphaSuave = 3.f * std::pow(camera_alpha, 2) - 2.f * std::pow(camera_alpha, 3);
		float alphaSuave = 6.f * std::pow(camera_alpha, 5) - 15.f * std::pow(camera_alpha, 4) + 10.f * std::pow(camera_alpha, 3);

		sf::Vector2f novaPosicao = camera_inicio + alphaSuave * (camera_destino - camera_inicio);

		camera.setCenter(novaPosicao);
	}

	GerenciadorGrafico::GerenciadorGrafico() :
		janela(sf::VideoMode(LARGURA_TELA, ALTURA_TELA), "Jogo Simão", sf::Style::Titlebar | sf::Style::Close),
		camera(sf::FloatRect(0.0f, 0.0f, LARGURA_TELA, ALTURA_TELA)),
		camera_movendo(false),
		camera_destino(0.f, ALTURA_TELA/2),
		camera_velocidade(0.f) {
		janela.setFramerateLimit(60);
	}
	float GerenciadorGrafico::dt(0.f);

	GerenciadorGrafico::~GerenciadorGrafico() {}


	void GerenciadorGrafico::limpar() {
		janela.clear(sf::Color::Cyan);
	}

	void GerenciadorGrafico::mostrar() {
		moverCamera();
		janela.setView(camera);
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

	void GerenciadorGrafico::desenhaHUD(sf::Drawable* pObjeto)
	{
		if (pObjeto) {
			janela.setView(janela.getDefaultView());

			janela.draw(*pObjeto);

			janela.setView(camera);
		}
	}

	void GerenciadorGrafico::transicaoCamera(int qnt) {
		if (camera_movendo) return;
		camera_inicio = camera.getCenter();
		camera_alpha = 0.0f;
		camera_destino.x = camera.getCenter().x + (LARGURA_TELA * qnt);
		camera_velocidade = 1.5f;
		camera_movendo = true;
	} //depois inplementar mov vertical da camera?

	float GerenciadorGrafico::getBordaCamera(bool lado) {
		if (lado == LADO_DIREITO)
			return camera.getCenter().x + LARGURA_TELA / 2;
		else
			return camera.getCenter().x - LARGURA_TELA / 2;
	}

	void GerenciadorGrafico::resetCamera()
	{
		//camera.setCenter({ 400,300 });
		camera_inicio = camera.getCenter();
		camera_alpha = 0.0f;
		camera_destino.x = 400;
		camera_velocidade = 5.f;
		camera_movendo = true;
	}
   
}