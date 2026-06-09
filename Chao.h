#pragma once
#include "Entidade.h"
#include "Personagem.h"

namespace Entidades {
	class Chao :public Entidade {
	public:
		Chao();
		~Chao();

		void executar();
		void colidir(Personagens::Personagem* pP);
		void setTamanho(int tam);
		void salvar();
	};
}

