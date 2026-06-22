#include "Tronco.h"

namespace Entidades {
    namespace Obstaculos {
        Tronco::Tronco() : Obstaculo(), tipo(0), imagem2(), forcaFlutuacao(2000.f)
        {
            imagem.loadFromFile("sprites/Tronco.png"); //temporario
            imagem2.loadFromFile("sprites/Troncobackground.png");
            sprite.setTexture(imagem);
            setEscala(2);
            calculaOrigemSprite();
            //sprite.setPosition(posicao);
            
        }
        Tronco::~Tronco()
        {
        }
        void Tronco::executar()
        {
            if (tipo == 0) {
                sprite.setTexture(imagem, true);
                sprite.setScale(2, 2);
                calculaOrigemSprite();
            }
            else {
                sprite.setTexture(imagem2, true);
                sprite.setScale(1, 1);
                calculaOrigemSprite();
            }
            aceleracao.y -= forcaFlutuacao;

            float dt = Gerenciadores::GerenciadorGrafico::getDeltaTime();
            velocidade += aceleracao * dt;
            posicao += velocidade * dt;
            sprite.setPosition(posicao);
        }
        void Tronco::obstaculizar(Personagens::Jogador* p)
        {
            float topoTronco= sprite.getGlobalBounds().top;
            float fundoTronco = topoTronco + sprite.getGlobalBounds().height;
            float esquerdaTronco = sprite.getGlobalBounds().left;
            float direitaTronco = esquerdaTronco + sprite.getGlobalBounds().width;

            if (p->getPosicao().y <= sprite.getGlobalBounds().top + 10) {
                p->setNoChao(true);
                p->setVelocidadeY(0.f);
                p->setPosicao({ p->getPosicao().x, topoTronco });
            }
            else if (p->getSprite()->getGlobalBounds().top >= fundoTronco - 10) {
                p->setPulando(false);
                p->setVelocidadeY(0.f);
                p->setPosicao({ p->getPosicao().x, (fundoTronco + p->getHitbox().height) });
            }
            else if (p->getPosicao().x < sprite.getPosition().x) {
                p->setPosicao({ (esquerdaTronco - p->getHitbox().width / 2), p->getPosicao().y });
            }
            else if (p->getPosicao().x > sprite.getPosition().x) {
                p->setPosicao({ (direitaTronco + p->getHitbox().width / 2), p->getPosicao().y });
            }
        }
        void Tronco::obstaculizar(Personagens::Inimigo* i) {
            // Não irá colidir com inimigos
        }
        void Tronco::salvar()
        {
            salvarDataBuffer();
        }
        void Tronco::salvarDataBuffer()
        {
            buffer << "tronco";

            Obstaculo::salvarDataBuffer();

            buffer << " " << tipo << endl;
        }
        void Tronco::carregar(ifstream& arquivo) {
            Obstaculo::carregar(arquivo);

            arquivo >> tipo;
        }
        void Tronco::setTipo(const int t)
        {
            tipo = t % 2;
        }
    }
}
