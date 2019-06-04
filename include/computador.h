#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include "player.h"
#include "mao.h"
#include <string>

using namespace std;

class Computador: public Player{
    public:
        Computador(string nome, int time);
        virtual void pedirTruco();
        virtual bool revisarTruco();
        virtual void receberMao(Mao mao);
        virtual Mao get_mao();
};

#endif
