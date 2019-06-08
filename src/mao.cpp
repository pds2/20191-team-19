#include "../include/mao.h"
#include "../include/carta.h"
#include <list>

using namespace std;

Mao::Mao(){}

Mao::Mao(Mesa m)
{
    for (int i = 0; i < 3; i++)
    {
        Carta c;
        bool existe = false;
        do{
            existe = confereCarta(m);
        } while (existe);
        this->_cartas.push_back(c);
        m.baralho.push_back(c);
    }
}

bool Mao::confereCarta(Mesa m)
{
    Carta c = Carta();
    list<Carta>::iterator it = m.baralho.begin();
    for (it; it != m.baralho.end(); it++)
    {
        if(it->get_peso() == c.get_peso())
            return true;
    }
    return false;
}

int Mao::calcularPeso()
{
    int peso = 0;
    list<Carta>::iterator it;
    for (it = this->_cartas.begin(); it != this->_cartas.end(); it++)
    {
        peso += it->get_peso();
    }
    return peso;
}

Carta Mao::get_carta(int i){
    list<Carta> :: iterator it = this->_cartas.begin();
    advance(it, i - 1);
    return *it;
}
