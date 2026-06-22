#pragma once
#include "Entidade.h"
namespace Entidades {
	namespace Personagens {
		class Personagem:public Entidade {
		protected:
			int num_vidas;
			float friccao;
			bool noChao;

		public:
			Personagem();
			~Personagem();

			void salvarDataBuffer();
			void carregar(ifstream& arquivo);
			virtual void executar() = 0;
			virtual void salvar() = 0;
			virtual void mover() = 0;
			void setNoChao(const bool b);
			const float getVelX() const;
			const float getVelY() const;
			void tomarDano(const int d = 0);
			const int getVidas() const;
			void setVidas(const int v);
		};
	}
}

