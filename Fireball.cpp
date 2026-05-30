#include "Fireball.h"

namespace Entidades{
	Fireball::Fireball() : Entidade(), tamanho(1)
	{

	}
	Fireball::Fireball(int tam) : Entidade(), tamanho(tam)
	{

	}
	Fireball::~Fireball() 
	{

	}
	void Fireball::executar()
	{
		imagem.loadFromFile("sprites/FireballFinal.png"); //temporario
		sprite.setTexture(imagem);
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		sprite.setScale(4, 4);
		//sprite.setPosition(400.f, 400.f);
	}
	void Fireball::salvar()
	{

	}
	void Fireball::salvarDataBuffer()
	{

	}
}
