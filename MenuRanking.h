#pragma once
#include "Menu.h"
class MenuRanking:public Menu {
private:
	Jogo* pJogo;
	sf::Text texto;
	sf::Font fonte;
public:
	MenuRanking(Jogo* pJ);
	~MenuRanking();
	void executar();
	void verificaclique();
};

