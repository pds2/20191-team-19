#include <string>
#include <iostream>
#include "../include/computador.h"
#include "../include/mao.h"
#include "../include/mesa.h"

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

void Computador::jogar(Mesa m){
    int posicao = 0;
    int maior = -1;
    for (int i = 0; i < 4; i++){
            if(m.cartas[i] > maior){
                maior = m.cartas[i];
                posicao = i;
            }
    }
    if(this->_time == 2 && posicao == 0 || posicao == 2){
        list<Carta>::iterator it;
        int menor = INT16_MAX;
        string carta;
        for (it = this->_mao._cartas.begin(); it != this->_mao._cartas.end(); it++)
        {
            if(it->get_peso() < menor){
                menor = it->get_peso();
                carta = it->get_nome() + " " + it->get_naipe(); //MEXER AQUI
            }
        }
        cout << carta;
    }
    
}
