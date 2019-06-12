#include <string>
#include <iostream>
#include <stdlib.h>
#include "../include/pessoa.h"
#include "../include/mao.h"

using namespace std;

Pessoa::Pessoa(string nome)
{
  this->_nome = nome;
  this->_time = 1;
}

void Pessoa::receberMao(Mao &mao)
{
  this->_mao = mao;
  this->_pesoMao = this->_mao.calcularPeso();
}

void Pessoa::pedirTruco() {}

bool Pessoa::revisarTruco() {}

void Pessoa::jogarCoberta() {}

Mao Pessoa::get_mao()
{
  return this->_mao;
}

void Pessoa::imprime_mao()
{
  list<Carta>::iterator it;
  for (it = _mao._cartas.begin(); it != _mao._cartas.end(); it++)
  {
    cout << "Carta:" << it->get_nome() << " " << it->get_naipe() << endl;
  }
}

string Pessoa::escolhe_carta()
{
  int _num = 0;
  list<Carta>::iterator it = _mao._cartas.begin();
  cout << "1"
       << " - "
       << " " << it->get_nome() << " " << it->get_naipe() << endl;
  it++;
  cout << "2"
       << " - "
       << " " << it->get_nome() << " " << it->get_naipe() << endl;
  it++;
  cout << "3"
       << " - "
       << " " << it->get_nome() << " " << it->get_naipe() << endl;
  cout << " Escolha a carta: " << endl;
  cin >> _num;
  it = _mao._cartas.begin();
  advance(it, _num -1);
  cout << endl;
  cout << "Carta Escolhida:" << it->get_nome() << " " << it->get_naipe() << endl;
  string ap = it->get_nome() + it->get_naipe();
  _mao._cartas.erase(it);
  return ap;
}

string Pessoa::get_nome()
{
  return this->_nome;
}
int Pessoa::get_time()
{
  return this->_time;
}
