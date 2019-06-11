#ifndef MESA_H
#define MESA_H

#include <string>
#include <list>
#include "computador.h"
#include "pessoa.h"

class Mesa{
public:
    int cartas[4];
    int rodadaAnterior[4];
    int ganhouRodada[2];
    int valorRodada;
    list<Carta> baralho;
    Mesa();
    void imprime_mesa(Pessoa &p, Computador &c1, Computador &c2, Computador &c3);
    void imprime_mesa(Pessoa &p, Computador &c1, Computador &c2, Computador &c3, Carta &carta);
    Carta recuperaCarta(int id, int peso);
    int verificaQuemGanhou();
    void limpaMesa();
};

#endif
