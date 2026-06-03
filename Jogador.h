#pragma once
#include "Personagem.h"
namespace Entidades {
	namespace Personagens {
		class Inimigo; //talvez mude pra include
		class Jogador:public Personagem {
		protected:
			int pontos; //talvez nem use?
			sf::Texture atacando;
			bool pulando;
			float timer_pulo;
			float tempo_pulo;
			float timer_atk;
			float tempo_atk;



		public:
			Jogador();
			~Jogador();
			void colidir(Inimigo* pIn);
			void executar();
			void salvar();		
			void mover();
			void setPulando(bool pulo);
			void iniciarPulo();
			void pular();
			void atacar();
			
		};
	}
}


