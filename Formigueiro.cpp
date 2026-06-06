#include "Formigueiro.h"

namespace Entidades {
	namespace Obstaculos {
		Formigueiro::Formigueiro(float x, float y) : Obstaculo(x, y), dano(1) 
		{ 
			danoso = true;
			imagem.loadFromFile("sprites/Formigueiro.png"); //temporario
			sprite.setTexture(imagem);
			sprite.setPosition(x, y);
		}

		Formigueiro::Formigueiro() : Obstaculo(), dano(1) 
		{ 
			danoso = true; 
		}

		Formigueiro::~Formigueiro()
		{
		}

		void Formigueiro::executar()
		{

		}

		void Formigueiro::obstaculizar(Personagens::Jogador* p)
		{
		}

		void Formigueiro::salvar()
		{
		}

		void Formigueiro::salvarDataBuffer()
		{
		}
		
		
		
	}
}