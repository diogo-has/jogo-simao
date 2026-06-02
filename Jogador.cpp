#include "Jogador.h"
#include <math.h>

namespace Entidades {
	namespace Personagens {
		Jogador::Jogador() : tempo_pulo(.4f), timer_pulo(tempo_pulo), tempo_atk(.7f), timer_atk(tempo_atk) {
			friccao = 0.99f;
			imagem.loadFromFile("sprites/p1.png"); //Mudar qnd botar p2
			atacando.loadFromFile("sprites/p1_atk.png");
			sprite.setTexture(imagem);

			calculaOrigemSprite();
		}
		Jogador::~Jogador() {
		}
		void Jogador::colidir(Inimigo* pIn) {
		}
		void Jogador::executar() {
			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
			if (timer_atk < tempo_atk) {
				timer_atk += dt;
				sprite.setTexture(atacando, true);
			} else {
				sprite.setTexture(imagem, true);
			}
			mover();
		}
		void Jogador::salvar() {
		}
		void Jogador::mover() {
			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();

			// Implementação porca de colisão com o chão, fazer melhor dps
			//if ((posicao.y + (sprite.getLocalBounds().height / 2.f) >= ALTURA_TELA)) {
			//	aceleracao.y = 0;
			//	posicao.y = ALTURA_TELA - (sprite.getLocalBounds().height / 2.f);
			//	timerPulo = 0.f;
			//}
			if (noChao)
			{
				timer_pulo = 0.f;
			}
			else {
				//velocidade.y += 100; //solucao temporaria para o jogador estar "dentro" da plataforma
			}
			velocidade += aceleracao * dt;
			velocidade *= pow(1-friccao, dt);

			if (aceleracao.x > 0)
				mudarDirecao(DIRECAO_DIREITA);
			else if (aceleracao.x < 0)
				mudarDirecao(DIRECAO_ESQUERDA);

			

			posicao += velocidade * dt;
			sprite.setPosition(posicao);
		}
		void Jogador::pular() {
			if (timer_pulo < tempo_pulo) {
				velocidade.y = -700.f;
				timer_pulo += Gerenciadores::GerenciadorGrafico::getDeltaTime();
				noChao = false;
			}
		}
		void Jogador::setpulo(float t)
		{
			timer_pulo = t;
		}
		void Jogador::atacar() {
			timer_atk = 0.f;
		}
	}
}