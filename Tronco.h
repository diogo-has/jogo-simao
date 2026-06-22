#pragma once
#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {
        class Tronco : public Obstaculo
        {
            private:
                int tipo;
                sf::Texture imagem2;
                float forcaFlutuacao;
            public:
                Tronco();
                ~Tronco();
                void executar();
                void obstaculizar(Personagens::Jogador* p);
                void obstaculizar(Personagens::Inimigo* i);
                void salvar();
                void salvarDataBuffer();
                void carregar(ifstream& arquivo);
                void setTipo(int t);
        };

    }
}

