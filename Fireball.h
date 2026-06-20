#pragma once
#include "Entidade.h"

namespace Entidades {
    class Boitata;
    class Fireball : public Entidade
    {
        protected:
            bool ativo;
            int tamanho;
            float timer_vida;
            float tempo_vida;
            Boitata* pBoitata;

        public:
            Fireball();
            ~Fireball();
            void executar();
            void salvar();//TODO
            void salvarDataBuffer();
            void setTamanho(int tam);
    };
}

