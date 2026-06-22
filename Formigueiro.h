#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Formigueiro :public Obstaculo {
			private:
				int dano;
				float forcaFlutuacao;

			public:
				Formigueiro();
				~Formigueiro();
				void executar();
				void obstaculizar(Personagens::Jogador* p);
				void obstaculizar(Personagens::Inimigo* i);
				void salvar();
				void salvarDataBuffer();
				void carregar(ifstream& arquivo);

		};

	}

}