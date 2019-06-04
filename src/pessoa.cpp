#include <string>
#include <iostream>
#include "../include/pessoa.h"
#include "../include/mao.h"

using namespace std;

Pessoa::Pessoa(string nome){
    this->_nome = nome;
    this->_time = 1;
}

void Pessoa::receberMao(Mao mao){
    this->_mao = mao;
    this->_pesoMao = this->_mao.calcularPeso();
}

void Pessoa::pedirTruco() { }

bool Pessoa::revisarTruco() { }

void Pessoa::jogarCoberta() { }

Mao Pessoa::get_mao(){
    return this->_mao;
}
