#include "Macaco.h"

namespace Entidades {
	namespace Personagens {
		Macaco::Macaco():Inimigo(), tamanho(), timer_movimento(0.f), tempo_movimento(1.8f)
		{
			imagem.loadFromFile("sprites/evilmonkeydefault.png"); //temporario
			sprite.setTexture(imagem);
			//sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			tamanho = raiva;
			sprite.setPosition(0, 0);
			setEscala(tamanho);
			calculaOrigemSprite();
			velocidade.x = 100.f;
		}
		Macaco::~Macaco()
		{
			
		}
		void Macaco::executar()
		{
			tamanho = raiva;
			setEscala(tamanho);
			mover();
		}
		void Macaco::salvar()
		{
		}
		void Macaco::mover()
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
		void Macaco::danificar(Jogador* p)
		{
			p->tomarDano(1);
		}
		void Macaco::salvarDataBuffer()
		{
		}
	}
}
