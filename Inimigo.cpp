#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		Inimigo::Inimigo() :Personagem(), raiva(cont)
		{
			num_vidas += raiva;
			cont++;
		}
		int Inimigo::cont(0);
		Inimigo::~Inimigo()
		{
		}
	}
}


