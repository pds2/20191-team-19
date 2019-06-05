#ifndef MESA_H
#define MESA_H

#include "carta.h"

class Mesa{
public:
    Carta cartas[4];
    Mesa();
    void imprime_mesa();
}

#endif