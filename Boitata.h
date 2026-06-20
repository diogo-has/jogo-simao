#pragma once
#include "Inimigo.h"
#include "Fireball.h"

namespace Entidades {
	namespace Personagens {
		class Boitata :public Inimigo {
		private:
			int inflamabilidade; //determina o tamanho do projétil
			float timer_movimento;
			float tempo_movimento;
			Fireball* pFireball;

		public:
			Boitata();
			~Boitata();
			void executar();
			void salvar();
			void mover();
			void danificar(Jogador* p);
			void salvarDataBuffer();
			int getInflamabilidade();
		};
	}
}

