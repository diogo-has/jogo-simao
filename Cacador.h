#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Cacador : public Inimigo
		{
			private:
				int maldade;
				float timer_movimento;
				float tempo_movimento;
				sf::FloatRect hitbox;
			public:
				Cacador();
				~Cacador();
				void executar();
				void salvar();
				void mover();
				void danificar(Jogador* p);
				void salvarDataBuffer();
				sf::FloatRect getHitbox();
		};
	}
}
