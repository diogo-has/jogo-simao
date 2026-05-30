#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		Personagem::Personagem(): velocidade(0.f, 0.f), aceleracao(0.f, 0.f), num_vidas(3) {
		}
		Personagem::~Personagem() {
		}
		void Personagem::salvarDataBuffer() {
		}
		void Personagem::setVelocidadeX(float vx) {
			velocidade.x = vx;
		}
		void Personagem::setVelocidadeY(float vy) {
			velocidade.y = vy;
		}
		void Personagem::setAceleracaoX(float ax) {
			aceleracao.x = ax;
		}
		void Personagem::setAceleracaoY(float ay) {
			aceleracao.y = ay;
		}
	}
}
