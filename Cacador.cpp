#include "Cacador.h"

namespace Entidades {
	namespace Personagens {
		Cacador::Cacador() : Inimigo(), maldade(rand()%5 + 1), timer_movimento(0.f), tempo_movimento(4.f)
		{
			imagem.loadFromFile("sprites/cacadordefault.png"); //temporario
			sprite.setTexture(imagem);
			sprite.setTextureRect(sf::IntRect(22, 5, 20, 50));
			setEscala(3);
			calculaOrigemSprite();
			velocidade.x = -100.f;
			mudarDirecao(DIRECAO_ESQUERDA);
		}
		Cacador::~Cacador()
		{
		}
		void Cacador::executar()
		{
			mover();
		}
		
		void Cacador::salvar()
		{
		}
		void Cacador::mover()
		{
			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
			timer_movimento += dt;
			if (timer_movimento >= tempo_movimento) {
				velocidade.x *= -1;
				mudarDirecao(!getDirecao());
				timer_movimento = 0.f;
			}

			velocidade += aceleracao * dt;
			posicao += velocidade * dt;
			sprite.setPosition(posicao);
		}
		void Cacador::danificar(Jogador* p)
		{
			p->tomarDano(maldade);
		}
		void Cacador::salvarDataBuffer()
		{
		}
		
	}
}