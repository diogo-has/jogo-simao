#pragma once
#include "Jogador.h"
#include "Inimigo.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo : public Entidade { 
			protected:
				bool danoso;
			public:
				Obstaculo();
				virtual ~Obstaculo();
				void salvarDataBuffer();
				void carregar(ifstream& arquivo);
				virtual void executar() = 0;
				virtual void salvar() = 0;
				virtual void obstaculizar(Personagens::Jogador* p) = 0;
				virtual void obstaculizar(Personagens::Inimigo* i) = 0;
				const bool getDanoso() const;
			
		};
	}
}