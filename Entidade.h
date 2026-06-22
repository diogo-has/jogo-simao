#pragma once
#include "Ente.h"
#include <ostream>
#include <fstream>

#define MIN_RAND_ENTIDADES 3

using std::ostream;
using std::ifstream;


namespace Entidades {
	class Entidade:public Ente {
	protected:
		sf::Vector2f posicao;
		sf::Vector2f velocidade;
		sf::Vector2f aceleracao;
		ostream buffer;
		bool direcao;
		float escala;
		bool vivo;
		void salvarDataBuffer();
		void carregar(ifstream& arquivo);

	public:
		Entidade();
		virtual ~Entidade();

		virtual void executar() = 0;
		virtual void salvar() = 0;
		void gravitar();
		void destruir();
		bool getVivo();
		void mudarDirecao(bool dir);
		bool getDirecao();
		void setEscala(float esc);
		ostream* getBuffer();
		void setVelocidadeX(float vx);
		void setVelocidadeY(float vy);
		void setAceleracaoX(float ax);
		void setAceleracaoY(float ay);
		void setPosicao(sf::Vector2f pos);
		sf::Vector2f getPosicao();
		virtual sf::FloatRect getHitbox();
		
	};
}

