#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include "../include/carta.h"
#include "../include/mao.h"
#include "../include/computador.h"
#include "../include/jogo.h"
#include "../include/pessoa.h"

using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    system("clear");
    /*
        peso:
            4 = 1;
            5 = 2;
            6 = 3;
            7 = 4;
            Q = 5;
            J = 6;
            K = 7;
            A = 8;
            2 = 9;
            3 = 10;
            7 OUROS = 11;
            ESPADILHA = 12;
            7 COPAS = 13;
            ZAP = 14;

    Mao m = Mao();
    list<Carta> :: iterator it;
    for(it = m._cartas.begin(); it != m._cartas.end(); it++){
        cout << "Carta:" << it->get_nome() << " " << it->get_naipe() << endl;
        cout << "Valor:" << it->get_peso() << endl;
    }
    Computador c = Computador("PC 1", m, 1);
    */

    int opcao;
    string nome;

    cout << "*******************************************"<<endl;
        cout<<"\t\t TRUCÃO MALADO "<<endl;
        cout<<" Menu: "<<endl;
        cout<<" 1 - Iniciar Jogo"<<endl;
        cout<<" 2 - Carregar Jogo"<<endl;
        cout<<" 3 - Sair"<<endl;
    cin >> opcao;
    //Inicia o jogo atraves da opcao desejada
    Jogo j = Jogo(opcao);

    //Solicita o nome do jogador
    cout << "Digite seu nome: " << endl;
    cin >> nome;
    //Cria o jogador
    Pessoa p = Pessoa(nome);

    //Cria os computadores
    Computador c1 = Computador("PC 1", 2);
    Computador c2 = Computador("PC 2", 1);
    Computador c3 = Computador("PC 3", 2);

    //Cria as maos
    Mao m = Mao();
    p.receberMao(m);

    m = Mao();
    c1.receberMao(m);

    m = Mao();
    c2.receberMao(m);

    m = Mao();
    c3.receberMao(m);

    p.imprime_mao();
    //escolhe a primeira carta
    p.escolhe_carta(1);
    p.imprime_mao();
    p.escolhe_carta(1);
    p.imprime_mao();
    p.escolhe_carta(1);
    p.imprime_mao();

    return 0;
}
