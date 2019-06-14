#ifndef MESA_H
#define MESA_H

#include <string>
#include <list>
#include "carta.h"

class Mesa{
public:
    int cartas[4];
    int rodadaAnterior[4];
    int ganhouRodada[2];
    int valorRodada;
    list<Carta> baralho;
    Mesa();
    void imprime_mesa(string p, string c1, string c2, string c3, Carta &carta);
    void imprime_mesa(string p, string c1, string c2, string c3);
    Carta recuperaCarta(int id, int peso);
    int verificaQuemGanhou();
    void limpaMesa();
};

#endif
