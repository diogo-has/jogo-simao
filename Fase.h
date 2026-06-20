#pragma once

#include "Inimigo.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"
#include "Jogador.h"

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
		int tipoChao;
		sf::Sprite background;
		sf::Texture tHUDp1;
		sf::Texture tHUDp2;
		sf::Sprite HUDp1;
		sf::Sprite HUDp2;
		bool singleplayer;

		void criarMacacos();
		void criarPlataformas();

		//chamar pela construtora
		virtual void criarInimigos() = 0;
		virtual void criarObstaculos() = 0;
		
		void criarCenario();

	public:
		Fase();
		~Fase();
		virtual void executar() = 0;
		void transicaoTela(int qnt);
		void encerrar(Personagens::Jogador* pJog1, Personagens::Jogador* pJog2 = nullptr);
		void removerJogadorDois(Personagens::Jogador* pJog);
		void atualizaHUDP1(int vidas);
		void atualizaHUDP2(int vidas);
		
	};
}