#include "Jogo.h"
#include "Menu.h"
#include "Plataforma.h"
#include "Formigueiro.h"
#include "ListaEntidades.h"
#include "Macaco.h"
#include "Cacador.h"
#include "Tronco.h"
#include "MenuSelecao.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>


using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::string;

using Entidades::Personagens::Jogador;
 
void Jogo::inserirRanking(const string nome, const int pontos) {
    struct JogadorRanking {
        int pontuacao;
        string nome;
    };

    vector<JogadorRanking> ranking;

    std::ifstream arquivoLeitura("rankFile.dat");
    if (arquivoLeitura.is_open()) {
        JogadorRanking j;
        while (arquivoLeitura >> j.pontuacao) {
            arquivoLeitura >> std::ws;
            std::getline(arquivoLeitura, j.nome);
            ranking.push_back(j);
        }
        arquivoLeitura.close();
    }

    auto it = ranking.begin();
    while (it != ranking.end() && it->pontuacao >= pontos) {
        ++it;
    }

    ranking.insert(it, { pontos, nome });

    ofstream arquivoEscrita("rankFile.dat");
    for (const auto& jog : ranking) {
        arquivoEscrita << jog.pontuacao << " " << jog.nome << "\n";
    }
    arquivoEscrita.close();
}

void Jogo::salvarJogada() {
    ofstream saveFile("saveFile.dat");
    if (pFase1) {
        saveFile << "fase1 ";
        pFase1->salvar(saveFile);
    }
    else if (pFase2) {
        saveFile << "fase2 ";
        pFase2->salvar(saveFile);
    }
    
    saveFile.close();
}

Jogo::Jogo() : gg(), pJog1(), pJog2(), atual(0), pFase1(nullptr), pFase2(nullptr), pausado(false) {
    cout << "Digite o nome do jogador: ";
    cin >> nomeJogador;
    std::srand(std::time(nullptr));
    Ente::setGG(&gg);
    fonte.loadFromFile("04b.ttf");

    textoPausa.setFont(fonte);
    textoPausa.setString("Jogo Pausado\n\nAperte [1] para salvar jogada\nAperte [2] para voltar ao menu\nAperte [ESC] para voltar ao jogo");
    textoPausa.setCharacterSize(28);
    textoPausa.setPosition(20.f, 20.f);
    textoPausa.setFillColor(sf::Color::Black);


    executar();
}

Jogo::~Jogo() {}

