#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#define LARGURA_TELA 800
#define ALTURA_TELA 600

class Ente;
namespace Gerenciadores {
	class GerenciadorGrafico {
	private:
		sf::RenderWindow janela;
		sf::Clock clock;
		static float dt;

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
		void desenhaBackground(sf::Drawable* pObjeto);
	};
}

