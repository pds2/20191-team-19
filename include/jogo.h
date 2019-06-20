#ifndef JOGO_H
#define JOGO_H

#include <string>
#include "mesa.h"
#include "pessoa.h"
#include "computador.h"

using namespace std;

class Jogo{
    private:
        int _pntTimeA;
        int _pntTimeB;
        int _quemComeca;
        string _nome;
        void novoJogo();
        Mesa _mesa;
        Pessoa _p;
        Computador _c1;
        Computador _c2;
        Computador _c3;
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
        void iniciarRodada();
};

#endif 
