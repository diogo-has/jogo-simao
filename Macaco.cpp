#include "Macaco.h"

namespace Entidades {
	namespace Personagens {
		Macaco::Macaco():Inimigo(), tamanho(raiva)
		{
			imagem.loadFromFile("sprites/evilmonkeydefault.png"); //temporario
			sprite.setTexture(imagem);
			sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			sprite.setScale(4, 4);
			sprite.setPosition(400.f, 400.f);
		}
		Macaco::~Macaco()
		{
		}
		void Macaco::executar()
		{
			
		}
		void Macaco::salvar()
		{
		}
		void Macaco::mover()
		{
			//TODO
		}
		void Macaco::danificar(Jogador* p)
		{
			//TODO
		}
		void Macaco::salvarDataBuffer()
		{
		}
	}
}
