#pragma once
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Inimigo:public Personagem
		{
		protected:
			int raiva;

		public:
			Inimigo();
			~Inimigo();
			virtual void executar() = 0;
			virtual void danificar(Jogador* p) = 0;
			virtual void salvar() = 0;
			void sofrerDano(const int dano);
			void salvarDataBuffer();
			void carregar(ifstream& arquivo);
			void setRaiva(const int r);
		};
	}
}
