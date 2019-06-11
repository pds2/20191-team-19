#include "../include/jogo.h"
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

string Jogo::get_nome(){
    return this->_nome;
}
