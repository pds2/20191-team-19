#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include "player.h"
#include "mao.h"

class Pessoa: public Player{
    public:
        Pessoa();
        Pessoa(string nome);
        virtual void pedirTruco();
        virtual bool revisarTruco();
        virtual string get_nome();
        virtual Mao get_mao();
        virtual void receberMao(Mesa& mesa);
        void jogarCoberta();
        void imprime_mao();
        string escolhe_carta();
};

#endif
