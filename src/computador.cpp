#include <string>
#include <iostream>
#include "../include/computador.h"
#include "../include/mao.h"

using namespace std;

Computador::Computador(string nome, int time){
    this->_nome = nome;
    this->_time = time;
}

void Computador::receberMao(Mao mao){
    this->_mao = mao;
    this->_pesoMao = this->_mao.calcularPeso();
}

void Computador::pedirTruco() { }

bool Computador::revisarTruco() { }

Mao Computador::get_mao(){
    return this->_mao;
}
