#include <iostream>
#include <unistd.h>
#include "../include/jogo.h"
#include "../include/mesa.h"
#include "../include/pessoa.h"
#include "../include/computador.h"

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
    this->_quemComeca = 0;

    //Solicita o nome do jogador
    cout << "Digite seu nome: ";
    cin >> this->_nome;
    cout << endl;
}

string Jogo::get_nome(){
    return this->_nome;
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
    this->_mesa = Mesa();

    //Cria o jogador
    this->_p = Pessoa(this->get_nome());

    //Cria os computadores
    this->_c1 = Computador("PC 1", 2, 1);
    this->_c2 = Computador("PC 2", 1, 2);
    this->_c3 = Computador("PC 3", 2, 3);
    while(this->get_pntTimeA() != 12 && this->get_pntTimeB() != 12){
        iniciarRodada();
    }
    if(get_pntTimeA() == 12){
        return 1;
    }else{
        return 2;
    }
}

void Jogo::iniciarRodada(){
    this->_p.receberMao(this->_mesa);
    this->_c1.receberMao(this->_mesa);
    this->_c2.receberMao(this->_mesa);
    this->_c3.receberMao(this->_mesa);

    int i = 4;
    while(i > 1){
        system("clear");
        cout << "\tTIME A  " << this->get_pntTimeA() << "\tx\t" << this->get_pntTimeB() << "  TIME B" << endl;
        this->_c1.jogar(this->_mesa);
        this->_mesa.imprime_mesa(this->_p.get_nome(), this->_c1.get_nome(), this->_c2.get_nome(), this->_c3.get_nome(), i);
        sleep(5 + (rand() % 4));

        system("clear");
        cout << "\tTIME A  " << this->get_pntTimeA() << "\tx\t" << this->get_pntTimeB() << "  TIME B" << endl;
        this->_c2.jogar(this->_mesa);
        this->_mesa.imprime_mesa(this->_p.get_nome(), this->_c1.get_nome(), this->_c2.get_nome(), this->_c3.get_nome(), i);
        sleep(5 + (rand() % 4));

        system("clear");
        cout << "\tTIME A  " << this->get_pntTimeA() << "\tx\t" << this->get_pntTimeB() << "  TIME B" << endl;
        this->_c3.jogar(this->_mesa);
        this->_mesa.imprime_mesa(this->_p.get_nome(), this->_c1.get_nome(), this->_c2.get_nome(), this->_c3.get_nome(), i);
        sleep(5 + (rand() % 4));
        
        string carta = this->_p.escolhe_carta();
        system("clear");
        cout << "\tTIME A  " << this->get_pntTimeA() << "\tx\t" << this->get_pntTimeB() << "  TIME B" << endl;
        this->_mesa.imprime_mesa(this->_p.get_nome(), this->_c1.get_nome(), this->_c2.get_nome(), this->_c3.get_nome(), carta, i);
        sleep(1 + (rand() % 4));

        system("clear");
        int time = this->_mesa.verificaQuemGanhou();
        if (time == 0 || time == 2)
            this->set_pntTimeA(this->_mesa.valorRodada);
        else
            this->set_pntTimeB(this->_mesa.valorRodada);
        this->_mesa.limpaMesa();
        i--;
    }
}
