#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Formigueiro :public Obstaculo {
			private:
				int dano;
			public:
				Formigueiro(float x, float y);
				Formigueiro();
				~Formigueiro();
				void executar();
				void obstaculizar(Personagens::Jogador* p);
				void salvar();
				void salvarDataBuffer();

		};

	}

}