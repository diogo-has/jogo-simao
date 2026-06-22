#pragma once
#include "Entidade.h"

namespace Entidades {
    namespace Personagens {
        class Boitata;
        class Jogador;
    }
    class Fireball : public Entidade
    {
        protected:
            bool ativo;
            int tamanho;
            float timer_vida;
            float tempo_vida;
            Personagens::Boitata* pBoitata;

        public:
            Fireball();
            ~Fireball();
            void executar();
            void salvar();
            void salvarDataBuffer();
            void colidir(Personagens::Jogador* pJog);
            void carregar(ifstream& arquivo);
            void setTamanho(int tam);
            void setBoitata(Personagens::Boitata* pb);
    };
}

