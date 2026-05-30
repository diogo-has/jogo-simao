#pragma once
#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {
        class Tronco : public Obstaculo
        {
            private:
                int vida;
                int estagio; // 0: inteiro; 1: pouco quebrado; 2: muito quebrado; 3: quebrado (invisivel e sem colisao); talvez mudar visualmente para indicar os estagios?
                bool quebrado;
            public:
                Tronco();
                ~Tronco();
                void executar();
                void obstaculizar(Personagens::Jogador* p);//TODO
                void salvar();//TODO
                void salvarDataBuffer();
        };

    }
}

