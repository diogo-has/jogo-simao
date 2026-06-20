#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {

		private:
			int altura;
		public:
			//Plataforma(float x, float y);

			Plataforma();

			~Plataforma();

			void executar();
			void obstaculizar(Personagens::Jogador* p);
			void salvar();
			void setAltura(int a);

		};
	}
}
