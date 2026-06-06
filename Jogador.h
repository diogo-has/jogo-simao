#pragma once
#include "Personagem.h"
namespace Entidades {
	namespace Personagens {
		class Inimigo; //talvez mude pra include
		class Jogador:public Personagem {
		protected:
			int pontos; //talvez nem use?
			sf::Texture atacando;
			float timer_pulo;
			float tempo_pulo;
			float timer_atk;
			float tempo_atk;
			float cooldown_colisao;
			float tempo_cooldown;



		public:
			Jogador();
			~Jogador();
			void colidir(Inimigo* pIn);
			void executar();
			void salvar();		
			void mover();
			void pular();
			void setpulo(float t);
			void atacar();
			sf::FloatRect getHitbox();
			bool podeColidir();
			void ativarCooldown();
			
		};
	}
}


