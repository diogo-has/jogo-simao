#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Macaco:public Inimigo
		{
			private:
				int tamanho;
			public:
				Macaco();
				~Macaco();
				void executar();
				void salvar();
				void mover();
				void danificar(Jogador* p);
				void salvarDataBuffer();
		};
	}
}

