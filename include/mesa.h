#ifndef MESA_H
#define MESA_H

#include "carta.h"

class Mesa{
public:
    int cartas[4];
    int rodadaAnterior[4];
    int valorRodada;
    Mesa();
    void imprime_mesa();
};

#endif
