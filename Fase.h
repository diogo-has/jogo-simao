#pragma once

#include "Inimigo.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "Plataforma.h"

#include <ostream>
#include <fstream>

using std::ostream;
using std::ifstream;

// Professor sugeriu fazer a relação "fase - geren. col." ser bidirecional para fazer o tratamento do chão
// Chefão tem que atirar
class Jogo;
namespace Fases {
	
	class Fase:public Ente {
	private:
		const int maxMacacos;
		const int maxPlataformas;
		vector<Entidades::Obstaculos::Plataforma*> LPs;

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
		virtual void carregar(ifstream& arquivo) = 0;
		void encerrar(Personagens::Jogador* pJog1, Personagens::Jogador* pJog2 = nullptr);
		void removerJogadorDois(Personagens::Jogador* pJog);
		void atualizaHUDP1(const int vidas);
		void atualizaHUDP2(const int vidas);
		void salvar(ostream& arquivo);
		
	};
}