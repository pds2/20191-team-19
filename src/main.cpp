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
        NAIPES:
        "♥"
        "♦"
        "♣"
        "♠"
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

    cout << "*******************************************" << endl;
    cout << "\t\t TRUCÃO MALADO " << endl;
    cout << " Menu: " << endl;
    cout << " 1 - Iniciar Jogo" << endl;
    cout << " 2 - Carregar Jogo" << endl;
    cout << " 3 - Sair" << endl;
    cout << ">";
    cin >> opcao;

    //Inicia o jogo atraves da opcao desejada
    Jogo j = Jogo(opcao);
    int time = j.iniciarJogo();
    if(time){
        cout << "PARABÉNS, VOCÊ GANHOU!!";
    }else{
        cout << "TENTE NOVAMENTE MAIS TARDE";
    }
    
    
    // //Cria a mesa
    // Mesa mesa = Mesa();

    // //Cria o jogador
    // Pessoa p = Pessoa(j.get_nome());

    // //Cria os computadores
    // Computador c1 = Computador("PC 1", 2, 1);
    // Computador c2 = Computador("PC 2", 1, 2);
    // Computador c3 = Computador("PC 3", 2, 3);

    // //Cria as maos
    // Mao m = Mao(mesa);
    // p.receberMao(m);

    // m = Mao(mesa);
    // c1.receberMao(m);
    // cout << "MAO C1" << endl;
    // c1.imprime_mao();

    // cout << "" << endl;
    // cout << "" << endl;

    // m = Mao(mesa);
    // c2.receberMao(m);
    // cout << "MAO C2" << endl;
    // c2.imprime_mao();

    // cout << "" << endl;
    // cout << "" << endl;

    // m = Mao(mesa);
    // c3.receberMao(m);
    // cout << "MAO C3" << endl;
    // c3.imprime_mao();

    // cout << "" << endl;
    // cout << "" << endl;
    // int i = 0;
    // while(i < 3){
    //     c1.jogar(mesa);
    //     mesa.imprime_mesa(p.get_nome(), c1.get_nome(), c2.get_nome(), c3.get_nome());
    //     cout << endl;
    //     c2.jogar(mesa);
    //     mesa.imprime_mesa(p.get_nome(), c1.get_nome(), c2.get_nome(), c3.get_nome());
    //     cout << endl;
    //     c3.jogar(mesa);
    //     mesa.imprime_mesa(p.get_nome(), c1.get_nome(), c2.get_nome(), c3.get_nome());
    //     cout << endl;

    //     string c = p.escolhe_carta();
    //     mesa.imprime_mesa(p.get_nome(), c1.get_nome(), c2.get_nome(), c3.get_nome(), c);

    //     cout << endl;
    //     c1.imprime_mao();
    //     c2.imprime_mao();
    //     c3.imprime_mao();
    //     p.imprime_mao();
    //     cout << endl;

    //     int time = 1;
    //     if (time == 1)
    //         j.set_pntTimeA(mesa.valorRodada);
    //     else
    //         j.set_pntTimeB(mesa.valorRodada);
    //     mesa.limpaMesa();
    //     cout  << "teste";
    //     i++;
    // }
    // /*
    // p.imprime_mao();
    // //escolhe a primeira carta
    // p.escolhe_carta(1);
    // p.imprime_mao();
    // p.escolhe_carta(1);
    // p.imprime_mao();
    // p.escolhe_carta(1);
    // p.imprime_mao();
    // */
    return 0;
}
