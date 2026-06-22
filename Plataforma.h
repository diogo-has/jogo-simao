#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {

		private:
			float forcaFlutuacao;
			float altura;
		public:
			//Plataforma(float x, float y);

			Plataforma();

			~Plataforma();

			void executar();
			void obstaculizar(Personagens::Jogador* p);
			void obstaculizar(Personagens::Inimigo* i);
			void salvar();
			void salvarDataBuffer();
			void carregar(ifstream& arquivo);
			void setAltura(float a);

		};
	}
}
