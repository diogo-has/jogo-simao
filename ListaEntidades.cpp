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
		if (!pE) return;
		lista.incluir(pE);
	}

	void ListaEntidades::remover(Entidades::Entidade* pE) {
		if (!pE) return;
		lista.remover(pE);
	}

	void ListaEntidades::percorrer() {
		Lista<Entidades::Entidade>::Iterator<Entidades::Entidade> it = lista.begin();
		while (it != lista.end()) {
			Entidades::Entidade* ent = *it;
			if (!ent) {
				++it;
				continue;
			}

			if (!ent->getVivo()) {
				++it;
				lista.remover(ent);
				delete ent;
			}
			else {
				ent->gravitar();
				ent->executar();
				ent->desenhar();
				++it;
			}
		}
		//while (it != NULL) {
		//	(*it)->executar();
		//	(*it)->desenhar();
		//	++it;
		//}
	}

}
	
