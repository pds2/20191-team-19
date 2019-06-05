#ifndef MAO_H
#define MAO_H

#include "carta.h"
#include <list>

using namespace std;

class Mao {
    private:
        string a;
    public:
        list<Carta> _cartas;
        Mao();
        int calcularPeso();
        Carta get_carta(int i);
};

#endif
