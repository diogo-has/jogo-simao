#include "Formigueiro.h"

namespace Entidades {
	namespace Obstaculos {

		Formigueiro::Formigueiro() : Obstaculo(), dano(1), forcaFlutuacao(2000.f)
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
			aceleracao.y -= forcaFlutuacao;

			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
			velocidade += aceleracao * dt;
			posicao += velocidade * dt;
			sprite.setPosition(posicao);
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

		void Formigueiro::obstaculizar(Personagens::Inimigo* i) {
			// Não irá colidir com inimigos
		}

		void Formigueiro::salvar()
		{
			salvarDataBuffer();
		}

		void Formigueiro::salvarDataBuffer()
		{
			buffer << "formigueiro";

			Obstaculo::salvarDataBuffer();

			buffer << " " << dano << endl;
		}

		void Formigueiro::carregar(ifstream& arquivo) {
			Obstaculo::carregar(arquivo);

			arquivo >> dano;
		}
		
		
		
	}
}