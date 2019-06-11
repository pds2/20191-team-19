#include "../include/jogo.h"
#include "../include/carta.h"
#include "../include/mao.h"
#include "../include/computador.h"
#include "../include/jogo.h"
#include "../include/pessoa.h"
#include "../include/mesa.h"
#include <iostream>

using namespace std;

Jogo::Jogo(int opcao){

    switch (opcao)
    {
    case 1:
        novoJogo();
        break;
    
    default:
        break;
    }

}

void Jogo::novoJogo(){
    this->_pntTimeA = 0;
    this->_pntTimeB = 0;
    
    //Solicita o nome do jogador
    cout << "Digite seu nome: ";
    cin >> this->_nome;
    cout << endl;
}

void Jogo::set_pntTimeA(int valor){
    this->_pntTimeA += valor;
}

void Jogo::set_pntTimeB(int valor){
    this->_pntTimeB += valor;
}

int Jogo::get_pntTimeA(){
    return this->_pntTimeA;
}

int Jogo::get_pntTimeB(){
    return this->_pntTimeB;
}

int Jogo::iniciarJogo(){
    //Cria a mesa
    Mesa mesa = Mesa();

    //Cria o jogador
    Pessoa p = Pessoa(this->get_nome());

    //Cria os computadores
    Computador c1 = Computador("PC 1", 2, 1);
    Computador c2 = Computador("PC 2", 1, 2);
    Computador c3 = Computador("PC 3", 2, 3);
    while(this->get_pntTimeA() != 12 && this->get_pntTimeB() != 12){
        iniciarRodada(mesa, p, c1, c2, c3);
    }
    if(get_pntTimeA() == 12){
        return 1;
    }else{
        return 2;
    }
}

void Jogo::iniciarRodada(Mesa& mesa, Pessoa& p, Computador& c1, Computador& c2, Computador& c3){
    int i = 0;
    while(i < 3){
        c1.jogar(mesa);
        mesa.imprime_mesa(p.get_nome(), c1.get_nome(), c2.get_nome(), c3.get_nome());
        cout << endl;
        c2.jogar(mesa);
        mesa.imprime_mesa(p.get_nome(), c1.get_nome(), c2.get_nome(), c3.get_nome());
        cout << endl;
        c3.jogar(mesa);
        mesa.imprime_mesa(p.get_nome(), c1.get_nome(), c2.get_nome(), c3.get_nome());
        cout << endl;

        string c = p.escolhe_carta();
        mesa.imprime_mesa(p.get_nome(), c1.get_nome(), c2.get_nome(), c3.get_nome(), c);

        cout << endl;
        c1.imprime_mao();
        c2.imprime_mao();
        c3.imprime_mao();
        p.imprime_mao();
        cout << endl;

        int time = 1;
        if (time == 1)
            this->set_pntTimeA(mesa.valorRodada);
        else
            this->set_pntTimeB(mesa.valorRodada);
        mesa.limpaMesa();
        cout  << "teste";
        i++;
    }
}

string Jogo::get_nome(){
    return this->_nome;
}
