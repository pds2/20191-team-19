#include "../include/mao.h"
#include "../include/carta.h"
#include <list>

using namespace std;

Mao::Mao()
{
    list<Carta> mao;
    for (int i = 0; i < 3; i++)
    {
        Carta c;
        list<Carta>::iterator it;

        bool existe = false;
        do
        {
            c = Carta();
            for (it = mao.begin(); it != mao.end(); it++)
            {
                if ((it->get_naipe() == c.get_naipe()) && (it->get_nome() == c.get_nome()))
                    existe = true;
            }

        } while (existe);
        mao.push_back(c);
    }
    this->_cartas = mao;
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
