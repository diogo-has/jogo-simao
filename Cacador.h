#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Cacador : public Inimigo
		{
			private:
				int maldade;
				float timer_movimento;
				float tempo_movimento;
			public:
				Cacador();
				~Cacador();
				void executar();
				void salvar();
				void salvarDataBuffer();
				void carregar(ifstream& arquivo);
				void mover();
				void danificar(Jogador* p);
		};
	}
}
