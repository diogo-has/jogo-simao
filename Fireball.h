#pragma once
#include "Entidade.h"

namespace Entidades {
    class Fireball : public Entidade
    {
        protected:
            bool ativo;
            int tamanho;
        public:
            Fireball();
            Fireball(int tam = 1);
            ~Fireball();
            void executar();
            void salvar();//TODO
            void salvarDataBuffer();
    };
}

