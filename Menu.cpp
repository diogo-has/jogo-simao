#include "Menu.h"
#include "MenuSelecao.h"

Menu::Menu() : Ente(), pJogo(NULL) {
	imagem.loadFromFile("sprites/jogar.png");
	sprite.setTexture(imagem);
	sprite.setTextureRect(sf::IntRect(0, 0, 408, 136));
	sprite.setPosition(225.f, 255.f);
}

Menu::Menu(Jogo* pj): psel(NULL),hitbox_jogar(248,224,320,105) //hitbox_opcoes(0.f, 0.f, 200.f, 200.f) {
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

void Menu::verificaclique()
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*pGG->getJanela());
	sf::Vector2f mundoPos = (*pGG->getJanela()).mapPixelToCoords(pixelPos);
	if (hitbox_jogar.contains(mundoPos) ){
		psel = new MenuSelecao(pJogo);
		pJogo->setAtual(1);
	}
}

void Menu::mostrarhitboxes()
{
	shape.setPosition(hitbox_jogar.left, hitbox_jogar.top);
	shape.setSize(sf::Vector2f(hitbox_jogar.width, hitbox_jogar.height));
	shape.setFillColor(sf::Color::Blue);
	pGG->getJanela()->draw(shape);
	
}

MenuSelecao* Menu::getpsel() const
{
	if (psel) {
		return psel;
	}
	return nullptr;
}

