#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include <string>
#include "player.h"
#include "mao.h"
#include "mesa.h"

using namespace std;

class Computador: public Player{
    private:
        int _id;
        void jogaNaMesa(int id, string carta, int peso, Mesa& m);
        void jogaMenorCarta(Mesa& m);
        void jogaCartaMaior(int posicao, Mesa& m);
        void primeiroJogando(Mesa& m);
        void deletaCarta(int peso, string carta);
    public:
        Computador();
        Computador(string nome, int time, int id);
        int get_id();
        virtual void pedirTruco();
        virtual bool revisarTruco();
        virtual void receberMao(Mesa& mesa);
        virtual string get_nome();
        virtual Mao get_mao();
        void jogar(Mesa& m);

        //teste
        void imprime_mao();
};

#endif
