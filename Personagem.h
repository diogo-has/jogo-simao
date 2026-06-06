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
			virtual void executar() = 0;
			virtual void salvar() = 0;
			virtual void mover() = 0;
			void setNoChao(bool b);
			void setPosicao(sf::Vector2f pos);
			sf::Vector2f getPosicao();
			float getVelX() const;
			float getVelY() const;
		};
	}
}

