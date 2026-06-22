#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		Inimigo::Inimigo() :Personagem(), raiva(3)
		{
			//num_vidas = raiva;
		}

		Inimigo::~Inimigo()
		{
		}

		void Inimigo::sofrerDano(const int dano) {
			num_vidas -= dano;
			if (num_vidas <= 0)
				destruir();
		}

		void Inimigo::salvarDataBuffer() {
			Personagem::salvarDataBuffer();

			buffer << " " << raiva;
		}

		void Entidades::Personagens::Inimigo::carregar(ifstream& arquivo) {
			Personagem::carregar(arquivo);

			arquivo >> raiva;
		}

		void Inimigo::setRaiva(const int r)
		{
			raiva = r;
		}

	}
}


