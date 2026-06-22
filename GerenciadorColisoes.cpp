#include "GerenciadorColisoes.h"

namespace Gerenciadores {
	const bool GerenciadorColisoes::verificarColisao(Entidade* pe1, Entidade* pe2) const
	{
		if (!(pe1 && pe2)) return(false);
		// Talvez depois fazer sistema de hitbox melhor
		//sf::FloatRect hitbox1 = pe1->getSprite()->getGlobalBounds();
		//sf::FloatRect hitbox2 = pe2->getSprite()->getGlobalBounds();
		sf::FloatRect hitbox1 = pe1->getHitbox();
		sf::FloatRect hitbox2 = pe2->getHitbox();

		return hitbox1.intersects(hitbox2);
	}

	void GerenciadorColisoes::tratarColisoesJogsInimigs()
	{
		vector<Personagens::Inimigo*>::iterator it;
		for (it = LIs.begin(); it != LIs.end(); ) {
			bool colidiuP1 = verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it));
			if (colidiuP1) {
				pJog1->colidir(*it);
			}
			if (pJog2) {
				bool colidiuP2 = verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it));
				if (colidiuP2) {
					pJog2->colidir(*it);
				}
			}
			if (!(*it)->getVivo())
				it = LIs.erase(it);
			else
				it++;
		}
	}

	void GerenciadorColisoes::tratarColisoesJogsObstacs()
	{
		list<Obstaculos::Obstaculo*>::iterator it;
		float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
		for (it = LOs.begin(); it != LOs.end(); it++) {
			bool colidiu = verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it));
			if (colidiu) {
				(*it)->obstaculizar(pJog1);
			}
			if (pJog2) {
				bool colidiuP2 = verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it));
				if (colidiuP2) {
					(*it)->obstaculizar(pJog2);
				}
			}
		}
	}

	void GerenciadorColisoes::tratarColisoesInimigsObstacs() {
		std::vector<Personagens::Inimigo*>::iterator itIni;
		std::list<Obstaculos::Obstaculo*>::iterator itObs;

		for (itIni = LIs.begin(); itIni != LIs.end(); itIni++) {
			for (itObs = LOs.begin(); itObs != LOs.end(); itObs++) {

				bool colidiu = verificarColisao(
					static_cast<Entidade*>(*itIni),
					static_cast<Entidade*>(*itObs)
				);

				if (colidiu) {
					(*itObs)->obstaculizar(*itIni);
				}
			}
		}
	}

	void GerenciadorColisoes::tratarColisoesJogsProjeteis()
	{
		set<Fireball*>::iterator it;
		for (it = LPs.begin(); it != LPs.end(); ) {
			bool colidiu = verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it));
			if (colidiu) {
				(*it)->colidir(pJog1);
				(*it)->destruir();
			}
			if (pJog2) {
				bool colidiuP2 = verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it));
				if (colidiuP2) {
					(*it)->colidir(pJog2);
					(*it)->destruir();
				}
			}
			if (!(*it)->getVivo())
				it = LPs.erase(it);
			else
				it++;
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
		if (pJog2) {
			bool colidiuP2 = verificarColisao(static_cast<Entidade*>(chao), static_cast<Entidade*>(pJog2));
			if (colidiuP2) {
				chao->colidir(pJog2);
			}
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

	GerenciadorColisoes::GerenciadorColisoes() : LIs(), LOs(), LPs(), chao(nullptr), pJog1(nullptr), pJog2(nullptr)
	{
		LIs.clear();
		LOs.clear();
		LPs.clear();
		//...
	}

	GerenciadorColisoes::~GerenciadorColisoes()
	{

	}

	void GerenciadorColisoes::incluirInimigo(Personagens::Inimigo* pi)
	{
		LIs.push_back(pi);
	}

	void GerenciadorColisoes::removerInimigo(Personagens::Inimigo* pi) {
		//vector<Personagens::Inimigo*>::iterator it;
		//for (it = LIs.begin(); it != LIs.end(); ) {
		//	if (pi == *it) {
		//		it = LIs.erase(it)
		//	}
		//	else {
		//		it++;
		//	}
		//}
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
		tratarColisoesInimigsObstacs();

	}
	
	void Gerenciadores::GerenciadorColisoes::setJogador(int nJog, Personagens::Jogador* pJog) {
		if (nJog == 1) {
			pJog1 = pJog;
		}
		else if (nJog == 2) {
			pJog2 = pJog;
		}
	}
	//void GerenciadorColisoes::setJogador(Personagens::Jogador* pj)
	//{
	//	pJog1 = pj;
	//}

	
	
}
