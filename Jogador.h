#pragma once
#include "Personagem.h"

#define JOGADOR_1 true
#define JOGADOR_2 false

namespace Entidades {
	namespace Personagens {
		class Inimigo;
		class Jogador:public Personagem {
		protected:
			int pontos;
			sf::Texture atacando;
			sf::Texture dano;
			bool pulando;
			float timer_pulo;
			float tempo_pulo;
			float timer_atk;
			float tempo_atk;
			float cooldown_colisao;
			float tempo_cooldown;
			sf::FloatRect hitbox;
			bool jog1;



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
			sf::FloatRect getHitbox() override;
			bool podeColidir();
			void ativarCooldown();
			void setJog(bool jog);
			int getPontos();
			
		};
	}
}


