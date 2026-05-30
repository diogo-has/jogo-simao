#include "Cacador.h"

namespace Entidades {
	namespace Personagens {
		Cacador::Cacador() : Inimigo(), maldade(rand()%4 + 1)
		{
		}
		Cacador::~Cacador()
		{
		}
		void Cacador::executar()
		{
			imagem.loadFromFile("sprites/cacadordefault.png"); //temporario
			sprite.setTexture(imagem);
			sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
			sprite.setScale(3, 3);
			sprite.setPosition(500.f, 400.f); //mudar depois
		}
		
		void Cacador::salvar()
		{
		}
		void Cacador::mover()
		{
		}
		void Cacador::danificar(Jogador* p)
		{
		}
		void Cacador::salvarDataBuffer()
		{
		}
	}
}