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

void Computador::receberMao(Mao& mao){
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

void Computador::jogaNaMesa(int id, string carta, int peso, Mesa& m){
    m.cartas[id] = peso;
}

void Computador::primeiroJogando(Mesa& m){
    list<Carta>::iterator it;
    string carta;
    int maior = 6;
    for(it = this->_mao._cartas.begin(); it != this->_mao._cartas.end(); it++){
        if((it->get_peso() > maior) && (it->get_peso() > 6) && (it->get_peso() < 12)){
            maior = it->get_peso();
            carta = it->get_nome() + it->get_naipe();
        }
    }
    if(maior == 6)
        jogaMenorCarta(m);
    else
        jogaNaMesa(this->_id, carta, maior, m);
    deletaCarta(maior, carta);

}

void Computador::jogar(Mesa& m){
    int posicao = 0;
    int maior = -100000;
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
    else if((this->_time == 2) && (posicao == 1 || posicao == 3))
        jogaMenorCarta(m);
    else if(this->_time == 1 && posicao == 0)
        jogaMenorCarta(m);
    /*Verifica se a maior carta pertence ao time adversario e joga a maior se possuir, se nao, a menor*/
    else if((this->_time == 2) && (posicao == 0 || posicao == 2)){
        jogaCartaMaior(posicao, m);
    }
    else if((this->_time == 1) && (posicao == 1 || posicao == 3)){
        jogaCartaMaior(posicao, m);
    }
}

void Computador::jogaMenorCarta(Mesa& m){
        //Procura a menor carta para jogar
        list<Carta>::iterator it;
        int menor = 100000;
        string carta;
        for (it = this->_mao._cartas.begin(); it != this->_mao._cartas.end(); it++)
        {
            if(it->get_peso() < menor){
                menor = it->get_peso();
                carta = it->get_nome() + it->get_naipe();
            }
        }
        //Joga a carta
        jogaNaMesa(this->_id, carta, menor, m);
        deletaCarta(menor, carta);

}

void Computador::jogaCartaMaior(int posicao, Mesa& m){ //Nao ta funcionando
    list<Carta>::iterator it;
    string carta;
    int maior = 10000;
    int diferenca;
    for(it = this->_mao._cartas.begin(); it != this->_mao._cartas.end(); it++){
        diferenca = it->get_peso() - m.cartas[posicao];
        if(diferenca > 0 && diferenca < maior - m.cartas[posicao]){
            maior = it->get_peso();
            carta = it->get_nome() + it->get_naipe();
        }
    }
    if(maior != 10000){
        jogaNaMesa(this->_id, carta, maior, m);
        deletaCarta(maior, carta);
    }else{
        jogaMenorCarta(m);
    }
}

void Computador::imprime_mao()
{
  //system("clear");
  list<Carta> :: iterator it;
  for(it = _mao._cartas.begin(); it != _mao._cartas.end(); it++){
    cout << "Carta: " << it->get_nome() << it->get_naipe() << endl;
  }
}

void Computador::deletaCarta(int peso, string carta){
    list<Carta> :: iterator it;
    string c;
    for(it = _mao._cartas.begin(); it != _mao._cartas.end(); it++){
        c = it->get_nome() + it->get_naipe();
        if(it->get_peso() == peso && carta == c){
        }
    }
    _mao._cartas.erase(it);
}

string Computador::get_nome(){
  return this->_nome;
}
int Computador::get_time()
{
  return this->_time;
}
