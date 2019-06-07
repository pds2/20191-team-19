#ifndef JOGO_H
#define JOGO_H

class Jogo{
    protected:
        int _pntTimeA;
        int _pntTimeB;
        int quemComeca;
        void novoJogo();
    public:
        Jogo(int opcao);
        void set_quemComeca(int valor);
        void set_pntTimeA(int valor);
        void set_pntTimeB(int valor);
        int get_quemComeca();
        int get_pntTimeA();
        int get_pntTimeB();
};

#endif 
