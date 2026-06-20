#include "Fireball.h"
#include "Boitata.h"

namespace Entidades{
	Fireball::Fireball() : Entidade(), tamanho(4), timer_vida(0.f), tempo_vida(0.8f)
	{
		imagem.loadFromFile("sprites/FireballFinal.png"); //temporario
		sprite.setTexture(imagem);
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
		setEscala(tamanho);
		sofre_gravidade = true;
	}
	Fireball::~Fireball() 
	{

	}
	void Fireball::executar()
	{
		float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
		timer_vida += dt;
		if (timer_vida >= tempo_vida) {
			vivo = false;
		}
		velocidade += aceleracao * dt;
		posicao += velocidade * dt;
		sprite.setPosition(posicao);
	}
	void Fireball::salvar()
	{

	}
	void Fireball::salvarDataBuffer()
	{

	}
	void Fireball::setTamanho(int tam)
	{
		setEscala(tam);
		tamanho = tam;

	}
}
