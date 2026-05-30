#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Boitata :public Inimigo
		{
		private:
			int inflamabilidade; //determina o tamanho do projétil
		public:
			Boitata();
			~Boitata();
			void executar();
			void salvar();
			void mover();
			void danificar(Jogador* p);
			void lancarProjetil();
			void salvarDataBuffer();
		};
	}
}

