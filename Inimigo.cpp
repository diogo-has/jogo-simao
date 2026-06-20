#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		Inimigo::Inimigo() :Personagem(), raiva(3)
		{
			num_vidas = raiva;
		}

		Inimigo::~Inimigo()
		{
		}

		void Inimigo::setRaiva(int r)
		{
			raiva = r;
		}

	}
}


