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
		float Personagem::getVelX() const
		{
			return velocidade.x;
		}
		float Personagem::getVelY() const
		{
			return velocidade.y;
		}
		void Personagem::tomarDano(int d)
		{
			num_vidas -= d;
		}
		int Personagem::getVidas() const
		{
			return num_vidas;
		}
		void Personagem::setVidas(int v)
		{
			num_vidas = v;
		}
	}
}
