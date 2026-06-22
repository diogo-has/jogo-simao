#include "MenuRanking.h"
#include <fstream>
#include <string>

using std::ifstream;
using std::string;

namespace Menus {
	MenuRanking::MenuRanking(Jogo* pJ) : pJogo(pJ), texto() {
		imagem.loadFromFile("sprites/background.png");
		imagem.setRepeated(true);
		sprite.setTexture(imagem);
		sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));
		sprite.setPosition(0.f, 0.f);

		string rankStr;
		ifstream rankFile("rankFile.dat");
		for (int i = 0; i < 10; i++) {
			string pts;
			string nome;
			if (!(rankFile >> pts)) break;
			rankFile >> nome;
			rankStr += (nome + " ----------- " + pts + "pts\n");
		}


		fonte.loadFromFile("04b.ttf");

		texto.setFont(fonte);
		texto.setString("Ranking: \n\n" + rankStr + "\n\nClique para voltar");
		texto.setCharacterSize(24);
		texto.setPosition(20.f, 20.f);

	}

	MenuRanking::~MenuRanking() {
	}

	void MenuRanking::executar() {
		desenhar();
		pGG->desenhaAlheio(&texto);
	}

	void MenuRanking::verificaclique() {
		pJogo->setAtual(0);
		delete(this);
	}
}