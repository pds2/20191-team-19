#ifndef JOGO_H
#define JOGO_H

#include <string>
#include "jogo.h"
#include "carta.h"
#include "mao.h"
#include "computador.h"
#include "jogo.h"
#include "pessoa.h"
#include "mesa.h"

using namespace std;

class Jogo{
    private:
        int _pntTimeA;
        int _pntTimeB;
        int _quemComeca;
        string _nome;
        void novoJogo();
    public:
        Jogo(int opcao);
        void set_quemComeca(int valor);
        void set_pntTimeA(int valor);
        void set_pntTimeB(int valor);
        int get_quemComeca();
        int get_pntTimeA();
        int get_pntTimeB();
        string get_nome();
        int iniciarJogo();
        void iniciarRodada(Mesa& mesa, Pessoa& p, Computador& c1, Computador& c2, Computador& c3);
};

#endif 
