#include "Boitata.h"

namespace Entidades {
	namespace Personagens {
		Boitata::Boitata() : Inimigo(), inflamabilidade(rand() % 5 + 1), timer_movimento(0.f), tempo_movimento(3.f) {
			imagem.loadFromFile("sprites/Boitatafinal.png");
			sprite.setTexture(imagem);
			sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
			setEscala(2);
			calculaOrigemSprite();
			velocidade.x = 100.f;
		}
		Boitata::~Boitata()
		{
		}
		void Boitata::executar()
		{
			
			//sprite.setPosition(400.f, 400.f);
			mover();
		}
		void Boitata::salvar()
		{

		}
		void Boitata::mover()
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
