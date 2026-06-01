#include "Jogador.h"
#include <math.h>

namespace Entidades {
	namespace Personagens {
		Jogador::Jogador(): timerPulo(1.f), tempoMaxPulo(.4f) {
			friccao = 0.99f;
		}
		Jogador::~Jogador() {
		}
		void Jogador::colidir(Inimigo* pIn) {
		}
		void Jogador::executar() {
			mover();
		}
		void Jogador::salvar() {
		}
		void Jogador::mover() {
			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();

			// Implementação porca de colisão com o chão, fazer melhor dps
			if ((posicao.y + (sprite.getLocalBounds().height / 2.f) >= ALTURA_TELA)) {
				aceleracao.y = 0;
				posicao.y = ALTURA_TELA - (sprite.getLocalBounds().height / 2.f);
				timerPulo = 0.f;
			}
			if (noChao)
			{
				timerPulo = 0.f;

			}
			else {
				velocidade.y += 100; //solucao temporaria para o jogador estar "dentro" da plataforma
			}
			velocidade += aceleracao * dt;
			velocidade *= pow(1-friccao, dt);

			if (aceleracao.x < 0)
				espelhar(true);
			else if (aceleracao.x > 0)
				espelhar(false);

			

			posicao += velocidade * dt;
			sprite.setPosition(posicao);
		}
		void Jogador::pular() {
			if (timerPulo <= tempoMaxPulo) {
				velocidade.y = -1000.f;
				timerPulo += Gerenciadores::GerenciadorGrafico::getDeltaTime();
				noChao = false;
			}
		}
		void Jogador::setNoChao(bool b)
		{
			noChao = b;
		}
		void Jogador::setPosicaoY(float y)
		{
			posicao.y = y;
		}
		void Jogador::setpulo(float t)
		{
			timerPulo = t;
		}
	}
}