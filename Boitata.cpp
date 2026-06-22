#include "Boitata.h"

namespace Entidades {
	namespace Personagens {
		Boitata::Boitata() : Inimigo(), inflamabilidade(raiva), timer_movimento(0.f), tempo_movimento(3.f) {
			num_vidas = 9;
			imagem.loadFromFile("sprites/Boitatafinal.png");
			friccao = 0.99f;
			sprite.setTexture(imagem);
			sprite.setTextureRect(sf::IntRect(0, 0, 64, 52));
			setEscala(2);
			calculaOrigemSprite();
			mudarDirecao(DIRECAO_ESQUERDA);
		}
		Boitata::~Boitata()
		{
		}
		void Boitata::executar()
		{
			inflamabilidade = raiva;

			//sprite.setPosition(400.f, 400.f);
			mover();
		}
		void Boitata::salvar()
		{
			salvarDataBuffer();
		}
		void Boitata::mover()
		{
			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
			timer_movimento += dt;
			aceleracao.x = 0.f;
			if (timer_movimento >= tempo_movimento) {
				bool direcao = getDirecao();
				aceleracao.x = 60000.f * (direcao ? 1 : -1);
				mudarDirecao(!direcao);
				timer_movimento = 0.f;
				
			}
			velocidade += aceleracao * dt;
			posicao += velocidade * dt;
			velocidade *= pow(1 - friccao, dt);
			sprite.setPosition(posicao);
		}
		void Boitata::danificar(Jogador* p)
		{
			p->tomarDano(1);
			p->ativarCooldown();
			p->setVelocidadeX((p->getVelX()) * (-2.f));
			p->setVelocidadeY(-200.0);
			velocidade.y = -2000.f;
		}
		void Boitata::salvarDataBuffer()
		{
			buffer << "boitata";

			Inimigo::salvarDataBuffer();

			buffer << " " << inflamabilidade
				<< " " << timer_movimento
				<< endl;

			// FIREBALL??????
		}
		void Boitata::carregar(ifstream& arquivo) {
			Inimigo::carregar(arquivo);

			arquivo >> inflamabilidade
				>> timer_movimento;
		}
		const int Boitata::getInflamabilidade() const
		{
			return inflamabilidade;
		}
		void Boitata::setFireball(Fireball* pfb) {
			pFireball = pfb;
		}
	}
}
