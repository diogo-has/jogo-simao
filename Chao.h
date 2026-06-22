#pragma once
#include "Entidade.h"
#include "Personagem.h"

namespace Entidades {
	class Chao :public Entidade {
	private:
		int tipo;
	public:
		Chao();
		~Chao();

		void executar();
		void colidir(Personagens::Personagem* pP);
		void setTamanho(const int tam);
		void salvar();
		void salvarDataBuffer();
		void carregar(ifstream& arquivo);
		void setTipo(const int tip);
	};
}

