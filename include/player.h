#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "mao.h"

using namespace std;

class Player{
    protected:
        string _nome;
        Mao _mao;
        int _pesoMao;
        int _time;
    public:
        virtual void receberMao(Mao& mao) = 0;
        virtual void pedirTruco() = 0;
        virtual bool revisarTruco() = 0;
        virtual Mao get_mao() = 0;
        virtual string get_nome() = 0;
        virtual int get_time()=0;
};

#endif
