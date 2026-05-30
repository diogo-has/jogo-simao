#include "Boitata.h"

namespace Entidades {
	namespace Personagens {
		Boitata::Boitata() : Inimigo(), inflamabilidade(rand()%5 +1)
		{
		}
		Boitata::~Boitata()
		{
		}
		void Boitata::executar()
		{
			imagem.loadFromFile("sprites/DefaultBoitata1.png"); //temporario
			sprite.setTexture(imagem);
			sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			sprite.setScale(4, 4);
			//sprite.setPosition(400.f, 400.f);
		}
		void Boitata::salvar()
		{

		}
		void Boitata::mover()
		{

		}
		void Boitata::danificar(Jogador* p)
		{

		}
		void Boitata::lancarProjetil()
		{
			//new projetil(inflamabilidade)
			//projetil executar
		}
		void Boitata::salvarDataBuffer()
		{

		}
	}
}
