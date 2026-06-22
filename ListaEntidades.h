#pragma once
#include <list>
#include <ostream>
#include "Entidade.h"
#include "Lista.h"

using std::ostream;

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
		void salvar(ostream& arquivo);
	};
}

