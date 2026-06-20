#include "Formigueiro.h"

namespace Entidades {
	namespace Obstaculos {

		Formigueiro::Formigueiro() : Obstaculo(), dano(1) 
		{ 
			danoso = true;
			imagem.loadFromFile("sprites/Formigueiro.png"); //temporario
			sprite.setTexture(imagem);
		}

		Formigueiro::~Formigueiro()
		{
		}

		void Formigueiro::executar()
		{

		}

		void Formigueiro::obstaculizar(Personagens::Jogador* p)
		{
			if (p->podeColidir() && danoso) {
				p->tomarDano(dano);
				p->ativarCooldown();
				p->setVelocidadeX((p->getVelX()) * (-2.0));
				p->setVelocidadeY(-200.0);
			}
			
		}

		void Formigueiro::salvar()
		{
		}

		void Formigueiro::salvarDataBuffer()
		{
		}
		
		
		
	}
}