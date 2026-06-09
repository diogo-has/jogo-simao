#pragma once

#include "Inimigo.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"

// Professor sugeriu fazer a relação "fase - geren. col." ser bidirecional para fazer o tratamento do chão
// Chefão tem que atirar
namespace Fases {
	
	class Fase:public Ente {
	private:
		const int maxMacacos;
		const int maxPlataformas;

	protected:
		Listas::ListaEntidades lista_ents;
		Gerenciadores::GerenciadorColisoes GC;
		int tamanho;

		void criarMacacos();
		void criarPlataformas();

		//chamar pela construtora
		virtual void criarInimigos() = 0;
		virtual void criarObstaculos() = 0;
		virtual void criarChao() = 0;
		
		void criarCenario();

	public:
		Fase();
		~Fase();
		virtual void executar() = 0;
		void transicaoTela(int qnt);
		
	};
}