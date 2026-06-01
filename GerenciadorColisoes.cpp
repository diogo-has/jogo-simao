#include "GerenciadorColisoes.h"

namespace Gerenciadores {
	const bool GerenciadorColisoes::verificarColisao(Entidade* pe1, Entidade* pe2) const
	{
		// Talvez depois fazer sistema de hitbox melhor
		sf::FloatRect hitbox1 = pe1->getSprite()->getGlobalBounds();
		sf::FloatRect hitbox2 = pe2->getSprite()->getGlobalBounds();

		return hitbox1.intersects(hitbox2);
	}

	void GerenciadorColisoes::tratarColisoesJogsInimigs()
	{
		vector<Personagens::Inimigo*>::iterator it;
		for (it = LIs.begin(); it != LIs.end(); it++) {
			bool colidiuP1 = verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it));
			if (colidiuP1) {
				//...
			}
			//bool colidiuP2 = verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it));
			//if (colidiuP2) {
			//	//...
			//}
		}
	}

	void GerenciadorColisoes::tratarColisoesJogsObstacs()
	{
		list<Obstaculos::Obstaculo*>::iterator it;
		for (it = LOs.begin(); it != LOs.end(); it++) {
			bool colidiu = verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it));
			if (colidiu) {
				(*it)->obstaculizar(pJog1);
				//...
			}
			//bool colidiuP2 = verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it));
			//if (colidiuP2) {
			//	//...
			//}
		}
	}

	void GerenciadorColisoes::tratarColisoesJogsProjeteis()
	{
		set<Fireball*>::iterator it;
		for (it = LPs.begin(); it != LPs.end(); it++) {
			bool colidiu = verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it));
			if (colidiu) {
				//...
			}
			//bool colidiuP2 = verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it));
			//if (colidiuP2) {
			//	//...
			//}
		}
	}

	GerenciadorColisoes::GerenciadorColisoes() : LIs(), LOs(), LPs(), pJog1(nullptr)
	{
		LIs.clear();
		LOs.clear();
		LPs.clear();
		//...
	}

	GerenciadorColisoes::~GerenciadorColisoes()
	{
		//...
	}

	void GerenciadorColisoes::incluirInimigo(Personagens::Inimigo* pi)
	{
		LIs.push_back(pi);
	}
	
	void GerenciadorColisoes::incluirObstaculo(Obstaculos::Obstaculo* po)
	{
		LOs.push_back(po);
	}

	void GerenciadorColisoes::incluirProjetil(Fireball* pp)
	{
		LPs.insert(pp);
	}

	void GerenciadorColisoes::executar()
	{
		tratarColisoesJogsInimigs();
		tratarColisoesJogsObstacs();
		tratarColisoesJogsProjeteis();
	}
	void GerenciadorColisoes::setJogador(Personagens::Jogador* pj)
	{
		pJog1 = pj;
	}

	
	
}
