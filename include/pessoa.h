#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include "player.h"
#include "mao.h"

class Pessoa: public Player{
    public:
        Pessoa(string nome);
        virtual void pedirTruco();
        virtual bool revisarTruco();
        virtual Mao get_mao();
        virtual void receberMao(Mao mao);
        void jogarCoberta();
        void imprime_mao();
};

#endif
