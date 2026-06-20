#pragma once
#include <list>
#include "Entidade.h"
#include "Lista.h"

namespace Listas {
	class ListaEntidades {
	private:
		Lista<Entidades::Entidade> lista;

	public:
		ListaEntidades();
		~ListaEntidades();
		void incluir(Entidades::Entidade* pE);
		void remover(Entidades::Entidade* pE);
		void percorrer();
	};
}

