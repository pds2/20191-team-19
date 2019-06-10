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
    for (int i = 1/*Quando player funcionando, mudar para 0*/; i < 4; i++)
    {
        peso = this->cartas[i];
        c = recuperaCarta(i - 1/*Quando player funcionando, tirar o -1*/, peso);
        cout << c.get_nome() << c.get_naipe() << endl;
    }
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
