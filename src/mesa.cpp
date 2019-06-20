#include <iostream>
#include <math.h>
#include "../include/carta.h"
#include "../include/mesa.h"

using namespace std;

Mesa::Mesa(){
    for (int i = 0; i < 4; i++)
    {
        if(i % 2 ==0)
            this->ganhouRodada[i] = 0;
        this->cartas[i] = 0;
        this->rodadaAnterior[i] = 0;
    }
    this->valorRodada = 2;
}

/**
 * Pessoa ja jogou
*/
void Mesa::imprime_mesa(string pessoa, string c1, string c2, string c3, string carta, int rodada){
    int peso = 0;
    string carta1, carta2, carta3;

    int i = 1;
    peso = this->cartas[i];
    if(peso != 0)
        carta1 = recuperaCarta(i, peso, rodada);
    else
        carta1 = "      ";
    i++;
    peso = this->cartas[i];
    if(peso != 0)
        carta2 = recuperaCarta(i, peso, rodada);
    else
        carta2 = "      ";
    i++;
    peso = this->cartas[i];
    if(peso != 0)
        carta3 = recuperaCarta(i, peso, rodada);
    else
        carta3 = "      ";

    cout << "--------------------------------------------------" << endl;
    cout << "\t\t\t" << c2 << endl;
    cout << "\t\t    " << carta2 << endl;
    cout << endl; cout << endl;
    cout << "    "<< c3 << ": "  << carta3;
    cout << "\t\t   "<< c1 << ": " << carta1 << "  ";
    cout << endl; cout << endl;
    cout << "\t\t\t" << carta << endl;
    cout << "\t\t\t" << pessoa << endl;
    cout << "--------------------------------------------------" << endl;
}

/**
 * Pessoa ainda nao jogou
*/
void Mesa::imprime_mesa(string pessoa, string c1, string c2, string c3, int rodada){
    int peso = 0;
    string carta1, carta2, carta3;
    int i = 1;
    peso = this->cartas[i];
    if(peso != 0)
        carta1 = recuperaCarta(i, peso, rodada);
    else
        carta1 = "      ";
    i++;
    peso = this->cartas[i];
    if(peso != 0)
        carta2 = recuperaCarta(i, peso, rodada);
    else
        carta2 = "      ";
    i++;
    peso = this->cartas[i];
    if(peso != 0)
        carta3 = recuperaCarta(i, peso, rodada);
    else
        carta3 = "      ";

    cout << "--------------------------------------------------" << endl;
    cout << "\t\t\t" << c2 << endl;
    cout << "\t\t    " << carta2 << endl;
    cout << endl; cout << endl;
    cout << "    "<< c3 << ": "  << carta3;
    cout << "\t\t   "<< c1 << ": " << carta1 << "  ";
    cout << endl; cout << endl;
    cout << "\t\t  " << "       " << endl;
    cout << "\t\t\t" << pessoa << endl;
    cout << "--------------------------------------------------" << endl;
}

string Mesa::recuperaCarta(int id, int peso, int rodada){
    list<Carta>::iterator it = this->baralho.begin();
    string c;
    if(id != 0){
        advance(it, id * rodada - 1);
    }
    for(it = this->baralho.begin(); it != this->baralho.end(); it++){
        if(it->get_peso() == peso){
            c = it->get_nome() + it->get_naipe();
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
        if(maior < this->cartas[i]){
            maior = this->cartas[i];
            posicao = i;
        }
    }
    if(this->ganhouRodada[0] != 0 || this->ganhouRodada[0] != 0)
        return posicao;
    else if(posicao == 0 || posicao == 2){
        this->ganhouRodada[0]++;
        return 4;
    }
    else{
        this->ganhouRodada[1]++;
        return 4;
    }
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
