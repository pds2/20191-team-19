#ifndef JOGO_H
#define JOGO_H

#include <string>

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
};

#endif 
