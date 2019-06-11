#ifndef MESA_H
#define MESA_H

#include "carta.h"
#include <list>

class Mesa{
public:
    int cartas[4];
    int rodadaAnterior[4];
    int ganhouRodada[2];
    int valorRodada;
    list<Carta> baralho;
    Mesa();
    void imprime_mesa();
    Carta recuperaCarta(int id, int peso);
    int verificaQuemGanhou();
    void limpaMesa();
};

#endif
