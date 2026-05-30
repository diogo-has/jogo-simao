#include "Tronco.h"

namespace Entidades {
    namespace Obstaculos {
        Tronco::Tronco() : Obstaculo(), vida(3), estagio(0), quebrado(false)
        {
            
        }
        Tronco::~Tronco()
        {
        }
        void Tronco::executar()
        {
            imagem.loadFromFile("sprites/Tronco.png"); //temporario
            sprite.setTexture(imagem);
            sprite.setScale(2, 2);
            sprite.setPosition(400.f, 400.f); //mudar depois
        }
        void Tronco::obstaculizar(Personagens::Jogador* p)
        {
        }
        void Tronco::salvar()
        {
        }
        void Tronco::salvarDataBuffer()
        {
        }
    }
}
