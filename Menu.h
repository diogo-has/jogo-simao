#pragma once

#include "GerenciadorGrafico.h"
#include "Jogo.h"
#include "Ente.h"

class MenuSelecao;


class Menu : public Ente {

	private:
		Jogo* pJogo;
		sf::FloatRect hitbox_jogar;
		sf::RectangleShape shape;
		sf::FloatRect hitbox_carregar;
		sf::RectangleShape shape_carregar;
		sf::FloatRect hitbox_ranking;
		sf::RectangleShape shape_ranking;
	protected:
		Menu* psel; // temporario?
	public:
		Menu();
		Menu(Jogo* pj);
		~Menu();
		virtual void executar();
		virtual void verificaclique();
		void mostrarhitboxes();
		Menu* getpsel() const;
		
};