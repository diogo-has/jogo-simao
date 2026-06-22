#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
using std::cout;
using std::endl;

#define LARGURA_TELA 800
#define ALTURA_TELA 600
#define LADO_DIREITO true
#define LADO_ESQUERDO false

class Ente;
namespace Gerenciadores {
	class GerenciadorGrafico {
	private:
		sf::RenderWindow janela;
		sf::View camera;
		sf::Clock clock;
		static float dt;
		
		bool camera_movendo;
		sf::Vector2f camera_inicio;
		sf::Vector2f camera_destino;
		float camera_alpha;
		float camera_velocidade;

		void moverCamera();

	public:
		GerenciadorGrafico();
		~GerenciadorGrafico();
		
		void limpar();
		void mostrar();
		bool janelaAberta();
		sf::RenderWindow* getJanela();
		void desenharEnte(Ente* pE);
		void atualizarDeltaTime();
		static float getDeltaTime();
		void desenhaAlheio(sf::Drawable* pObjeto);
		void desenhaHUD(sf::Drawable* pObjeto);
		void transicaoCamera(const int qnt);
		float getBordaCamera(const bool lado);
		void resetCamera();
	};
}

