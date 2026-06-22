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
		const bool getVivo() const;
		void mudarDirecao(const bool dir);
		const bool getDirecao() const;
		void setEscala(const float esc);
		ostream* getBuffer();
		void setVelocidadeX(const float vx);
		void setVelocidadeY(const float vy);
		void setAceleracaoX(const float ax);
		void setAceleracaoY(const float ay);
		void setPosicao(const sf::Vector2f pos);
		const sf::Vector2f getPosicao() const;
		const virtual sf::FloatRect getHitbox() const;
		
	};
}

