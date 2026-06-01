#pragma once
#include "Obstaculo.h"
#include "Jogador.h"
#include <iostream>

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {

			private:
				int altura;
			public:
				Plataforma(float x, float y) : Obstaculo(x, y) { 
					executar();
					sprite.setPosition( x, y);
				}
				Plataforma():Obstaculo(), altura(1) {}
				~Plataforma() {}
				void executar () {
					imagem.loadFromFile("sprites/plataforma.png"); //temporario
					sprite.setTexture(imagem);
					sprite.setOrigin(sprite.getGlobalBounds().width / 2.f , sprite.getLocalBounds().height /2.f);
					sprite.setScale(2, 2);
					//sprite.setPosition(400.f,550.f); //mudar depois
				
				}
				void obstaculizar( Personagens::Jogador* p) 
				{
					p->setNoChao(true);
					
					float topo =
						sprite.getPosition().y -
						sprite.getGlobalBounds().height / 2.f;

					float metadeJogador =
						(p->getSprite()->getGlobalBounds().height / 2.f ) - 15.f; // para o player ficar "dentro" da plataforma 15px

					float y = topo - metadeJogador;
					p->setAceleracaoY(0.f);
					p->setpulo(0.f);
					p->setPosicaoY(y);

					
					
				}
				void salvar(){}

		};
	}
}