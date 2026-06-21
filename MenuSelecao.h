#pragma once
#include "Menu.h"
class MenuSelecao : public Menu
{
	private:
		int numbotoes;
		bool singleplayer;
		bool fase1;
		sf::FloatRect hitbox_players;
		sf::FloatRect hitbox_fase;
		sf::FloatRect hitbox_iniciar;
		sf::RectangleShape shapeplayers;
		sf::RectangleShape shapefase;
		sf::RectangleShape shapeiniciar;
		Jogo* pJogo;
	public:
		MenuSelecao(Jogo* pj);
		~MenuSelecao();
		void executar();
		void verificaclique();
		void mostrarhitboxes();
};

