#pragma once
#include "Personagem.h"
namespace Entidades {
	namespace Personagens {
		class Inimigo; //talvez mude pra include
		class Jogador:public Personagem {
		protected:
			int pontos; //talvez nem use?
			bool noChao;
			float timerPulo;
			float tempoMaxPulo;


		public:
			Jogador();
			~Jogador();
			void colidir(Inimigo* pIn);
			void executar();
			void salvar();		
			void mover();
			void pular();
			void setNoChao(bool b);
			void setPosicaoY(float y);
			void setpulo(float t);
		};
	}
}


