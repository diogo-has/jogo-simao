#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		Personagem::Personagem(): Entidade(), num_vidas(3) {
		}
		Personagem::~Personagem() {
		}
		void Personagem::salvarDataBuffer() {
			Entidade::salvarDataBuffer();

			buffer << " " << num_vidas << " " << friccao << " " << noChao;
		}
		void Entidades::Personagens::Personagem::carregar(ifstream& arquivo) {
			Entidade::carregar(arquivo);

			arquivo >> num_vidas >> friccao >> noChao;
		}
		void Personagem::setNoChao(const bool b) {
			noChao = b;
		}
		const float Personagem::getVelX() const
		{
			return velocidade.x;
		}
		const float Personagem::getVelY() const
		{
			return velocidade.y;
		}
		void Personagem::tomarDano(const int d)
		{
			num_vidas -= d;
		}
		const int Personagem::getVidas() const
		{
			return num_vidas;
		}
		void Personagem::setVidas(const int v)
		{
			num_vidas = v;
		}
	}
}