void Jogo::executar() {

    Menus::Menu menu(this);
    

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
                    if (pFase1 || pFase2)
                        pausado = !pausado;
                    break;
                case sf::Keyboard::Num1:
                    if (pausado)
                        salvarJogada();
                    break;
                case sf::Keyboard::Num2:
                    if (pausado) {
                        pausado = false;
                        pJog1.tomarDano(3);
                    }
                    break;
                case sf::Keyboard::Up:
                    pJog1.iniciarPulo();
                    break;
                case sf::Keyboard::W:
                    if (pJog2)
                        pJog2->iniciarPulo();
                    break;
                case sf::Keyboard::Slash:
                    if (pFase1 || pFase2)
                        pJog1.atacar();
                    break;
                case sf::Keyboard::V:
                    if ((pFase1 || pFase2) && pJog2)
                        pJog2->atacar();
                    break;
                }
            case sf::Event::MouseButtonPressed:
                if (evento.mouseButton.button == sf::Mouse::Left){
                    switch (atual) {
                    case 0:
                        menu.verificaclique();
                        break;
                    case 1:
                        menu.getpsel()->verificaclique();
                        break;
                    }
                }

            }
        }
        float velocidade = 2000.f;

        // Controles Jogador 1
        pJog1.setAceleracaoX(0.f);
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            pJog1.setAceleracaoX(-velocidade);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            pJog1.setAceleracaoX(velocidade);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            pJog1.pular();
        else
            pJog1.setPulando(false);

        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
        //    pJog1.atacar();

        // Controles Jogador 2
        if (pJog2) {
            pJog2->setAceleracaoX(0.f);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                pJog2->setAceleracaoX(-velocidade);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                pJog2->setAceleracaoX(velocidade);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                pJog2->pular();
            else
                pJog2->setPulando(false);

            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
            //    pJog2->atacar();

        }
        
        if (pJog1.getPosicao().x >= gg.getBordaCamera(LADO_DIREITO) && pJog1.getDirecao() == DIRECAO_DIREITA)
            gg.transicaoCamera(1);
        if (pJog1.getPosicao().x <= gg.getBordaCamera(LADO_ESQUERDO) && pJog1.getDirecao() == DIRECAO_ESQUERDA)
            gg.transicaoCamera(-1);

        if (pFase1 && pJog1.getPosicao().x >= 5600.f) {
            if (pJog2) {
                setAtual(5);
                pJog2->setPosicao({ 100.f, 100.f });
            }
            else
                setAtual(4);
            pJog1.setPosicao({ 100.f, 100.f });
            gg.resetCamera();
        }

        // Fim do jogo
        if (pFase2 && pJog1.getPosicao().x >= 5600.f) {
            cout << "GANHOU!!!" << endl;
            gg.resetCamera();
            setAtual(0);
            pJog1.setVidas(3); // temporario
            pJog1.setPosicao({ 20, 200 }); //temporario
            pJog1.setVelocidadeX(0);//temporario

            int pontos = pJog1.getPontos() + (pJog2 ? pJog2->getPontos() : 0);
            inserirRanking(nomeJogador, pontos);

            if (pJog2) {
                delete pJog2;
                pJog2 = nullptr;
            }
        }

            
        gg.limpar();
        if (!pausado) {

            switch (atual) {
                case 0:
                    //cout << "executando menu" << endl;
                    menu.executar();
                    //menu.mostrarhitboxes();
                
                    break;
                case 1:
                    menu.getpsel()->executar();
                    //menu.getpsel()->mostrarhitboxes();
                    break;
                case 2:
                    if (pJog1.getVidas() <= 0) {
                        cout << "indo para o menu" << endl;
                        gg.resetCamera();
                        setAtual(0);
                        pJog1.setVidas(3);
                        pJog1.setPosicao({ 20, 200 });
                        pJog1.setVelocidadeX(0);
                        pJog1.setPontos(0);
                        break;
                    }
                    pFase1->atualizaHUDP1(pJog1.getVidas());
                    pFase1->executar();
                    break;
                case 3:
                    if (pJog1.getVidas() <= 0) {
                        cout << "indo para o menu" << endl;
                        gg.resetCamera();
                        setAtual(0);
                        pJog1.setVidas(3);
                        pJog1.setPosicao({ 20, 200 });
                        pJog1.setVelocidadeX(0);
                        pJog1.setPontos(0);
                        delete pJog2;
                        pJog2 = nullptr;
                        break;
                    }
                    pFase1->atualizaHUDP1(pJog1.getVidas());
                    if (pJog2) {
                        pFase1->atualizaHUDP2(pJog2->getVidas());
                        if (pJog2->getVidas() <= 0) {
                            pFase1->encerrar(nullptr, pJog2);
                            pJog2 = nullptr;
                        }
                    }
                    pFase1->executar();
                    break;
                case 4:
                    if (pJog1.getVidas() <= 0) {
                        cout << "indo para o menu" << endl;
                        gg.resetCamera();
                        setAtual(0);
                        pJog1.setVidas(3);
                        pJog1.setPosicao({ 20, 200 });
                        pJog1.setVelocidadeX(0);
                        pJog1.setPontos(0);
                        break;
                    }
                    pFase2->atualizaHUDP1(pJog1.getVidas());
                    pFase2->executar();
                    break;
                case 5:
                    if (pJog1.getVidas() <= 0) {
                        cout << "indo para o menu" << endl;
                        gg.resetCamera();
                        setAtual(0);
                        pJog1.setVidas(3);
                        pJog1.setPosicao({ 20, 200 });
                        pJog1.setVelocidadeX(0);
                        pJog1.setPontos(0);
                        delete pJog2;
                        pJog2 = nullptr;
                        break;
                    }
                    pFase2->atualizaHUDP1(pJog1.getVidas());
                    if (pJog2) {
                        pFase2->atualizaHUDP2(pJog2->getVidas());
                        if (pJog2->getVidas() <= 0) {
                            pFase2->encerrar(nullptr, pJog2);
                            pJog2 = nullptr;
                        }
                    }
                    pFase2->executar();
                    break;

            }
        }
        else {
            gg.desenhaHUD(&textoPausa);
        }
        gg.mostrar();
    }
}

void Jogo::setAtual(const short int a)
{
    if (a >= 0 && a <= 6) {
        if (pFase1) {
            pFase1->encerrar(&pJog1, pJog2);
            
            delete pFase1;
            pFase1 = nullptr;
        }
        if (pFase2) {
            pFase2->encerrar(&pJog1, pJog2);
            delete pFase2;
            pFase2 = nullptr;
        }
        if (a == 2) {
            pFase1 = new Fases::FasePrimeira(&pJog1);
            //pJog1.setPosicao({ 100.f, 100.f });
        }
        if (a == 3) {
            if (!pJog2) {
                pJog2 = new Jogador;
                pJog2->setJog(JOGADOR_2);
            }
            pFase1 = new Fases::FasePrimeira(&pJog1, pJog2);
        }
        if (a == 4) {
            pFase2 = new Fases::FaseSegunda(&pJog1);
            //pJog1.setPosicao({ 100.f, 100.f });
        }
        if (a == 5) {
            if (!pJog2) {
                pJog2 = new Jogador;
                pJog2->setJog(JOGADOR_2);
            }
            pFase2 = new Fases::FaseSegunda(&pJog1, pJog2);
            //pJog1.setPosicao({ 100.f, 100.f });
        }
            
        
        //listaEnt.percorrer();
        

        atual = a;
    }
}

void Jogo::carregarJogada() {
    ifstream saveFile("saveFile.dat");

    string fase;
    bool singleplayer;

    if (!(saveFile >> fase >> singleplayer)) return;

    pJog1.carregar(saveFile);
    if (!singleplayer) {
        pJog2 = new Jogador;
        pJog2->setJog(JOGADOR_2);
        pJog2->carregar(saveFile);
    }
    if (fase == "fase1") {
        pFase1 = new Fases::FasePrimeira(&pJog1, pJog2, true);
        pFase1->carregar(saveFile);
        atual = singleplayer ? 2 : 3;
    }
    else if (fase == "fase2") {
        pFase2 = new Fases::FaseSegunda(&pJog1, pJog2, true);
        pFase2->carregar(saveFile);
        atual = singleplayer ? 4 : 5;
    }
    saveFile.close();
}



