#ifndef MAO_H
#define MAO_H

#include <list>
#include "carta.h"
#include "mesa.h"

using namespace std;

class Mao {
    public:
        list<Carta> _cartas;
        Mao();
        Mao(Mesa &m);
        bool confereCarta(Carta &c, Mesa &m);
        int calcularPeso();
        Carta get_carta(int i);
};

#endif
