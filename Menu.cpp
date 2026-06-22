#include "Menu.h"
#include "MenuSelecao.h"
#include "MenuRanking.h"

namespace Menus {
	Menu::Menu() : Ente(), pJogo(NULL) {
		imagem.loadFromFile("sprites/jogar.png");
		sprite.setTexture(imagem);
		sprite.setTextureRect(sf::IntRect(0, 0, 408, 136));
		sprite.setPosition(225.f, 255.f);
	}

	Menu::Menu(Jogo* pj) : psel(NULL), hitbox_jogar(248, 224, 320, 85), hitbox_carregar(248, 324, 320, 65), hitbox_ranking(248, 394, 320, 65) //hitbox_opcoes(0.f, 0.f, 200.f, 200.f) {
	{
		pJogo = pj;
		imagem.loadFromFile("sprites/menu.png");
		sprite.setTexture(imagem);
		sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));
		sprite.setPosition(0.f, 0.f);


	}
	Menu::~Menu() {

		pJogo = NULL;
		if (psel) {
			delete psel;
			psel = NULL;

		}
	}
	void Menu::executar() {


		desenhar();

	}

	void Menu::verificaclique() {
		sf::Vector2i pixelPos = sf::Mouse::getPosition(*pGG->getJanela());
		sf::Vector2f mundoPos = (*pGG->getJanela()).mapPixelToCoords(pixelPos);
		if (hitbox_jogar.contains(mundoPos)) {
			MenuSelecao* pMenuSel = new MenuSelecao(pJogo);
			psel = static_cast<Menu*>(pMenuSel);
			pJogo->setAtual(1);
		}
		if (hitbox_carregar.contains(mundoPos)) {
			cout << "Carregando jogo..." << endl;
			pJogo->carregarJogada();
		}
		if (hitbox_ranking.contains(mundoPos)) {
			cout << "Mostrar ranking" << endl;
			MenuRanking* pMenuRank = new MenuRanking(pJogo);
			psel = static_cast<Menu*>(pMenuRank);
			pJogo->setAtual(1);

		}
	}

	void Menu::mostrarhitboxes() {
		shape.setPosition(hitbox_jogar.left, hitbox_jogar.top);
		shape.setSize(sf::Vector2f(hitbox_jogar.width, hitbox_jogar.height));
		shape.setFillColor(sf::Color::Blue);
		pGG->getJanela()->draw(shape);

		shape_carregar.setPosition(hitbox_carregar.left, hitbox_carregar.top);
		shape_carregar.setSize(sf::Vector2f(hitbox_carregar.width, hitbox_carregar.height));
		shape_carregar.setFillColor(sf::Color::Red);
		pGG->getJanela()->draw(shape_carregar);

		shape_ranking.setPosition(hitbox_ranking.left, hitbox_ranking.top);
		shape_ranking.setSize(sf::Vector2f(hitbox_ranking.width, hitbox_ranking.height));
		shape_ranking.setFillColor(sf::Color::Green);
		pGG->getJanela()->draw(shape_ranking);
	}

	Menu* Menu::getpsel() const {
		if (psel) {
			return psel;
		}
		return nullptr;
	}

}