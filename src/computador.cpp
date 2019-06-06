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
    //Procura pela maior carta na mesa
    for (int i = 0; i < 4; i++){
            if(m.cartas[i] > maior){
                maior = m.cartas[i];
                posicao = i;
            }
    }
    /*Verifica se o computador que está jogando é do time 2(Computadores) 
    e se a maior carta é de um deles*/
    if(this->_time == 2 && posicao == 0 || posicao == 2){
        list<Carta>::iterator it;
        int menor = INT16_MAX;
        string carta;
        for (it = this->_mao._cartas.begin(); it != this->_mao._cartas.end(); it++)
        {
            //Procura a menor carta para jogar
            if(it->get_peso() < menor){
                menor = it->get_peso();
                carta = it->get_nome() + " " + it->get_naipe(); //MEXER AQUI
            }
        }
        //Imprime e adiciona na mesa
        cout << carta;
        if(posicao == 2) m[0] = menor : m[2] = menor;
    }
    
}
