#pragma once
#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {
        class Tronco : public Obstaculo
        {
            private:
                int tipo;
                sf::Texture imagem2;
            public:
                Tronco();
                ~Tronco();
                void executar();
                void obstaculizar(Personagens::Jogador* p);//TODO
                void salvar();//TODO
                void salvarDataBuffer();
                void setTipo(int t);
        };

    }
}

