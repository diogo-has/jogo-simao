#pragma once
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Inimigo:public Personagem
		{
		private:
			static int cont;

		protected:
			int raiva;

		public:
			Inimigo();
			~Inimigo();
			virtual void executar() = 0;
			virtual void danificar(Jogador* p) = 0;
			virtual void salvar() = 0;
			virtual void salvarDataBuffer() = 0;



		

		};
	}
}
