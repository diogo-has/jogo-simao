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
			void setNoChao(bool b); //ver se é utilizado
			float getVelX() const;
			float getVelY() const;
			void tomarDano(int d = 0);
			int getVidas() const;
			void setVidas(int v); //nao sei se é permitido
		};
	}
}

