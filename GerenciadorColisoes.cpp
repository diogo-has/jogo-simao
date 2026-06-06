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
			if (colidiuP1 && pJog1->podeColidir()) {
				pJog1->ativarCooldown();
				if (pJog1->getPosicao().y < (*it)->getPosicao().y) {
					pJog1->setVelocidadeY(-400.f);

					pJog1->setVelocidadeX((pJog1->getVelX() * -3.f));
				
				}
				else if (pJog1->getVelX() > 50 || pJog1->getVelX() < -50) {
					pJog1->setVelocidadeX((pJog1->getVelX()) * (-2.0));
					pJog1->setVelocidadeY(-200.0);
				}
				else {
					pJog1->setVelocidadeX((*it)->getVelX() * 2);
				}
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
		float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
		for (it = LOs.begin(); it != LOs.end(); it++) {
			bool colidiu = verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it));
			if (colidiu && pJog1->podeColidir()) {
				
				(*it)->obstaculizar(pJog1);
				pJog1->setVelocidadeX((pJog1->getVelX()) * (-2.0));
				pJog1->setVelocidadeY(-200.0);
				pJog1->ativarCooldown();
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

	void GerenciadorColisoes::tratarColisoesChao() {
		vector<Personagens::Inimigo*>::iterator it;
		for (it = LIs.begin(); it != LIs.end(); it++) {
			bool colidiuIni = verificarColisao(static_cast<Entidade*>(chao), static_cast<Entidade*>(*it));
			if (colidiuIni)
				chao->colidir(*it);
		}

		bool colidiuP1 = verificarColisao(static_cast<Entidade*>(chao), static_cast<Entidade*>(pJog1));
		if (colidiuP1) {
			chao->colidir(pJog1);
		}
		//bool colidiu = verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(chao));
		//if (colidiu) {
		//	chao->colidir(pJog1);
		//}
	}

	//void GerenciadorColisoes::tratarColisoesJogsChao() {
	//	bool colidiu = verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(chao));
	//	if (colidiu) {
	//		chao->executar
	//	}
	//}

	GerenciadorColisoes::GerenciadorColisoes() : LIs(), LOs(), LPs(), pJog1(nullptr), pJog2(nullptr)
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

	void GerenciadorColisoes::setChao(Chao* pc) {
		chao = pc;
	}

	void GerenciadorColisoes::executar()
	{
		tratarColisoesChao();
		tratarColisoesJogsInimigs();
		tratarColisoesJogsObstacs();
		tratarColisoesJogsProjeteis();
	}
	
	void GerenciadorColisoes::setJogadores(Personagens::Jogador* pj1, Personagens::Jogador* pj2) {
		pJog1 = pj1;
		pJog2 = pj2;
	}
	//void GerenciadorColisoes::setJogador(Personagens::Jogador* pj)
	//{
	//	pJog1 = pj;
	//}

	
	
}
