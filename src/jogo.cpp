#include "../include/jogo.h"

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
    
    this->_valorRodada = 0;
    this->_pntTimeA = 0;
    this->_pntTimeB = 0;

}

void Jogo::set_valorRodada(int valor){
    this->_valorRodada += valor;
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

int Jogo::get_valorRodada(){
    return this->_valorRodada;
}
