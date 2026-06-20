#include "MenuSelecao.h"

MenuSelecao::MenuSelecao(Jogo* pj): 
	Menu(pj), pJogo(pj), numbotoes(5), singleplayer(true), fase1(true), hitbox_players(52,143,700,60), hitbox_fase(52, 393,700,60), hitbox_iniciar(535,530,170,80)
{
	
	imagem.loadFromFile("sprites/selfase.png");
	sprite.setTexture(imagem);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));
	sprite.setPosition(0.f, 0.f);
}

MenuSelecao::~MenuSelecao()
{
}
void MenuSelecao::executar()
{
	
	desenhar();
}

void MenuSelecao::verificarhitboxes()
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*pGG->getJanela());
	sf::Vector2f mundoPos = (*pGG->getJanela()).mapPixelToCoords(pixelPos);
	if (hitbox_players.contains(mundoPos)) {
		singleplayer = !singleplayer;
		if (fase1 && singleplayer) {
			imagem.loadFromFile("sprites/selfase.png");
			sprite.setTexture(imagem);
		}
		else if (!fase1 && singleplayer) {
			imagem.loadFromFile("sprites/selfase-2-1.png");
			sprite.setTexture(imagem);
		}
		else if (fase1 && !singleplayer) {
			imagem.loadFromFile("sprites/selfase-1-2.png");
			sprite.setTexture(imagem);
		}
		else if (!fase1 && !singleplayer) {
			imagem.loadFromFile("sprites/selfase-2-2.png");
			sprite.setTexture(imagem);
		}
	}
	if (hitbox_fase.contains(mundoPos)) {
		fase1 = !fase1;
		if (fase1 && singleplayer) {
			imagem.loadFromFile("sprites/selfase.png");
			sprite.setTexture(imagem);
		}
		else if (!fase1 && singleplayer) {
			imagem.loadFromFile("sprites/selfase-2-1.png");
			sprite.setTexture(imagem);
		}
		else if (fase1 && !singleplayer) {
			imagem.loadFromFile("sprites/selfase-1-2.png");
			sprite.setTexture(imagem);
		}
		else if (!fase1 && !singleplayer) {
			imagem.loadFromFile("sprites/selfase-2-2.png");
			sprite.setTexture(imagem);
		}
	}
	if (hitbox_iniciar.contains(mundoPos)) {
		if (singleplayer && fase1) {
			pJogo->setAtual(2);
		}
		else if (!singleplayer && fase1) {
			pJogo->setAtual(3);
		}
		else if (singleplayer && !fase1) {
			pJogo->setAtual(4);
		}
		else if (!singleplayer && !fase1) {
			pJogo->setAtual(5);
		}

		
	}
}
void MenuSelecao::mostrarhitboxes() 
{
	shapeplayers.setPosition(hitbox_players.left, hitbox_players.top);
	shapeplayers.setSize(sf::Vector2f(hitbox_players.width, hitbox_players.height));
	shapeplayers.setFillColor(sf::Color::Blue);
	shapefase.setPosition(hitbox_fase.left, hitbox_fase.top);
	shapefase.setSize(sf::Vector2f(hitbox_fase.width, hitbox_fase.height));
	shapefase.setFillColor(sf::Color::Blue);
	pGG->getJanela()->draw(shapeplayers);

	pGG->getJanela()->draw(shapefase);
}
