#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include "player.h"
#include "mao.h"
#include "mesa.h"
#include <string>

using namespace std;

class Computador: public Player{
    private:
        int _id;
        void jogaNaMesa(int id, string carta, int peso, Mesa &m);
        void jogaMenorCarta(Mesa &m);
        void jogaCartaMaior(int posicao, Mesa &m);
        void primeiroJogando(Mesa &m);
    public:
        Computador(string nome, int time, int id);
        int get_id();
        virtual void pedirTruco();
        virtual bool revisarTruco();
        virtual void receberMao(Mao mao);
        virtual Mao get_mao();
        void jogar(Mesa &m);
        
        //teste
        void imprime_mao();
};

#endif
