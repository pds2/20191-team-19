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
  //system("clear");
  list<Carta> :: iterator it;
  for(it = _mao._cartas.begin(); it != _mao._cartas.end(); it++){
      cout << "Carta:" << it->get_nome() << " " << it->get_naipe() << endl;
      //cout << "Valor:" << it->get_peso() << endl;
  }
}
void Pessoa::escolhe_carta()
{
  int _num=1,i;
  list<Carta> :: iterator ap = this->_mao._cartas.begin();
  cout<<" Escolha a carta: "<<endl;
  for(i=1,ap;ap!=_mao._cartas.end();ap++,i++)
  {
    cout<<" "<<i<<" - "<<" "<<ap->get_nome()<<" "<<ap->get_naipe()<<endl;
  }
  list<Carta> :: iterator it = this->_mao._cartas.begin();
  advance(it, _num - 1);
  cout<<endl;
  cout << "Carta Escolhida:" << it->get_nome() << " " << it->get_naipe() << endl;
  _mao._cartas.erase(it);
}
