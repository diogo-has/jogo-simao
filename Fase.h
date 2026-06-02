#pragma once

#include "Ente.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"

// Professor sugeriu fazer a relação "fase - geren. col." ser bidirecional para fazer o tratamento do chão
// Chefão tem que atirar
namespace Fases {
	
	class Fase:public Ente {
	protected:
		Listas::ListaEntidades lista_ents;
		Gerenciadores::GerenciadorColisoes GC;

		//void criarInimFaceis();
		//void criarPlataformas();

		//chamar pela construtora
		virtual void criarInimigos() = 0;
		virtual void criarObstaculos() = 0;
		virtual void criarChao() = 0;
		
		void criarCenario();
		void criarBoitatas();

	public:
		Fase();
		~Fase();
		virtual void executar() = 0;
		void transicaoTela(int qnt);
		
	};
}