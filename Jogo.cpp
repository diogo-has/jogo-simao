#include "Jogo.h"
#include "Menu.h"
#include "Plataforma.h"
#include "Formigueiro.h"
#include "ListaEntidades.h"
#include "Macaco.h"
#include "Cacador.h"
#include "Tronco.h"
#include "FasePrimeira.h"
#include <iostream>
using std::cout;
using std::endl;

using Entidades::Personagens::Jogador;

Jogo::Jogo() : gg(), pJog1(), atual(0) {
    Ente::setGG(&gg);
    listaEnt.incluir(static_cast<Entidades::Entidade*>(&pJog1));
    executar();
}

Jogo::~Jogo() {}

void Jogo::executar() {
    Menu menu(this);
    

           
    //temporario
    Fases::FasePrimeira fase1(&pJog1);
    //fase1.setJog(&pJog1);

    while (gg.janelaAberta()) {
        gg.atualizarDeltaTime();

        sf::Event evento;


        while (gg.getJanela()->pollEvent(evento)) {
            switch (evento.type) {
            case sf::Event::Closed:
                gg.getJanela()->close();
                break;
            case sf::Event::KeyPressed:
                switch (evento.key.code) {
                case sf::Keyboard::Escape:
                    gg.getJanela()->close();
                    break;
                case sf::Keyboard::Up:
                    pJog1.iniciarPulo();
                }
            }
        }
        pJog1.setAceleracaoX(0.f); // Reset de aceleração, melhor por em outro lugar
        //pJog1.setAceleracaoY(2000.f); // Implementacção porca de gravidade

        float velocidade = 2000.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            pJog1.setAceleracaoX(-velocidade);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            pJog1.setAceleracaoX(velocidade);
        // Implementação porca de pulo
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            //pJog1.setVelocidadeY(-500.f);
            pJog1.pular();
        else
            pJog1.setPulando(false);
        if (evento.type == sf::Event::MouseButtonPressed) {
            if (evento.mouseButton.button == sf::Mouse::Left) {
                menu.verificaclique();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            pJog1.atacar();

        if (pJog1.getPosicao().x >= gg.getBordaCamera(LADO_DIREITO) && pJog1.getDirecao() == DIRECAO_DIREITA)
            gg.transicaoCamera(1);
        if (pJog1.getPosicao().x <= gg.getBordaCamera(LADO_ESQUERDO) && pJog1.getDirecao() == DIRECAO_ESQUERDA)
            gg.transicaoCamera(-1);

        
        gg.limpar();
        switch (atual) {
            case 0:
                menu.executar();
                
                break;
            case 1:
                fase1.executar();
                //listaEnt.percorrer();
                break;
        }
        gg.mostrar();
    }
}

void Jogo::setAtual(short int a)
{
    if (a >= 0 && a <= 4) {

        
        //listaEnt.percorrer();
        

        atual = a;
    }
}



