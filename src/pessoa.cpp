#include <string>
#include <iostream>
#include <stdlib.h>
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
void Pessoa::imprime_mao()
{
  system("clear");
  list<Carta> :: iterator it;
  for(it = _mao._cartas.begin(); it != _mao._cartas.end(); it++){
      cout << "Carta:" << it->get_nome() << " " << it->get_naipe() << endl;
      //cout << "Valor:" << it->get_peso() << endl;
  }
}
