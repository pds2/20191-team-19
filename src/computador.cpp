#include <string>
#include <iostream>
#include "../include/computador.h"
#include "../include/mao.h"
#include "../include/mesa.h"

using namespace std;

Computador::Computador(string nome, int time, int id){
    this->_id = id;
    this->_nome = nome;
    this->_time = time;
}

void Computador::receberMao(Mao mao){
    this->_mao = mao;
    this->_pesoMao = this->_mao.calcularPeso();
}

int Computador::get_id(){
    return this->_id;
}

void Computador::pedirTruco() { }

bool Computador::revisarTruco() { }

Mao Computador::get_mao(){
    return this->_mao;
}

void Computador::jogaNaMesa(int id, string carta, int peso, Mesa m){
    cout << carta << endl;
    m.cartas[id] = peso;
}

void Computador::primeiroJogando(Mesa m){
    list<Carta>::iterator it = this->_mao._cartas.begin();
    string carta;
    int maior = INT16_MIN;
    for(it; it != this->_mao._cartas.end(); it++){
        if(it->get_peso() > maior){
            maior = it->get_peso();
            carta = it->get_nome() + " " + it->get_naipe();
        }
    }
    if(maior >=7 && maior <= 11)
        jogaNaMesa(this->_id, carta, maior, m);
    else
        jogaMenorCarta(m);
}

void Computador::jogar(Mesa m){
    int posicao = 0;
    int maior = INT16_MIN;
    //Procura pela maior carta na mesa
    for (int i = 0; i < 4; i++){
            if(m.cartas[i] > maior){
                maior = m.cartas[i];
                posicao = i;
            }
    }
    /*Verifica se e o primeiro a jogar*/
    if(maior == 0)
        primeiroJogando(m);
    /*Verifica se o parceiro de time possui a maior carta na mesa e joga a menor da mão*/
    else if(this->_time == 2 && posicao == 1 || posicao == 3)
        jogaMenorCarta(m);
    else if(this->_time == 1 && posicao == 0)
        jogaMenorCarta(m);
    /*Verifica se a maior carta pertence ao time adversario e joga a maior se possuir, se nao, a menor*/
    else if(this->_time == 2 && posicao == 0 || posicao == 2){
        cout << maior << " " << posicao << endl;
        jogaMaiorCarta(posicao, m);
    }
}

void Computador::jogaMenorCarta(Mesa m){
        //Procura a menor carta para jogar
        list<Carta>::iterator it = this->_mao._cartas.begin();
        int menor = INT16_MAX;
        string carta;
        for (it; it != this->_mao._cartas.end(); it++)
        {
            if(it->get_peso() < menor){
                menor = it->get_peso();
                carta = it->get_nome() + " " + it->get_naipe();
            }
        }
        //Joga a carta
        jogaNaMesa(this->_id, carta, menor, m);
        
}

void Computador::jogaMaiorCarta(int posicao, Mesa m){ //Nao ta funcionando 
    list<Carta>::iterator it = this->_mao._cartas.begin();
    string carta;
    int maior = INT16_MIN;
    for(it; it != this->_mao._cartas.end(); it++){
        if(it->get_peso() > m.cartas[posicao]){
            maior = it->get_peso();
            carta = it->get_nome() + " " + it->get_naipe();
        }
    }
    if(maior != 0){
        jogaNaMesa(this->_id, carta, maior, m);
    }else{
        jogaMenorCarta(m);
    }
}

void Computador::imprime_mao()
{
  //system("clear");
  list<Carta> :: iterator it;
  for(it = _mao._cartas.begin(); it != _mao._cartas.end(); it++){
      cout << "Carta:" << it->get_nome() << " " << it->get_naipe() << endl;
  }
}

