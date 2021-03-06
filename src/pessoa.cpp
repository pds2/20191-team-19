#include <string>
#include <iostream>
#include <stdlib.h>
#include "../include/pessoa.h"
#include "../include/mao.h"

using namespace std;

Pessoa::Pessoa(){}

Pessoa::Pessoa(string nome)
{
  this->_nome = nome;
  this->_time = 1;
}

void Pessoa::receberMao(Mesa& mesa)
{
  Mao mao = Mao(mesa);
  this->_mao = mao;
  this->_pesoMao = this->_mao.calcularPeso();
}

void Pessoa::pedirTruco() {}

bool Pessoa::revisarTruco() {}

void Pessoa::jogarCoberta() {}

string Pessoa::get_nome()
{
  return this->_nome;
}

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
  string num_;
  int _num = 0, i;
  string carta;
  list<Carta>::iterator it = this->_mao._cartas.begin();
  if(this->_mao._cartas.size() != 0){
    for(it = this->_mao._cartas.begin(), i = 1; it != this->_mao._cartas.end(); it++, i++){
      cout << i
      << " - "
      << " " << it->get_nome() << " " << it->get_naipe() << endl;
    }

    while(true){
      try{
    cout << " Escolha a carta: " << endl;
    fflush(stdin);
            getline(cin, num_);
                     _num=atoi(num_.c_str());
                     if(_mao._cartas.size() == 3){
                       if(_num !=1 && _num != 2 && _num != 3)
                       {
                         throw "Entrada inválida.";
                       }else
                           break;
                         }
                           if(_mao._cartas.size()==2){
                             if(_num !=1 && _num != 2)
                             {
                               throw "Entrada inválida.";
                             }else
                                break;
                                }
                                if(_mao._cartas.size() == 1)
                                {
                                  if(_num !=1  )
                                  {
                                    throw "Entrada inválida.";
                                  }else
                                    break;
                                }
                 }catch(const char* e)
                 {
                      cout << "Erro: " << e <<endl;
                      cout << "Escolha uma entrada valida" << endl;
                 }
               }


    it = this->_mao._cartas.begin();
    advance(it, _num - 1);
    cout << endl;
    cout << "Carta Escolhida: " << it->get_nome() << " " << it->get_naipe() << endl;

    carta = it->get_nome() + it->get_naipe();
    this->_mao._cartas.erase(it);
  }
  return carta;
}
