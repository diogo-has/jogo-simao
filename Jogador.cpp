#include "Jogador.h"
#include "Inimigo.h"
#include <math.h>
#define OFFSET_HITBOX 80

namespace Entidades {
	namespace Personagens {
		Jogador::Jogador() : tempo_pulo(.4f), timer_pulo(tempo_pulo), tempo_atk(.7f), timer_atk(tempo_atk), cooldown_colisao(0.f), tempo_cooldown(1.f), jog1(true), pontos(0) {
			num_vidas = 3;
			friccao = 0.99f;
			imagem.loadFromFile("sprites/p1.png");
			atacando.loadFromFile("sprites/p1_atk.png");
			dano.loadFromFile("sprites/p1damage.png");
			sprite.setTexture(imagem);

			calculaOrigemSprite();

			posicao = { 30.f, 30.f };
			sprite.setPosition(posicao);

			hitbox.height = sprite.getGlobalBounds().height;
			hitbox.width = sprite.getGlobalBounds().width - OFFSET_HITBOX;
		}
		Jogador::~Jogador() {
		}
		void Jogador::colidir(Inimigo* pIn) {
			if (cooldown_colisao <= 0.f) {
				if (timer_atk < tempo_atk) {
					pIn->sofrerDano(3);
					pontos += 10;
					cout << pontos << endl;
					timer_atk = tempo_atk;
					return;
				}
				ativarCooldown();
				if (num_vidas > 0) {
					pIn->danificar(this);
				}
				if (posicao.y < pIn->getPosicao().y) {
					velocidade.x *= -3.f;
					velocidade.y = -400.f;
		
				}
				else if (std::abs(velocidade.x) > 50) {
					velocidade.x *= -2.f;
					velocidade.y = -200.f;
				}
				else {
					velocidade.x *= 2.f;
				}
			}
		}
		void Jogador::executar() {
			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
			if (timer_atk < tempo_atk) {
				timer_atk += dt;
				sprite.setTexture(atacando, true);
				hitbox.width = sprite.getGlobalBounds().width - OFFSET_HITBOX/2;
			} else {
				sprite.setTexture(imagem, true);
				hitbox.width = sprite.getGlobalBounds().width - OFFSET_HITBOX;
			}

			mover();
			if (velocidade.y > 0)
				noChao = false;

			hitbox.left = sprite.getGlobalBounds().left + (OFFSET_HITBOX / 2);
			hitbox.top = sprite.getGlobalBounds().top;

			if (cooldown_colisao > 0.f)
			{
				cooldown_colisao -= dt;
			}
			if (!podeColidir()) {
				sprite.setTexture(dano);
			}
			if (cooldown_colisao <= 0.5f && cooldown_colisao > 0.f) { //temporario?
				sprite.setTexture(imagem);
			}
			
		}
		void Jogador::salvar() {
			salvarDataBuffer();
		}
		void Jogador::salvarDataBuffer() {
			//buffer << (jog1 ? "jogador1" : "jogador2");
			Personagem::salvarDataBuffer();

			buffer << " " << pontos
				<< " " << pulando
				<< " " << timer_pulo
				<< " " << timer_atk
				<< " " << cooldown_colisao
				<< " " << jog1
				<< endl;
		}
		void Entidades::Personagens::Jogador::carregar(ifstream& arquivo) {
			Personagem::carregar(arquivo);

			arquivo >> pontos
				>> pulando
				>> timer_pulo
				>> timer_atk
				>> cooldown_colisao
				>> jog1;
		}
		void Jogador::mover() {
			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
			
			if (noChao)
			{
				timer_pulo = 0.f;
			}
			velocidade += aceleracao * dt;
			velocidade *= pow(1-friccao, dt);

			if (aceleracao.x > 0)
				mudarDirecao(DIRECAO_DIREITA);
			else if (aceleracao.x < 0)
				mudarDirecao(DIRECAO_ESQUERDA);

			

			posicao += velocidade * dt;

			if (posicao.x < 1.f)
				posicao.x = 1.f;
			sprite.setPosition(posicao);
		}
		void Jogador::iniciarPulo()
		{
			if (noChao && !pulando) {
				pulando = true;
				noChao = false;
				timer_pulo = 0.f;
				velocidade.y = -400.f;
			}
		}

		void Jogador::pular() {
			if (!pulando) return;

			float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();

			if (timer_pulo < tempo_pulo) {
				velocidade.y = -700.f;
				timer_pulo += dt;
			}
			else {
				pulando = false;
			}
		}

		void Jogador::setPulando(bool pulo) {
			pulando = pulo;
		}

		void Jogador::atacar() {
			timer_atk = 0.f;
		}

		sf::FloatRect Jogador::getHitbox() {
			return hitbox;
		}

		bool Jogador::podeColidir()
		{
			return cooldown_colisao <= 0.f;
		}

		void Jogador::ativarCooldown()
		{
			cooldown_colisao = tempo_cooldown;
		}

		void Jogador::setJog(bool jog) {
			if (jog) {
				imagem.loadFromFile("sprites/p1.png");
				atacando.loadFromFile("sprites/p1_atk.png");
				sprite.setTexture(imagem);
			}
			else {
				imagem.loadFromFile("sprites/p2.png");
				atacando.loadFromFile("sprites/p2_atk.png");
				sprite.setTexture(imagem);
			}
			jog1 = jog;

		}

		int Jogador::getPontos() {
			return pontos;
		}
		
	
	}
}