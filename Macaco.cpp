#include "Macaco.h"

namespace Entidades {
	namespace Personagens {
		Macaco::Macaco():Inimigo(), tamanho(raiva)
		{
			
		}
		Macaco::~Macaco()
		{
		}
		void Macaco::executar()
		{
			imagem.loadFromFile("sprites/temp.png"); //temporario
			sprite.setTexture(imagem);
			sprite.setPosition(400.f, 400.f); //mudar depois
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
