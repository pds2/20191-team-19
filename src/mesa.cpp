#include "../include/mesa.h"
#include "../include/carta.h"
#include <iostream>

using namespace std;

Mesa::Mesa(){
    for (int i = 0; i < 4; i++)
    {
        this->cartas[i] = 0;
    }
}

/**
 * Pessoa ja jogou
*/
void Mesa::imprime_mesa(string p, string c1, string c2, string c3, Carta &carta){
    int peso = 0;
    string carta1, carta2, carta3;

    int i = 1;
    peso = this->cartas[i];
    if(peso != 0)
        carta1 = recuperaCarta(i, peso).get_nome() + recuperaCarta(i, peso).get_naipe();
    else
        carta1 = "      ";
    i++;
    peso = this->cartas[i];
    if(peso != 0)
        carta2 = recuperaCarta(i, peso).get_nome() + recuperaCarta(i, peso).get_naipe();
    else
        carta2 = "      ";
    i++;
    peso = this->cartas[i];
    if(peso != 0)
        carta3 = recuperaCarta(i, peso).get_nome() + recuperaCarta(i, peso).get_naipe();
    else
        carta3 = "      ";

    cout << "--------------------------------------------------" << endl;
    cout << "\t\t\t" << "   " << c2 << endl;
    cout << "\t\t    " << carta2 << endl;
    cout << endl; cout << endl;
    cout << "    "<< c3 << ": "  << carta3;
    cout << "\t\t   "<< c1 << ": " << carta1 << "  ";
    cout << endl; cout << endl;
    cout << "\t\t  " << carta.get_nome() << carta.get_naipe() << endl;
    cout << "\t\t\t" << "   " << p << endl;
    cout << "--------------------------------------------------" << endl;
}

/**
 * Pessoa ainda nao jogou
*/
void Mesa::imprime_mesa(string p, string c1, string c2, string c3){
    int peso = 0;
    string carta1, carta2, carta3;
    int i = 1;
    peso = this->cartas[i];
    if(peso != 0)
        carta1 = recuperaCarta(i, peso).get_nome() + recuperaCarta(i, peso).get_naipe();
    else
        carta1 = "      ";
    i++;
    peso = this->cartas[i];
    if(peso != 0)
        carta2 = recuperaCarta(i, peso).get_nome() + recuperaCarta(i, peso).get_naipe();
    else
        carta2 = "      ";
    i++;
    peso = this->cartas[i];
    if(peso != 0)
        carta3 = recuperaCarta(i, peso).get_nome() + recuperaCarta(i, peso).get_naipe();
    else
        carta3 = "      ";

    cout << "--------------------------------------------------" << endl;
    cout << "\t\t\t" << "   " << c2 << endl;
    cout << "\t\t    " << carta2 << endl;
    cout << endl; cout << endl;
    cout << "    "<< c3 << ": "  << carta3;
    cout << "\t\t   "<< c1 << ": " << carta1 << "  ";
    cout << endl; cout << endl;
    cout << "\t\t  " << "       " << endl;
    cout << "\t\t\t" << "   " << p << endl;
    cout << "--------------------------------------------------" << endl;
}

Carta Mesa::recuperaCarta(int id, int peso){
    list<Carta>::iterator it = this->baralho.begin();
    Carta c;
    if(id != 0){
        advance(it, id * 3);
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
    if(this->ganhouRodada[0] == 1 || this->ganhouRodada[1] == 1)
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
            this->ganhouRodada[i]++;
        }
    }
    this->valorRodada = 0;
}
