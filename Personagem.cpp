#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		Personagem::Personagem(): Entidade(), num_vidas(3) {
			sofre_gravidade = true;
		}
		Personagem::~Personagem() {
		}
		void Personagem::salvarDataBuffer() {
		}
		void Personagem::setNoChao(bool b) {
			noChao = b;
		}
		void Personagem::setPosicao(sf::Vector2f pos) {
			posicao = pos;
			sprite.setPosition(posicao);
		}
		sf::Vector2f Personagem::getPosicao() {
			return posicao;
		}
	}
}
