#include "../include/mesa.h"
#include "../include/carta.h"
#include <iostream>
#include <math.h>

using namespace std;

Mesa::Mesa(){
    for (int i = 0; i < 4; i++)
    {
        this->cartas[i] = 0;
    }
}

void Mesa::imprime_mesa(){
    int peso = 0;
    Carta c;

    int i = 2; peso = this->cartas[i]; c = recuperaCarta(i - 1/*Quando player funcionando, tirar o -1*/, peso);
    cout << "\t\t\t" << "   PC" << i << ":" << endl;
    cout << "\t\t\t" << c.get_nome() << c.get_naipe() << endl;
    cout << endl; cout << endl;

    i++; peso = this->cartas[i]; c = recuperaCarta(i - 1/*Quando player funcionando, tirar o -1*/, peso);
    cout << "    " << "PC" << i << ":  " << c.get_nome() << c.get_naipe();

    i = i -2; peso = this->cartas[i]; c = recuperaCarta(i - 1/*Quando player funcionando, tirar o -1*/, peso);
    cout << "\t\t        " << c.get_nome() << c.get_naipe() << "  :PC" << i;
    cout << endl; cout << endl;
}

Carta Mesa::recuperaCarta(int id, int peso){
    list<Carta>::iterator it = this->baralho.begin();
    Carta c;
    if(id != 0){
        advance(it, id + pow(2, id));
    }
    for(it; it != this->baralho.end(); it++){
        if(it->get_peso() == peso){
            c = *it;
            return c;
        }
    }
}

//Volta posição
int Mesa::verificaQuemGanhou(){
    int maior = -10000;
    int posicao;
    for (int i = 0; i < 4; i++)
    {
        if(maior < this->cartas[i])
            maior = this->cartas[i];
            posicao = i;
    }
    if(this->ganhouRodada[0] != 0 || this->ganhouRodada[0] != 0)
        return posicao;
    else if(posicao == 0 || posicao == 2)
        this->ganhouRodada[0]++;
    else
        this->ganhouRodada[1]++;
}

void Mesa::limpaMesa(){
    for(int i = 0; i < 4; i++){
        this->rodadaAnterior[i] = this->cartas[i];
        this->cartas[i] = 0;
        if(i < 2){
            this->ganhouRodada[i];
        }
    }

    list<Carta> :: iterator it;
    for(it = this->baralho.begin(); it != this->baralho.end(); it++){
        this->baralho.erase(it);
    }

    this->valorRodada = 0;
}
