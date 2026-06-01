#include "ListaEntidades.h"
#include <iostream>


namespace Listas {
	ListaEntidades::ListaEntidades() : lista() {
		lista.limpar();
	}

	ListaEntidades::~ListaEntidades() {
		lista.limpar();
	}

	void ListaEntidades::incluir(Entidades::Entidade* pE) {
		lista.incluir(pE);
	}

	void ListaEntidades::percorrer() {
		Lista<Entidades::Entidade>::Iterator<Entidades::Entidade> it = lista.begin();
		while (it != NULL) {
			(*it)->executar();
			(*it)->desenhar();
			++it;
		}
	}
}
	
