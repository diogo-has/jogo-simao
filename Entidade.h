#pragma once
#include "Ente.h"
#include <ostream>
#define MIN_RAND_ENTIDADES 3

namespace Entidades {
	class Entidade:public Ente {
	protected:
		sf::Vector2f posicao;
		sf::Vector2f velocidade;
		sf::Vector2f aceleracao;
		//std::ostream buffer;
		bool sofre_gravidade;
		bool ativo;
		void salvarDataBuffer();

	public:
		Entidade();
		virtual ~Entidade();

		virtual void executar() = 0;
		virtual void salvar() = 0;
		void gravitar();
		void destruir();
		bool getAtivo();
		virtual void setVelocidadeX(float vx);
		virtual void setVelocidadeY(float vy);
		virtual void setAceleracaoX(float ax);
		virtual void setAceleracaoY(float ay);
		void setPosicao(sf::Vector2f pos);
		sf::Vector2f getPosicao();
		virtual sf::FloatRect getHitbox();
		
	};
}

